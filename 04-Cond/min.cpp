/* Mosmann, Juan Ignacio 
AED K1051 2020 
Resolución Min 03/06/2020*/

#include <cassert> // Para las pruebas

int min(int,int); //Definición de la función

int main(){ //Pruebas del correcto funcionamiento de la función
assert (min (2,3)== 2);
assert (min(3,12)== 3);
assert (min (5,-2)== -2);
assert (min(0,123)== 0);
}

int min(int a, int b){

    return a < b ? a : b ; //Retorno de la función 
}
