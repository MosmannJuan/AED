/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
16/09/2020*/

#pragma once
#include <array>
#include <cstdint>
#include <cstring>

struct Punto{double x,y;};

struct Color {uint8_t r, g, b ;};

struct Nodo{
    Punto p;
    Nodo* SigNodo;
};

struct Poligono {
    Nodo* PrimerPunto;
    Color c;};

//Declaración de colores

const Color rojo {255, 0, 0};

const Color verde {0, 255, 0};

const Color azul {0, 0, 255};

const Color cyan {0, 255, 255};

const Color magenta {255, 0, 255};

const Color amarillo {255, 255, 0};

const Color blanco = {255, 255, 255};

const Color negro = {0, 0, 0};

// Funciones de Polígono

void AddVertice (Poligono&, const Punto&); //Agrega al final del array de puntos del poligono el punto ingresado en el argumento

Punto GetVertice (const Poligono&, const unsigned&); //Retorna el valor del Punto del poligono ubicado en la posicion indicada 

void SetVertice (Poligono &, const unsigned& , const Punto&); //Setea el valor del punto ingresado en la posicion indicada 

void RemoveVertice (Poligono &); //Quita el punto en la ultima posición del polígono ingresado como argumento

unsigned GetCantidadDeLados (const Poligono&); //Retorna la cantidad de lados que posee el polígono ingresado (coincide con la cantidad de vertices)

double GetPerimetro (const Poligono&); //Retorna un double correspondiente al perímetro del polígono ingresado

bool IsIgual (const Poligono&, const Poligono&); //Retorna un booleano true si los dos polígonos ingresados son iguales o false si no lo son

void MostrarPoligono(const Poligono&);

//Funciones necesarias de Punto
double GetDistancia(const Punto&, const Punto&); //Necesaria para la función de calculo de perimetro de poligonos

bool IsIgualPunto (const Punto&, const Punto&); //Necesaria para la función de comparación de polígonos

Punto RestarPuntos(const Punto& , const Punto&); //Necesaria para la función GetDistancia

void MostrarPunto (Punto);

//Funciones necesarias de Color
bool IsIgualColor (const Color&, const Color&); //Necesaria para la función de comparación de polígonos

std::string GetHtmlrgb (const Color&); //Retorna una cadena correspondiente al color en formato "rgb(r,g,b)"

