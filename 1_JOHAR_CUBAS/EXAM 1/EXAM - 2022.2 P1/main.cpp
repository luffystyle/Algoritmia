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

void fusionar(struct Lista &l1, struct Lista &l2 ){
    
    if(l1.cola->elemento < l2.cabeza->elemento){
        l1.cola->siguiente = l2.cabeza;
        l1.cola = l2.cola;
    }else{
        if(l2.cola->elemento < l1.cabeza->elemento){
            l2.cola->siguiente= l1.cabeza;
            l1.cabeza = l2.cabeza;
        }else{
            Nodo* inicio = nullptr;
            Nodo* fin = nullptr;
            while(!esListaVacia(l1) and !esListaVacia(l2)){
                if(l1.cabeza->elemento <= l2.cabeza->elemento){
                    if(inicio ==nullptr){
                        inicio = l1.cabeza;
                        fin = l1.cabeza;
                    }else{
                        fin->siguiente = l1.cabeza;
                        fin = l1.cabeza;
                    }
                    l1.cabeza = l1.cabeza->siguiente;
                }else{
                    if(inicio ==nullptr){
                        inicio = l2.cabeza;
                        fin = l2.cabeza;
                    }else{
                        fin->siguiente = l2.cabeza;
                        fin = l2.cabeza;
                    }
                    l2.cabeza = l2.cabeza->siguiente;
                } 
            }
            if(!esListaVacia(l1)){
                fin->siguiente = l1.cabeza;
                fin = l1.cola;
            }
            if(!esListaVacia(l2)){
                fin->siguiente = l2.cabeza;
                fin = l2.cola;
            }
            l1.cabeza = inicio;
            l1.cola = fin;
        }
        
        
    }
    
    
    
}


int main(int argc, char** argv) {
    
    struct Lista lunes,martes,miercoles,jueves,viernes;
    construir(lunes);
    construir(martes);
    construir(miercoles);
    construir(jueves);
    construir(viernes);
    
    insertarAlFinal(lunes,8,6,'L');
    insertarAlFinal(lunes,10,14,'L');
    insertarAlFinal(lunes,12,1,'L');
    
    insertarAlFinal(martes,9,3,'M');
    insertarAlFinal(martes,11,8,'M');
    
    insertarAlFinal(miercoles,8,2,'m');
    insertarAlFinal(miercoles,9,5,'m');
    insertarAlFinal(miercoles,10,10,'m');
    
    insertarAlFinal(jueves,14,13,'J');
    insertarAlFinal(jueves,15,9,'J');
    insertarAlFinal(jueves,16,11,'J');

    insertarAlFinal(viernes,17,4,'V');
    insertarAlFinal(viernes,18,12,'V');
    insertarAlFinal(viernes,19,7,'V');
        
    fusionar(lunes,martes);
    fusionar(lunes,miercoles);
    fusionar(lunes,jueves);
    fusionar(lunes,viernes);
    imprime(lunes);

    
    return 0;
}













































