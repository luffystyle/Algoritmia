#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

struct NodoArbol{
    int elemento;  //Este dato representa el Elemento
    struct NodoArbol * izquierda;  //puntero al hijo izquierdo
    struct NodoArbol * derecha;   //puntero al hijo derecho
};


struct ArbolBinario{
    struct NodoArbol * raiz;
};

///////////////////////////
/// FUNCIONES AB INICIO ///
///////////////////////////

void construir(struct ArbolBinario & arbol ){
    arbol.raiz = NULL;
}

bool esNodoVacio(struct NodoArbol * nodo){
    return nodo == NULL;
}

bool esArbolVacio( struct ArbolBinario arbol){
    return esNodoVacio(arbol.raiz);
}

struct NodoArbol * crearNuevoNodoArbol(struct NodoArbol * arbolIzquierdo, 
                               int elemento, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct NodoArbol * arbolIzquierdo,
                         int elemento, struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo, elemento, arbolDerecho);
    arbol.raiz = nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct ArbolBinario arbolIzquierdo,
                         int elemento, struct ArbolBinario arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo.raiz, elemento, arbolDerecho.raiz);
    arbol.raiz = nuevoNodo;
}

int raiz(struct NodoArbol * nodo){
    if (esNodoVacio(nodo)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    return nodo->elemento;
}

struct NodoArbol * hijoDerecho(struct ArbolBinario arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    return arbol.raiz->derecha;
}

struct  NodoArbol * hijoIzquierdo(struct ArbolBinario arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    
    return arbol.raiz->izquierda;
 }

void imprimeNodo(struct NodoArbol * nodo){
    cout<<setw(5)<<nodo->elemento<<" ";
}

void imprimeRaiz(struct ArbolBinario arbol){
    imprimeNodo(arbol.raiz);
}

void recorrerEnOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimeNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

/*En árbol, se lleva a cabo visitando el hijo izquierdo del nodo, luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerEnOrden(struct ArbolBinario arbol){
    /*Imprime en orden*/
    if (not esArbolVacio(arbol)){
        recorrerEnOrdenRecursivo(arbol.raiz);
    }
}

void recorrerEnPreOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        imprimeNodo(nodo);
        recorrerEnPreOrdenRecursivo(nodo->izquierda);
        recorrerEnPreOrdenRecursivo(nodo->derecha);
    }
}

/*recorrido descendente, se lleva a cabo visitando cada nodo, seguido de sus hijos,
 luego todos los restantes, comenzando por la raíz*/
void recorrerPreOrden(struct ArbolBinario arbol){
    if (not esArbolVacio(arbol)){
        recorrerEnPreOrdenRecursivo(arbol.raiz);
    }
}

void recorrerEnPostOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        recorrerEnPostOrdenRecursivo(nodo->izquierda);
        recorrerEnPostOrdenRecursivo(nodo->derecha);
        imprimeNodo(nodo);
    }
}

/*recorrido ascendente, se lleva a cabo visitando los hijos, y luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerPostOrden(struct ArbolBinario arbol){
   
    if (not esArbolVacio(arbol)){
        recorrerEnPostOrdenRecursivo(arbol.raiz);
    }
}

int maximo(int a, int b){
    return a>=b ? a: b;
}

int alturaRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if(esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 0; 
    else
        return 1 + maximo( alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int altura(struct ArbolBinario arbol){
    return alturaRecursivo(arbol.raiz); //como el arbol ha sido construido no va apuntar a NULL
}

int numeroNodosRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);   
}

/*Determina el número de elementos del árbol*/
int numeroNodos(struct ArbolBinario arbol){
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if ( esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha) )
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}

int numeroHojas(struct ArbolBinario arbol){
    return numeroHojasRecursivo(arbol.raiz);
}

int esEquilibradoRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 1;
    else{
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia<=1 and 
               esEquilibradoRecursivo(nodo->izquierda) and 
               esEquilibradoRecursivo(nodo->derecha);
    }        
}

int esEquilibrado(struct ArbolBinario arbol ){
    return esEquilibradoRecursivo(arbol.raiz);
}

int esHoja(struct ArbolBinario arbol){
    if(esArbolVacio(arbol))
        return 0;
    else
        return esNodoVacio(arbol.raiz->izquierda) and esNodoVacio(arbol.raiz->derecha);
}

void destruirRecursivo(struct NodoArbol * nodo){
    if(not (esNodoVacio(nodo))){
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
        nodo = NULL;
    }
}

void destruirArbolBinario(struct ArbolBinario arbol){
    destruirRecursivo(arbol.raiz);
    arbol.raiz = NULL;
}

///////////////////////////
//// FUNCIONES AB FIN /////
///////////////////////////

int main(int argc, char** argv) {

    struct ArbolBinario arbol;
    construir(arbol);
    
    cout<<"Es árbol vacio: "<<esArbolVacio(arbol)<<endl;
    plantarArbolBinario(arbol, NULL, 100, NULL);
    imprimeRaiz(arbol); cout<<endl;
    struct ArbolBinario arbol1, arbol2, arbol3, arbol4;
    plantarArbolBinario(arbol1, NULL, 25, NULL);
    plantarArbolBinario(arbol2, NULL, 75, NULL);
    plantarArbolBinario(arbol3, arbol1, 50, arbol2);
    plantarArbolBinario(arbol4, NULL, 150, NULL);
    plantarArbolBinario(arbol, arbol3, 100, arbol4);
    cout<<"Es Árbol vacio: "<<esArbolVacio(arbol)<<endl;
    
    cout<<"Recorrer en orden: "<<endl;
    recorrerEnOrden(arbol); cout<<endl;
    cout<<"Recorrer en pre orden: "<<endl;
    recorrerPreOrden(arbol); cout<<endl;
    cout<<"Recorrer en post orden: "<<endl;
    recorrerPostOrden(arbol); cout<<endl;
    
    cout<<"ALTURA arbol: "<<altura(arbol)<<endl;
    cout<<"NÚMERO DE HOJAS: "<<numeroHojas(arbol)<<endl;
    cout<<"NÚMERO DE NODOS: "<<numeroNodos(arbol)<<endl;
    cout<<"ES EQUILIBRADO: "<<esEquilibrado(arbol)<<endl;
    
    destruirArbolBinario(arbol);
    cout<<"Es árbol vacio: "<<esArbolVacio(arbol)<<endl;
    
    return 0;
}

