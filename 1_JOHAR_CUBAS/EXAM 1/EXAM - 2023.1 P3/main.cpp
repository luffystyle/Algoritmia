/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <valarray>

using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "funcionesLista.h"

void ordenarAcendente(struct Lista &lista){
    struct Nodo* recorrido = lista.cabeza;
    
    while(recorrido!=nullptr){
        struct Nodo*siguiente=recorrido->siguiente;
        int aux= recorrido->elemento;
        while(siguiente!=nullptr){
            int aux2=siguiente->elemento;
            if(aux>siguiente->elemento){
                recorrido->elemento=aux2;
                siguiente->elemento=aux;
                aux=aux2;
            }
            
            siguiente=siguiente->siguiente;
        }
        recorrido=recorrido->siguiente;
    }
    
}


void fusionar2(struct Lista &l1,struct Lista &l2){
    
    if(l1.cola->elemento < l2.cabeza->elemento){
        l1.cola->siguiente = l2.cabeza;
        l1.cola = l2.cola;
    }else{
        if(l2.cola->elemento < l1.cabeza->elemento){
            l2.cola->siguiente = l1.cabeza;
            l1.cabeza = l2.cabeza;
        }else{
            Nodo * inicio =nullptr;
            Nodo * fin =nullptr;
            while(!esListaVacia(l1) and !(esListaVacia(l2)) ){
                if(l1.cabeza->elemento <= l2.cabeza->elemento ){
                    if(inicio == nullptr){
                        inicio = l1.cabeza;
                        fin = l1.cabeza;
                    }else{
                        fin->siguiente = l1.cabeza;
                        fin = l1.cabeza;
                    }
                    l1.cabeza = l1.cabeza->siguiente;
                }else{
                    if(inicio==nullptr){
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



void fusionar(struct Lista &lista1,struct Lista &lista2){
    /*Aqui la lista 1 es disjunta a la lista 2 y es menor*/
    if (lista1.cola->elemento < lista2.cabeza->elemento){
        lista1.cola->siguiente = lista2.cabeza;
        lista1.cola = lista2.cola;
    }
    else {
        /*Aqui la lista 2 es disjunta a la lista 1 y es menor*/
        if (lista2.cola->elemento < lista1.cabeza->elemento){
            lista2.cola->siguiente = lista1.cabeza;
            lista1.cabeza = lista2.cabeza;
        }
        else {
            Nodo *inicio = nullptr;
            Nodo *fin = nullptr;
            while (!esListaVacia(lista1) && !esListaVacia(lista2)){
                if (lista1.cabeza->elemento<=lista2.cabeza->elemento){
                    if (inicio==nullptr){//cabeza
                        inicio = lista1.cabeza;
                        fin = lista1.cabeza;
                    }
                    else {
                        fin->siguiente = lista1.cabeza;
                        fin = lista1.cabeza;
                    }
                    lista1.cabeza = lista1.cabeza->siguiente; 
                }
                else{
                    if (inicio==nullptr){
                        inicio = lista2.cabeza;
                        fin = lista2.cabeza;
                    }
                    else {
                        fin->siguiente = lista2.cabeza;
                        fin = lista2.cabeza;
                    }
                    lista2.cabeza = lista2.cabeza->siguiente;
                }
            }
            if (!esListaVacia(lista1)){
                fin->siguiente = lista1.cabeza;
                fin = lista1.cola;
            }
            if (!esListaVacia(lista2)){
                fin->siguiente = lista2.cabeza;
                fin = lista2.cola;
            }
            lista1.cabeza = inicio;
            lista1.cola = fin;
        }
    }
    lista1.suma += lista2.suma;
}


void fusionarEnOrden(struct Lista &l1,struct Lista &l2){
    struct Nodo* recorrido = l1.cabeza;
    struct Nodo* recorrido2 = l2.cabeza;
    struct Nodo* nodoInstertado =nullptr;
    struct Nodo* anterior = nullptr;
    while(recorrido!=nullptr){
        if(recorrido2==nullptr) break;
        
        if(recorrido->elemento<recorrido2->elemento){
            nodoInstertado=recorrido2;
            recorrido2=recorrido2->siguiente;
            
            nodoInstertado->siguiente=recorrido->siguiente;
            
            recorrido->siguiente=nodoInstertado;
            recorrido = nodoInstertado;
            
            anterior = recorrido;
            recorrido=recorrido->siguiente;
        }else if(recorrido->elemento > recorrido2->elemento){
            nodoInstertado=recorrido2;
            recorrido2 = recorrido2->siguiente;
            if(recorrido == l1.cabeza){
                nodoInstertado->siguiente=l1.cabeza;
                l1.cabeza=nodoInstertado;
                recorrido = nodoInstertado;
            }else{
                
                nodoInstertado->siguiente=recorrido;
                anterior->siguiente = nodoInstertado;
                recorrido=nodoInstertado;
            }
            anterior = recorrido;
            recorrido=recorrido->siguiente;
        }
    }
    l1.suma += l2.suma;
    if(!esListaVacia(l2)){
        struct Nodo*ultimoNodo=obtenerUltimoNodo(l1);
        ultimoNodo->siguiente= recorrido2;
    }
    
    
}

void construirListas(struct Lista &lista,struct Lista &l1,struct Lista &l2,struct Lista &l3){
    struct Nodo* recorrido = lista.cabeza;
    while(recorrido!=nullptr){
        int numeroEjercito = (recorrido->elemento%10); 
        int numero = recorrido->elemento/10;
        if(numeroEjercito ==1){
            insertarAlFinal(l1,numero);
            l1.suma += numero;
        }
        if(numeroEjercito ==2){
            insertarAlFinal(l2,numero);
            l2.suma += numero;
        }
        if(numeroEjercito ==3){
            insertarAlFinal(l3,numero);
            l3.suma += numero;
        }
        recorrido= recorrido->siguiente;
    }
    //ahora ordenamos:
    ordenarAcendente(l1);
    ordenarAcendente(l2);
    ordenarAcendente(l3);
    
}

void simulacionDeBatalla(struct Lista &l1,struct Lista &l2,struct Lista &l3){
    
    struct Nodo * recorrido = l1.cabeza;
    struct Nodo * recorrido2 = l2.cabeza;
    struct Nodo * recorrido3 = l3.cabeza;
    int cont =0;

    
    while(1){
        int i=0;
        cout<<"Inicia la batalla:"<<endl;
        cout<<"Ejército 1 – Bowser: ";
        imprime(l1);
        cout<<"Ejército 2 – Peach: ";
        imprime(l2);
        struct Nodo * recorrido = l1.cabeza;
        struct Nodo * recorrido2 = l2.cabeza;
        while((!esListaVacia(l1) and !esListaVacia(l2)) || (recorrido!=nullptr or recorrido2!=nullptr) ){
            if(i==2 or recorrido==nullptr or recorrido2==nullptr) break;
            i++;
            
            cout<<"Pelea "<<i<<": "<<recorrido->elemento<<" Vs "<<recorrido2->elemento;
            if(recorrido->elemento>recorrido2->elemento){
                cout<<", gana "<<recorrido->elemento<<endl;
                l2.suma = l2.suma - recorrido2->elemento;
                eliminaNodo(l2,recorrido2->elemento);
                recorrido= recorrido->siguiente;
                recorrido2=l2.cabeza;

            }else{
                cout<<", gana "<<recorrido2->elemento<<endl;
                l1.suma = l1.suma - recorrido->elemento;
                eliminaNodo(l1,recorrido->elemento);
                recorrido2 = recorrido2->siguiente;
                recorrido = l1.cabeza;
            }
        }

        cout<<"Nivel de Ataque Total del Ejercito 1: "<<l1.suma<<endl;
        cout<<"Nivel de Ataque Total del Ejercito 2: "<<l2.suma<<endl;
        if(l1.suma>l2.suma and cont==0){
            cout<<"El ejército de DonKey Kong se une al ejército de Peach."<<endl<<endl;
            cont=1;//lo cambio la bandera
            fusionar(l2,l3);
            
            //imprime(l2);
        }else if(cont!=0){
            cout<<"Ya no se puede unir nadie al ejército de Peach."<<endl<<endl;
        }
        if(l1.suma ==0 || l2.suma ==0){
            if(l1.suma==0){
                cout<<"Gana la batalla Bowser"<<endl;
            }
            if(l2.suma==0){
                cout<<"Gana la batalla Peach"<<endl;
            }
            break;
        }
        
        
    }
    
}



int main(int argc, char** argv) {
    int n=2;
    int cantGuerreros=12;
    struct Lista lista,l1,l2,l3,l11,l33;
    construir(lista);
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
    construir(l1);
    construir(l2);
    construir(l3);
    construirListas(lista,l1,l2,l3);
//    fusionarEnOrden(l1,l3);
//    imprime(l1);
//    
//    fusionar(l1,l3);
//    imprime(l1);
//    
    cout<<"Lista de Guerreros: ";
    imprime(lista);
    cout<<endl;
    cout<<"Los ejercitos formados son:"<<endl;
    cout<<"Ejército 1 – Bowser: ";
    imprime(l1);
    cout<<"Nivel de Ataque Total del Ejercito 1: "<<l1.suma<<endl<<endl;
    
    cout<<"Ejército 2 – Peach: ";
    imprime(l2);
    cout<<"Nivel de Ataque Total del Ejercito 2: "<<l2.suma<<endl<<endl;
    
    cout<<"Ejército 3 – DonKey Kong: ";
    imprime(l3);
    cout<<"Nivel de Ataque Total del Ejercito 3: "<<l3.suma<<endl<<endl;
    
    simulacionDeBatalla(l1,l2,l3);
    
    
    
    
   
    
    return 0;
}
























