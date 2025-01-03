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
#include "Lista.h"
#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesLista.h"

int calcularAltura(struct NodoArbol* nodo) {
    if (nodo == NULL)
        return 0;
    else {
        int alturaIzq = calcularAltura(nodo->izquierda);  // Calcula la altura del sub rbol izquierdo
        int alturaDer = calcularAltura(nodo->derecha);  // Calcula la altura del sub rbol derecho
        return max(alturaIzq, alturaDer) + 1;  // Retorna la altura m xima entre los sub rboles izquierdo y derecho, m s 1 (altura del nodo actual)
    }
}

int calAltura(struct NodoArbol *raiz){
    if(raiz ==nullptr){
        return 0;
    }else{
        int izq= calAltura(raiz->izquierda);
        int der=calAltura(raiz->derecha);
        return max(izq,der) +1;
    }
}


struct NodoArbol* rotacionDerecha(struct NodoArbol * nodo){
    NodoArbol *nodoIzq = nodo->izquierda;
    nodo->izquierda = nodoIzq->derecha;
    nodoIzq->derecha = nodo;
    return nodoIzq;
}

struct NodoArbol* rotacionIzquierda(struct NodoArbol * nodo){
    NodoArbol * nodoDer = nodo->derecha;
    nodo->derecha = nodoDer->izquierda;
    nodoDer->izquierda = nodo;
    return nodoDer;
}

struct NodoArbol* rotacionDerDoble(struct NodoArbol * nodo){
    nodo->izquierda = rotacionIzquierda(nodo->izquierda);
    return rotacionDerecha(nodo);
}

struct NodoArbol* rotacionIzqDoble(struct NodoArbol * nodo){
    nodo->derecha = rotacionDerecha(nodo->derecha);
    return rotacionIzquierda(nodo);
}


struct NodoArbol * balanceoNodo(struct NodoArbol *raiz){
    int alturaIzq = calcularAltura(raiz->izquierda) ;
    int alturaDer = calcularAltura(raiz->derecha);
    int diferencia = alturaIzq - alturaDer ; 
    
    if(diferencia > 1 ){
        if(calcularAltura(raiz->izquierda->izquierda) >= calcularAltura(raiz->izquierda->derecha) ){
            raiz = rotacionDerecha(raiz);
        }else{
            raiz = rotacionDerDoble(raiz);
        }
        
    }else if( diferencia < -1){
        if(calcularAltura(raiz->derecha->derecha) >= calcularAltura(raiz->derecha->izquierda)){
            raiz = rotacionIzquierda(raiz);
        }else{
            raiz = rotacionIzqDoble(raiz);
        }
        
    }
    
    return raiz;
}


struct NodoArbol* balancearArbolToken(struct NodoArbol*raiz ){
    if(raiz == nullptr) return nullptr; 
    raiz->izquierda = balancearArbolToken(raiz->izquierda);
    raiz->derecha = balancearArbolToken(raiz->derecha);
    raiz = balanceoNodo(raiz);
    return raiz;
}
//sumar segun la posicion del pre orden en que se encuentre las hojas
void sumaArboles(struct NodoArbol *raiz,struct NodoArbol *raiz2){
    if(raiz2 == nullptr) return;
    
    //esto es para cuando quiero insertar y sumarlo
//    if(raiz== nullptr){
//        plantarArbolBB(raiz,nullptr,raiz2,nullptr);
//    }else raiz->elemento += raiz2->elemento;
    
    if(raiz != nullptr) {
        raiz->elemento +=raiz2->elemento;
    }
    sumaArboles(raiz->izquierda,raiz2->izquierda);
    sumaArboles(raiz->derecha,raiz2->derecha);
    
}

struct NodoArbol * busca(struct NodoArbol *raiz,int dato){
    if(raiz == nullptr) return raiz;
    else{
        if(raiz->elemento == dato){
            return raiz;
        }else{
            if(raiz->elemento > dato){
                raiz = raiz->izquierda;
            }else{
                raiz = raiz->derecha;
            }
            return busca(raiz,dato);
        }
    }
}

void postOrdenIterativa(struct ArbolBinarioBusqueda arbol){
    NodoArbol * parbol;
    int alto,ultimo=0;
    Pila pila;
    if(esArbolVacio(arbol)) return ;
    construir(pila);
    parbol = arbol.arbolBinario.raiz;
    
    while(1){
        while(parbol !=nullptr){
            apilar(pila,parbol->elemento);
            parbol = parbol->izquierda;
        }
        alto = cima(pila);
        parbol = busca(arbol.arbolBinario.raiz,alto);
        //esto es si es que el ultimo raiz izquierdo no tiene hijos izquierdos pero si tiene el derecho
        if(parbol->derecha != nullptr and ultimo !=parbol->derecha->elemento){
            parbol = parbol->derecha;
        }else{
            ultimo = desapilar(pila);
            cout<<ultimo<<" ";
            
            parbol = nullptr;
        }
            
        if(esPilaVacia(pila)) break;
    }
    
}

void preOrdenIterativa(struct ArbolBinarioBusqueda arbol){
    if(esArbolVacio(arbol)) return;
    Pila pila;
    construir(pila);
    NodoArbol *parbol = arbol.arbolBinario.raiz;
    apilar(pila,parbol->elemento);
    while(!esPilaVacia(pila)){
        int elemento = desapilar(pila);
        NodoArbol * nodo = busca(arbol.arbolBinario.raiz,elemento);
        cout <<nodo->elemento<<"  ";
        
        if(nodo->derecha!=nullptr){
            apilar(pila,nodo->derecha->elemento);
        }
        if(nodo->izquierda !=nullptr){
            apilar(pila,nodo->izquierda->elemento);
        }
    }
    
}

void enOrdenItertivo(struct ArbolBinarioBusqueda& arbol){
    
    if (esArbolVacio(arbol)) return;

    Pila stack;
    construir(stack);
    NodoArbol* parbol = arbol.arbolBinario.raiz;

    while (!esPilaVacia(stack) || parbol != nullptr) {
        // Alcanzar el nodo más a la izquierda del nodo actual
        while (parbol != nullptr) {
            apilar(stack, parbol->elemento);
            parbol = parbol->izquierda;
        }
        
        // parbol debe ser NULL en este punto
        int elemento = desapilar(stack);
        parbol = busca(arbol.arbolBinario.raiz, elemento);
        
        // Procesar el nodo
        cout << parbol->elemento << " ";
        
        // Visitar el subárbol derecho
        parbol = parbol->derecha;
    }

}
 

NodoArbol* encontrarMinimo(NodoArbol* nodo) {
    while (nodo->izquierda != nullptr) {
        nodo = nodo->izquierda;
    }
    return nodo;
}

// Función para eliminar un nodo con un elemento específico
NodoArbol* eliminarNodo(NodoArbol* raiz, int elemento) {
    if (raiz == nullptr) return raiz;

    if (elemento < raiz->elemento) {
        raiz->izquierda = eliminarNodo(raiz->izquierda, elemento);
    } else if (elemento > raiz->elemento) {
        raiz->derecha = eliminarNodo(raiz->derecha, elemento);
    } else {
        // Nodo encontrado
        if (raiz->izquierda == nullptr) {
            NodoArbol* temp = raiz->derecha;
            delete raiz;
            return temp;
        } else if (raiz->derecha == nullptr) {
            NodoArbol* temp = raiz->izquierda;
            delete raiz;
            return temp;
        }

        // Nodo con dos hijos: obtener el sucesor inorden
        NodoArbol* temp = encontrarMinimo(raiz->derecha);
        raiz->elemento = temp->elemento;
        raiz->derecha = eliminarNodo(raiz->derecha, temp->elemento);
    }
    return raiz;
}

void imprimirArbol(struct NodoArbol * pR, int nivel = 0) {
    // Verificar si el nodo es nulo, en ese caso no hay nada que imprimir y se retorna
    if (pR == NULL)
        return;

    // Imprimir el sub rbol derecho, incrementando el nivel en 1
    imprimirArbol(pR->derecha, nivel + 1);

    // Imprimir espacios en blanco para indentar el nodo actual seg n su nivel
    for (int i = 0; i < nivel; i++)
        cout << "    ";
    
    // Imprimir el elemento del nodo actual
    cout << pR->elemento << endl;

    // Imprimir el sub rbol izquierdo, incrementando el nivel en 1
    imprimirArbol(pR->izquierda, nivel + 1);
}

void recorrePorAmplitud(struct NodoArbol * raiz,int nivel){
    if(raiz == nullptr) return;
    if(nivel == 0){
        imprimeNodo(raiz);
    }else if(nivel>0){
        recorrePorAmplitud(raiz->izquierda,nivel-1);
        recorrePorAmplitud(raiz->derecha,nivel-1);
    }
}

void porAmplitudRecursivo(struct ArbolBinario &arbol){
    if(esArbolVacio(arbol))return;
    int alto = altura(arbol);
    for(int nivel = 0; nivel<=alto;nivel++){
        recorrePorAmplitud(arbol.raiz,nivel);
    }
//    cout<<endl;
//    for(int nivel = alto; 0<=nivel ;nivel--){
//        recorrePorAmplitud(arbol.raiz,nivel);
//    }
}


void postOrdenIterativaEliminar(struct ArbolBinarioBusqueda arbol,int dato){
    NodoArbol * parbol;
    int alto,ultimo=0;
    Pila pila;
    if(esArbolVacio(arbol)) return ;
    construir(pila);
    parbol = arbol.arbolBinario.raiz;
    
    while(1){
        while(parbol !=nullptr){
            apilar(pila,parbol->elemento);
            parbol = parbol->izquierda;
        }
        alto = cima(pila);
        parbol = busca(arbol.arbolBinario.raiz,alto);
        //esto es si es que el ultimo raiz izquierdo no tiene hijos izquierdos pero si tiene el derecho
        if(parbol->derecha != nullptr and ultimo !=parbol->derecha->elemento){
            parbol = parbol->derecha;
        }else{
            ultimo = desapilar(pila);
            //cout<<ultimo<<" ";
            if(ultimo== dato){
                eliminarNodo(arbol,dato);
                break;
            }
            parbol = nullptr;
        }
            
        if(esPilaVacia(pila)) break;
    }
    
}



int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol,arbol2;
    construir(arbol);
    insertar(arbol,3);
    insertar(arbol,1);
    insertar(arbol,2);
    insertar(arbol,5);
    insertar(arbol,8);
    insertar(arbol,12);
    insertar(arbol,18);
    
//    preOrden(arbol);
//    //aca estoy balanceando el arbol sin tocar las raiz
//    arbol.arbolBinario.raiz=balancearArbolToken(arbol.arbolBinario.raiz);
    
//    cout<<endl<<"Balanceo:"<<endl;
//    imprimirArbol(arbol.arbolBinario.raiz);cout<<endl;
//    preOrden(arbol);cout<<endl;
//    cout<<"POST- ORDEN: ";
//    postOrden(arbol);
//    cout<<endl<<endl;
    
    //ahora vamos a sumar arboles solo los nodos especificos:
    construir(arbol2);
    insertar(arbol2,2);
    insertar(arbol2,1);
    insertar(arbol2,4);
    insertar(arbol2,5);
//    preOrden(arbol2);
    
//    
//    sumaArboles(arbol.arbolBinario.raiz,arbol2.arbolBinario.raiz);
//    cout<<endl;
//    preOrden(arbol);cout<<endl;
    
    struct ArbolBinarioBusqueda arbol5;
    construir(arbol5);
    insertar(arbol5, 100);
    insertar(arbol5, 50);
    insertar(arbol5, 150);
    insertar(arbol5, 125);
    insertar(arbol5, 175);
    insertar(arbol5, 200);
    insertar(arbol5, 25);
    insertar(arbol5, 75);
    cout<<endl;
    
    
//    postOrdenIterativa(arbol5);cout<<endl;
//    preOrdenIterativa(arbol5);cout<<endl;
//    enOrdenItertivo(arbol5 );cout<<endl;
//    cout<<"Amplitud: "<<endl;
//    porAmplitudRecursivo(arbol5.arbolBinario);cout<<endl;
//    cout<<"Altura: "<<calcularAltura(arbol5.arbolBinario.raiz);
//    //cout<<endl<<"Altura2: "<<calcularAltura(arbol5.arbolBinario.raiz->derecha->izquierda);
//    //arbol5.arbolBinario.raiz = eliminarNodo(arbol5.arbolBinario.raiz,50);
////    arbol5.arbolBinario.raiz = eliminarNodoRecursivo(arbol5.arbolBinario.raiz,50);
//    //preOrden(arbol5);
    postOrden(arbol5);
    cout<<endl;
    postOrdenIterativaEliminar(arbol5,125);
    postOrden(arbol5);
    
    
    return 0;
}
