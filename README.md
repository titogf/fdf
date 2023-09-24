# fdf

FDF is a program that reads a map that you will pass by parameter and converts it into a 3D map.
The name of the map must end in .fdf and must have the heights of those points in the space.
The program will return 'error' if the map does not contain the same number of columns in each row.

Example:

$>cat 42.fdf<br>
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0<br>
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0<br>
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0<br>
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0<br>
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0<br>
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0<br>
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0<br>
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0<br>
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0<br>
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0<br>
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0<br>
$>
