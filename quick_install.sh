#!/bin/sh

RED="\e[31m"
GREEN="\e[32m"
RESET="\e[0m"

program=./build/CityWeather

if ! [[ -e $program ]]; then
    echo -e "\e[33mCmake is running...\e[0m"
    mkdir build > /dev/null 2>&1
    cd build 
    cmake .. 2>/dev/null
    make -j ./CityWeather 2>/dev/null
fi

