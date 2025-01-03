/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on September 30, 2024, 8:19 PM
 */

#include <iostream>

using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "Lista.h"
#include "funcionesLista.h"


void reorganizar(Lista &lista1, Lista &lista2) {
    
    
    // Primer caso: Cuando todos los elementos de la lista 1 son mayores que la lista 2. Complejidad O(1)
    if(lista1.cola->elemento >= lista2.cabeza->elemento) {
        lista1.cola->siguiente = lista2.cabeza; // la cola ya no apunta a nullptr, sino al primer nodo de la lista2
        lista1.longitud += lista2.longitud; // aumento la longitud
        lista1.cola = lista2.cola; // actualizo la cola
    } else { 
        if(lista2.cola->elemento > lista1.cabeza->elemento) {  // Segundo Caso: Cuando todos los elementos de la lista2 son mayores que la lista 1. Complejidad O(1)
            lista2.cola->siguiente = lista1.cabeza;
            lista1.longitud += lista2.longitud;
            lista1.cabeza = lista2.cabeza;
        } else {
            //Terce Caso: Cuando los elementos se traslapan segun su nivel de impacto. Complejidad O(n)
            Lista listaFinal; // Aqui no estas creando espacio de memoria. Solo creas una variable auxiliar para que apunten a esas DM que necesitas.
            listaFinal.cabeza = nullptr;
            listaFinal.cola = nullptr;
            
            while((lista1.cabeza) != nullptr && (lista2.cabeza) != nullptr ) { //Vamos recorriendo los nodos de la listas. Cuando nos movemos, nuestra cabeza cambia
                // Comparo las cabezas de las dos listas
                if(lista1.cabeza->elemento >= lista2.cabeza->elemento) { // Si la cabeza de lista1 es mayor a la cabeza de Lista2
                    // Si son iguales las cabezas, doy prioridad a Lista1 segun su categoria
                    if(listaFinal.cabeza == nullptr) { // PRIMERA VEZ
                        listaFinal.cabeza = lista1.cabeza;
                        listaFinal.cola = lista1.cabeza;
                    } else {
                        listaFinal.cola->siguiente = lista1.cabeza;
                        listaFinal.cola = lista1.cabeza;
                    }
                    lista1.cabeza = lista1.cabeza->siguiente; //  Avanzamos uno
                } else { // Si la cabeza de lista1 es menor que la cabeza de la lista2
                    // Como no es menor, voy recorriendo la lista2
                    if(lista2.cabeza->elemento > lista1.cabeza->elemento) {
                        if(listaFinal.cabeza == nullptr) {
                            listaFinal.cabeza = lista2.cabeza;
                            listaFinal.cola = lista2.cabeza;
                        } else {
                            listaFinal.cola->siguiente = lista2.cabeza;
                            listaFinal.cola = lista2.cabeza;
                        }
                        lista2.cabeza = lista2.cabeza->siguiente;
                    }
                }
            }
            
            while(lista1.cabeza != nullptr) {
                if(listaFinal.cabeza == nullptr) { //Primer elemento de la lista Final
                    listaFinal.cabeza = lista1.cabeza;
                    listaFinal.cola = lista1.cola;
                } else {
                    listaFinal.cola->siguiente = lista1.cabeza;
                    listaFinal.cola = lista1.cabeza;
                }
                lista1.cabeza = lista1.cabeza->siguiente;
            }
            
            while(lista2.cabeza != nullptr) { //Ahora para la lista2
                if(listaFinal.cabeza == nullptr) { //Primer elemento de la lista Final
                    listaFinal.cabeza = lista2.cabeza;
                    listaFinal.cola = lista2.cola;
                } else {
                    listaFinal.cola->siguiente = lista2.cabeza;
                    listaFinal.cola = lista2.cabeza;
                }
                lista2.cabeza = lista2.cabeza->siguiente;
            }
            
            lista1.cabeza = listaFinal.cabeza;
            lista1.cola = listaFinal.cola;
            lista1.longitud += lista2.longitud;
        }
    }
    
}

void fusionarlista(Lista &listaA, Lista &listaB, Lista &listaC, Lista &listaD, Lista &listaE) {
    
    listaB.cola->siguiente = listaA.cabeza;
    listaA.cola->siguiente = listaC.cabeza;
    listaC.cola->siguiente = listaD.cabeza;
    listaD.cola->siguiente = listaE.cabeza;
}

void insertarDatos(Lista &listaA, Lista &listaB, Lista &listaC, Lista &listaD, Lista &listaE) {
    
    construir(listaA);
    construir(listaB);
    construir(listaC);
    construir(listaD);
    construir(listaE);
    
    insertarencola(listaA, 15);
    insertarencola(listaA, 13);
    insertarencola(listaA, 12);
    insertarencola(listaA, 11);
    
    insertarencola(listaB, 20);
    insertarencola(listaB, 19);
    
    insertarencola(listaC, 18);
    insertarencola(listaC, 17);
    insertarencola(listaC, 16);
    
    insertarencola(listaD, 17);
    insertarencola(listaD, 15);
    insertarencola(listaD, 14);
    insertarencola(listaD, 13);
    insertarencola(listaD, 12);
    
    insertarencola(listaE, 14);
    insertarencola(listaE, 12);
    insertarencola(listaE, 10);
    insertarencola(listaE, 8);
    
    imprime(listaA);
    imprime(listaB);
    imprime(listaC);
    imprime(listaD);
    imprime(listaE);
}

int main(int argc, char** argv) {

    Lista listaA, listaB, listaC, listaD, listaE;
    
    insertarDatos(listaA, listaB, listaC, listaD, listaE);
    // voy a crear una super lista
    //fusionarlista(listaA, listaB, listaC, listaD, listaE);

    cout << "Reorganizando: " << endl;
    
    reorganizar(listaA, listaB);
    reorganizar(listaA, listaC);
    reorganizar(listaA, listaD);
    reorganizar(listaA, listaE);
    
    imprime(listaA);
    //imprime(listaB);
    //ordernarLista(listaB);

    return 0;
}

