// TRIANGULO 
#include <iostream>
#include <cmath>
using namespace std;

void triangulo( int a, int b) {
    
    if( a>b ) return;
    
    for( int i = 0; i < a; i++) cout <<"* ";//***
    cout << endl;
    
    triangulo(a+1, b);
    
    for( int i = 0; i < a; i++) cout << "* ";
    cout << endl;   
}

int main(int argc, char** argv) {

    int a = 3, b = 5;
    triangulo(3, 5);

    return 0;
}

