/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
16/09/2020*/

#include "PoligonoArray.h"
#include <cassert>

int main(){


Poligono pol1;
pol1.c = rojo;
AddVerticeAlFinal (pol1, {0,0});
AddVerticeAlFinal (pol1, {1,0});
AddVerticeAlFinal (pol1, {1,1});
AddVerticeAlFinal (pol1, {0,1});

Poligono pol2;
pol2.c = verde;
AddVerticeAlFinal (pol2, {0,0});
AddVerticeAlFinal (pol2, {1,0});
AddVerticeAlFinal (pol2, {0,2});
AddVerticeAlFinal (pol2, {1,1});

Poligono pol3;
pol3.c = verde;
AddVerticeAlFinal (pol3,{0,0});
AddVerticeAlFinal (pol3,{1,0});
AddVerticeAlFinal (pol3,{0,2});
AddVerticeAlFinal (pol3,{1,1});
AddVerticeAlFinal (pol3,{3,4});

MostrarPoligono(pol1);
MostrarPoligono(pol2);
MostrarPoligono(pol3);
//Pruebas IsIgual (comparacion de poligonos)

assert (not IsIgual(pol1, pol2));
assert (IsIgual (pol1, pol1));

//pruebas GetPerimetro

assert (4 == GetPerimetro(pol1));
assert (not (GetPerimetro(pol1) == 5.14));

//Pruebas AddVertice
AddVerticeAlFinal (pol2, {3,4}); //Agrega en la ultima posicion de pol2 el punto {3,4} dejandolo igual a pol3

assert (IsIgual(pol2, pol3));

//Pruebas SetVertice

SetVertice(pol3, 4, {2,3}); //modifica en pol3, en su posicion 4 el valor del punto por {2,3}

assert (not IsIgual(pol2, pol3)); //podemos ver como deja de ser igual a pol2
assert (IsIgualPunto(pol3.puntos.at(4), {2,3}));

//Pruebas GetVertice

assert (IsIgualPunto (GetVertice(pol1, 0), {0,0}));
assert (not IsIgualPunto (GetVertice(pol1, 3), {0,0}));

//Pruebas GetCantidadDeLados

assert (GetCantidadDeLados (pol1) == 4);
assert (GetCantidadDeLados (pol2) == 5);
assert (not (GetCantidadDeLados (pol1) == 2));

//pruebas RemoveVertice

RemoveVertice(pol2); //Quitamos el ultimo vertice de pl2

assert (GetCantidadDeLados(pol2) == 4); //Se puede ver como se modifico la cantidad de lados del pol2 ya que le quitamos un vertice
assert (not (GetCantidadDeLados (pol2) == 5));


} 