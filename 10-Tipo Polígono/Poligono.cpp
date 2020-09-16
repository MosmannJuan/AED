/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
16/09/2020*/

#include "Poligono.h"
#include <iostream>
#include <cmath>

//Definición de funciones

void AddVertice (Poligono& pol, const Punto& pun){
    pol.puntos.at( pol.n ).x = pun.x;
    pol.puntos.at( pol.n ).y = pun.y;
    pol.n ++;
}

Punto GetVertice (const Poligono& pol, const unsigned& pos){
return pol.puntos.at(pos);
}

void SetVertice (Poligono& pol, const unsigned& pos , const Punto& p){
if (pos < pol.n)
 pol.puntos.at( pos ).x = p.x ,
 pol.puntos.at( pos ).y = p.y ;
 else
 std::cout << "Necesita agregar mas puntos al poligono (Use AddVertice)";
}

void RemoveVertice (Poligono & pol){
    pol.n --;
}

unsigned GetCantidadDeLados (const Poligono& pol){
    return pol.n;
}

double GetPerimetro (const Poligono& pol){
double resultado = 0;
for (int i = pol.n - 1; i > 0 ; i--){
    resultado = resultado + GetDistancia(pol.puntos.at(i), pol.puntos.at(i-1));
}
return resultado + GetDistancia(pol.puntos.at(pol.n-1), pol.puntos.at(0));
}

bool IsIgual (const Poligono& pol1, const Poligono &pol2){
    bool puntos = true;
    
    for (int i = pol1.n - 1; i >= 0 ; i--)
    puntos = puntos and IsIgualPunto(pol1.puntos.at(i), pol2.puntos.at(i));
    
    return pol1.n == pol2.n and puntos and IsIgualColor(pol1.c, pol2.c);

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
    return  a.x == b.x and a.y == b.y; }

//Funciones necesarias de Color

bool IsIgualColor (const Color& c1, const Color& c2){
return c1.r == c2.r and c1.g == c2.g and c1.b == c2.b ;
}