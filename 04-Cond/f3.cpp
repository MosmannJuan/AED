/* Mosmann, Juan Ignacio 
AED K1051 2020 
Resolución f3 03/06/2020*/

#include <cassert> //Para usar los assert para las pruebas

double f3(double); //Defino la función

int main(){ //Para las pruebas de la función
    assert (f3(-3.0)== 3.0);
    assert (f3(3.0)== -3.0);
    assert (f3(5.0)== 5.0);
    assert (f3(-5.0)== -5.0);
    assert (f3(2.5)== -2.5);
    assert (f3(-7.3)== -7.3);

}

double f3(double x){
    return (-3 <= x and x <= 3) ? -x : x; //Retorno de la función (al al escribir la condicion así: -3<=x<=3 daba errores)
}
