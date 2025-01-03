
#include <iostream>
#include <iomanip>
using namespace std; 

void triangulo(int a, int b) {
    int i;
    
    if(a>b) return;
    for(i = 0; i<a; i++) cout<<" * ";//***  
    cout<<endl;
    triangulo(a+1, b);
    for(i = 0; i<a; i++) cout<<" * ";
    cout<<endl;
}

int main(int argc, char** argv) {

    triangulo(3, 5);
    
    return 0;
}
