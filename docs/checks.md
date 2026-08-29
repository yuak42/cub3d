# Checks

In case of any wrong configuration of the .cub file, You should print

```
Error
<message with a suitable choice of yours>
```

1. General Check

[ ] Check is there invalid lines.
[ ] Check is there more than one identifiers.

2. Identifiers

[ ] Check every identifier exists and unique (NO, SO, WE, EA, F, C).

3. .xpm files

[ ] Check paths are valid. (readable, existence)

4. Floor and Ceiling

[ ] Check color values are in compatible format (r,g,b)
[ ] Check numbers in [0, 255]
[ ] No extra commas
[ ] No wrong writing like 0000,20,0000001 -> stupid

5. Map

[ ] Check if it is in the last.
[ ] Check if it is closed by walls. Check any part of the map not just start position. flood_fill every zeros and start positions
[ ] Check only one start position exists.
[ ] Check no invalid characters (characters other than 0,1,N,S,E,W and space).
[ ] Check is there any space inside of the map.

\*\*\*\* Check is it trimmind char '\n' for every identifier
