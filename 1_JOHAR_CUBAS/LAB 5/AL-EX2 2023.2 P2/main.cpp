/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
#include "ArbolBinario.h"
#include "NodoArbol.h"
#include "funcionesArbolesBinarios.h"
#include "Lista.h"
#include "Nodo.h"
#include "NodoArbol.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

struct NodoArbol * crearNuevoNodoArbolNew(struct NodoArbol * arbolIzquierdo, 
                               char letra, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->letra = letra;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBinarioNew(struct NodoArbol *&raiz, struct NodoArbol * arbolIzquierdo,
                         char letra, struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNew(arbolIzquierdo, letra, arbolDerecho);
    raiz = nuevoNodo;
}

int existeLetra(char letra,char *palabra){
    for(int i=0;palabra[i]!='\0';i++){
        if(letra == palabra[i]){
            return 1;
        }
    }
    return -1;
}

int validacionPalabra(char *aux,char *palabra,int pos){
    char aux2[6];
    for(int i=0;i<pos;i++) aux2[i] = aux[i];
    int existe =0,contador=0;
    for(int i =0;palabra[i]!='\0';i++){
        existe = 0;
        contador ++;
        for(int j=0;j<pos;j++){
            if(palabra[i]==aux2[j]){
                existe=1;
                aux2[j] = ' ';
                break;
            }
        }
        if(existe!=1){
            break;
        }
    }
    if(existe ==1 and contador ==pos){
        return 1;
    }else{
       return 0; 
    }
    
}
int palabraExistente(struct NodoArbol *raiz,char *palabra,char *aux,int pos){
    if(raiz == nullptr){
        return 0;
    }
    
    if(existeLetra(raiz->letra,palabra)==1){
        aux[pos++] = raiz->letra  ;
    }else{
        return 0 ;
    }
    if(raiz->derecha==nullptr and raiz->izquierda==nullptr){
        if(validacionPalabra(aux,palabra,pos)){
            return 1;
        }else{
            return 0;
        }
    }
    
    return palabraExistente(raiz->izquierda,palabra,aux,pos) + palabraExistente(raiz->derecha,palabra,aux,pos);
    
}



NodoArbol *eliminarNodo(struct NodoArbol *raiz,int dato){
    if(dato < raiz->elemento){
        raiz->izquierda = eliminarNodo(raiz->izquierda,dato);
    }else{
        if(dato > raiz->elemento){
            raiz->derecha = eliminarNodo(raiz->derecha,dato);
        }else{
            if(raiz->izquierda == nullptr){
                NodoArbol *hijo = raiz->derecha;
                delete raiz;
                return hijo;
            }else{
                if(raiz->derecha == nullptr){
                    NodoArbol *hijo = raiz->izquierda;
                    delete raiz;
                    return hijo;
                }else{
                    NodoArbol *nodo = encontrarMinim(raiz->derecha);
                    raiz->elemento = nodo->elemento;
                    raiz->derecha = eliminarNodo(raiz->derecha,nodo->elemento);
                }
                
            }
            
            
        }
    }
    return raiz;
    
}


void postOrdenItera(struct NodoArbol * raiz){
    Pila pila;
    construir(pila);
    int ultimo = 0,alto;
    NodoArbol *parbol = raiz;
    
    while(1){
        while(parbol!=nullptr){
            apilar(pila,parbol->elemento);
        }
        alto = cima(pila);
        
        
        
        if(esPilaVacia(pila)) break;
    }
    
}
struct NodoArbol * encontrarMinim(struct NodoArbol *raiz){
    while(raiz->izquierda!=nullptr){
        raiz = raiz->izquierda;
    }
    return raiz;
}
struct NodoArbol* recorrerEnPostOrdenRecursivoEliminar(struct NodoArbol * nodo,int dato){//O(n)
    if(esNodoVacio(nodo)){
        return nodo;
    }
    
    nodo->izquierda = recorrerEnPostOrdenRecursivoEliminar(nodo->izquierda,dato);
    nodo->derecha = recorrerEnPostOrdenRecursivoEliminar(nodo->derecha,dato);
    //imprimeNodo(nodo);
    if(nodo->elemento == dato){
        
        // Nodo con solo un hijo o sin hijos
        if (nodo->izquierda == nullptr) {
            NodoArbol *temp = nodo->derecha;
            delete nodo;
            return temp;
        } else if (nodo->derecha == nullptr) {
            NodoArbol *temp = nodo->izquierda;
            delete nodo;
            return temp;
        }

        // Nodo con dos hijos: obtener el sucesor (nodo mínimo en el subárbol derecho)
        NodoArbol *temp = encontrarMinim(nodo->derecha);

        // Copiar el contenido del sucesor al nodo actual
        nodo->elemento = temp->elemento;
        nodo->letra = temp->letra;
        // Eliminar el sucesor   
        nodo->derecha = recorrerEnPostOrdenRecursivoEliminar(nodo->derecha, temp->elemento);
        
    }

    return nodo;
}


int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);
    plantarArbolBinarioNew(arbol.raiz,nullptr,'L',nullptr);
    arbol.raiz->elemento=20;
    plantarArbolBinarioNew(arbol.raiz->izquierda,nullptr,'D',nullptr);
    arbol.raiz->izquierda->elemento =28;
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda,nullptr,'E',nullptr);
    arbol.raiz->izquierda->izquierda->elemento = 30;
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha,nullptr,'E',nullptr);
    arbol.raiz->izquierda->derecha->elemento = 12;
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->izquierda,nullptr,'R',nullptr);
    arbol.raiz->izquierda->derecha->izquierda->elemento =15;
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->derecha,nullptr,'G',nullptr);
    arbol.raiz->izquierda->derecha->derecha->elemento =16;
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->derecha->izquierda,nullptr,'T',nullptr);
    arbol.raiz->izquierda->derecha->derecha->izquierda->elemento = 18;
    plantarArbolBinarioNew(arbol.raiz->derecha,nullptr,'I',nullptr);
    arbol.raiz->derecha->elemento = 19;
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda,nullptr,'C',nullptr);
    arbol.raiz->derecha->izquierda->elemento = 36;
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda,nullptr,'C',nullptr);
    arbol.raiz->derecha->izquierda->izquierda->elemento = 40;
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda->izquierda,nullptr,'O',nullptr);
    arbol.raiz->derecha->izquierda->izquierda->izquierda->elemento =27;
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha,nullptr,'N',nullptr);
    arbol.raiz->derecha->derecha->elemento = 10;
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda,nullptr,'A',nullptr);
    arbol.raiz->derecha->derecha->izquierda->elemento = 9;
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda->izquierda,nullptr,'F',nullptr);
    arbol.raiz->derecha->derecha->izquierda->izquierda->elemento = 7;
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda->derecha,nullptr,'T',nullptr);
    arbol.raiz->derecha->derecha->izquierda->derecha->elemento = 2;
    char palabras[6][6]={{'H','I','J','O','\0'},
                       {'F','I','N','A','L','\0'},
                       {'M','U','N','D','O','\0'},
                       {'D','E','L','\0'},
                       {'D','I','A','\0'},
                       {'C','I','C','L','O','\0'} };
    int n=6,m=6;
    int pos=0;
    char palabraAux[6];
    for(int i=0;i<n;i++){
        if(palabraExistente(arbol.raiz,palabras[i],palabraAux,pos)==1){
           cout<<"Existe la palabra "<<palabras[i][0]<<palabras[i][1]<<endl; 
        }
    }
    recorrerPostOrden(arbol);
    cout<<endl;
    arbol.raiz = recorrerEnPostOrdenRecursivoEliminar(arbol.raiz,12);
    recorrerEnPostOrdenRecursivo(arbol.raiz);
    return 0;
}

