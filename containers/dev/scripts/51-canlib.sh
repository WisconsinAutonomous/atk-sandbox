#!/bin/bash

cd /tmp/scripts/canlib

DEBIAN_FRONTEND=noninteractive

# kvaser-canlib
apt-get update -qq
apt-get install -y software-properties-common
apt-add-repository -y ppa:astuff/kvaser-linux
apt-get update -qq
apt-get install kvaser-canlib-dev -y

# kvlibsdk (database)
apt-get install libxml2-dev libssl-dev zlib1g-dev tar -y
tar xfz kvlibsdk.tar.gz
cd kvlibsdk
make
make install

# linuxcan
# Allows virtualcan
if [[ `uname -r` != *"linuxkit"* ]]; then
	cd /tmp/scripts/canlib
	apt install -y usbutils linux-headers kmod
	tar xvzf linuxcan.tar.gz
	cd linuxcan
	make
	make install
	make load
fi

