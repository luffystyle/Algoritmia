/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"
int rec  = 0;
void validar(struct Pila pila,int cantPilas,char *arr){
    
    for(int i=0;i<cantPilas;i++){
        if(arr[i]=='S' ){
            cout<<desapilar(pila)<<" ";
        }else{
            int aux= desapilar(pila);
            cout<<desapilar(pila)<<" ";
            apilar(pila,aux);
        }
    }
    cout<<desapilar(pila);
}

void  validacion2(char *arr,int cantPilas){
    Pila pila;
    construir(pila);
    for(int i=0;i<=cantPilas;i++){
        apilar(pila,i+1);
        if(arr[i]=='S' || i==cantPilas){
            while(!esPilaVacia(pila)){
                cout<<desapilar(pila)<<" ";
            }
        }
    }
}

void submarinoRec(char*orden,int mov,int index,int baja){
    if(index>mov)return;
    if(orden[index]=='S' || index==mov){
        cout<<index+1<<" ";
        rec=index;
        if(baja<1){
           submarinoRec(orden,mov,index+1,baja);  
        }else{
            return;
        }              
    }else{        
        submarinoRec(orden,mov,index+1,baja+1); 
        cout<<index+1<<" ";
        if(baja<1){
           submarinoRec(orden,mov,rec+1,baja);  
        }
    }       
}






int main(int argc, char** argv) {
    Pila pila;
    construir(pila);
    apilar(pila,8);
    apilar(pila,7);
    apilar(pila,6);
    apilar(pila,5);
    apilar(pila,4);
    apilar(pila,3);
    apilar(pila,2);
    apilar(pila,1);
    
    imprimir(pila);
    
    int cantPilas=3;
    char arr[5]={'S','S','S','B','S'};
    char arr3[7]={'S','B','S','B','B','S','S'};
    char arr2[3]={'B','B','S'};
    //validar(pila,cantPilas,arr2);
    validacion2(arr2,cantPilas);
    cout<<endl;
    submarinoRec(arr2,3,0,0);
    return 0;
}

