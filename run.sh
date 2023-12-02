#!/bin/bash

echo  "---Building App---"

if [ ! -d "build" ]
then
    mkdir build
fi
cd build
cmake ..

echo  "---Running App---"
make
cd ..
