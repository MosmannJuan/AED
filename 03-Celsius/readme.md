# **Autor de la resolución:** 

## **Ususario Github:** MosmannJuan

## Mosmann, Juan Ignacio

## **Legajo N°** 158.964-7

## **Trabajo Práctico N°3:** "Funciones y comparación de valores en punto flotante - Celsius"
  
### **Etapa 1: Análisis del problema.**

#### **Enunciado:** Desarrollar una función que, dada una magnitud en Farehnheit, calcule la
equivalente en Celsius. 

### Problemas: 
### Hay dos sub-problemas que se requieren solucionar antes de poder probar e implementar la función Celsius:
-Valor de la fracción versus la división entera de la expresión 5/9 en C++
- Representación no precisa de los tipos flotantes.

###Una solución al primer problema es realizar división entre flotantes. Para el segundo problema, debemos incorporar la comparación con tolerancia, para eso debemos diseñar una función bool que reciba dos flotantes a comparar y un flotante que repesente la tolerancia.

#### Hipótesis: Se definirá una función **celsius** que tome un valor real, que representa a la temperatura en grados farenheit, y retorne otro valor real que represente la temperatura en grados celsius. 
#### Para verificar que el valor real obtenido se encuentra dentro de los valores esperados se definirá otra funcion **AreNear** que tome 3 valores reales, siendo uno de ellos el obtenido por la función anterior, que compare los valores y que retorne un valor booleano que verifica si respeta la tolerancia definida.
#### Para las pruebas se utilizarán asserts.

#### Modelo IPO:
- **Celsius:** R → Pasaje a celsius → R
- **AreNear** R x R x R → Comparación → Bool

### **Etapa 2: Diseño de la solución.**

#### Léxico del algoritmo: 
- **celsius:** f ∈ R
- **AreNear:** c, x, tol ∈ R

#### Representación visual:

<p align = "center">
  
![Celsius](https://user-images.githubusercontent.com/63465251/83701544-54ab6f00-a5e0-11ea-91f4-3090d7d0a749.jpg)

</p>

