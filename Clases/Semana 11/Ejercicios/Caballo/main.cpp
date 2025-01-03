/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 30 de octubre de 2023, 10:29 AM
 */

#include <iostream>
#include <iomanip>
#define N 5
#define maxmov 8 
int m[maxmov][2];


using namespace std;

void generamovimientos(){
    m[0][0]= -2; m[0][1]= 1;
    m[1][0]= -1; m[1][1]= 2;
    m[2][0]=  1; m[2][1]= 2;
    m[3][0]=  2; m[3][1]= 1;
    m[4][0]=  2; m[4][1]=-1;
    m[5][0]=  1; m[5][1]=-2;
    m[6][0]= -1; m[6][1]=-2;
    m[7][0]= -2; m[7][1]=-1;
}

int esvalido(int tablero[N][N],int x,int y){
    if(x>=0 && y>=0 && x<N && y<N && tablero[x][y]==0)
        return 1;
    else
        return 0;   
}

int buscasolucion(int tablero[N][N],int x,int y, int mov){
    int nx,ny;
    
    if(mov==N*N+1){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
            cout << setw(4) << tablero[i][j];
        cout << endl;
        }  
        cout << endl;
        return 0;
        // si queremos una solución coloque return 1;
    }
    for(int i=0;i<maxmov;i++){
        nx = x + m[i][0];
        ny = y + m[i][1];
        if(esvalido(tablero,nx,ny)){
            tablero[nx][ny] = mov;
            if(buscasolucion(tablero,nx,ny,mov+1))
                return 1;
            tablero[nx][ny] = 0;
        }
    }
    return 0;
    
}


int main(int argc, char** argv) {
    int x=0,y=0;
    int tablero[N][N];
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) tablero[i][j]=0;
    
    generamovimientos();
    tablero[x][y] = 1;
    if(buscasolucion(tablero,x,y,2))
        cout << "Encontro solución" << endl;
    else
        cout << "No encontro solución" << endl;
    

    return 0;
}

