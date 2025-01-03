/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int laberinto(int tablero[][5],int fil,int col){
    int termina = 0;
    
    if(fil >= 0 and fil < 3 and col >= 0 and col < 5){
        if(tablero[fil][col]== 1){
            tablero[fil][col] = 3;//para marcar mi recorrido y no se vuleva a repetir
            
            if(col==4 and fil==2){
                termina =1;//terminó
            }else{
                //*camina hacia abajo
                if(termina == 0) termina = laberinto(tablero,fil+1,col);
                //camina hacia la derecha
                if(termina == 0) termina = laberinto(tablero,fil,col+1);
                //camina haca arriba
                if(termina == 0) termina = laberinto(tablero,fil-1,col);    
                //camina hacia la izquierda    
                if(termina == 0) termina = laberinto(tablero,fil,col-1); 
            }

            if(termina==1){
                tablero[fil][col]= 7;
            }

        }
    }
    return termina;
}

void mostrarRuta(int tablero[][5]){
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(int argc, char** argv) {
    int tablero[][5]={ {1,0,1,1,1},
                       {1,1,1,0,1},
                       {0,0,1,0,1}};
    
    int ruta = laberinto(tablero,0,0);
    mostrarRuta(tablero);
    
    return 0;
}

