/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525or: miguel
 *
 * Created on October 12, 2024, 8:01 AM
 */

//Problema 2

#include <iostream>
#include <fstream>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "funciones.h"



void cargarDatosLista(Lista &L1, Pedido ped) { //Dice que recibre el pedido
    insertarAlFinal(L1, ped);
    
}


void ordenarLista(Lista &L1) {
    Nodo *cabeza;
    cabeza = L1.cabeza;

    
    Nodo * recorrido = L1.cabeza;
    int maximo;
    int unidades;
    maximo = (recorrido->pedido.tPreparacion + recorrido->pedido.tViaje)%10; // guardo el maximo
    while(!esListaVacia(L1)) {
        unidades = (recorrido->pedido.tPreparacion + recorrido->pedido.tViaje)%10;
        
        recorrido = recorrido->siguiente;
    }

    
    Nodo * recorrido = cabeza; // vuelvo a la cabeza
    int maximo;
    int decenas;
    maximo = (recorrido->pedido.tPreparacion + recorrido->pedido.tViaje)%10; // guardo el maximo
    while(!esListaVacia(L1)) {
        decenas = (recorrido->pedido.tPreparacion + recorrido->pedido.tViaje)%10;
        
        recorrido = recorrido->siguiente;
    }
}


int main(int argc, char** argv) {

    
    
    ifstream arch("Datos.txt", ios::in);
    if(!arch) {
        cout << "El archivo Datos.txt no se pudo abrir" << endl;
        exit(1);
    }
    
    Pedido pedido;
    char c, complejidad;
    double distancia;
    int hPunta, disponibilidad;
    Lista  L1;
    construir(L1);
    
    
    
    while(true) {
        arch.getline(pedido.cadena, 5, ',');
        if(arch.eof()) break;
        arch >> complejidad >>c >> disponibilidad>> c>>distancia >> c >> hPunta;
        arch.get();
        if( complejidad == 'b') {
            pedido.tPreparacion = 10;
        } else if (complejidad == 'm') {
            pedido.tPreparacion = 20;
        } else {
            pedido.tPreparacion = 30;
        }
                
        if(disponibilidad == 0) {
            pedido.tPreparacion += 5;
        } 
        pedido.tViaje = (distancia/45)*60;
        if(hPunta == 1) {
            pedido.tViaje += 10;
        }
        
        cargarDatosLista(L1, pedido);
        
    }
    imprime(L1);
    ordenarLista(L1);
    
    destruir(L1);
    
    
    return 0;
}

