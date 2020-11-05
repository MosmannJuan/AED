# Autor de la resolución:
## Usuario Github: MosmannJuan
## Mosmann, Juan Ignacio
## Legajo N° 158.964-7

# Trabajo N° 10: "Tipo polígono"

# Etapa 1: Análisis del problema.
## Enunciado: Desarrollar el tipo de dato Polígono que representa polígonos con color en el plano. Las operaciones son: AddVértice, GetVértice, SetVértice, RemoveVértice, GetCantidadLados, y Get_GetPerímetro.

## Restricciones
• Las pruebas deben realizarse con assert, sin usar cin ni cout.

## Tareas
1. Especificar el tipo matemáticamente.
2. Diseñar y codificar las pruebas en main.
3. Implementar el tipo.

## Hipótesis de trabajo: Asumimos para la definición del máximo de lados del polígono que tendrá un límite de 20 lados (isodecágono). Se tendrán en cuenta para la resolución las anteriores definiciones de Tipo Punto (https://github.com/MosmannJuan/AED/tree/master/08-Tipo%20Punto)  y Tipo Color (https://github.com/MosmannJuan/AED/tree/master/09-Tipo%20Color).

## Edit 5/11 (Implementación de punteros):

1. Al hacer uso de punteros, el almacenamiento de puntos se transforma en dinámico, razón por la cual no habrá un límite de puntos a almacenar. 
2. Al poseer ya una función encargada de leer poligonos de cualquier flujo (Ver en el siguiente link: https://github.com/MosmannJuan/AED/tree/master/11-FlujoPoligonos), se eliminó la función LeerPoligono de este archivo ya que resultaba redundante e incluso más restrictiva, ya que solamente podía leer del flujo estándar.
