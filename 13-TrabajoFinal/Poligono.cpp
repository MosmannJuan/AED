/* Mosmann, Juan Ignacio
AED 2020
Curso K1051
16/09/2020
Actualización con uso de punteros finalizada 05/11/2020 */

#include "Poligono.h"
#include <iostream>
#include <cmath>



//Definición de funciones

void AddVerticeAlComienzo (Poligono& pol, const Punto& pun){ //Es más rápida ya que no tiene que recorrer todos los puntos
    
    auto n = new Nodo; 
   
    n->p.x = pun.x;
    n->p.y = pun.y;
    n->SigNodo = pol.PrimerPunto;

    pol.PrimerPunto = n;    
    
}

void AddVerticeAlFinal (Poligono& pol, const Punto& pun){
    
    auto n = new Nodo; 
   
    n->p.x = pun.x;
    n->p.y = pun.y;
    n->SigNodo = nullptr;

    if(pol.PrimerPunto == nullptr) pol.PrimerPunto = n;
           
    else{
        auto aux = pol.PrimerPunto;

        while(aux->SigNodo != nullptr) aux = aux->SigNodo;

        aux->SigNodo = n;
    }
    
}

Punto GetVertice (const Poligono& pol, const unsigned& pos){
    Nodo* aux;
    aux = pol.PrimerPunto;
    for(int i = 0; i < pos ; ++i) aux = aux->SigNodo;
    return aux->p ;
}

void SetVertice (Poligono & pol, const unsigned& pos, const Punto& p){
    
    auto aux = pol.PrimerPunto;
    for(unsigned i = 0; i < pos; ++i) aux = aux->SigNodo;
    
    aux->p.x = p.x;
    aux->p.y = p.y;


}

void InsertVertice (Poligono& pol, const unsigned& pos , const Punto& p){
    Nodo  *n = new Nodo;
    n->p.x = p.x;
    n->p.y = p.y;

    if(pos == 0) {
        n->SigNodo = pol.PrimerPunto; //Si quiero ubicarlo en el primer lugar, hago que mi nodo apunte a la dirección que apuntaba el puntero del poligono
        pol.PrimerPunto = n; // Luego hago que el puntero del poligono que inidica el principio de la lista apunte a el nodo nuevo
        }

    else{ 
        Nodo *aux = pol.PrimerPunto;
        for(int i = 1; i < pos ; ++i) aux = aux->SigNodo; //Recorre la lista asignando a aux los distintos punteros hasta alcanzar al que apunta a la posición deseada
        n->SigNodo = aux->SigNodo; //Asigno al nuevo nodo la dirección que corresponde al nodo que se ubicaba en la posición que quiero ocupar
        aux->SigNodo = n; //Asigno al anterior nodo la dirección del nuevo nodo
    }
}

void RemoveLastVertice (Poligono & pol){
    unsigned i = GetCantidadDeLados(pol);
    Nodo* aux = pol.PrimerPunto;
    for (unsigned j = 0; j < i - 2 ; ++j) aux = aux->SigNodo; //Recorre la lista hasta que obtiene en aux la posición del anteultimo nodo
    auto aux2 = aux->SigNodo;
    delete aux2; //Libero en memoria el ultimo nodo 
    aux->SigNodo = nullptr; //Rompe la conexión con el que era el ultimo nodo
}


unsigned GetCantidadDeLados (const Poligono& pol){
    unsigned lados = 0;
    Nodo* aux = pol.PrimerPunto;

    while (aux != nullptr) {
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

while (aux->SigNodo != nullptr){
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

   while (aux1 != nullptr){
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

    

    for (auto aux {pol.PrimerPunto}; aux;aux =  aux->SigNodo) MostrarPunto(aux->p);
    
    std::cout <<"\n";
}

void RemoveFirst(Poligono& pol){
    auto aux = pol.PrimerPunto;
    pol.PrimerPunto = pol.PrimerPunto->SigNodo;
    delete aux;
}

void LiberarMemoriaHeap(Poligono& pol){ //???
  while (pol.PrimerPunto != nullptr) RemoveFirst(pol); 
} 

bool IsEmptyPuntos (const Poligono& pol){
    return pol.PrimerPunto == nullptr;
}