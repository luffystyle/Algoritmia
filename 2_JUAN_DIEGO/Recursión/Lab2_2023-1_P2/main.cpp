/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 10 de abril de 2024, 12:59 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int almacenOrigen[8][5][2]={{{2010,100},{2010,50},{2010,50},{0},{0}},
                            {{2021,100},{2021,100},{2021,50},{2021,50},{0}},
                            {{2018,50},{2018,50},{2018,25},{2018,25},{2018,25}},
                            {{2015,100},{2015,50},{2015,25},{0},{0}},
                            {{2020,100},{2020,100},{0},{0},{0}},
                            {{2019,100},{2019,50},{2019,50},{2019,25},{0}},
                            {{2022,100},{2022,100},{0},{0},{0}},
                            {{0},{0},{0},{0},{0}}};//Puerta
/*============================================================================*/
int almacenDestino[5][4][2]{{{0},{0},{0},{0}},//Pila pivot
                            {{0},{0},{0},{0}},
                            {{0},{0},{0},{0}},
                            {{0},{0},{0},{0}},
                            {{0},{0},{0},{0}},};

int pos=0;

/*
 * 
 */
int seleccionAntiguo(int i,int m,int min){
    if(i==m)return min;    
    if(almacenOrigen[i][0][0]<min && almacenOrigen[i][0][0]!=0){
        min=almacenOrigen[i][0][0];
        pos=i;
    }
    seleccionAntiguo(i+1,m,min);
}
int obtenerLongitud(int tamanho,int j,int high,int pila){
    if(j==tamanho)return high;
    if(almacenOrigen[pila][j][0]>0){
        high++;
    }
    obtenerLongitud( tamanho, j+1, high, pila);
}
void puertaAlmacen(int longitud,int i,int pila){
    if(i==longitud)return;
    almacenOrigen[7][i][0]=almacenOrigen[pila][i][0];
    almacenOrigen[7][i][1]=almacenOrigen[pila][i][1];
    puertaAlmacen(longitud,i+1,pila);
    almacenOrigen[pila][i][0]=0;
    almacenOrigen[pila][i][1]=0;
}
void pivot(int longitud,int n,int j){
    if(longitud==0)return;
    almacenDestino[0][j][0]=almacenOrigen[7][longitud-1][0];
    almacenDestino[0][j][1]=almacenOrigen[7][longitud-1][1];
    pivot(longitud-1,n,j+1);
}
void posFinal(int longitud,int k,int n){
    if(longitud==0)return;
    almacenDestino[n][k][0]=almacenDestino[0][longitud-1][0];
    almacenDestino[n][k][1]=almacenDestino[0][longitud-1][1];   
    posFinal(longitud-1,k+1,n);
    almacenDestino[0][k][0]=0;
    almacenDestino[0][k][1]=0;
}
void imprimir(int n){
    for(int i=0;i<5;i++){
        cout<<"Pila "<<i+1<<" ";
        for(int j=0;j<4;j++){            
            cout<<almacenDestino[i][j][0]<<"-";
            cout<<almacenDestino[i][j][1]<<" ";
        }
        cout<<endl;
    }
}
void barricas(int n,int m,int pila,int altura,int tamanho,int pilasAlmacen){
    if(pila==m){
        return;
    }
    if(pilasAlmacen==0){
        return;
    }
    int menor;
    int longitud;
    int min=9999;
    menor=seleccionAntiguo(0,m,min);
    
    longitud=obtenerLongitud(tamanho,0,0,pila);
    //cout<<longitud;
    if(longitud<=altura){
        puertaAlmacen(longitud,0,pila);
        pivot(longitud,n,0);
        posFinal(longitud,0,pilasAlmacen);
        pilasAlmacen--; 
        cout<<menor<<endl;
    }
    almacenOrigen[pos][0][0]=9999;
    barricas(n,m,pila+1,altura,tamanho,pilasAlmacen);
}
int main(int argc, char** argv) {
    
    int m=7;
    int n=4;
    int tamanho=5;
    int altura=4;
    int pilasAlmacen=4;
    
    barricas(n,m,0,altura,tamanho,pilasAlmacen);    
    imprimir(n);
    
    return 0;
}

