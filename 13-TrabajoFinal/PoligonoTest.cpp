/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
16/09/2020
Actualización con uso de punteros finalizada 05/11/2020 */

#include "Poligono.h"
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

//Muestro por pantalla como quedaron los polígonos almacenados, para así probar la función MostrarPoligono, luego las pruebas se realizarán usando assert

MostrarPoligono(pol1);
MostrarPoligono(pol2);
MostrarPoligono(pol3);



//Pruebas IsIgual (comparacion de poligonos)

assert (not IsIgual(pol1, pol2));
assert (not IsIgual(pol2, pol3));
assert (IsIgual (pol1, pol1));

//pruebas GetPerimetro

assert (4 == GetPerimetro(pol1));
assert (not (GetPerimetro(pol1) == 5.14));


//Pruebas AddVerticeAlFinal
AddVerticeAlFinal (pol2, {3,4}); //Agrega en la ultima posicion de pol2 el punto {3,4} dejandolo igual a pol3
assert (IsIgual(pol2, pol3));


//Pruebas InsertVertice

InsertVertice(pol3, 4, {2,3}); //agrega en pol3, en su posicion 4 el punto {2,3}

assert (not IsIgual (pol2, pol3)); //podemos ver como deja de ser igual a pol2
assert (IsIgualPunto(GetVertice (pol3,4), {2,3}));

//Pruebas GetVertice

assert (IsIgualPunto (GetVertice(pol1, 0), {0,0})); //Compruebo para el primer punto guardado
assert (not IsIgualPunto (GetVertice(pol1, 2), {0,0})); //Compruebo que el tercer punto no coincide con el (0, 0)


//Pruebas GetCantidadDeLados

assert (GetCantidadDeLados (pol1) == 4);
assert (GetCantidadDeLados (pol2) == 5);
assert (not (GetCantidadDeLados (pol1) == 2));

//pruebas RemoveLastVertice

RemoveLastVertice(pol2); //Quitamos el ultimo vertice de pol2
assert (GetCantidadDeLados(pol2) == 4); //Se puede ver como se modifico la cantidad de lados del pol2 ya que le quitamos un vertice
assert (not (GetCantidadDeLados (pol2) == 5));

//Pruebas SetVertice

SetVertice(pol1, 0, {-1, 0});
assert (IsIgualPunto(GetVertice(pol1, 0), {-1, 0}));
assert (not IsIgualPunto(GetVertice(pol1, 0), {0, 0}));
assert (GetCantidadDeLados(pol1) == 4);

//Pruebas AddVerticeAlComienzo

AddVerticeAlComienzo(pol2, {-3,-1});
assert (IsIgualPunto(GetVertice(pol2, 0), {-3, -1}));
assert (not IsIgualPunto(GetVertice(pol2, 0), {0, 0}));
assert (GetCantidadDeLados(pol2) == 5);

//Pruebas RemoveFirst

RemoveFirst (pol2);
assert (not IsIgualPunto(GetVertice(pol2, 0), {-3, -1}));
assert (IsIgualPunto(GetVertice(pol2, 0), {0, 0}));
assert (GetCantidadDeLados(pol2) == 4);

//Pruebas IsEmptyPuntos

assert (not IsEmptyPuntos (pol1));
assert (not IsEmptyPuntos (pol2));
assert (not IsEmptyPuntos (pol3));

//Pruebas LiberarMemoriaHeap

LiberarMemoriaHeap (pol1);
LiberarMemoriaHeap (pol2);
LiberarMemoriaHeap (pol3);

assert (IsEmptyPuntos (pol1));
assert (IsEmptyPuntos (pol2));
assert (IsEmptyPuntos (pol3));

}