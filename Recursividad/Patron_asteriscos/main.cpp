#include <iostream>
using namespace std;

void patron(int n, int i) {
    
    if( n == 0) return ;
    
    patron(n/2, i );
    for( int k = 0; k < i; k++) cout << "   ";
    for( int k = 0; k < n; k++) cout << " * ";
    cout << endl;
    patron(n/2, n/2 + i);  
}

int main(int argc, char** argv) {
    
    
    int n = 8, i = 0;
    patron(n, i);
        
    return 0;
}
