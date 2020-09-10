/*Mosmann, Juan Ignacio
AED 2020
Curso K1051
05/09/2020*/

#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdint>

struct Color {uint8_t r, g, b ;};


//Prototipo de funciones

Color Mezclar(const Color&, const Color&); //Retorna un color correspondiente a la mezcla de dos colores en partes iguales (promedio)

Color MezclarConPartes (const unsigned& , const Color& , const unsigned& , const Color& ); //Retorna un color correspondiente a la mezcla permitiendo mezclar en partes desiguales, cada color es precedido por la cantidad de partes correspondientes

Color SumarColores (const Color& , const Color&); //Retorna un Color correspondiente a la suma de cada parte de dos colores

Color RestarColores (const Color& , const Color&); //Retorna un Color correspondiente a la resta de cada parte de dos colores

Color GetComplementario (const Color&); //Retorna el color complementario al ingresado en el argumento

std::string GetHtmlHex (const Color&); //Retorna una cadena correspondiente al color en hexadecimal siguiendo la siguiente forma "#rgb"

std::string GetHtmlrgb (const Color&); //Retorna una cadena correspondiente al color en formato "rgb(r,g,b)"

bool IsIgual (const Color&, const Color&); //Compara dos colores y retorna un booleano true si son iguales o false si no lo son

//Declaración de las constantes

const Color rojo {255, 0, 0};

const Color verde {0, 255, 0};

const Color azul {0, 0, 255};

const Color cyan {0, 255, 255};

const Color magenta {255, 0, 255};

const Color amarillo {255, 255, 0};

const Color blanco = SumarColores(SumarColores(rojo, verde), azul);

const Color negro = RestarColores(RestarColores(RestarColores (blanco, rojo), verde), azul);

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


}

//Definición de funciones

Color Mezclar(const Color& a, const Color& b){
    Color res;

    res.r = (a.r + b.r) / 2 ;
    res.g = (a.g + b.g) / 2 ;
    res.b = (a.b + b.b) / 2 ;

return res;
}

Color MezclarConPartes (const unsigned& n, const Color& a, const unsigned& m, const Color& b){
    Color res;

    res.r = (a.r * n + b.r * m) / (n+m) ;
    res.g = (a.g * n + b.g * m) / (n+m) ;
    res.b = (a.b * n + b.b * m) / (n+m) ;

    return res;
}

Color SumarColores (const Color& a, const Color& b){
    Color res;

    res.r = (a.r + b.r > 255) ? 255 : a.r + b.r ;
    res.g = (a.g + b.g > 255) ? 255 : a.g + b.g ;
    res.b = (a.b + b.b > 255) ? 255 : a.b + b.b ;

    return res;
}

Color RestarColores (const Color& a, const Color& b){
    Color res;

    res.r = (a.r - b.r < 0) ? 0 : a.r - b.r ;
    res.g = (a.g - b.g < 0) ? 0 : a.g - b.g ;
    res.b = (a.b - b.b < 0) ? 0 : a.b - b.b ;

    return res;
}

Color GetComplementario (const Color& a){
    Color comp;

    comp.r = blanco.r - a.r ;
    comp.g = blanco.g - a.g ;
    comp.b = blanco.b - a.b ;

    return comp;
}

std::string GetHtmlHex (const Color& c){
char resultado [7];

sprintf(resultado, "#%02X%02X%02X", c.r, c.g, c.b);

return resultado;
}

std::string GetHtmlrgb (const Color& c){
    std::string red = std::to_string (c.r);
    std::string green = std::to_string (c.g);
    std::string blue = std::to_string (c.b);

    return "rgb(" + red + "," + green + "," + blue + ")";
}

bool IsIgual (const Color& c1, const Color& c2){
return c1.r == c2.r and c1.g == c2.g and c1.b == c2.b ;
}