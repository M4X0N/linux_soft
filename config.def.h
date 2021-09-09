/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Liberation Mono:pixelsize=14:antialias=true:autohint=true" };
static const char dmenufont[]       = "Liberation Mono:pixelsize=14:antialias=true:autohint=true";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
/*	GRUVBOX COLORS	*/
static const char col_bg0[]			= "#282828";
static const char col_bg1[]			= "#3c3836";
static const char col_bg2[]			= "#504945";
static const char col_bg3[]			= "#665c54";
static const char col_bg4[]			= "#7c6f64";

static const char col_fg0[]			= "#fbf1c7";
static const char col_fg1[]			= "#ebdbb2";
static const char col_fg2[]			= "#d5c4a1";
static const char col_fg3[]			= "#bdae93";
static const char col_fg4[]			= "#a89984";
// Pale
static const char col_red[]			= "#cc241d";
static const char col_green[]		= "#98971a";
static const char col_yellow[]		= "#d79921";
static const char col_blue[]		= "#458588";
static const char col_purple[]		= "#b16286";
static const char col_aqua[]		= "#689d6a";
// Bright
static const char col_0red[]		= "#fb4934";
static const char col_0green[]		= "#b8bb26";
static const char col_0yellow[]		= "#fabd2f";
static const char col_0blue[]		= "#83a598";
static const char col_0purple[]		= "#d3869b";
static const char col_0aqua[]		= "#8ec07c";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_fg0,   col_bg0,   col_bg1 },
	[SchemeSel]  = { col_0yellow,   col_bg0,   col_bg4  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const char ptagf[] = "%s:%s";	/* format of a tag label */
static const char etagf[] = "%s";	/* format of an empty tag */
static const int lcaselbl = 0;		/* 1 means make tag label lowercase */	

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "gaplessgrid.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "###",      gaplessgrid },
	{ "[M]",      monocle },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_bg0, "-nf", col_fg0, "-sb", col_bg0, "-sf", col_0yellow, NULL };
static const char *termcmd[]  = { "st", NULL };

static const char *smenucmd[] = { "echo", "MENU", "|", "dmenu", "-m", dmenumon, "-fn", dmenufont, "-nb", col_bg0, "-nf", col_0blue, "-sb", col_0blue, "-sf", col_bg0, NULL };
static const char *killcmd[] = { "xkill", NULL };

static const char *passmenucmd[] = { "passmenu", NULL };
static const char *sscmd[]  = { "screenshot", NULL };
//static const char *sscmd[]  = { "maim -u | xclip -selection clipboard -t image/png -i", NULL };

static const char *rangercmd[]  = { "st", "ranger", NULL };
static const char *thunarcmd[]  = { "thunar", NULL };
static const char *bravecmd[]	= { "brave", NULL };
static const char *firefoxcmd[]	= { "firefox", NULL };

static const char *topcmd[]  = { "st", "bpytop", NULL };


static Key keys[] = {
	/* modifier             key    function        argument */
	{ MODKEY|ControlMask, 	119,   spawn,		   {.v = topcmd } }, // Ctrl Win Delete

	{ MODKEY,               33,    spawn,          {.v = dmenucmd } }, // p
	{ MODKEY,				135,   spawn,          {.v = dmenucmd } }, // options key
	{ MODKEY|ShiftMask,		33,    spawn,          {.v = passmenucmd } }, // P
	{ MODKEY|ShiftMask,     36,    spawn,          {.v = termcmd } }, // Return
	{ MODKEY,               26,    spawn,          {.v = rangercmd } }, // e
	{ MODKEY|ShiftMask,		26,    spawn,          {.v = thunarcmd } }, // e

	{ MODKEY,               56,    togglebar,      {0} },             // b
	{ MODKEY,               44,    focusstack,     {.i = +1 } },      // j
	{ MODKEY,               45,    focusstack,     {.i = -1 } },      // k
	{ MODKEY,               31,    incnmaster,     {.i = +1 } },      // i
	{ MODKEY,               40,    incnmaster,     {.i = -1 } },      // d
	{ MODKEY,               43,    setmfact,       {.f = -0.05} },    // h
	{ MODKEY,               46,    setmfact,       {.f = +0.05} },    // l
	{ MODKEY,               36,    zoom,           {0} },             // Return
	{ MODKEY,               23,    view,           {0} },             // Tab
	{ MODKEY|ShiftMask,     54,    killclient,     {0} },             // c
	{ MODKEY,               28,    setlayout,      {.v = &layouts[0]} }, // t
	{ MODKEY,               41,    setlayout,      {.v = &layouts[1]} }, // f
	{ MODKEY,				42,    setlayout,      {.v = &layouts[2]} }, // g
	{ MODKEY,               58,    setlayout,      {.v = &layouts[3]} }, // m
	{ MODKEY,               65,    setlayout,      {0} },             // space
	{ MODKEY|ShiftMask,     65,    togglefloating, {0} },             // space
	{ MODKEY,               19,    view,           {.ui = ~0 } },     // 0
	{ MODKEY|ShiftMask,     19,    tag,            {.ui = ~0 } },     // 0
	{ MODKEY,               59,    focusmon,       {.i = -1 } },      // comma
	{ MODKEY,               60,    focusmon,       {.i = +1 } },      // period
	{ MODKEY|ShiftMask,     59,    tagmon,         {.i = -1 } },      // comma
	{ MODKEY|ShiftMask,     60,    tagmon,         {.i = +1 } },      // period
	TAGKEYS(                10,                    0)                 // 1
	TAGKEYS(                11,                    1)                 // 2
	TAGKEYS(                12,                    2)                 // 3
	TAGKEYS(                13,                    3)                 // 4
	TAGKEYS(                14,                    4)                 // 5
	TAGKEYS(                15,                    5)                 // 6
	TAGKEYS(                16,                    6)                 // 7
	TAGKEYS(                17,                    7)                 // 8
	TAGKEYS(                18,                    8)                 // 9
	{ MODKEY|ControlMask,	22,		quit,			{0} },				// Backspace
	{ MODKEY|ShiftMask,		22,		quit,			{1} },				// Backspace

	{ NULL,					107,	spawn,          {.v = sscmd } }, // PrntScrn
	{ MODKEY|ShiftMask,		59,		cyclelayout,	{.i = -1 } },		// comma
	{ MODKEY|ShiftMask,		60,		cyclelayout,    {.i = +1 } },		// period
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },

	{ ClkStatusText,        0,              Button1,        spawn,          {.v = smenucmd } },
	{ ClkStatusText,        0,              Button3,        spawn,          {.v = killcmd } },
};

