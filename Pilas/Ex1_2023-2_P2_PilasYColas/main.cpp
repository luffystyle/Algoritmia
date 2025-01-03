
//EXAMEN 1 - 2023-2
#include <iostream>
using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "Cola.h"
#include "Pila.h"

#include "funcionesCola.h"
#include "funcionesLista.h"
#include "funcionesPila.h"
#include "funcionesAuxiliares.h"


int main(int argc, char** argv) {

    struct Cola cola;
    struct Pila pila1, pila2;
    construir(cola);
    construir(pila1);
    construir(pila2);
    
    encolar(cola, 206);
    encolar(cola, 107);
    encolar(cola, 208);
    encolar(cola, 109);
    encolar(cola, 210);
    encolar(cola, 211);
    encolar(cola, 112);
    encolar(cola, 113);
    
    apilar(pila1, 101);
    apilar(pila1, 120);
    apilar(pila1, 115);
    apilar(pila1, 104);
    apilar(pila1, 130);
    apilar(pila1, 119);
    
//    apilar(pila2, 203);
//    apilar(pila2, 204);
    
    ordenarPila(pila1, pila2);
    imprimir(pila1);
    
//    cout << "INICIAL: " << endl;
//    imprimirResultados(cola, pila1, pila2);
//    
//    reinicia_cola(cola, pila1, pila2, cola.lista.longitud);
//    cout << "REINICIA COLA: "<<endl;
//    imprimirResultados(cola, pila1, pila2);
//    
//    reclasifica_pilas(pila1, pila2);
//    cout << "RECLASIFICA PILAS: "<<endl;
//    imprimirResultados(cola, pila1, pila2);

    
    return 0;
}

