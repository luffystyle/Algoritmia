/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

int existenciaServidor(int matriz[][7],struct Pila pila,int cant){
    int valorPosible,encima;
    
    for(int i=0;i<cant-1;i++){
        valorPosible = desapilar(pila);
        encima=cima(pila);
        if(matriz[valorPosible][encima]!=0){
            int des=desapilar(pila);
            apilar(pila,valorPosible);
        }
        if(longitud(pila)==1) break;
    }
    valorPosible = desapilar(pila);
    int existe =1;
    for(int i=0;i<cant;i++){
        if(matriz[i][valorPosible]!=0){
            existe=0;
        }
    }
    if(existe!=1){
        return -1;
    }
    for(int i=0;i<cant;i++){
        if(matriz[valorPosible][i]==0 and i!=valorPosible){
            existe = 0;
            break;
        }
    }
    
    if(existe!=1){
        return -1;
    }else{
        return valorPosible+1;
    }
}

int main(int argc, char** argv) {
    Pila pila;
    construir(pila);
    int cant = 7;
    int matriz[7][7]={{0,0,0,0,0,0,0},
                      {10,0,20,30,0,20,40},
                      {0,0,0,0,0,100,0},
                      {0,0,0,0,0,80,0},
                      {50,10,5,10,0,100,4},
                      {100,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0}};
    
    for(int i=0;i<cant;i++) apilar(pila,i);
    
    int numPos = existenciaServidor(matriz,pila,cant);
    if(numPos!=-1){
        cout<<"Skynerd ha sido detectado en el servidor: "<<numPos<<endl;
    }else{
        cout<<"Skynerd no se encuentra en el servidor"<<endl;
    }
    
    return 0;
}

