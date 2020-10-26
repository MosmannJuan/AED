/* Mosmann, Juan Ignacio
AED 2020
Declaración de estructuras y funciones
Leer poligonos desde un archivo */

#pragma once
#include <array>
#include <cstdint>
#include <string>
#include <iostream>

struct Punto{double x,y;};

struct Color {uint8_t r, g, b ;}; 

struct Poligono {
    unsigned n;
    std::array <Punto, 20> puntos;
    Color c;};

void MostrarPunto(Punto); //Muestra por la salida estándar un punto con el formato (x,y)

std::string GetHtmlrgb (Color); //Se usa para mostrar el color

bool ExtraerPunto(std::istream&, Punto&); //Lee de un flujo de entrada las coordenadas x e y de un punto

bool ExtraerPuntos(std::istream&, Poligono&); //Repite la accion de ExtraerPunto para poder extraer varios puntos juntos

bool ExtraerColor(std::istream&, Color&); //Extrae los valores correspondientes a r, g y b de un color

void AddVertice (Poligono&, const Punto&); //Agrega al final del array de puntos del poligono el punto ingresado en el argumento

bool ExtraerPoligono(std::istream&, Poligono&); //Extrae un color y una serie de puntos de un flujo de entrada y las almacena en un poligono

bool ExtraerPoligonos(std::istream&); //Extrae todos los poligonos que puede extraer de un flujo de entrada y los muestra por pantalla.

void MostrarPoligono(const Poligono&); //Muestra por pantalla un poligono.

bool EnviarPunto(std::ostream&, Punto); //Envia las coordenadas de un punto por un flujo de salida 

bool EnviarColor(std::ostream&, Color); //Envia las componentes de un color por un flujo de salida

bool EnviarPoligono(std::ostream&, const Poligono&); //Envia un color y una serie de puntos correspondientes a un poligono por un flujo de salida

bool ExtraerSeparador (std::istream& in ); //Limpia el flujo de entrada y extrae el caracter '#' utilizado para separar los poligonos

double GetPerimetro (const Poligono&); //Retorna un double correspondiente al perímetro del polígono ingresado

double GetDistancia(Punto,  Punto); //Retorna el valor de la distancia entre dos puntos

Punto RestarPuntos(Punto , Punto); //Retorna el punto resultado de restar ambos

bool IOPoligonoCondicionado (std::istream&, std::ostream&, double);