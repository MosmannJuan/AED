/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
16/09/2020*/

#include "Punto.h"
#include <cassert>

int main() {
    
    //Pruebas IsIgual
    assert (IsIgualPunto({2,3},{2,3}));
    assert (not IsIgualPunto({-3,2},{4,2}));

   //Pruebas SumarPuntos comparando por coordenadas
   assert(SumarPuntos({2,3}, {3,7}).x == 5.0 and SumarPuntos({2,3}, {3,7}).y == 10);
   assert(not (SumarPuntos({6,4}, {9,-2}).x == 0 and SumarPuntos({6,4}, {9,-2}).y == 78));
   
   //Pruebas ProductoPorEscalar comparando con IsIgual
   assert (IsIgualPunto(ProductoPorEscalar (2.5, {2,-4}), {5, -10}));
   assert (not IsIgualPunto(ProductoPorEscalar (-1, {3,2}),{-3, 5}));
   
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
   assert (IsIgualPunto(RestarPuntos ({0,4},{2,-3}),{-2, 7}));
   assert (not IsIgualPunto (RestarPuntos ({-1, 3}, {8,2}), {15,7}));

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
   assert (IsIgualPunto (CoordenadasPolares({1,0}), {1, 0}));
   assert (IsIgualPunto (CoordenadasPolares({0,1}), {1,90}));
   assert (IsIgualPunto (CoordenadasPolares({-1,0}), {1, 180}));
   assert (IsIgualPunto (CoordenadasPolares({0,-1}), {1, 270}));
   assert (not IsIgualPunto(CoordenadasPolares({3,4}), {9,27}));

   //Pruebas para ProductoEscalar
   assert (ProductoEscalar({1,2},{3,4}) == 11);
   assert (not (ProductoEscalar ({15,-2},{2,1}) == -1234));

   //Pruebas para MoverPunto
   Punto prueba {3,2};
   MoverPunto (prueba, {-2,3});
   assert (IsIgualPunto({-2,3}, prueba));
   assert (not IsIgualPunto (prueba, {3,2}));
}