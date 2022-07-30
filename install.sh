#!/bin/bash
# Additional wrapper to
echo "Started"

echo "Cleaning"
rm config.h &
rm drw.o &
rm dwm &
rm dwm.o &
rm util.o &

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
rm config.h &
rm drw.o &
rm dwm &
rm dwm.o &
rm util.o &

echo "Finished"
