/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 7 de diciembre de 2024, 08:42 AM
 */

// PREGUNTA 2b
#include <iostream>
#include "ArbolB.h"
#include "funcionesAB.h"
#include "ArbolBB.h"
#include "funcionesABB.h"

using namespace std;


struct NodoArbol * crearNuevoNodoNew(struct NodoArbol * izquierda, int elemento, char caracter,
        struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nuevo->caracter = caracter;
    return nuevo;
}

void plantarArbolBinarioNew(struct NodoArbol *& raiz, 
                    struct NodoArbol * izquierda, int elemento, char caracter,
                    struct NodoArbol * derecha){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoNew(izquierda, elemento, caracter, derecha);
    raiz = nuevoNodo;
}

void insertarRecursivoNew(struct NodoArbol *& raiz, int elemento, char caracter){
    if(esNodoVacio(raiz))
        plantarArbolBinarioNew(raiz, nullptr, elemento, caracter, nullptr);
    else
        if(raiz->elemento > elemento)
            insertarRecursivoNew(raiz->izquierda,  elemento, caracter);
        else
            if(raiz->elemento < elemento)
                insertarRecursivoNew(raiz->derecha, elemento, caracter);
            else
                cout << "El elemento " << elemento << "Ya se encuentra en el árbol" << endl;
}

void insertarNew(struct ArbolBinarioBusqueda & arbol, int elemento, char caracter){
    insertarRecursivoNew(arbol.arbolBinario.raiz, elemento, caracter);
}



int buscarNewRecursivo(struct NodoArbol * nodo, int valor, char caracter){
    if(esNodoVacio(nodo)) return -1;
    if(nodo->elemento == valor) {
        if(nodo->caracter == caracter) 
            return 1;
        else return -1;
    }
    if(nodo->elemento < valor)
        return buscarNewRecursivo(nodo->derecha, valor, caracter);
    else if(nodo->elemento > valor)
        return buscarNewRecursivo(nodo->izquierda, valor, caracter);
}
int buscarNew(const struct ArbolBinario & arbol, int valor, char caracter){
    return buscarNewRecursivo(arbol.raiz, valor, caracter);
}



int main(int argc, char** argv) {

    ArbolBinarioBusqueda abb;
    construir(abb);
    
    insertarNew(abb, 4, 'P');
    insertarNew(abb, 2, 'U');
    insertarNew(abb, 6, '0');
    insertarNew(abb, 1, 'P');
    insertarNew(abb, 3, 'C');
    insertarNew(abb, 5, '2');
    insertarNew(abb, 7, '2');
    insertarNew(abb, 8, '4');
    
    recorrerEnOrden(abb.arbolBinario); cout << endl;
    
    int intentos;
    cout << "Ingrese el numero de maximo de intentos: ";
    cin >> intentos;
    cout << endl;
    int i = 0;
    int longipalabra = 0;
    string cadena;
    
    while(true) {
        cout << "Intento " << i+1 << "/" << intentos << endl;
        cout << "Ingresela contraseña: " ;
        cin >> cadena;
        longipalabra = 0;
        while(true) {
            if(!cadena[longipalabra]) break;
            longipalabra++; // hallar la longitud de la cadena
        }
        
        
        if(longipalabra == numeroNodos(abb.arbolBinario)) {
            int corrector = 0;
            for(int k= 0; k<longipalabra; k++) {
                if(buscarNew(abb.arbolBinario, k+1, cadena[k]) == 1) {
                    corrector++;
                } else{
                    cout << "Intento Fallido." << endl;
                    break;
                }
            }
            if(corrector == longipalabra) {
                cout << "Acceso concedido." << endl;
                break;
            }
        } else {
            cout << "Longitud incorrecta. Intento fallido." << endl;
        }

        if(intentos < i) {
            cout << "Se llegó al número de intentos fallidos permitidos." << endl;
            break;
        }

        i++;
    }
    
    return 0;
}

