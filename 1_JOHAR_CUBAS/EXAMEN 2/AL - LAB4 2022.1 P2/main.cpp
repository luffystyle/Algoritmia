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
#include "NodoArbol.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"

struct NodoArbol * encuentraMinimo(struct NodoArbol * nodo){
    while(nodo->izquierda!=nullptr){
        nodo= nodo->izquierda;
    }
    return nodo;
}

void actualizacionDelDespacho(struct ArbolBinarioBusqueda &arbol,int despacho){
    if(esArbolVacio(arbol)) return;
    int resto=0;
    while(1){
        NodoArbol * parbol= encuentraMinimo(arbol.arbolBinario.raiz);
        if(resto == 0){
            if(parbol->cantidad == despacho){
                eliminarNodo(arbol,parbol->elemento);
            }else{
                if(parbol->cantidad > despacho){
                    parbol->cantidad -= despacho ;
                }else{

                    resto = despacho - parbol->cantidad;
                    eliminarNodo(arbol,parbol->elemento);
                }
            }
        }else{
            if(parbol->cantidad == resto){
               eliminarNodo(arbol,parbol->elemento);
                resto = 0;
            }else{
                if(parbol->cantidad > resto){
                    parbol->cantidad -= resto ;
                    resto = 0;
                }else{
                    resto = resto - parbol->cantidad;
                    eliminarNodo(arbol,parbol->elemento);
                }
            }
        }
        
        if(resto==0) break; 
    }
}

void actualizacionDelDespacho2(struct ArbolBinarioBusqueda &arbol,int despacho){
    while(despacho>0){
        NodoArbol * minimo = encuentraMinimo(arbol.arbolBinario.raiz);
        if(minimo->cantidad <= despacho){
            despacho = despacho - minimo->cantidad;
            eliminarNodo(arbol,minimo->elemento);            
        }else{
            minimo->cantidad -= despacho;
            despacho = 0;
        }
    }
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,20220815,40);
    insertar(arbol,20220710,50);
    insertar(arbol,20220630,50);
    insertar(arbol,20220720,50);
    insertar(arbol,20220624,40);
    insertar(arbol,20220615,40);
    insertar(arbol,20220618,40);
    insertar(arbol,20220930,30);
    recorrerPreOrden(arbol.arbolBinario);cout<<endl;
    //recorrerEnOrden(arbol.arbolBinario);
    int cantSolicitudes = 3;
    int despacho1 =20,despacho2=40,despacho3=200; 
    cout<<endl<<"Despacho 1: "<<despacho1<<endl;
    actualizacionDelDespacho(arbol,despacho1);
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl<<"Despacho 2: "<<despacho2<<endl;
    actualizacionDelDespacho(arbol,despacho2);
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl<<"Despacho 3: "<<despacho3<<endl;
    actualizacionDelDespacho(arbol,despacho3);
    recorrerPreOrden(arbol.arbolBinario);    
   
    
    return 0;
}

