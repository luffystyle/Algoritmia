/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int cantidadUnidad(int mapa[][6],int n, int m,int fil,int col, int x, int y, int universo ){
    int cant = 0;
    if (x>=n || x<0 || y>=m || y<0 ) return 0;
    // esto es para que valla hacia la derecha
    if(col !=0){
        if(universo==1){
            for(int i=0;i<m;i++){
            cant += mapa[x][i];
            }
        }
        for(int i=0;i<n;i++) if(i!=x)cant +=mapa[i][y];
        
    }else{
        //esto es para cuando sube de arriba hacia abajo
        if(universo==1){
            for(int i=0;i<n;i++) cant +=mapa[i][y];
        }
        for(int i=0;i<m;i++) if(i!=y) cant += mapa[x][i];
    }
    
   cant += cantidadUnidad(mapa,n,m,fil,col,x+fil,y+col,0); 
    
    return cant;
}













// x= filas y y= colum
int sonda(int mapa[][6], int n,int m,int xmov, int ymov, int x, int y, int primerUniverso){
    //si las filas y col pasan retorna el valor 0
    if(x>=n || y>=m || x<0 || y<0) return 0;
    int cont=0;
    if(ymov!=0){
        //va a sumar toda las fulas de la columna "x" // sumando derecha e izquierda
        if(primerUniverso)
            for(int i=0;i<m;i++) cont+=mapa[x][i];
        //va a sumar tadas las columnas de la fila y, exepto la fila q ya se sumo en la columna
        for(int i=0;i<n;i++)
            if(i!=x) cont+=mapa[i][y];
    }
    else{
        //si es el primer universo va a sumar todas las filas de una columna// arriba y abajo
        if(primerUniverso) for(int i=0;i<n;i++) cont+=mapa[i][y];
        //va a sumar todas las columnas de una fila
        for(int i=0;i<n;i++) //sumara derecha e izquierda
            if(i!=y) cont+=mapa[x][i];
    }
    
    cont+=sonda(mapa, n, m, xmov, ymov, x+xmov, y+ymov, 0);
    return cont;
}





int main(int argc, char** argv) {
    int mapa[][6]={{0,0,0,1,0,1},
                   {0,0,1,0,0,0},
                   {0,1,0,0,0,1},
                   {1,0,0,0,0,0},
                   {0,1,0,0,0,0},
                   {0,0,0,0,1,0}};
    int x,y,n,m;
    x=4;
    y=3;
    m=6;
    n=6;
    
    cout<<cantidadUnidad(mapa, n, m, 0, 1, x,y, 1);
    
    
    return 0;
}

