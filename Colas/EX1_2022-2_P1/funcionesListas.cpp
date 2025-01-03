
#include <iostream>
using namespace std;
#include "funcionesListas.h"

void construir(Lista &pL) {
    pL.cabeza = NULL;
    pL.longitud = 0;
}

bool esListaVacia( Lista L) {
    return L.cabeza == NULL;
}

int obtenerLongitud( Lista L) {
    return L.longitud;
}

Nodo* crearNodo(Elemento e, Nodo* s) {
    Nodo* p = new Nodo;
    p->elem = e;
    p->sig = s;
    return p;
}

void insertarAlComienzo(Lista &pL, Elemento e) {
    Nodo* p = crearNodo(e, pL.cabeza);
    pL.cabeza = p;
    pL.longitud++;
}

void mostrar( Lista L) {
    Nodo* p;
    int i;
    if (esListaVacia(L)) {
        cout << "Lista vacia" << endl;
    } else {
        p = L.cabeza;
        for (i = 1; i <= L.longitud; i++) {
            cout << p->elem << "  ";
            p = p->sig;
        }
        cout << endl;
    }
}

Nodo* ubicarUltimo( Lista L ) {
    int i;
    Nodo *pU;
    if (esListaVacia(L)) return NULL;
    else {
        pU = L.cabeza;
        for(i=1;i<=L.longitud-1;i++)
            pU = pU->sig;
        return pU;
    }
}


void insertarAlFinal(Lista &pL, Elemento e) {
    Nodo* p = crearNodo(e, NULL);
    if (esListaVacia(pL)) {
        pL.cabeza = p;
    } else {
        Nodo* pU = ubicarUltimo(pL);
        pU->sig = p;
    }
    pL.longitud++;
}

Nodo* ubicarAnterior(Lista L, Elemento e) {
    Nodo* p = L.cabeza;
    Nodo* pA = NULL;
    for (int i = 1; i <= L.longitud; i++) {
        if (p->elem == e) {
            return pA;
        }
        pA = p;
        p = p->sig;
    }
    return NULL;
}

Nodo* ubicar(Lista L, Elemento e) {
    Nodo* p = L.cabeza;
    for (int i = 1; i <= L.longitud; i++) {
        if (p->elem == e) {
            return p;
        }
        p = p->sig;
    }
    return NULL;
}

void eliminar(Lista &pL, Elemento e) {
    Nodo* p = ubicar(pL, e);
    if (p == NULL) {
        cout << "No es posible eliminar un dato inexistente" << endl;
    } else {
        Nodo* pA = ubicarAnterior(pL, e);
        if (pA == NULL) {  // se elimina primer Nodo
            pL.cabeza = p->sig;
        } else {
            pA->sig = p->sig;
        }
        pL.longitud--;
        delete p;
    }
}

void destruir(Lista &pL) {
    Nodo* p = pL.cabeza;
    while (p) {
        Nodo* q = p->sig;
        delete p;
        p = q;
    }
    pL.cabeza = NULL;
    pL.longitud = 0;
    cout << "La lista ha sido destruida" << endl;
}