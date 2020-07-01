# **Autor de la resolución:** 

## **Ususario Github:** MosmannJuan

## Mosmann, Juan Ignacio

## **Legajo N°** 158.964-7

## **Trabajo Práctico Opcional:** "Funciones recursivas con operador condicional"
  
### **Etapa 1: Análisis del problema.**

#### **Enunciado:** Desarrollar las siguientes funciones: 
* División entera de naturales: Div
* MCD (Máximo Común Denominador): Mcd
* Factorial: Fact
* Fibonacci: Fib

#### Restricciónes: 
- Las pruebas deben realizarse con assert.
- Cada función debe aplicar el operador condicional.

#### (Para realizar los análisis se efectuarán separados para cada una de las funciones).

## **Función Div:**

#### **Hipótesis:** Se desarrollará una función recursiva que tome dos valores naturales y retorne el resultado natural de la división entera entre ellos. Las pruebas se desarrollarán utilizando assert.

#### **Modelo IPO:** N*N → división recursiva → N


## **Función Mcd:**

#### **Hipótesis:** Se desarrollará una función recursiva utilizando el Algoritmo de Euclides que tome dos valores enteros y retorne el valor entero correspondiente al MCD entre ellos. Las pruebas se desarrollarán utilizando assert.

#### **Modelo IPO:** Z*Z → Algoritmo de Euclides → Z


## **Función Fact:** 

#### **Hipótesis:** Se desarrollará una función recursiva que tome un valor natural y retorne el valor real de su factorial. Las pruebas se desarrollarán utilizando assert.

#### **Modelo IPO:** N → Factorial → R


## **Función Fib:**

#### **Hipótesis:** Se desarrollará una función que tome un valor natural correspondiente a la posición en la serie de Fibonacci y retorne el valor natural correspondiente a dicha posición. Las pruebas se desarrollarán utilizando assert.

#### **Modelo IPO:** N → Fibonacci → N


### **Etapa 2: Diseño de la solución.**

## **Función Div:** 

#### Léxico del algoritmo: dividendo, divisor ∈ N
#### Div: N² → N / Div(dividendo, divisor) =
#### 0          si   dividendo < divisor
#### 1 + Div(x-y,y)  e.o.c


## **Función Mcd:**

#### Léxico del algoritmo: x, y ∈ Z 
#### Mcd:  Z² → Z / Mcd(x,y) =  
#### x      si   y = 0
#### Mcd(y, x%y) e.o.c (x%y representa al resto de la división entera entre x e y)


## **Función Fact:**

#### Léxico del algoritmo: n ∈ N
#### Fact: N → R / Fact(n) = 
#### 1           si   n = 0
#### n * Fact(n-1)   e.o.c
##### (se eligió que la función pertenezca a los reales del tipo double en c++ para poder representar números de magnitudes mayores que las que permitiría el tipo int o unsigned)



## **Función Fib:**

#### Léxico del algoritmo: n ∈ N
#### Fib: N → N / Fib(n) = 
#### n             si    n < 2
#### Fib(n-1) + Fib(n-2) e.o.c
