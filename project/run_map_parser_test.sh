shopt -s globstar

for map in **/*.cub; do
    echo "Testing: $map"
    ./cub3d "$map"
done