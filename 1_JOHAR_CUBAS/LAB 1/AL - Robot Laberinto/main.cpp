/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

void laberintoRobot(int tabla[][5],int limFil,int limCol,int x,int y){
    
    if(y>=limCol || y<0 || x>=limFil || x<0) return; 
    if(x==limFil-1 and y == limCol-1) cout<<tabla[x][y]<<" ";
    //derecha hasta uno antes del limite para que cuando agarre de abajo agrre desde el ultima columna
    for(int i=y;i<limCol-1;i++) cout<<tabla[x][i]<<" ";
    //abajo
    for(int i=x ;i<limFil-1;i++) cout<<tabla[i][limCol-1]<<" ";
    //izquierda
    for(int i=limCol-1;i>x;i--) cout<<tabla[limFil-1][i]<<" ";
    //arriba
    for(int i=limFil-1;i>y;i--) cout<<tabla[i][y]<<" ";
    
    laberintoRobot(tabla,limFil-1,limCol-1,x+1,y+1);
}

int cantidadMonticulos(int tabla[][5],int limFil,int limCol,int x,int y){
    int cant=0; 
    if(y>=limCol || y<0 || x>=limFil || x<0) return 0;
    
    if(x==limFil-1 and y == limCol-1){
        cout<<tabla[x][y]<<" ";
        cant++;
    }    
    for(int i=y;i<limCol-1;i++){
        cout<<tabla[x][i]<<" ";
        cant++;
    }
    //abajo
    for(int i=x ;i<limFil-1;i++){
        cout<<tabla[i][limCol-1]<<" ";
        cant++;
    }//izquierda
    for(int i=limCol-1;i>x;i--){
        cout<<tabla[limFil-1][i]<<" ";
        cant++;
    }//arriba
    for(int i=limFil-1;i>y;i--){
        cout<<tabla[i][y]<<" ";
        cant++;
    }
    
    
    cant += cantidadMonticulos(tabla,limFil-1,limCol-1,x+1,y+1);
    return cant;
}



int main(int argc, char** argv) {
    int tabla[][5]={{1 , 2, 3, 4, 5},
                    {6 , 7, 8, 9,10},
                    {11,12,13,14,15},
                    {16,17,18,19,20},
                    {21,22,23,24,25}};
    
    int n=5,m=5;
    //derecha 0 1
    //izquierda 0 -1
    //arriba -1 0
    //abajo 1 0
    laberintoRobot(tabla,n,m,0,0);
    //la parte b
    cout<<endl<<"La cantidad de monticulos: "<<cantidadMonticulos(tabla,n,m,0,0)<<endl;
    return 0;
}

