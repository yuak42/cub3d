#!/bin/bash

shopt -s globstar nullglob

for map in maps/**/*.cub maps/*.cub; do
    echo -e "\nTesting: $map"

    ./cub3D "$map"

    echo -e "\n"
done