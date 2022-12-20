#!/bin/bash

######
# workaround for qt5-default package not existing in Ubuntu 22.04
# pulled from https://askubuntu.com/questions/1335184/qt5-default-not-in-ubuntu-21-04
cd
mkdir Downloads
cd ~/Downloads
cat <<EOF > qt5-default-control
Package: qt5-default
Source: qtbase-opensource-src
Version: 5.99.99+fake-13ubuntu37
Architecture: all
Depends: qtbase5-dev, qtchooser
Suggests: qt5-qmake, qtbase5-dev-tools
Conflicts: qt4-default
Section: libdevel
Priority: optional
Homepage: http://qt-project.org/
Description: Qt 5 development defaults fake package
EOF

equivs-build qt5-default-control
apt-get install ./qt5-default_5.99.99+fake-13ubuntu37_all.deb
#####

# run the spinnaker install scripts
cd /tmp/scripts/spinnaker
sh install_spinnaker.sh < "../spinnaker_input.txt"
sh configure_usbfs.sh
sh configure_spinnaker_paths.sh
sh configure_spinnaker.sh
