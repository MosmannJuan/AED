/*Juan Ignacio Mosmann
AED 2020
27/06/2020*/

#include <cassert>

unsigned div (unsigned,unsigned);

int main() {
assert (div(14,2) == 7);
assert (div(10000,2) == 5000);
assert (div(100000,2) == 50000);
// assert (div(1000000,2) == 500000); a partir de este valor el programa no puede ejecutarse (esto solo pasa cuando se abre haciendo click en el ejecutable)
}

unsigned div (unsigned dividendo, unsigned divisor) {
 return dividendo >= divisor ?   1 + div(dividendo - divisor, divisor) : 
                                 0 ;
 
}
