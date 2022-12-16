#!/bin/bash

compfiles=("config.h"
	   "drw.o"
	   "dwm"
	   "dwm.o"
   	   "util.o")

function clean
{
	for file in "${compfiles[@]}"; do
		if [ -f $file ]; then
			echo "Removing $file"
			sudo 2>/dev/null 1>/dev/null rm $file
		fi
	done
}

echo "Started"

clean
while getopts 'imu' OPTION; do
  case "$OPTION" in
    i)
      echo "Make and install"
      make && sudo make clean install
      ;;
    m)
      echo "Make only"
      make
      ;;
    u)
      echo "Uninstall"
      sudo make uninstall
      ;;
    ?)
      echo "Script usage: $(basename \$0) -i make+install -m - make, -u uninstall" >&2
      exit 1
      ;;
  esac
done
shift "$(($OPTIND -1))"

clean
echo "Finished"
