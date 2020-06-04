/*Mosmann, Juan Ignacio
AED K1051 2020
Resolución Celsius.cpp 
03/06/2020*/

#include <cassert> //Para poder realizar las pruebas con assert
#include <cmath> //Incluye la libreria cmath que permite calcular valor absoluto a representaciones con punto flotante

double celsius(double); 
bool AreNear(double,double,double); //Definición de las funciones

int main(){ //Utilizado para las pruebas
assert (AreNear (celsius(42.0), 5.556, 0.001) == true);
assert (AreNear (celsius (35.6),2, 0.001) == true);
}
double celsius(double f){
    double c;
    return  c = (5.0/9.0) * (f-32.0); // Función que devuelve el valor de la temperatura en celsius
}

bool AreNear (double c, double x, double tol = 0.001){ 
return abs(c-x) <= tol ? true : false;
/*Para comprobar que el valor respete la tolerancia se calcula el valor absoluto de la diferencia entre
el valor obtenido en la función celsius y el valor real obtenido por el calculo y se verifica que sea
menor o igual a la tolerancia */
}
