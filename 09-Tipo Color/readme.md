# Autor de la resolución:
## Usuario Github: MosmannJuan
## Mosmann, Juan Ignacio
## Legajo N° 158.964-7

# Trabajo N° 9: "Tipo Color"

# Etapa 1: Análisis del problema.
## Enunciado: Diseñar un tipo Color basado en el modelo RGB1, con tres canales de 8 bits. Todo color está compuesto por tres componentes: intensidad de red (rojo), de green (verde), y de blue (azul). Cada intensidad está en el rango [0, 255]. Definirlos valores para rojo, azul, verde, cyan, magenta, amarillo, negro, y blanco. Dos colores se pueden mezclar, lo cual produce un nuevo color que tiene el promedio de intensidad para cada componente.

## Restricciones
• Las operaciones de proyección para red, green, y blue se implementan con acceso directo a los componentes, no es necesario definir getters especiales. Por la misma razón, los setters no son necesarios.

• Utilizar el tipo uint8_t de cstdint, si no es posible, usar unsigned char.

• Los colores primarios, secundarios, negro y blanco deben implementarse como ocho variables declaradas fuera de main y de toda función, con el calificador const para que no puedan modificarse.

• Implementar la operación IsIgual que retorna true si un color es igual a otro, si no, false.

## Tareas
1. Especificar matemáticamente el tipo en Color.md:
a. Especificar el conjunto de operaciones.
b. Especificar el conjunto de valores.
2. Diseñar y codificar las pruebas en main.
3. Declarar los prototipos de las operaciones arriba de main.
4. Declarar Color antes de los prototipos las operaciones.
5. Compilar: Luego de finalizar tareas anteriores, estamos en condiciones de compilar. Deberíamos obtener error de linkeo (i.e., vinculación) pero no de compilación.
6. Codificar las definiciones de las operaciones, debajo de main.
7. Probar: Luego de las definiciones, deberíamos poder realizar el proceso de traducción completo (i.e., compilación y linkeo) sin errores. Una vez obtenido el programa ejecutable, deberíamos poder ejecutarlo sin errores.

## Hipótesis de trabajo: Consideramos para su definición al color negro como la ausencia total de color y al color blanco como la suma de todos los colores. 

## Justificación del uso de uint8_t : Se utiliza este tipo de dato ya que, al tratarse de un número entero sin signo que ocupa 8 bits, establece la condición de que los valores  r, g y b deben encontrarse entre 0 y 255.
