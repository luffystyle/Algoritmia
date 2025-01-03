
#include <iostream>
#include <iomanip>

using namespace std;

struct NodoArbol {
    int elemento;
    int cantidad;
    struct NodoArbol *izquierda;
    struct NodoArbol *derecha;
};


// el arbol solo contiene a la raiz
struct ArboBinario {
    struct NodoArbol *raiz;
};

struct Nodo{
    struct NodoArbol *nodo;// aqui se manda el Elemento que se desea manejar
    struct Nodo *siguiente;
};

struct Lista{ // La lista es como una estructura mayor. Y la Cola y Pila son particularidades
    struct Nodo *cabeza;
    struct Nodo *cola;
    int longitud;
};

struct Cola {
    struct Lista lista;
};

struct Pila {
    struct Lista lista;
};

void construir(struct Lista &lista) {
    lista.cabeza = NULL; 
    lista.cola = NULL;
    lista.longitud= 0;
}

bool esListaVacia(struct Lista lista) {
    return lista.cabeza == NULL;
}

int longitud(struct Lista tad) {
    return tad.longitud;
}

struct Nodo * crearNodo(struct NodoArbol *nodo, struct Nodo* siguiente) {
    struct Nodo *nuevoNodo = new struct Nodo;
    nuevoNodo->nodo = nodo;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

void insertarAlFinal(struct Lista &lista, struct NodoArbol * nodo) {
    struct Nodo *nuevoNodo = crearNodo(nodo, NULL);
    Nodo *ultimoNodo = lista.cola;
    if( ultimoNodo == NULL) {
        lista.cabeza = nuevoNodo;
        lista.cola = nuevoNodo;
    } else {
        ultimoNodo->siguiente = nuevoNodo;
        lista.cola = nuevoNodo;
    }
    lista.longitud++;
}













int main(int argc, char** argv) {








    return 0;
}

