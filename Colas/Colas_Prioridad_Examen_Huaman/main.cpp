
#include <iostream>

using namespace std;
#include "funciones.h"
#include "funcionesPila.h"

void ordenaColaRecursiva(Cola &pC, int n) {
    
    int i = 1, menor, aux;
    if(esColaVacia(pC)) return;
    menor = desencolar(pC);
    
    while( i<n ) {
        aux = desencolar(pC);
        if( aux < menor ) {
            encolar(pC, menor);
            menor = aux;
        } else {
            encolar(pC, aux);            
        }
        i++;        
    }
    ordenaColaRecursiva(pC, n-1);
    encolar(pC, menor);
}

void eliminarFallaTipoC(Cola &pC) {
    NodoC *p;
    p = pC.frente;
    for( int i = 1; i<=pC.longitud; i++) {
        if( p->elem > 30) {
            p = p->sig; 
            desencolar(pC);// la hacer el desencolar elimino el p, por eso que se elimina la referencia
        }
    }
}


void solucion(Cola &pC) {
    //NodoC *p;
    //p = pC.frente; // esta es la cabeza
    eliminarFallaTipoC(pC);
    cout << "Despues :" << endl;
    mostrar(pC);
    Pila P; // esta es mi pila auxiliar
    construir(P);
    //cout << "long es " << obtenerLongitud(pC) << endl;
    //Desencolamos Tipo B y luego apilamos
    int long_Lote = obtenerLongitud(pC)/2; // lo guardo en una variable
    for(int i = 0; i<long_Lote ; i++) {
        apilar(P, desencolar(pC)); // solo apilamos, lo que hemos desconlado
    }

    // Encolamos lo que tenemos apilado
    for(int i = 0; i<long_Lote; i++){
        encolar(pC, desapilar(P));
    }
    
    // Apilamos los tipo A, usando el desancolamiento
    for( int i = 0; i<long_Lote; i++) {
        apilar(P, desencolar(pC));
    }

    // Combinamos, primero Apilamos inmediatamente desencolas y encolas
    for( int i = 0; i<long_Lote; i++) {
        encolar(pC, desapilar(P));
        encolar(pC, desencolar(pC));
    }
    
}


int main(int argc, char** argv) {

    Cola C;
    construir(&C);
    // asumimos que  C es 3, B es 2, A es 1
    encolar(C, 34);
    encolar(C, 33);
    encolar(C, 32);
    encolar(C, 31);
    encolar(C, 24);
    encolar(C, 23);
    encolar(C, 22);
    encolar(C, 21);
    encolar(C, 14);
    encolar(C, 13);
    encolar(C, 12);
    encolar(C, 11);
    cout << C.longitud << endl;
    mostrar(C);    
    
    
    solucion(C);    
    mostrar(C);  
    
    

    
    return 0;
}

