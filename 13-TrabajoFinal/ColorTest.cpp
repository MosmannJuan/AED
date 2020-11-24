/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
Color Pruebas
15/09/2020*/

#include "color.h"
#include <cassert>

int main(){

    //Pruebas IsIgual
    assert (IsIgualColor(blanco, blanco));
    assert (not IsIgualColor (blanco, cyan));
    assert (not IsIgualColor(rojo, {250, 0, 0}));
    assert (IsIgualColor (rojo, {255, 0, 0}));

    //Pruebas Mezclar
    assert (IsIgualColor (Mezclar (rojo, azul), {127, 0, 127}));
    assert (not IsIgualColor (Mezclar (rojo, azul), blanco));

    //Pruebas MezclarConPartes
    assert (IsIgualColor (MezclarConPartes (2, rojo, 4, azul), {85, 0, 170}));
    assert (not IsIgualColor (MezclarConPartes (5, verde, 3, rojo), negro));

    //Pruebas SumarColores

    assert (IsIgualColor (SumarColores (rojo, verde), amarillo));
    assert (not IsIgualColor (SumarColores (rojo, verde), cyan));
    assert (IsIgualColor (SumarColores(rojo, rojo), rojo));

    //Pruebas RestarColores

    assert (IsIgualColor (RestarColores (rojo, verde), rojo));
    assert (IsIgualColor (RestarColores (blanco, rojo), cyan));
    assert (not IsIgualColor (RestarColores (rojo, verde), amarillo));

    //Pruebas GetComplementario

    assert (IsIgualColor (GetComplementario (rojo), cyan));
    assert (not IsIgualColor (GetComplementario (verde), rojo));

    //Pruebas GetHtmlHex

    assert ("#FF0000" == GetHtmlHex(rojo));
    assert ("#FFFFFF" == GetHtmlHex(blanco));
    assert (not ("#FF00FF" == GetHtmlHex(negro)));

    //Pruebas GetHtmlrgb

    assert ("rgb(255,0,0)" == GetHtmlrgb(rojo));
    assert ("rgb(255,255,255)" == GetHtmlrgb(blanco));
    assert (not ("rgb(255,0,255)" == GetHtmlrgb(verde)));

    //Prueba CrearSvgConTextoEscritoEnAltoContraste

    CrearSvgConTextoEscritoEnAltoContraste("Prueba.svg", "Hola, Mundo!", blanco);
    CrearSvgConTextoEscritoEnAltoContraste("Prueba 2.svg", "AED 2020 K1052", verde);


}