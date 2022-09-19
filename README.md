# fdf
Este proyecto consiste en crear un “marco” gráfico simple. Este representará el relieve de un
paisaje enlazando varios puntos (x, y, z) a través de segmentos. Las coordenadas de
este paisaje se guardan en un archivo pasado como parámetro a tu programa. Aquí tienes
un ejemplo:
$>cat 42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  10 10 0  0  10 10 0  0  0  10 10 10 10 10 0  0  0
0  0  10 10 0  0  10 10 0  0  0  0  0  0  0  10 10 0  0
0  0  10 10 0  0  10 10 0  0  0  0  0  0  0  10 10 0  0
0  0  10 10 10 10 10 10 0  0  0  0  10 10 10 10 0  0  0
0  0  0  10 10 10 10 10 0  0  0  10 10 0  0  0  0  0  0
0  0  0  0  0  0  10 10 0  0  0  10 10 0  0  0  0  0  0
0  0  0  0  0  0  10 10 0  0  0  10 10 10 10 10 10 0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
$>
Cada número corresponde a un punto en el espacio:
• La posición horizontal corresponde a su eje.
• La posición vertical corresponde a su eje de coordenadas (Y).
• El valor corresponde a su altitud
