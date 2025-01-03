/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <csetjmp>

using namespace std;

int mov[8][2];

int movimiento(){
    mov[0][0] = -1; mov[0][1] = 0 ;
    mov[1][0] = -1; mov[1][1] = -1;
    mov[2][0] = 0 ; mov[2][1] = 1 ;
    mov[3][0] = 1 ; mov[3][1] = 1 ;
    mov[4][0] = 1 ; mov[4][1] = 0 ;
    mov[5][0] = 1 ; mov[5][1] = -1;
    mov[6][0] = 0 ; mov[6][1] = -1;
    mov[7][0] = -1; mov[7][1] = -1;
    
    
}

void ImpresionDeLetras(int fil,int col,char palabra[],char tablero[][9],int logitudPal){
    int nfil,ncol,j;
    if(tablero[fil][col]==palabra[0]){
        for(int i =0;i<8;i++){
            nfil = fil + mov[i][0];
            ncol = col + mov[i][1];
            for(j=1;j<logitudPal;j++){
                if(ncol<0 || nfil<0 || ncol>=9 || nfil>=4) break;
                if(tablero[nfil][ncol]!=palabra[j]) break;
                nfil = nfil + mov[i][0];
                ncol = ncol + mov[i][1];
            }
            if(logitudPal==j){
                ;
            }
        
            
        }
      
        
        
    }
    
    
    
    
    
}



void pupiletras(char palabra[],char tablero[][9],int logitudPal){
    for(int i=0;i<4;i++){
        for(int j=0;j<9;j++){
            ImpresionDeLetras(i,j,palabra,tablero,logitudPal);
        }
    }
    
    
    
}



int main(int argc, char** argv) {
    
    char tablero[][9]{
        {'G','J','M','A','R','I','T','A','S'},
        {'Q','W','W','E','R','O','P','O','L'},
        {'R','M','A','R','I','P','O','S','A'},
        {'E','G','E','E','T','R','U','D','I'},
    };
    char palabra[]={'M','A','R','I','P','O','S','A'};
    int logitudPal=8;
    movimiento();
    pupiletras(palabra,tablero,logitudPal);
    
    
    return 0;
}

