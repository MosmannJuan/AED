/*Juan Ignacio Mosmann
AED 2020
28/06/2020*/

#include <cassert>

int mcd(int, int);

int main(){
   assert (mcd(270,192) == 6);
   assert (mcd(720, 224) == 16);
   assert (mcd(15000000,983) == 1);
   assert (mcd(15000000,12457896) == 24);
   assert (mcd(15000000,11111111) == 1);
   assert (mcd(15234578,77) == 1);
   assert (mcd(152345789,777) == 1);
}

int mcd(int x, int y){ //Para aplicar el cálculo del mcd de forma recursiva se utilizó el Algoritmo de Euclides 

    return y == 0? x :
    mcd (y, x % y);
}