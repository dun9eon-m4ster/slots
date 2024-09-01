#!/bin/bash

git submodule init
git submodule update

thread_count=$(cat /proc/cpuinfo | grep processor | wc -l)

rm ./build -rf
mkdir build
cd build
cmake ..
cmake --build . -j $thread_count
cd ..
cp -rT resources build
