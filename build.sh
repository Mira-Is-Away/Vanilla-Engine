#!/bin/bash

set -e

clear

cd bin
cmake ..
make -j"$(nproc)"

./vanilla