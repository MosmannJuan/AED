/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
05/09/2020*/


#include <iostream>
#include <cmath> /*Para poder utilizar calculos como raiz cuadrada(sqrt) o el arcotangente(atan)*/
#include <cassert>
#define PI 3.14159265 /*Asigno un valor para PI que usaremos para pasar a coordenadas polares con el angulo en grados*/

struct Punto{double x,y;};

enum struct CuadrantesyEjes {Cuadrante_I, Cuadrante_II, Cuadrante_III, Cuadrante_IV, Eje_X, Eje_Y, Origen_de_Coordenadas};

//Prototipo de funciones

Punto SumarPuntos(const Punto&, const Punto&); /*Toma dos puntos y devuelve su suma*/

Punto leerpunto(); /*Pide las coordenadas de un punto por la entrada estándar y retorna el punto*/

void MostrarPunto(const Punto&); /*Muestra por la salida estándar un punto con el formato (x,y)*/

Punto ProductoPorEscalar(const double&, const Punto&); /*Multiplica las coordenadas de un punto por un valor escalar*/

CuadrantesyEjes GetCuadrante(const Punto&); /*Retorna el cuadrante al que pertenece el punto ingresado, en caso de no pertenecer a ningun cuadrante retorna el eje al que pertenece, o bien, indica que se trata del origen de coordenadas*/

Punto RestarPuntos(const Punto&, const Punto&); /*Retorna el punto resultado de la resta de los dos ingresados considerando RestarPuntos(minuendo, sustraendo)*/

double GetDistancia(const Punto&, const Punto&); /*Retorna el valor de la distancia entre dos puntos*/

double GetDistanciaAlOrigen (const Punto&); /*Retorna el valor de la distancia desde al punto al origen de coordenadas*/

Punto CoordenadasPolares(const Punto&); /*Retorna el punto expresado en sus coordenadas polares siguiendo la siguiente forma: {módulo, ángulo en grados}*/

double ProductoEscalar(const Punto&, const Punto&);/*Considerando a los puntos como extremos de vectores en el origen, retorna el valor de su producto escalar*/

void MoverPunto (Punto&, const Punto&); //Modifica las coordenadas del primer punto por las del segundo ingresado simulando asi moverlo

bool IsIgual (const Punto&, const Punto&); //Compara 2 puntos y retorna un booleano true si son iguales y false si no lo son, en las pruebas se prueba primero para luego usarlo para comprar en los demas asserts

int main() {
    
    //Pruebas IsIgual
    assert (IsIgual({2,3},{2,3}));
    assert (not IsIgual({-3,2},{4,2}));

   //Pruebas SumarPuntos comparando por coordenadas
   assert(SumarPuntos({2,3}, {3,7}).x == 5.0 and SumarPuntos({2,3}, {3,7}).y == 10);
   assert(not (SumarPuntos({6,4}, {9,-2}).x == 0 and SumarPuntos({6,4}, {9,-2}).y == 78));
   
   //Pruebas ProductoPorEscalar comparando con IsIgual
   assert (IsIgual(ProductoPorEscalar (2.5, {2,-4}), {5, -10}));
   assert (not IsIgual(ProductoPorEscalar (-1, {3,2}),{-3, 5}));
   
   //Pruebas GetCuadrante
   assert (GetCuadrante ({1,1}) == CuadrantesyEjes::Cuadrante_I);
   assert (GetCuadrante ({-1,1}) == CuadrantesyEjes::Cuadrante_II);
   assert (GetCuadrante ({-1,-1}) == CuadrantesyEjes::Cuadrante_III);
   assert (GetCuadrante ({1,-1}) == CuadrantesyEjes::Cuadrante_IV);
   assert (GetCuadrante ({1,0}) == CuadrantesyEjes::Eje_X);
   assert (GetCuadrante ({0,-1}) == CuadrantesyEjes::Eje_Y);
   assert (GetCuadrante ({0,0}) == CuadrantesyEjes::Origen_de_Coordenadas);
   assert (not (GetCuadrante ({1,8}) == CuadrantesyEjes::Eje_X));
   assert (not (GetCuadrante ({4,-1}) == CuadrantesyEjes::Cuadrante_III));

   //Pruebas RestarPuntos usando IsIgual
   assert (IsIgual(RestarPuntos ({0,4},{2,-3}),{-2, 7}));
   assert (not IsIgual (RestarPuntos ({-1, 3}, {8,2}), {15,7}));

   //Pruebas GetDistancia
   assert (GetDistancia ({0,1}, {3,5}) == 5);
   assert (not (GetDistancia ({4,2}, {9,3}) == 2));

   //Pruebas GetDistanciaAlOrigen
   assert (GetDistanciaAlOrigen ({9, -12}) == 15 );
   assert (not (GetDistanciaAlOrigen ({-4, -2}) == 1));

   //Pruebas CoordenadasPolares comparo por coordenadas ya que no puedo establecer una tolerancia al comparar reales usando IsIgual
   assert (CoordenadasPolares({1,1}).x > 1.4 and CoordenadasPolares({1,1}).x < 1.42  and CoordenadasPolares({1,1}).y > 44.99 and CoordenadasPolares({1,1}).y < 45.01); //Se establece una tolerancia de 0.01
   assert (CoordenadasPolares({-1,1}).x > 1.4 and CoordenadasPolares({-1,1}).x < 1.42  and CoordenadasPolares({-1,1}).y > 134.99 and CoordenadasPolares({-1,1}).y < 135.01);
   assert (CoordenadasPolares({-1,-1}).x > 1.4 and CoordenadasPolares({-1,-1}).x < 1.42  and CoordenadasPolares({-1,-1}).y > 224.99 and CoordenadasPolares({-1,-1}).y < 225.01);
   assert (CoordenadasPolares({1,-1}).x > 1.4 and CoordenadasPolares({1,-1}).x < 1.42  and CoordenadasPolares({1,-1}).y > 314.99 and CoordenadasPolares({1,-1}).y < 315.01);
   assert (IsIgual (CoordenadasPolares({1,0}), {1, 0}));
   assert (IsIgual (CoordenadasPolares({0,1}), {1,90}));
   assert (IsIgual (CoordenadasPolares({-1,0}), {1, 180}));
   assert (IsIgual (CoordenadasPolares({0,-1}), {1, 270}));
   assert (not IsIgual(CoordenadasPolares({3,4}), {9,27}));

   //Pruebas para ProductoEscalar
   assert (ProductoEscalar({1,2},{3,4}) == 11);
   assert (not (ProductoEscalar ({15,-2},{2,1}) == -1234));

   //Pruebas para MoverPunto
   Punto prueba {3,2};
   MoverPunto (prueba, {-2,3});
   assert (IsIgual({-2,3}, prueba));
   assert (not IsIgual (prueba, {3,2}));
}
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