## Trabajo Práctico 3: "Ejemplo de Valores y Operaciones de Tipos de Datos"

### Autor de la resolución: Mosmann, Juan Ignacio.

### Objetivos del trabajo: Diseñar un programa C++ que ejemplifique la aplicación de los tipos de datos vistos en clases (unsigned, int, double, bool, char y string), sin extraer valores de cin (sólo usar valores constantes) y, en lo posible, no utilizar cout, y hacer las pruebas con assert.

### Resolución: 
#### Para la variable double se propuso aplicarlas al cálculo del área de una circunferencia de radio 2.5, para el valor de pi tomamos 16 decimales que son las que acepta el tipo de variable, para las pruebas utilizamos assert poniendo como condicion que el valor total del área no debe ser mayor a 20.
#### Para las variables string y unsigned se realizó un ejemplo conjunto, que consiste en calcular el promedio de un alumno y verificar si esta aprobado, declarando dos variables unsigned para las notas de los exámenes y dos variables string para "aprueba" y " por promoción". Se calcula el promedio y se utiliza para las pruebas dos assert, uno que indique que el promedio es mayor o igual a 8 y otro que pruebe el resultado de la concatenación de los string.
#### Para las variables tipo char, se diseño un ejemplo que consiste en tomar las iniciales de mi nombre, concatenarlas y luego se realizaron las pruebas con un assert que tiene como condición que el tamaño de dicha concatenación sea de 3.
#### Para el ejemplo con bool, simplemente se propusieron dos variables con distintos valores (true y false) y se realizó la operación AND con ellas, en el assert que usamos para la prueba se puso como condición que el resultado sea false (0).
#### Por último, para el ejemplo con variable int, se declararon 2 variables, una con valor positivo y otra con valor negativo, y se realizaron las 4 operaciones básicas entre ellas, las pruebas se realizaron mediante 4 asserts que tienen como condición la verificación de los resultados.

