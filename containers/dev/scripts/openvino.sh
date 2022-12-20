#!/bin/bash

cd /tmp
git clone https://github.com/openvinotoolkit/openvino.git
cd openvino
git submodule update --init --recursive
chmod +x install_build_dependencies.sh
./install_build_dependencies
mkdir build && cd build

cmake -DCMAKE_BUILD_TYPE=Release \
-DENABLE_PYTHON=ON \
-DPYTHON_EXECUTABLE=`which python3.10` \
-DPYTHON_LIBRARY=/usr/lib/x86_64-linux-gnu/libpython3.10.so \
-DPYTHON_INCLUDE_DIR=/usr/include/python3.10 ..

make --jobs=$(nproc --all)

mkdir -p /opt/intel/openvino
cmake --install . --prefix /opt/intel/openvino

cd /opt/intel/openvino
source setupvars.sh

rm -rf /tmp/openvino
