#!/bin/bash

find . -name "*.cub" | while read -r map; do
    echo -e "\nTesting: $map"
    valgrind ./cub3D "$map"
    echo -e "\n"
done