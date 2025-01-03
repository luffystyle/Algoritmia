/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Lista.h"
#include "Cola.h"
#include "Pila.h"
#include "funciones.h"
#include "funcionesCola.h"
#include "funcionesPila.h"
using namespace std;


/*
 * IMPLEMENTACIÓN DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */

/*Obtinene el nodo anterior simepre y cuando la lista este ordenada de menor a mayor*/
/*============================================================================*/
Nodo * obtenerNodoAnterior(const struct Lista & tad, int elemento){
    struct Nodo * anterior=nullptr;
    struct Nodo * recorrido=tad.cabeza;
    while((recorrido!=nullptr) && (recorrido->elemento<elemento)){//realizar las modificaciones (>) si es que la lista esta ordenada de mayor a menor
        anterior = recorrido;
        recorrido=recorrido->siguiente;        
    }
    return anterior;
}
/*============================================================================*/
void insertarEnOrden(Lista & tad,int elemento){
    //Verificamos si la lista esta vacia o no
    if(esListaVacia(tad)){
        Nodo * nuevo = crearNodo(elemento,nullptr);
        tad.cabeza=nuevo;
        tad.cola=nuevo;
    }else{
        Nodo * anterior = obtenerNodoAnterior(tad,elemento);
        if(anterior==nullptr){//se inserta al final
            if(tad.cabeza->elemento>elemento){//Cambiar el signo tanto en obtenerAnterior como en esta linea para tener el ordenamiento deseado
                insertarAlInicio(tad,elemento);
            }else{
                Nodo * nuevo = crearNodo(elemento,nullptr);
                tad.cola->siguiente=nuevo;
                tad.cola=nuevo;
            }
        }else{
            Nodo * nuevo = crearNodo(elemento,nullptr);
            nuevo->siguiente=anterior->siguiente;
            anterior->siguiente=nuevo;
        }
    }
}

/*============================================================================*/
struct Nodo * seEncuentra(Lista & tad,int elemento){
    int existe=1;
    struct Nodo * recorrido = tad.cabeza;
    while(recorrido!=nullptr && recorrido->elemento!=elemento){
        recorrido=recorrido->siguiente;
        if(recorrido==nullptr){
            cout<<"El elemento no se encuentra."<<endl;
            existe=0;
            recorrido=tad.cabeza;
            break;
        }
    }
    return recorrido;
}
/*============================================================================*/
void fusion(Lista & L1, Lista & L2){
     if(L1.cola->elemento<L2.cabeza->elemento){
         L1.cola->siguiente=L2.cabeza;
         L1.cola=L2.cola;
     }else if(L1.cabeza->elemento>L2.cola->elemento){
         L2.cola->siguiente=L1.cabeza;
         L1.cabeza=L2.cabeza;
     }else{
         struct Nodo *ini,*fin;
         ini=NULL;
         fin=NULL;
         while(!esListaVacia(L1) && !esListaVacia(L2)){
             if(L1.cabeza->elemento<=L2.cabeza->elemento){
                 if(ini==NULL){
                     ini=L1.cabeza;
                     fin=L1.cabeza;
                 }else{
                     fin->siguiente=L1.cabeza;
                     fin=L1.cabeza;
                 }
                 L1.cabeza=L1.cabeza->siguiente;
             }else{
                 if(L1.cabeza->elemento>L2.cabeza->elemento){
                     if(ini==NULL){
                         ini=L2.cabeza;
                         fin=L2.cabeza;
                     }else{
                         fin->siguiente=L2.cabeza;
                         fin=L2.cabeza;
                     }
                     L2.cabeza=L2.cabeza->siguiente;
                 }
             }
         }
         if(!esListaVacia(L1)){
             fin->siguiente=L1.cabeza;
             fin=L1.cola;
         }else{
             fin->siguiente=L2.cabeza;
             fin=L2.cola;
         }
         L1.cabeza=ini;
         L1.cola=fin;
     }
}
/*============================================================================*/
void ordenaListaElementos(Lista & lista1){
    if(esListaVacia(lista1)){
        cout<<"La lista esta vacia, por lo tanto no se puede orndear."<<endl;
        return;
    }
    int ordena=1;
    while(ordena){
        ordena=0;
        Nodo * recorre = lista1.cabeza;
        while(recorre->siguiente!=nullptr){
            if(recorre->elemento > recorre->siguiente->elemento){
                int temp = recorre->elemento;
                recorre->elemento=recorre->siguiente->elemento;
                recorre->siguiente->elemento=temp;
                ordena=1;
            }
            recorre=recorre->siguiente;
        }
    }
}
/*============================================================================*/
void ordenaListaNodos(Lista & lista1){
    if(esListaVacia(lista1)){
        cout<<"La lista esta vacia, por lo tanto no se puede orndear."<<endl;
        return;
    }
    int ordena=1;
    while(ordena){
        ordena=0;
        Nodo ** recorre=&lista1.cabeza;
        while((*recorre)->siguiente!=nullptr){
            if((*recorre)->elemento>(*recorre)->siguiente->elemento){
                Nodo * temp = (*recorre);
                (*recorre)=(*recorre)->siguiente;
                temp->siguiente=(*recorre)->siguiente;
                (*recorre)->siguiente=temp;
                ordena=1;
            }
            recorre=&(*recorre)->siguiente;
        }
    }
}
/*============================================================================*/
/*============================================================================*/
/*============================================================================*/

void ordenaColaRecursivo(Cola  & cola,int n){
    int mayor,aux,i=1;
    if(esColaVacia(cola))return;
    mayor=desencolar(cola);
    while(i<n){
        aux=desencolar(cola);
        if(aux>mayor){
            encolar(cola,mayor);
            mayor=aux;
        }else{
            encolar(cola,aux);
        }
        i++;
    }
    ordenaColaRecursivo(cola,n-1);
    encolar(cola,mayor);
}
/*============================================================================*/
void ordenaColaIterativo(Cola & cola,int n){
    if (esColaVacia(cola))return;
    for(int i=n;i>1;i--){
        int mayor = desencolar(cola);
        for(int j=1;j<n;j++){
            int aux=desencolar(cola);
            if(aux>mayor){
                encolar(cola,mayor);
                mayor=aux;
            }else{
                encolar(cola,aux);
            }
        }
        encolar(cola,mayor);
    }
}
/*============================================================================*/
void ordenaPilaRecursivo(Pila & pila1,int n){
    if(esPilaVacia(pila1))return;
    Pila paux;
    int valor,maximo,i=n,aux;    
    construir(paux);    
    if(n==0)return;//caso base    
    maximo=desapilar(pila1);
    i--;    
    while(i>0){
        valor=desapilar(pila1);
        if(maximo<valor){
            apilar(paux,maximo);
            maximo=valor;
        }else{
            apilar(paux,valor);
        }
        i--;
    }
    apilar(pila1,maximo);
    while(!esPilaVacia(paux)){
        aux=desapilar(paux);
        apilar(pila1,aux);
    }
    ordenaPilaRecursivo(pila1,n-1);
}
/*============================================================================*/
void ordenaPilaIterativo(Pila & pila){
    Pila paux;
    construir(paux);
    while(!esPilaVacia(pila)){
        int temp = cima(pila);
        desapilar(pila);
        while(!esPilaVacia(paux) && cima(paux)>temp){
            apilar(pila,cima(paux));
            desapilar(paux);
        }
        apilar(paux,temp);
    }
    //Transferimos los elementos a la pila original
    while(!esPilaVacia(paux)){
        apilar(pila,cima(paux));
        desapilar(paux);
    }
}
/*============================================================================*/
void pasaPila(Pila & pila1,Pila & pila2){
    int valor,n,aux;
    
    while(!esPilaVacia(pila1)){
        valor=desapilar(pila1);
        n=0;
        while(!esPilaVacia(pila1)){
            apilar(pila2,valor);
            valor=desapilar(pila1);
            n++;
        }
        while(!esPilaVacia(pila2)&& n>0){
            aux=desapilar(pila2);
            apilar(pila1,aux);
            n--;
        }
        apilar(pila2,valor);
    }
}
/*============================================================================*/
/*============================================================================*/


int main(int argc, char** argv) {
    
    struct Nodo * ptrAux;
    /*=================================*/
    /*=============LISTAS==============*/
    /*=================================*/
    cout<<"LISTAS"<<endl;
    struct Lista lista1,lista2;
    construir(lista1);
    //Obtener el nodo anterior **La lista debe estar ordenada
    insertarAlFinal(lista1,1);
    insertarAlFinal(lista1,2);
    insertarAlFinal(lista1,3);
    insertarAlFinal(lista1,4);
    insertarAlFinal(lista1,5);    
    ptrAux=obtenerNodoAnterior(lista1,4);
    cout<<"Obteber nodo anterior del 4: "<<ptrAux->elemento<<endl;
    destruir(lista1);
    //////////////////////
    //Insertar en orden. Los elemento de la lista ya estaran ordenados
    //////////////////////
    construir(lista1);
    insertarEnOrden(lista1,2);
    insertarEnOrden(lista1,5);
    insertarEnOrden(lista1,1);
    insertarEnOrden(lista1,3);
    insertarEnOrden(lista1,4);
    cout<<"Elementos insertados en orden: "<<endl;
    imprime(lista1);
    //////////////////////
    //Buscar un nodo en concreto
    //////////////////////
    ptrAux=seEncuentra(lista1,4);
    cout<<"Elemento buscado: "<<ptrAux->elemento<<endl;
    destruir(lista1);
    ///////////////////////
    //Fusion de dos listas
    //////////////////////
    construir(lista1);
    construir(lista2);
    
    insertarAlFinal(lista1,2);
    insertarAlFinal(lista1,5);
    insertarAlFinal(lista1,6);
    insertarAlFinal(lista1,8);
    
    insertarAlFinal(lista2,1);
    insertarAlFinal(lista2,3);
    insertarAlFinal(lista2,4);
    insertarAlFinal(lista2,7);
    
    cout<<"Lista 1: "<<endl;
    imprime(lista1);
    cout<<"Lista 2: "<<endl;
    imprime(lista2);
    
    fusion(lista1,lista2);
    cout<<"Fusion de listas: "<<endl;
    imprime(lista1);
    
    destruir(lista1);
    destruir(lista2);
    
    ///////////////////////
    //Ordenamiento de listas  BUBBLE SORT o burbuja (ELEMENTOS)
    //////////////////////
    construir(lista1);
    
    insertarAlFinal(lista1,2);
    insertarAlFinal(lista1,1);
    insertarAlFinal(lista1,6);
    insertarAlFinal(lista1,3);
    insertarAlFinal(lista1,5);
    insertarAlFinal(lista1,4);
    
    cout<<"Ordenamiento intercambiando los elementos: "<<endl;
    cout<<"Lista no ordenada: ";
    imprime(lista1);
    
    ordenaListaElementos(lista1);
    
    cout<<"Lista despues de ordenar: ";
    imprime(lista1);
    
    destruir(lista1);
    
    ///////////////////////
    //Ordenamiento de listas  BUBBLE SORT o burbuja (NODOS)
    //////////////////////
    //Serviria en caso de que el nodo tenga mas de un elemento    
    
    construir(lista1);
    
    insertarAlFinal(lista1,4);
    insertarAlFinal(lista1,2);
    insertarAlFinal(lista1,6);
    insertarAlFinal(lista1,1);
    insertarAlFinal(lista1,3);
    insertarAlFinal(lista1,5);
    cout<<"Ordenamiento intercambiando los nodos: "<<endl;
    cout<<"Lista no ordenada: ";
    imprime(lista1);
    
    ordenaListaNodos(lista1);
    
    cout<<"Lista despues de ordenar: ";
    imprime(lista1);
    
    destruir(lista1);
    cout<<endl;
    /*=================================*/
    /*=============COLAS===============*/
    /*=================================*/
    cout<<"COLAS"<<endl;
    struct Cola cola;
    construir(cola);
    ///////////////////////
    //Ordena una cola de manera recursiva
    //////////////////////
    cola.lista.cola=nullptr;
    encolar(cola,3);
    encolar(cola,2);
    encolar(cola,6);
    encolar(cola,4);
    encolar(cola,1);
    encolar(cola,5);    
    cout<<"Cola desordenada: ";
    imprime(cola);
    ordenaColaRecursivo(cola,cola.lista.longitud);
    cout<<"Cola despues de ordenar recursivamente: ";
    imprime(cola);
    destruirCola(cola);
    
    ///////////////////////
    //Ordena una cola de manera iterativa
    //////////////////////    
    construir(cola);
//    cola.lista.cola=nullptr;
    encolar(cola,4);
    encolar(cola,1);
    encolar(cola,6);
    encolar(cola,2);
    encolar(cola,5);
    encolar(cola,3); 
    cout<<"Cola desordenada: ";
    imprime(cola);
    ordenaColaIterativo(cola,cola.lista.longitud);
    cout<<"Cola despues de ordenar de manera iterativa: ";
    imprime(cola);
    
    /*=================================*/
    /*=============PILAS===============*/
    /*=================================*/
    
    cout<<"PILAS"<<endl;
    struct Pila pila1,pila2;
    construir(pila1);
    apilar(pila1,2);
    apilar(pila1,5);
    apilar(pila1,4);
    apilar(pila1,1);
    apilar(pila1,3);
    
    
    ///////////////////////
    //Ordena una pila de manera recursiva
    //////////////////////   
    cout<<"Pila desrodenada: ";
    imprimir(pila1);
    cout<<"Pila despues de ordenar recursivamente: ";
    ordenaPilaRecursivo(pila1,pila1.lista.longitud);
    imprimir(pila1);
    destruirPila(pila1);
    ///////////////////////
    //Ordena una pila de manera iterativa
    //////////////////////  
    construir(pila1);
    apilar(pila1,4);
    apilar(pila1,1);
    apilar(pila1,5);
    apilar(pila1,3);
    apilar(pila1,2);
    cout<<"Pila desrodenada: ";
    imprimir(pila1);
    cout<<"Pila despues de ordenar de manera iterativa: ";
    ordenaPilaIterativo(pila1);
    imprimir(pila1);
    
    ///////////////////////
    //Pasa pila: Pasar los elementos de una pila a otra sin modificar su orden
    ////////////////////// 
    //Se pasaran los elementos de la pila 1 a la pila 2
    construir(pila2);
    pasaPila(pila1,pila2);
    cout<<"Pila1 :";
    imprimir(pila1);
    cout<<"Pila2 :";
    imprimir(pila2);
    return 0;
}

