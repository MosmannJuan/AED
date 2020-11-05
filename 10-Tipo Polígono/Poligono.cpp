/* Mosmann, Juan Ignacio
AED 2020
Curso K1051
16/09/2020
Actualización con uso de punteros finalizada 05/11/2020 */

#include "Poligono.h"
#include <iostream>
#include <cmath>

//Definición de funciones

void AddVertice (Poligono& pol, const Punto& pun){
    
    Nodo  *n = new Nodo;
   
    n->p.x = pun.x;
    n->p.y = pun.y;
    n->SigNodo = NULL;

    if(pol.PrimerPunto == NULL) pol.PrimerPunto = n;
           
    else{
        Nodo* aux = pol.PrimerPunto;

        while(aux->SigNodo != NULL) aux = aux->SigNodo;

        aux->SigNodo = n;
    }
    
}

Punto GetVertice (const Poligono& pol, const unsigned& pos){
Nodo* aux;
aux = pol.PrimerPunto;
for(int i = 0; i < pos - 1; ++i) aux = aux->SigNodo;
return aux->p ;
}

void SetVertice (Poligono& pol, const unsigned& pos , const Punto& p){
    Nodo  *n = new Nodo;
    n->p.x = p.x;
    n->p.y = p.y;

    if(pos == 1) {
        n->SigNodo = pol.PrimerPunto; //Si quiero ubicarlo en el primer lugar, hago que mi nodo apunte a la dirección que apuntaba el puntero del poligono
        pol.PrimerPunto = n; // Luego hago que el puntero del poligono que inidica el principio de la lista apunte a el nodo nuevo
        }

    else{ 
        Nodo *aux = pol.PrimerPunto;
        for(int i = 1; i < pos - 1; ++i) aux = aux->SigNodo; //Recorre la lista asignando a aux los distintos punteros hasta alcanzar al que apunta a la posición deseada
        n->SigNodo = aux->SigNodo; //Asigno al nuevo nodo la dirección que corresponde al nodo que se ubicaba en la posición que quiero ocupar
        aux->SigNodo = n; //Asigno al anterior nodo la dirección del nuevo nodo
    }
}

void RemoveVertice (Poligono & pol){
    unsigned i = GetCantidadDeLados(pol);
    Nodo* aux = pol.PrimerPunto;
    for (unsigned j = 1; j < i - 1; ++j) aux = aux->SigNodo; //Recorre la lista hasta que obtiene en aux la posición del anteultimo nodo
    aux->SigNodo = NULL; //Rompe la conexión con el que era el ultimo nodo
}


unsigned GetCantidadDeLados (const Poligono& pol){
    unsigned lados = 0;
    Nodo* aux = pol.PrimerPunto;

    while (aux != NULL) {
        ++lados;
        aux = aux->SigNodo;} 

    return lados;

}

double GetPerimetro (const Poligono& pol){
double resultado = 0;
Punto puntoaux;
Nodo* aux;

puntoaux.x = pol.PrimerPunto->p.x;
puntoaux.y = pol.PrimerPunto->p.y;

aux = pol.PrimerPunto;

while (aux->SigNodo != NULL){
    resultado = resultado + GetDistancia(puntoaux, aux->p);
    puntoaux.x = aux->p.x;
    puntoaux.y = aux->p.y;
    aux = aux->SigNodo;} //Este ciclo utiliza un punto auxiliar para guardar el punto del nodo anterior y calcular su distancia con el punto almacenado en la dirección guardada en aux, hasta que se encuentra con el puntero que direcciona a la ultima dirección

    resultado = resultado + GetDistancia(puntoaux, aux->p) + GetDistancia(aux->p, pol.PrimerPunto->p); //Al valor del resultado actual se le debe sumar la distancia del anteultimo punto (ultimo almacenado en puntoaux) y el ultimo, y finalmente la distancia entre el ultimo y el primer punto.

    return resultado;
    
}


bool IsIgual (const Poligono& pol1, const Poligono &pol2){
   bool puntos = true;
   Nodo* aux1 {pol1.PrimerPunto};
   Nodo* aux2 {pol2.PrimerPunto};
   
   if (GetCantidadDeLados(pol1) != GetCantidadDeLados (pol2)) return false;

   while (aux1 != NULL){
       puntos = puntos and IsIgualPunto(aux1->p, aux2->p);
       aux1 = aux1->SigNodo;
       aux2 = aux2->SigNodo;
   }
   return puntos and IsIgualColor(pol1.c, pol2.c);


}

void MostrarPoligono(const Poligono& pol){

    std::cout <<"El color del poligono en formato rgb es es: " << GetHtmlrgb(pol.c) << "\n";
    std::cout <<"El poligono posee " << GetCantidadDeLados(pol) << " lados" << "\n";
    std::cout <<"Los puntos del poligono son: " <<"\n";

    Nodo* aux {pol.PrimerPunto};

    while (aux != NULL){
        MostrarPunto(aux->p);
        aux = aux->SigNodo;
    }
    std::cout <<"\n";
}

//Funciones necesarias de punto


double GetDistancia(const Punto& o, const Punto& e){
    Punto v;
    double r;
    v = RestarPuntos(e, o);
    r = sqrt(v.x * v.x + v.y * v.y);
    return r;
}

Punto RestarPuntos(const Punto& m, const Punto& s){
    Punto r;
    r.x = m.x - s.x;
    r.y = m.y - s.y;
    return r;
}

bool IsIgualPunto(const Punto& a, const Punto& b){
    return  a.x == b.x and a.y == b.y; 
}

void MostrarPunto(Punto p){
    std::cout << '(' << p.x << ", " << p.y << ')';
}

//Funciones necesarias de Color

bool IsIgualColor (const Color& c1, const Color& c2){
return c1.r == c2.r and c1.g == c2.g and c1.b == c2.b ;
}

std::string GetHtmlrgb (const Color& c){
    std::string red = std::to_string (c.r);
    std::string green = std::to_string (c.g);
    std::string blue = std::to_string (c.b);

    return "rgb(" + red + "," + green + "," + blue + ")";
}