/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
08/09/2020*/

#include <array>
#include <iostream>
#include <cassert>
#include <cstdint>
#include <cmath>

struct Punto{double x,y;};

struct Color {uint8_t r, g, b ;};

struct Poligono {
    unsigned n;
    std::array <Punto, 20> puntos;
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

//Funciones necesarias de Punto
double GetDistancia(const Punto&, const Punto&); //Necesaria para la función de calculo de perimetro de poligonos

bool IsIgualPunto (const Punto&, const Punto&); //Necesaria para la función de comparación de polígonos

Punto RestarPuntos(const Punto& , const Punto&); //Necesaria para la función GetDistancia

//Funciones necesarias de Color
bool IsIgualColor (const Color&, const Color&); //Necesaria para la función de comparación de polígonos

int main(){
Poligono pol1 {
    4,
   {0,0 , 1,0 , 1,1 , 0,1},
    rojo};

Poligono pol2{
    4,
    {0,0 , 1,0 , 0,2 , 1,1},
    verde};

Poligono pol3{
    5,
    {0,0 , 1,0 , 0,2 , 1,1 , 3,4},
    verde};

//Pruebas IsIgual (comparacion de poligonos)

assert (not IsIgual(pol1, pol2));
assert (IsIgual (pol1, pol1));

//pruebas GetPerimetro

assert (4 == GetPerimetro(pol1));
assert (not (GetPerimetro(pol1) == 5.14));

//Pruebas AddVertice
AddVertice (pol2, {3,4}); //Agrega en la ultima posicion de pol2 el punto {3,4} dejandolo igual a pol3

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