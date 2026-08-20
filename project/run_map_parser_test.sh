shopt -s globstar

for map in **/*.cub; do
    echo -e "\nTesting: $map"
    ./cub3d "$map"
	echo -e "\n"
done