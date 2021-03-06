/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
16/09/2020*/

#include "Punto.h"
#include <cmath> /*Para poder utilizar calculos como raiz cuadrada(sqrt) o el arcotangente(atan)*/
#include <iostream>
#define PI 3.14159265 /*Asigno un valor para PI que usaremos para pasar a coordenadas polares con el angulo en grados*/

/*Funciones de Punto*/

Punto SumarPuntos (const Punto& a, const Punto& b){
    Punto r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

Punto leerpunto(){
    Punto a;
    std::cout << "Ingrese el valor de la coordenada  x: ";
    std::cin >> a.x;
    std::cout <<"\n" <<"Ingrese el valor de la coordenada y: ";
    std::cin >> a.y;
return {a.x,a.y};
}

void MostrarPunto(const Punto& p){
std::cout <<"(" <<p.x <<";" <<p.y <<")" <<"\n";
}

Punto ProductoPorEscalar(const double& x, const Punto& p){
    Punto r;
    r.x = x * p.x;
    r.y = x * p.y;
    return r;
}

CuadrantesyEjes GetCuadrante(const Punto& p){
    if (p.x > 0 and p.y > 0) return CuadrantesyEjes::Cuadrante_I;
     if (p.x < 0 and p.y > 0) return CuadrantesyEjes::Cuadrante_II;
         if (p.x < 0 and p.y < 0) return CuadrantesyEjes::Cuadrante_III;
             if (p.x > 0 and p.y < 0) return CuadrantesyEjes::Cuadrante_IV;
                 if (p.x == 0 and p.y != 0) return CuadrantesyEjes::Eje_Y;
                      if (p.x != 0 and p.y == 0) return CuadrantesyEjes::Eje_X;
                         else return CuadrantesyEjes::Origen_de_Coordenadas;

}

Punto RestarPuntos(const Punto& m, const Punto& s){
    Punto r;
    r.x = m.x - s.x;
    r.y = m.y - s.y;
    return r;
}

double GetDistancia(const Punto& o, const Punto& e){
    Punto v;
    double r;
    v = RestarPuntos(e, o);
    r = sqrt(v.x * v.x + v.y * v.y);
    return r;
}

double GetDistanciaAlOrigen(const Punto& p){
    double r;
    r = sqrt(p.x * p.x + p.y * p.y);
    return r;
}

Punto CoordenadasPolares(const Punto& p){
    Punto a;
    double angulo;
    double modulo;
    double r;
    
    
    modulo = GetDistanciaAlOrigen(p);
    r = atan(p.y/p.x) * 180/PI;

    if (p.x > 0 and p.y > 0) {angulo = r;}
    if ((p.x < 0 and p.y > 0) or (p.x < 0 and p.y < 0) ) {angulo = r + 180;}
    if (p.x > 0 and p.y < 0) {angulo = r + 360;}
    if (p.x >= 0 and p.y == 0 ) {angulo = 0;}
    if (p.x < 0 and p.y == 0) {angulo = 180;}
    if (p.x == 0 and p.y > 0) {angulo = 90;}
    if (p.x == 0 and p.y < 0) {angulo = 270;}
a.x = modulo;
a.y = angulo;
return a;

}

double ProductoEscalar(const Punto& p, const Punto& q){return p.x*q.x + p.y*q.y;}

void MoverPunto (Punto& a, const Punto& b){
    a.x = b.x;
    a.y = b.y;
}

bool IsIgual(const Punto& a, const Punto& b){
    return  a.x == b.x and a.y == b.y; }