/* Mosmann, Juan Ignacio 
Legajo N° 158.964-7
AED K1051 
08/06/2020
*/

#include <cassert>

bool IsBisiesto(unsigned);

int main() {
    assert(not IsBisiesto(2018));
    assert(not IsBisiesto(2019));
    assert(IsBisiesto(2020)); //Para porbar un año divisible por 4 y no por 100, posterior a 1582. También se evalúa su entorno.
    assert(not IsBisiesto(2021));
    assert(not IsBisiesto(2022));
    assert(not IsBisiesto(1999));
    assert(IsBisiesto(2000)); //Para probar un año divisible por 100 y por 400, también se evalúa su entorno.
    assert(not IsBisiesto(2001));
    assert(not IsBisiesto(1200)); //Para probar un año anterior a 1582, que cumpla con las demás condiciones.
    assert(not IsBisiesto(1900)); //Para probar un año divisible por 100.
    assert(IsBisiesto(3516)); 
    assert(not IsBisiesto(12493));
}

bool IsBisiesto(unsigned anio){
return anio >= 1582 and anio % 4 == 0 and (anio % 100 != 0 or anio % 400 == 0); //Se pide que cumpla las siguientes condiciones: que sea mayor o igual a 1582, que sea divisible por 4 y que, a la vez, o no sea divisible por 100 o sea divisible por 400.
}
