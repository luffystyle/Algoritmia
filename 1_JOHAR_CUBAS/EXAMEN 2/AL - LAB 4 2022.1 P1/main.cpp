/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

#include "funcionesArbolesBB.h"

using namespace std;
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "Estructura.h"
#include "NodoArbol.h"
#include "funcionesArbolesBinarios.h"
//verificacion cuando son dos campos los que son restricitvos
void verificarInsertar(struct NodoArbol *nodo,struct Elemento elemento){
    if(nodo ==  nullptr){
        cout<<"Ok"<<endl;
        return;
    }
    if(nodo->elemento.campo1 < elemento.campo1){
        verificarInsertar(nodo->derecha,elemento);
    }else{
        if(nodo->elemento.campo1 > elemento.campo1){
            verificarInsertar(nodo->izquierda,elemento);
        }else{
            if(nodo->elemento.campo2 > elemento.campo2){
                verificarInsertar(nodo->izquierda,elemento);
            }else{
                if(nodo->elemento.campo2 < elemento.campo2){
                    verificarInsertar(nodo->derecha,elemento);
                }else{
                    cout<<"Cannot insert duplicate key"<<endl;
                    return;
                }
            }
        }
    }
}

void verificarActualizacion(struct NodoArbol *nodo,struct Elemento elemento,int campo1,int campo2){
    
    NodoArbol*anterior = nullptr;
    NodoArbol *parbol = nodo;
    NodoArbol *raiz = nodo;
    NodoArbol*campo2 = nullptr;
    while(parbol!=nullptr){
        
        if(parbol->elemento.campo1 < elemento.campo1){
            anterior = parbol;
            parbol = parbol->izquierda;
        }else{
            if(parbol->elemento.campo1 > elemento.campo1){
                anterior = parbol
                parbol = parbol->derecha;
            }else{
                campo2 = parbol;//guardo el puntero donde me dice q hay un campo 2 restrictivo
                if(nodo->elemento.campo2 > elemento.campo2){
                    parbol = parbol->izquierda;
                }else{
                    if(nodo->elemento.campo2 < elemento.campo2){
                        parbol = parbol->derecha;
                    }else{
                        if(campo1!=0){
                            
                        }
                    }
                }
                
            }
            
        }
        
    }        
    if(parbol ==  nullptr){
        cout<<"No se encontro el nodo que se desea actualizar"<<endl;
        return;
    }
}


int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,{10,8,5});
    insertar(arbol,{8,20,6});
    insertar(arbol,{15,10,3});
    insertar(arbol,{5,10,3});
    insertar(arbol,{10,1,7});
    insertar(arbol,{16,8,7});
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    verificarInsertar(arbol.arbolBinario.raiz,{5,11,6});
    //parte b
    int campo1 = 15,campo2 =0 ;
    verificarActualizacion(arbol.arbolBinario.raiz,{5,10,3},campo1,campo2);
    
    return 0;
}

