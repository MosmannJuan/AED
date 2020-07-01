/*Juan Ignacio Mosmann
AED 2020
28/06/2020*/

#include <cassert>

unsigned fib(unsigned);

int main(){
    assert (fib(5) == 5);
    assert (fib(14) == 377);
    assert (fib(20) == 6765);
    //assert (fib(10000) > 100000); comienza a tardar mucho tiempo en ejecutar

}

unsigned fib(unsigned n){
    return n < 2 ? n :
    fib(n-1) + fib(n-2);
}