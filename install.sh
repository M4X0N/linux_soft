#!/bin/bash
# Additional wrapper to
echo "Started"

while getopts 'mu' OPTION; do
  case "$OPTION" in
    m)
      echo "Make, without install"
      ;;
    u)
      echo "Uninstalling"
      ;;
    ?)
      echo "Script usage: $(basename \$0) -m - make, not install, -u uninstall" >&2
      exit 1
      ;;
  esac
done
shift "$(($OPTIND -1))"

echo "Ended"
