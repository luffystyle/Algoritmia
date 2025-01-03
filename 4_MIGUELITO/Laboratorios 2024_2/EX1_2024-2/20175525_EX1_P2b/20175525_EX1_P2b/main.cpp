
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 19 de octubre de 2024, 08:09 AM
 */

#include <iostream>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Cliente.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
#include "funciones.h"
#include "funcionesCliente.h"
#include "Cola.h"


//void encolarConPrioridad(Cola &C1, Cliente cli, int &vipAte, int &vipNo) {
//    
//    Nodo *nuevoNodo = crearNodo(cli, nullptr);
//    
//    
//    
//    if(esColaVacia(C1)) {
////       if(cli.prioridad == 1) { // es VIP
////            vipAte++; // NO encolo, solo aumento
////        } 
//        C1.lista.cabeza = nuevoNodo;
//        C1.lista.cola = nuevoNodo;
//        if(cli.prioridad == 1) {
//            C1.lista.colaVIP = nuevoNodo;
//            vipAte++;
//        }
//       
//    } else {
//        if(cli.prioridad == 1) { // es VIP
////            if(C1.lista.colaVIP->cliente.horaLlegada + 20 > nuevoNodo->cliente.horaLlegada) {
////                
////            }
//            if(C1.lista.colaVIP == nullptr) { // puros No vips, en este caso
//                nuevoNodo->siguiente = C1.lista.cabeza;
//                C1.lista.cabeza = nuevoNodo;
//                C1.lista.colaVIP = nuevoNodo;
//            } else {
//                if(C1.lista.colaVIP->siguiente == nullptr)
//                    C1.lista.cola = nuevoNodo;
//                nuevoNodo->siguiente = C1.lista.colaVIP->siguiente;
//                C1.lista.colaVIP->siguiente = nuevoNodo;
//                C1.lista.colaVIP = nuevoNodo;
//            }
//            vipAte++;
//            
//        }else { // NO es vip
//            C1.lista.cola->siguiente = nuevoNodo;
//            C1.lista.cola = nuevoNodo;
//        }
//    }
//    
//    C1.lista.longitud++;
//    
//    
//}




int main(int argc, char** argv) {

    Cola C1;
    construir(C1);
    
//    Cliente cli1 = {15, 35, 2};
//    Cliente cli2 = {30, 55, 1};
//    Cliente cli3 = {45, 35, 2};
//    Cliente cli4 = {60, 35, 1};
//    Cliente cli5 = {75, 35, 2};
//    Cliente cli6 = {90, 35, 1};
    
//    encolarConPrioridad(C1, cli1);
//    encolarConPrioridad(C1, cli2);
//    encolarConPrioridad(C1, cli3);
//    encolarConPrioridad(C1, cli4);
//    encolarConPrioridad(C1, cli5);
//    encolarConPrioridad(C1, cli6);
//    
    
    
//    int vipAtendidos = 0, vipNoAtendidos = 0;
    //encolarConPrioridad(C1, cli1, vipAtendidos, vipNoAtendidos);
    
    simulacionDeColas(C1);
    
//    imprime(C1);
    
    return 0;
}

