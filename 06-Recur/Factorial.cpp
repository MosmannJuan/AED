/*Juan Ignacio Mosmann
AED 2020
28/06/2020*/

#include <cassert>

double fact(unsigned);

int main(){
    assert (fact(1) == 1);
    assert (fact(0) == 1);
    assert (fact(10) == 3628800);

}

double fact(unsigned n){
    return n == 0 ? 1 :
    n * fact(n-1); 
}