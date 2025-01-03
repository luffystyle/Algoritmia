/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * CodigoÑ 20175525
 * Created on October 16, 2024, 7:50 PM
 */

#include <iostream>
#include <cstring>
using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "funcionesLista.h"
#include "funcionesCola.h"




//void encolarConPrioridad(Cola &cola, int codigo, int prioridad ) {
//    
////    Nodo *nodo;
//    Nodo *nuevoNodo;
//    Nodo *ptrAux; //Puntero aux
//    
//    //Creando el Nodo
////    nodo->codigo = codigo;
////    nodo->prioridad = prioridad;
//    
//    nuevoNodo = crearNodo(prioridad, codigo, nullptr);
//    if(esColaVacia(cola) || prioridad < cola.lista.cabeza->prioridad) { // Si la prioridad nueva es menor que la prioridad de la cabeza
//        // En este caso la prioridad si sirve, porque la que tiene menor es de mayor jerarquia
//        // Como es menor y el siguiente que viene por logica ya viene con un codigo mayor, ese va detras de la cabeza si o si
//        nuevoNodo->siguiente = cola.lista.cabeza; 
//        cola.lista.cabeza = nuevoNodo;
//        
//        if(esColaVacia(cola)) cola.lista.cola = nuevoNodo;
//        cola.lista.longitud++;
//        return;
//    }
//    
//    ptrAux = cola.lista.cabeza;
//    while(ptrAux->siguiente != nullptr && ptrAux->siguiente->prioridad <= prioridad) {
//        ptrAux = ptrAux->siguiente;
//    }
//    
//    nuevoNodo->siguiente = ptrAux->siguiente;
//    ptrAux->siguiente = nuevoNodo;
//    
//    if(nuevoNodo->siguiente == nullptr) cola.lista.cola = nuevoNodo;
//    cola.lista.longitud++;
//}



void encolarConPrioridad(Cola &cola, int codigo, int prioridad ) {
    
    
    Nodo *nuevoNodo = crearNodo(prioridad, codigo, nullptr);
    
    if(esColaVacia(cola)) {
        cola.lista.cabeza = nuevoNodo;
        cola.lista.cola = nuevoNodo;
        
    } else {
        // Al principio o caso haya un solo elemento
        Nodo *actual = cola.lista.cabeza;
        Nodo *anterior = nullptr;
        //Aqui recien vcoyn recorriendo
        // Cuando esto sea falso, ahi guardo. Solo estoy encontrando la posicion
        // 3 condiciones
        // 1) hasta que no haya mas nodo por recorrer
        while( actual != nullptr  ) {
            if(actual->prioridad > prioridad) { // Si el nuevo nodo tiene prioridad de menos jerarquia, seguimos avanzando
                anterior = actual;
                actual = actual->siguiente;
            } else if( actual->prioridad == prioridad){
                if(codigo <= actual->codigo) { // SIGO AVANZANDO
                    anterior = actual;
                    actual = actual->siguiente;
                } else { // Si es mayor 
                    break;
                }
            } else {
                break;
            }
        }
        
        //Insertar al inicio
        if(anterior == nullptr) { //En caso haya uno solo y el nodo nuevo tenga mayor o igual valor de su prioridad
           // por ejemplo, si tenemos un nodo con 1 prioridad y entra otro nodo con 1 prioridad. Ahi el anterior es nullptr
            nuevoNodo->siguiente = cola.lista.cabeza;
            cola.lista.cabeza = nuevoNodo;
        } else { // Insertar al medio o final
            anterior->siguiente = nuevoNodo;  
            nuevoNodo->siguiente = actual;
                      
        }
        if(actual == nullptr) { // Solo actualizamlo la cola
            cola.lista.cola = nuevoNodo;
        }
    }
    cola.lista.longitud++;
}



int main(int argc, char** argv) {

    Cola C1;
    construir(C1);

    encolarConPrioridad(C1, 1, 2);
    encolarConPrioridad(C1, 2, 1);
    encolarConPrioridad(C1, 3, 1);
    encolarConPrioridad(C1, 4, 3);
    encolarConPrioridad(C1, 5, 2);
    encolarConPrioridad(C1, 6, 3);
    encolarConPrioridad(C1, 7, 1);
    

    
    imprime(C1);
    
    return 0;
}

