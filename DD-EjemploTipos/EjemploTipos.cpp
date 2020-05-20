
/*Mosmann, Juan Ignacio
AED 2020 K1051
18/05/2020*/

#include <iostream>
#include <assert.h>
int main()
{ /*Ejemplo para variable Double, se utilizará para realizar el cálculo del área de un círculo de radio 2.5 
y asegurar que el valor es menor a 20*/
double pi, radio, area;

pi = 3.1415926535897932;

radio = 2.5;

area = pi*radio*radio;

assert (area < 20);

/*Ejemplo para string y unsigned, se calculará el promedio para un alumno y se verá si está aprobado o no*/

unsigned P1,P2,Promedio;
std::string a = "Aprueba", b = " por promocion";
P1 = 9;
P2 = 8;
Promedio = (P1+P2)/2;
assert (Promedio >= 8);
assert (a+b == "Aprueba por promocion");


/*Para el ejemplo con char utilizaremos un codigo que escriba las 
iniciales de un nombre y luego cuente cuantas son*/

char N1 = 'J', N2 = 'I', Ap = 'M' ;
char Iniciales []  = {N1,N2,Ap};

assert (sizeof Iniciales == 3); 

/*Ej bool, probaremos que al realizar la operación AND entre dos valores Booleanos
 distintos el resultado debe ser falso*/

bool T=true, F=false, resultado;

resultado = T&&F;

assert (resultado == false);

/*Ejemplo con int: se propondrán 2 números enteros y se realizaran 4 operaciones con ellos*/

int x=12, y=-2, suma, resta, producto, cociente;
suma=x+y;
resta=x-y;
producto=x*y;
cociente=x/y;
assert(suma==10);
assert(resta==14);
assert(producto==-24);
assert(cociente==-6);
}


