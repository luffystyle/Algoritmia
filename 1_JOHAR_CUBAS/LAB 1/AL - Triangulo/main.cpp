/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

void triangulo(int a,int b){
    
    if(a>b) return;
    
    for(int i=0;i<a;i++) cout <<" * ";
    cout << endl;
    triangulo(a+1,b);
    for(int i=0;i<a;i++) cout <<" * ";
    cout << endl;    
}




int main(int argc, char** argv) {

    triangulo(3,5);



    return 0;
}

