# FDF

El proyecto `fdf` es un programa en C que representa un modelo en estructura alámbrica en 3D de un paisaje. El modelo se genera a partir de un archivo con formato `.fdf` que contiene las coordenadas del paisaje.

## Descripción

El programa toma un archivo `.fdf` como entrada, que describe un paisaje en 3D mediante una matriz de puntos (x, y, z). Cada valor en el archivo representa un punto en el espacio, donde:

- La posición horizontal corresponde al eje X.
- La posición vertical corresponde al eje Y.
- El valor en sí mismo corresponde a la altitud (eje Z).

El objetivo del programa es representar gráficamente esta matriz en una proyección isométrica.

### Características Principales

- **Renderizado en 3D**: El programa representa el paisaje en una proyección isométrica, creando un efecto visual de 3D.
- **Gestión de Ventana**: La visualización se realiza en una ventana gráfica utilizando la MiniLibX. El programa responde de manera fluida a interacciones como minimizar, cerrar o cambiar de ventana.
- **Interacción del Usuario**: Permite cerrar la ventana presionando `ESC` o haciendo clic en la `X` del marco de la ventana. Mover el mapa con las flechas o ratón. Mover el eje de las cordenadas con el teclado numérico.
- 
## Instalación

Este proyecto incluye un `Makefile` para compilar los archivos fuente. Asegúrate de tener `make` instalado en tu sistema. Luego, puedes compilar el proyecto con:
`make`.Esto generará un ejecutable llamado fdf.

Para limpiar los archivos objeto y otros archivos generados, utiliza:
`make clean`

### Uso
Para ejecutar el programa, proporciona un archivo .fdf como argumento:

```
./fdf archivo.fdf
```
### Bonus
Algunas características extra que puedes agregar para mejorar el proyecto incluyen:

Proyecciones Adicionales: Soporte para proyecciones paralelas o cónicas.
Zoom: Capacidad de acercar y alejar el modelo.
Traslación: Mover el modelo dentro de la ventana.
Rotación: Rotar el modelo en el espacio 3D.
Otras Mejoras: Añadir cualquier otra funcionalidad que enriquezca la experiencia del usuario. (colores, información en la ppropia ventana)
