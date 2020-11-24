/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
16/09/2020
Actualización con uso de punteros finalizada 05/11/2020 */

#pragma once
#include <array>
#include <cstdint>
#include <cstring>
#include "Punto.h"
#include "Color.h"

//Declaración del Nodo

struct Nodo{
    Punto p;
    Nodo* SigNodo;
};


struct Poligono {
    Nodo* PrimerPunto = nullptr;
    Color c;
};



// Funciones de Polígono

void AddVerticeAlComienzo(Poligono&, const Punto&); //Agrega al inicio de la lista de puntos del poligono, el punto ingresado en el argumento 

void AddVerticeAlFinal (Poligono&, const Punto&); //Agrega al final de la lista de puntos del poligono, el punto ingresado en el argumento

Punto GetVertice (const Poligono&, const unsigned&); //Retorna el valor del Punto del poligono ubicado en la posicion indicada 

void SetVertice (Poligono &, const unsigned& , const Punto&);//Modifica el valor del punto en la posición indicada por el ingresado

void InsertVertice (Poligono &, const unsigned& , const Punto&); //Setea el valor del punto ingresado en la posicion indicada, desplazando hacia la derecha los demás puntos

void RemoveLastVertice (Poligono &); //Quita el punto en la ultima posición del polígono ingresado como argumento

unsigned GetCantidadDeLados (const Poligono&); //Retorna la cantidad de lados que posee el polígono ingresado (coincide con la cantidad de vertices)

double GetPerimetro (const Poligono&); //Retorna un double correspondiente al perímetro del polígono ingresado

bool IsIgual (const Poligono&, const Poligono&); //Retorna un booleano true si los dos polígonos ingresados son iguales o false si no lo son

void MostrarPoligono (const Poligono&); //Muestra por pantalla el Poligono pasado como argumento

void RemoveFirst(Poligono&); //Remueve el primer punto del poligono liberando la reserva de memoria heap

void LiberarMemoriaHeap(Poligono&); //Remueve todos los puntos del poligono liberando la reserva de memoria heap

bool IsEmptyPuntos (const Poligono&); //Retorna true si el Poligono no posee puntos (PrimerPunto == nullptr) y false e.o.c
