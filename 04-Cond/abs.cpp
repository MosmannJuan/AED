/* Mosmann, Juan Ignacio 
AED K1051 2020 
Resolución Abs 03/06/2020*/

#include <cassert>

int abs(int);

int main (){
assert (abs(1)==1);
assert (abs(-1)==1);
assert (abs(0)==0);
assert (abs(-745)==745);
}
int abs (int x){

    return x>=0 ? x : -x;
}
