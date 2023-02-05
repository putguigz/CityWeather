#!/bin/sh

RED="\e[31m"
GREEN="\e[32m"
RESET="\e[0m"

program=./CityWeather


if ! [[ -e $program ]]; then
    echo -e "Compiling With \e[33mMakefile...\e[0m"
    make  1>/dev/null
fi

valgrind --tool=memcheck --leak-check=yes --error-exitcode=1 $program 2>/dev/null

if [[ $? -eq 1 ]]; then
    echo -e "There is some ${RED}leaks${RESET}."
else
    echo -e "There is ${GREEN}0${RESET} leaks."
fi


