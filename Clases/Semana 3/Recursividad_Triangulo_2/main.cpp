#include <iostream>
#include <iomanip>
using namespace std; 


void imprime(int ini, int fin) {
    
    if(ini>=fin) return;
    
    cout<<" * ";
    imprime(ini+1, fin);    
}

void triangulo(int a, int b) {
    int i;
    
    if(a>b) return;
    imprime(0, a);
    cout<<endl;
    triangulo(a+1, b);
    imprime(0, a);
    cout<<endl;
}

int main(int argc, char** argv) {

    triangulo(3, 5);
    
    return 0;
}
