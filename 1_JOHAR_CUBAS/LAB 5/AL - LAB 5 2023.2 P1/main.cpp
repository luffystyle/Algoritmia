/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
//primer examen 2023.1
using namespace std;
#include "Lista.h"
#include "Pila.h"
#include "Nodo.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

int buscadorSkynerd(int matriz[][7],int n){
    Pila pila;
    construir(pila);
    for(int i=0;i<n;i++){
        apilar(pila,i);
    }
    
    while(longitud(pila)>1){
        int a = desapilar(pila);
        int altura = cima(pila);
        
        if(matriz[a][altura]!=0){
            int b = desapilar(pila);
            apilar(pila,a);
        }
        
    }
    int altura =cima(pila);
    
    for(int i=0;i<n;i++){
        if((matriz[altura][i]==0 and i!=altura) || (matriz[i][altura]!=0)){
            return -1;
        }
    }
    
    return altura+1;
}

int calcularMax(int *matriz){
    int mayor = -9999999;
    for(int i=0;i<7;i++){
        if(mayor < matriz[i]){
            mayor=matriz[i];
        }
    }
    return mayor;
}

int main(int argc, char** argv) {
    int n = 7;
    int matriz[7][7]={ {0,0,0,0,0,0,0},
                       {10,0,20,30,0,20,40},
                       {0,0,0,0,0,100,0},
                       {0,0,0,0,0,80,0},
                       {50,10,5,10,0,100,4},
                       {100,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0}};
    
    
    int encontrado = buscadorSkynerd(matriz,n);
    if(encontrado!=-1){
        cout<<"SkyNerd ha sido detectado en el servidor: "<<encontrado<<endl;
    }else{
         cout<<"SkyNerd no está en la red"<<endl;
    }
    
    int maximo = calcularMax(matriz[encontrado]);
    cout<<"Máximo de paquetes enviados por SkyNerd: "<<maximo<<endl;
    
    return 0;
}



































