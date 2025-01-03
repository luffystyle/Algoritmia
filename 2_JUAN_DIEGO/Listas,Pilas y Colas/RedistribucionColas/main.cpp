/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Cola.h"
#include "Pila.h"

using namespace std;
#include "funcionesCola.h"
#include "funcionesPila.h"
/*
 * IMPLEMENTACIÓN DE UNA COLA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */
void distribucion(struct Cola & cola, int cantidad_elementos){
    int i, valor;
    int longitud_lote=cantidad_elementos/3;
    Pila pila_aux;
    construir(pila_aux);
    
    cout<<"Desencolamos y encolamos A y B"<<endl;
    for (i=0; i<longitud_lote*2;i++){
        encolar(cola, desencolar(cola));
    }
    imprime(cola);
    
    cout<<"Desencolamos C y los perdemos"<<endl;
    for (i=0; i<longitud_lote;i++){
        valor=desencolar(cola);
    }
    imprime(cola);
    
    cout<<"Desencolar A y apilarlos"<<endl;
    for (i=0; i<longitud_lote;i++){
        apilar(pila_aux,desencolar(cola));
    }
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila: ";
    imprimir(pila_aux);
    
    cout<<"Desapilamos A y encolamos"<<endl;
    for (i=0; i<longitud_lote;i++){
        encolar(cola,desapilar(pila_aux));
    }
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila: ";
    imprimir(pila_aux);
    
    cout<<"Desencolamos B y apilamos"<<endl;
    for (i=0; i<longitud_lote;i++){
        apilar(pila_aux,desencolar(cola));
    }
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila: ";
    imprimir(pila_aux);
    
    
    cout<<"Desapilamos 1 de B y lo encolamos Y desencolamos 1 de A y encolamos"<<endl;
    for (i=0; i<longitud_lote;i++){
        encolar(cola,desapilar(pila_aux));
        encolar(cola,desencolar(cola));
    }
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila: ";
    imprimir(pila_aux);
    
    cout<<"Desencolamos A y B y apilamos"<<endl;
    for (i=0; i<longitud_lote*2;i++){
        apilar(pila_aux,desencolar(cola));
    }
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila: ";
    imprimir(pila_aux);
    
    cout<<"Desapilamos A y B y encolamos"<<endl;
    for (i=0; i<longitud_lote*2;i++){
        encolar(cola,desapilar(pila_aux));
    }
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila: ";
    imprimir(pila_aux);
    
}
int main(int argc, char** argv) {
    struct Cola cola;
    construir(cola);
    cout<<"La cola está vacía: "<<esColaVacia(cola)<<endl;
    encolar(cola, 11);//A1
    encolar(cola, 12);//A2
    encolar(cola, 13);//A3
    encolar(cola, 14);//A4
    encolar(cola, 21);//B1
    encolar(cola, 22);//B2
    encolar(cola, 23);//B3
    encolar(cola, 24);//B4
    encolar(cola, 31);//C1
    encolar(cola, 32);//C2
    encolar(cola, 33);//C3
    encolar(cola, 34);//C4
    
    cout<<"Cola Original:"<<endl;
    imprime(cola);
    
    distribucion(cola, 12);
    cout<<"Nueva Cola:"<<endl;
    imprime(cola);
    return 0;
}

