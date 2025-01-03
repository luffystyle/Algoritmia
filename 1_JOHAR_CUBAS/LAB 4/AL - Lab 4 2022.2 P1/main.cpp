/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#define N 5;
using namespace std;
#include "ArbolBinario.h"
#include "NodoArbol.h"
#include "funcionesArbolesBinarios.h"

void plantarArbolBinarioNew(struct NodoArbol *&raiz,struct NodoArbol *arbolIzq,int bin,int elemento,struct NodoArbol *arbolDer){
    struct NodoArbol *nodoNuevo;
    nodoNuevo = crearNuevoNodoArbol(arbolIzq,bin,elemento,arbolDer);
    raiz = nodoNuevo;    
}

void insertarNewRecur(struct NodoArbol * &raiz,int bin,int elemento){
    if(raiz == NULL){
        plantarArbolBinarioNew(raiz,nullptr,bin,elemento,nullptr);
    }else{
        
        insertarNewRecur(raiz->izquierda,0,elemento);
        insertarNewRecur(raiz->derecha,1,elemento);
    }
    
}


void insertarNew(struct ArbolBinario &arbol,int bin,int elemento){
    insertarNewRecur(arbol.raiz,bin,elemento);
}

void recorrerEnPre_OrdenRecursivo(struct NodoArbol *raiz,int &suma,int cant,int *cromo,int cont,int cont2){
    
    suma += raiz->elemento * raiz->bin ; 
    int i= cont2;
    
    cromo[i] = raiz->bin;
    
    if(raiz->izquierda !=nullptr){

        recorrerEnPre_OrdenRecursivo(raiz->izquierda,suma,cant,cromo,suma,cont2+1);
        recorrerEnPre_OrdenRecursivo(raiz->derecha,suma,cant,cromo,suma,cont2+1);
        //le pongo esto para que cuando regrese la suma se actualize hasta donde habia llegado la recursion a sumar
        suma = cont;
        i= cont2;
    }else{
        if(raiz->izquierda==nullptr and suma!=0){
          
          cout<<" [";
          for(int i=0;i<cant+1;i++){
              cout<<cromo[i];
              if(i!=cant){
                  cout<<",";
              }
          }
          cout<<"]->";
          cout<<"("<<suma<<") ,";

          //for(int i = 0;i<cant;i++) cromo[i]=0;
        }
    }

    
}

void recorrerEnPre_Orden(struct ArbolBinario &arbol,int n){
    if(!esArbolVacio(arbol)){
        int suma = 0;
        int cromo[n]={};
        int cont=0;
        recorrerEnPre_OrdenRecursivo(arbol.raiz,suma,n,cromo,0,cont);
    }
    
}

void determinarCantidadComb(struct NodoArbol *raiz,int peso,int &suma,int &cantidad,int cont){
    int sumatoria=0 ;
    sumatoria = sumatoria + raiz->elemento*raiz->bin;
    //suma = cont;
    suma += sumatoria;
    if(raiz->izquierda == nullptr){
        if(peso == suma){
            cantidad ++;
        }
        //suma = 0;
    }else{
        //pongo en el contador  que es igual a suma para que cuando regrese a la rama de arriba la suma que habia contado hasta el regreso
        //de la rama lo actualize donde se habia quedado la suma 
        determinarCantidadComb(raiz->izquierda,peso,suma,cantidad,suma);
        determinarCantidadComb(raiz->derecha,peso,suma,cantidad,suma);
        suma = cont;
    }
    
}


int main(int argc, char** argv) {
    
    struct ArbolBinario arbol,arbol1,arbol2,arbol3,arbol4,arbol5,arbol6;
    construir(arbol);
    int n=2;
    int elementos[5] = {10,50};
    insertarNew(arbol,0,0);
    for(int i=0;i<n;i++){
        insertarNew(arbol,0,elementos[i]);
    }
    
    recorrerEnPre_Orden(arbol,n);
    int peso=70;
    int cantidad = 0;
    int suma = 0;
    determinarCantidadComb(arbol.raiz,peso,suma,cantidad,0);
    cout<<endl<<"Cantidad: "<<cantidad<<endl;
    
//    plantarArbolBinario(arbol1,nullptr,0,50,nullptr);
//    plantarArbolBinario(arbol2,nullptr,1,50,nullptr);
//    plantarArbolBinario(arbol3,arbol1,0,10,arbol2);
//    plantarArbolBinario(arbol5,nullptr,0,50,nullptr);
//    plantarArbolBinario(arbol6,nullptr,1,50,nullptr);
//    plantarArbolBinario(arbol4,arbol5,1,10,arbol6);
//    plantarArbolBinario(arbol,arbol3,0,0,arbol4);
    
    //recorrerPreOrden(arbol);
    
    return 0;
}

