/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Lista.h"
#include "Nodo.h"
#include "funcionesLista.h"

void ordernarLista(struct Lista &lista,int n){
    struct Nodo *recorrido = lista.cabeza;
    int aux_hora,aux_sucur;
    char aux_dia;
    if(esListaVacia(lista)){
        return;
    }else{
        while(recorrido!=nullptr){
            struct Nodo *siguiente=recorrido->siguiente;
            
            while(siguiente!=nullptr){
                
                if(recorrido->hora > siguiente->hora){
                    aux_hora=siguiente->hora; aux_sucur=siguiente->sucursal;
                    aux_dia = siguiente->dia;
                    siguiente->hora = recorrido->hora;
                    siguiente->sucursal = recorrido->sucursal;
                    siguiente->dia = recorrido->dia;
                    recorrido->hora = aux_hora;
                    recorrido->sucursal = aux_sucur;
                    recorrido->dia = aux_dia;
                }
                
                siguiente= siguiente->siguiente;
            }
            
            
            recorrido=recorrido->siguiente;
        }
    
        
    }
    
    
    
    
}

void fusionListas(struct Lista &lista,const struct Lista &lunes,const struct Lista &martes,
        const struct Lista &miercoles,const struct Lista &jueves,const struct Lista &viernes){
    construir(lista);

    lista = lunes;
    
    struct Nodo* ultimoNodo = obtenerUltimoNodo(lista);
    ultimoNodo->siguiente = martes.cabeza; 
    lista.longitud = lista.longitud + martes.longitud; 
    
    ultimoNodo= obtenerUltimoNodo(lista);
    ultimoNodo->siguiente = miercoles.cabeza;
    lista.longitud = lista.longitud + miercoles.longitud;
    
    ultimoNodo= obtenerUltimoNodo(lista);
    ultimoNodo->siguiente = jueves.cabeza;
    lista.longitud = lista.longitud + jueves.longitud;
    
    ultimoNodo= obtenerUltimoNodo(lista);
    ultimoNodo->siguiente = viernes.cabeza;
    lista.longitud = lista.longitud + viernes.longitud;
    
    ordernarLista(lista,lista.longitud);
    
    
}

int main(int argc, char** argv) {
    struct Lista lunes,martes,miercoles,jueves,viernes,lista;
    construir(lunes);
    insertarAlInicio(lunes,8,6,'L');
    insertarAlFinal(lunes,10,14,'L');
    insertarAlFinal(lunes,12,1,'L');
   // imprime(lunes);
    
    construir(martes);
    insertarAlInicio(martes,9,3,'M');
    insertarAlFinal(martes,11,8,'M');
    //imprime(martes);
    
    construir(miercoles);
    insertarAlInicio(miercoles,8,2,'m');
    insertarAlFinal(miercoles,9,5,'m');
    insertarAlFinal(miercoles,10,10,'m');
    //imprime(miercoles);
    
    construir(jueves);
    insertarAlInicio(jueves,14,13,'J');
    insertarAlFinal(jueves,15,9,'J');
    insertarAlFinal(jueves,16,11,'J');
    //imprime(jueves);
    
    construir(viernes);
    insertarAlInicio(viernes,17,4,'V');
    insertarAlFinal(viernes,18,12,'V');
    insertarAlFinal(viernes,19,7,'V');
    //imprime(viernes);
//    eliminaNodo(viernes,18,12,'V');
//    imprime(viernes);
    fusionListas(lista,lunes,martes,miercoles,jueves,viernes);
    imprime(lista);
    cout<<lista.longitud;
    return 0;
}

