# Autor de la resolución:
## Usuario Github: MosmannJuan
## Mosmann, Juan Ignacio
## Legajo N° 158.964-7

# Trabajo N° 11: "Flujo de datos de polígono"

# Etapa 1: Análisis del problema.
## Enunciado: Desarrollar una función que reciba a traves de un flujo de entrada (estándar o alguno en particular) un polígono y lo guarde en memoria.

## Hipótesis de trabajo: Se utilizarán las definiciones anteriormente usadas de tipo Punto, tipo Color y tipo Poligono. Se desarrollará la solución del problema mediante la definición de funciones. Para las pruebas se mostrarán los puntos, el color y, finalmente, el poligono extraído por pantalla utilizando una función.

## Problemas encontrados: 
* Al usar el tipo de datos uint_8 para las coordenadas del color, ExtraerColor solo tomaba un digito de cada numero.
* Para poder hacer que las funciones retornen un booleano si se lograba extraer lo solicitado, no basto con solo retornar el istream, se debio agregar delante bool con el nombre del flujo entre parentesis luego.

