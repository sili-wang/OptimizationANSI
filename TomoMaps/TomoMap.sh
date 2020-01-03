#!/bin/bash

clear
g++ -std=c++11 TomoMap.cpp
./a.out $1 $2

sleep 2
xdg-open "TomoMaps.html"
