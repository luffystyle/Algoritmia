/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "Cola.h"
#include "Lista.h"
#include "Nodo.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"

void recorrePorAmplitudItera(struct ArbolBinario arbol){
    if(esArbolVacio(arbol)) return;
    Cola cola;
    construir(cola);
    NodoArbol *parbol ;
    encolar(cola,arbol.raiz);
    while(!esColaVacia(cola)){
        parbol = desencolar(cola);
        imprimeNodo(parbol);
        if(!esNodoVacio(parbol->izquierda)){
            encolar(cola,parbol->izquierda);
        }
        if(!esNodoVacio(parbol->derecha)){
            encolar(cola,parbol->derecha);
        }
    }
    
            
}
void validacionIngresoProducto(struct ArbolBinario arbol,int calidad){
    if(esArbolVacio(arbol)) return;
    Cola cola;
    construir(cola);
    NodoArbol *parbol ;
    int limiteAux, cantidadAux =0,nivelAnterior ;
    encolar(cola,arbol.raiz);
    while(!esColaVacia(cola)){
        parbol = desencolar(cola);
        if(parbol->nivel == calidad -1){
            limiteAux = parbol->nivel * 2;
        }
        if(parbol->nivel == calidad){
            cantidadAux++;
        }else{
            if(parbol->nivel == calidad+1){
                break;
            }
        }
        
        //imprimeNodo(parbol);
        if(!esNodoVacio(parbol->izquierda)){
            encolar(cola,parbol->izquierda);
        }
        if(!esNodoVacio(parbol->derecha)){
            encolar(cola,parbol->derecha);
        }

    }
    
    if(cantidadAux == limiteAux){
        cout<<"No es posible"<<endl;
    }else{
        if(cantidadAux < limiteAux){
            cout<<"Si es posible agregar"<<endl;
        }
    }
    
}

bool buscar(struct NodoArbol *nodo, int codigo) {
    if (nodo == nullptr) return false;
    if (nodo->elemento == codigo) return true;
    if (codigo < nodo->elemento) return buscar(nodo->izquierda, codigo);
    return buscar(nodo->derecha, codigo);
}

int validarActualizacion(struct ArbolBinarioBusqueda arbol, int codigoActual, int nuevoCodigo){
    if(esArbolVacio(arbol))return 0;
    //busc0amos que el codigo no se repita en el arbol
    if(buscar(arbol.arbolBinario.raiz,nuevoCodigo)) return 0;
    
    //tenemos que encontrar el nodo padre
    NodoArbol *padre = nullptr,*actual = arbol.arbolBinario.raiz;
    while(actual!=nullptr and actual->elemento != codigoActual){
        padre = actual;
        if(codigoActual < actual->elemento ){
            actual = actual->izquierda;
        }else{
            actual = actual->derecha;
        }
    }
    
    //ahora vemos si existe el nodo que buscamos
    if(actual == nullptr) return 0;
    
    //verificamos que mantenga el orden establecido
    if(padre != nullptr){
        if((padre->izquierda == actual and nuevoCodigo > padre->elemento) || 
                (padre->derecha == actual and nuevoCodigo < padre->elemento)){
            return 0;
        }
    }
    
    //si tuviera hijo el nodo a reemplazar
    if((actual->izquierda!=nullptr and nuevoCodigo < maximoNodo(actual->izquierda)) ||
            (actual->derecha!=nullptr and nuevoCodigo > minimoNodo(actual->derecha) ) ){
        return 0;
    }
    
    return 1;
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,10,1);
    insertar(arbol,5,2);
    insertar(arbol,20,2);
    insertar(arbol,21,3);
    insertar(arbol,2,3);
    insertar(arbol,6,3);
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    cout<<"Recorrido por Amplitud: "<<endl;
    recorrePorAmplitudItera(arbol.arbolBinario);
    cout<<endl;
    int calidad = 3;
    validacionIngresoProducto(arbol.arbolBinario,calidad);
    int codigoActual = 5,nuevoCodigo = 7;
    int valido = validarActualizacion(arbol,codigoActual,nuevoCodigo);
    if(valido ==1){
        cout<<"Se puede actualizar"<<endl;
    }else{
        cout<<"No se puede actualizar"<<endl;
    }
    return 0;
}

