#! /bin/bash
# Install all dependencies for this project.

sudo apt-get update

# Cmake
sudo apt-get install cmake

# Google test (gtest)
sudo apt-get install libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp ./*.a /usr/lib
