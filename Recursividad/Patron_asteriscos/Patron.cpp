#include <iostream>
using namespace std;

void patron(int n, int i){// T(n) = 2T(n/2) + 1 = O(n)
    if(n == 0) return;

    int j;

    patron(n/2, i);
    for(j = 0; j < i; j++) cout << "   ";
    for(j = 0; j < n; j++) cout << " * ";
    cout << endl;
    patron(n/2, n/2 + i);
}

int main(){
    patron(8,0);
    return 0;
}
