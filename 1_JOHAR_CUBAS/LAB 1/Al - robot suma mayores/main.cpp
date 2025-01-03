/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int robot(int tablero[][3],int fil,int col,int x,int y){
    int der=-99999,abajo=-99999,total;
    if(x == fil-1 and y== col-1) return tablero[x][y];
    
    if(x+1<fil){
        abajo=robot(tablero,fil,col,x+1,y);    
    }
    if(y+1<col){
        der=robot(tablero,fil,col,x,y+1);
    }
    if(der > abajo){
       return der +tablero[x][y];
    }
    if(der < abajo){
       return abajo + tablero[x][y];
    }
    
    
}

        
int main(int argc, char** argv) {
    int tablero[][3]={  {3,8,6},
                        {3,10,2},
                        {0,9,1}};
    int fil=3,col=3;
    
    cout<<robot(tablero,fil,col,0,0);
    
    
    
    return 0;
}

