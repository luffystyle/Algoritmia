/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <codecvt>

using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "funcionesLista.h"





//void fuisonarListasOrden(struct Lista &l1,struct Lista &l2){
//    
//    if(l1.cola->elemento < l2.cabeza->elemento ){
//        l1.cola->siguiente = l2.cabeza;
//        l1.cola = l2.cola;
//    }else{
//        if(l2.cola->elemento < l1.cabeza->elemento){
//            l2.cola->siguiente = l1.cabeza;
//            l1.cabeza = l2.cabeza;
//            l1.cola = l2.cola;
//        }else{
//            Nodo* inicio = nullptr;
//            Nodo* fin = nullptr;
//            while(!esListaVacia(l1) and !esListaVacia(l2)){
//                if(l1.cabeza->elemento <= l2.cabeza->elemento){
//                    if(inicio ==nullptr){
//                        inicio = l1.cabeza;
//                        fin = l1.cabeza;
//                    }else{
//                        fin->siguiente = l1.cabeza;
//                        fin = l1.cabeza;
//                    }
//                    l1.cabeza = l1.cabeza->siguiente;
//                }else{
//                    if(inicio ==nullptr){
//                        inicio = l2.cabeza;
//                        fin = l2.cabeza;
//                    }else{
//                        fin->siguiente = l2.cabeza;
//                        fin = l2.cabeza;
//                    }
//                    l2.cabeza = l2.cabeza->siguiente;
//                }
//            }
//            if(!esListaVacia(l1)){
//                fin->siguiente = l1.cabeza;
//                fin = l1.cola;
//            }
//            if(!esListaVacia(l2)){
//                fin->siguiente = l2.cabeza;
//                fin = l2.cola;
//            }
//            l1.cabeza = inicio;
//            l1.cola = fin;
//            
//        }
//        
//    }
//}



void ordenarListaAscendente(struct Lista &lista) {
    Nodo* recorrido = nullptr;
    Nodo* siguiente = nullptr;
    Nodo* anterior = nullptr;
    
    for (int i = 0; i < lista.longitud - 1; i++) {
        recorrido = lista.cabeza;
        siguiente = recorrido->siguiente;
        anterior = nullptr;
        
        for (int j = 0; j < lista.longitud - 1 - i; j++) {
            if (recorrido->elemento < siguiente->elemento) {
                // Intercambiar los nodos
                if (anterior != nullptr) {
                    anterior->siguiente = siguiente;
                } else {
                    lista.cabeza = siguiente;
                }
                
                recorrido->siguiente = siguiente->siguiente;
                siguiente->siguiente = recorrido;
                
                // Actualizar los punteros para continuar el recorrido
                Nodo* temp = siguiente;
                siguiente = recorrido;
                recorrido = temp;
            }
            
            // Avanzar al siguiente nodo
            anterior = recorrido;
            recorrido = siguiente;
            siguiente = siguiente->siguiente;
        }
    }
}

void ordenarDescendente(struct Lista &lista){
    struct Nodo* recorrido =nullptr;
    struct Nodo* siguiente =nullptr;
    struct Nodo* anterior =nullptr;
    
    for(int i=0;i<lista.longitud - 1; i++){
        recorrido = lista.cabeza;
        siguiente = recorrido->siguiente;
        anterior = nullptr;
        
        for(int j=0;j<lista.longitud-1-i;j++){
            if(recorrido->elemento < siguiente->elemento ){
                
                if(anterior!=nullptr){
                    anterior->siguiente = siguiente;
                }else{
                    lista.cabeza = siguiente;
                }
                recorrido->siguiente = siguiente->siguiente;
                siguiente->siguiente = recorrido;
                
                Nodo* temp = siguiente;
                siguiente = recorrido;
                recorrido = temp;
                
            }
            anterior = recorrido;
            recorrido = siguiente;
            siguiente = siguiente->siguiente;
            
        }
        
    }
}

void ordenarDescendentemete(struct Lista &lista){
    struct Nodo*recorrido =nullptr;
    struct Nodo*siguiente= nullptr;
    struct Nodo*anterior= nullptr;
    
    for(int i=0;i<lista.longitud -1;i++){
        recorrido = lista.cabeza;
        siguiente = recorrido->siguiente;
        anterior = nullptr;
        for(int j=0;j<lista.longitud -1 -i;j++){
            if(recorrido->elemento < siguiente->elemento){
                if(anterior!=nullptr){
                    anterior->siguiente = siguiente;
                }else{
                    lista.cabeza = siguiente;
                }
                recorrido->siguiente= siguiente->siguiente;
                siguiente->siguiente = recorrido;
                
                Nodo*aux= siguiente;
                siguiente = recorrido;
                recorrido = aux;
                
            }
            anterior = recorrido;
            recorrido = siguiente;
            siguiente = siguiente->siguiente;   
        }   
    } 
}

void ordenarAscendentemente(struct Lista &lista){
    struct Nodo * recorrido = nullptr ;
    struct Nodo * siguiente = nullptr;
    struct Nodo * anterior= nullptr;
    
    for(int i=0;i<lista.longitud -1;i++){
        recorrido = lista.cabeza;
        siguiente = recorrido->siguiente;
        anterior =nullptr;
        
        for(int j=0; j<lista.longitud -1-i;j++){
            if(recorrido->elemento > siguiente->elemento){
                if(anterior !=nullptr){
                    anterior->siguiente = siguiente;
                }else{
                    lista.cabeza  =siguiente;
                }
                recorrido->siguiente = siguiente->siguiente;
                siguiente->siguiente = recorrido;
                
                Nodo *aux = siguiente;
                siguiente = recorrido;
                recorrido = aux;                      
            }
            anterior = recorrido;
            recorrido = siguiente;
            siguiente = siguiente->siguiente;
        }
    }    
    
}

void intercalarLista(struct Lista &l1,struct Lista &l2){
    struct Nodo * recorrido = l1.cabeza;
    struct Nodo * r2 = l2.cabeza;
    while(recorrido != nullptr){
        if(r2 ==nullptr) break;
        r2 = l2.cabeza;
        l2.cabeza = l2.cabeza->siguiente;
        r2->siguiente = recorrido->siguiente;
        recorrido->siguiente = r2;       
        recorrido = r2;
        r2 = l2.cabeza;
        recorrido = recorrido->siguiente;
    }
    
    if(!esListaVacia(l2)){
        struct Nodo * ultimoNodo= obtenerUltimoNodo(l1);
        ultimoNodo->siguiente = r2;
    }
    
}

void invertirLista(struct Lista &l2){
    struct Nodo* anterior =nullptr;
    struct Nodo* recorrido =l2.cabeza;
    struct Nodo* siguiente = nullptr;
    
    while(recorrido!=nullptr){
        siguiente = recorrido->siguiente;
        
        recorrido->siguiente = anterior;
        
        
        anterior = recorrido;
        recorrido = siguiente    ;
    }
    
    l2.cabeza = anterior;
    
    
}


int main(int argc, char** argv) {
    
    struct Lista lista,lista2;
    construir(lista);
    construir(lista2);
    insertarAlFinal(lista,723);
    insertarAlFinal(lista,182);
    insertarAlFinal(lista,123);
    insertarAlFinal(lista,262);
    insertarAlFinal(lista,851);
    insertarAlFinal(lista,352);
    insertarAlFinal(lista,653);
    insertarAlFinal(lista,103);
    insertarAlFinal(lista,561);
    insertarAlFinal(lista,841);
    insertarAlFinal(lista,391);
    insertarAlFinal(lista,241);
    
    insertarAlFinal(lista2,10);
    insertarAlFinal(lista2,20);
    insertarAlFinal(lista2,30);
    insertarAlFinal(lista2,40);
    insertarAlFinal(lista2,250);
    
    imprime(lista);
    imprime(lista2);
    cout<<"Ordenar lista por borbuja:"<<endl;
    
    ordenarAscendentemente(lista);
    imprime(lista);
    imprime(lista2);
    cout<<"Intercalar Lista"<<endl;
    intercalarLista(lista,lista2);
    imprime(lista);
    
    imprime(lista2);
    //fuisonarListasOrden(lista,lista2);
    
    struct Lista l2;
    construir(l2);
    insertarEnOrden(l2,10);
    insertarEnOrden(l2,8);
    insertarEnOrden(l2,50);
    insertarEnOrden(l2,23);
    imprime(l2);
    
    cout<<"Invertir Lista"<<endl;
    invertirLista(l2);
    imprime(l2);
    return 0;
}

