#include <iostream>
#include <cmath>
#define MAXCOL 5
#define MAXFIL 4

using namespace std;

int m[8][2];

int main(int argc, char **argv) {
    
    m[0][0] = -1; m[0][1] =  0; 
    m[1][0] = -1; m[1][1] =  1;
    m[2][0] =  0; m[2][1] =  1;
    m[3][0] =  1; m[3][1] =  1;
    m[4][0] =  1; m[4][1] =  0;
    m[5][0] =  1; m[5][1] = -1;
    m[6][0] =  0; m[6][1] = -1;
    m[7][0] = -1; m[7][1] = -1;  
    
    
    for(int i = 0; i<8; i++) {//columas
        for(int j = 0; j<2; j++) {//filas
            cout<<m[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}


