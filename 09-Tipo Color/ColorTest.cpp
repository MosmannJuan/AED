/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
Color Pruebas
15/09/2020*/

#include "color.h"
#include <cassert>

int main(){

    //Pruebas IsIgual
    assert (IsIgual(blanco, blanco));
    assert (not IsIgual (blanco, cyan));
    assert (not IsIgual(rojo, {250, 0, 0}));
    assert (IsIgual (rojo, {255, 0, 0}));

    //Pruebas Mezclar
    assert (IsIgual (Mezclar (rojo, azul), {127, 0, 127}));
    assert (not IsIgual (Mezclar (rojo, azul), blanco));

    //Pruebas MezclarConPartes
    assert (IsIgual (MezclarConPartes (2, rojo, 4, azul), {85, 0, 170}));
    assert (not IsIgual (MezclarConPartes (5, verde, 3, rojo), negro));

    //Pruebas SumarColores

    assert (IsIgual (SumarColores (rojo, verde), amarillo));
    assert (not IsIgual (SumarColores (rojo, verde), cyan));
    assert (IsIgual (SumarColores(rojo, rojo), rojo));

    //Pruebas RestarColores

    assert (IsIgual (RestarColores (rojo, verde), rojo));
    assert (IsIgual (RestarColores (blanco, rojo), cyan));
    assert (not IsIgual (RestarColores (rojo, verde), amarillo));

    //Pruebas GetComplementario

    assert (IsIgual (GetComplementario (rojo), cyan));
    assert (not IsIgual (GetComplementario (verde), rojo));

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