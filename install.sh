#!/bin/bash
# Additional wrapper to
echo "Started"

echo "Cleaning"
2>/dev/null 1>/dev/null rm config.h &
2>/dev/null 1>/dev/null rm drw.o &
2>/dev/null 1>/dev/null rm dwm &
2>/dev/null 1>/dev/null rm dwm.o &
2>/dev/null 1>/dev/null rm util.o &

while getopts 'imu' OPTION; do
  case "$OPTION" in
    i)
      echo "Make and install"
      make && sudo make install
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

echo "Cleaning"
2>/dev/null 1>/dev/null rm config.h &
2>/dev/null 1>/dev/null rm drw.o &
2>/dev/null 1>/dev/null rm dwm &
2>/dev/null 1>/dev/null rm dwm.o &
2>/dev/null 1>/dev/null rm util.o &

echo "Finished"
