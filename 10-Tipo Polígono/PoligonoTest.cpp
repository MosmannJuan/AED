/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
16/09/2020*/

#include "Poligono.h"
#include <cassert>

int main(){


Poligono pol1;
pol1.PrimerPunto=NULL;
pol1.c = rojo;
AddVertice (pol1, {0,0});
AddVertice (pol1, {1,0});
AddVertice (pol1, {1,1});
AddVertice (pol1, {0,1});

Poligono pol2;
pol2.PrimerPunto=NULL;
pol2.c = verde;
AddVertice (pol2, {0,0});
AddVertice (pol2, {1,0});
AddVertice (pol2, {0,2});
AddVertice (pol2, {1,1});

Poligono pol3;
pol3.PrimerPunto=NULL;
pol3.c = verde;
AddVertice (pol3,{0,0});
AddVertice (pol3,{1,0});
AddVertice (pol3,{0,2});
AddVertice (pol3,{1,1});
AddVertice (pol3,{3,4});

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


//Pruebas AddVertice
AddVertice (pol2, {3,4}); //Agrega en la ultima posicion de pol2 el punto {3,4} dejandolo igual a pol3
assert (IsIgual(pol2, pol3));


//Pruebas SetVertice

SetVertice(pol3, 4, {2,3}); //agrega en pol3, en su posicion 4 el punto {2,3}


assert (not IsIgual(pol2, pol3)); //podemos ver como deja de ser igual a pol2


//Pruebas GetVertice

assert (IsIgualPunto (GetVertice(pol1, 1), {0,0})); //Compruebo para el primer punto guardado
assert (not IsIgualPunto (GetVertice(pol1, 3), {0,0})); //Compruebo que el tercer punto no coincide con el (0, 0)


//Pruebas GetCantidadDeLados

assert (GetCantidadDeLados (pol1) == 4);
assert (GetCantidadDeLados (pol2) == 5);
assert (not (GetCantidadDeLados (pol1) == 2));

//pruebas RemoveVertice

RemoveVertice(pol2); //Quitamos el ultimo vertice de pol2
assert (GetCantidadDeLados(pol2) == 4); //Se puede ver como se modifico la cantidad de lados del pol2 ya que le quitamos un vertice
assert (not (GetCantidadDeLados (pol2) == 5));


}