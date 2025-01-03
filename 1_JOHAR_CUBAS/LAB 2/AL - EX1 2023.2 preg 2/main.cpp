/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "Cola.h"
#include "Lista.h"
#include "Nodo.h"
#include "Pila.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

void pasarPilas(struct Pila &pila1,struct Pila &pila2){
    int valor;
    if(esPilaVacia(pila2)) return;
    valor = desapilar(pila2);
    pasarPilas(pila1,pila2);
    apilar(pila1,valor);
    
}

void ordenarPilas(struct Pila &pila, int n){
    int mayor,mayor_1,aux,aux_1,i=1;
    struct Pila pila2;
    construir(pila2);
    if(esPilaVacia(pila) or n==1) return ;
    mayor = desapilar(pila);
    mayor_1 = mayor%100;
    while(i<n){
        aux=desapilar(pila);
        aux_1=aux%100;
        if(mayor_1<aux_1){
            apilar(pila2,mayor);
            mayor = aux;
        }else{
            apilar(pila2,aux);
        }  
        i++;
    }
    apilar(pila,mayor);
    while(!esPilaVacia(pila2)){
        apilar(pila,desapilar(pila2));
    }
    destruirPila(pila2);
    ordenarPilas(pila,n-1);
}


void reinicia_cola(struct Cola &cola,int cantColas,struct Pila &pila1,struct Pila &pila2){
    if(pila1.lista.longitud == 3 || pila2.lista.longitud == 3){
        if(pila1.lista.longitud == 3){
            struct Pila pilaAux;
            construir(pilaAux);
            int cantPilas1=pila1.lista.longitud;
            pasarPilas(pila1,pila2);
            ordenarPilas(pila1,longitud(pila1));
            
            int cantidadColamiento= longitud(cola)- pila1.lista.longitud ;
            int i=0,valor;
            //LOS 3 PRIMEROS DE LA COLA LO GUARDO EN UNA PILA AUXILIAR
            while(i<cantidadColamiento){
                valor = desencolar(cola);
                apilar(pilaAux,valor);
                i++;
            }
            //LLO ORDELO DICHA PILA PARA QUE ME DE DE MENOR A MAYOR SU ORDEN AL MOMENTO DE PONERLO EN LA COLA
            ordenarPilas(pilaAux,i);
            i=0;
            //LUEGO LOS RESTANTES DE LA COLA LO GUARDO EN LA PILA 2 
            //ACA EN VEZ DEL 5 PODRIA PONER WHILE(!ESCOLAVACIA(COLA)){
            while(i<5){
                apilar(pila2,desencolar(cola));
                i++;
            }
            //ACA EMPIEZO A PONER LO DE LA PILA 1 EN LA COLA 
            while(!esPilaVacia(pila1)){
                encolar(cola,desapilar(pila1));
            }
            //ACA LOS SIGUIENTES 3 RESTANTES DE LA PILA AUXILIAR 
            while(!esPilaVacia(pilaAux)){
                encolar(cola,desapilar(pilaAux));
            }
            //SIEMPRE QUE SE UTILIZE UNA PILA AUXILIAR DESTRUIRLO
            destruirPila(pilaAux);
        }

    }
    
    
}

void pasarReclasificacionPilas(struct Pila &pila1,struct Pila &pila2,int n){
    int valor,prioridad ;
    if(esPilaVacia(pila2)) return;
    valor = desapilar(pila2);
    prioridad = (int)valor/100;
    pasarReclasificacionPilas(pila1,pila2,n-1);
    if(prioridad==1) apilar(pila2,valor);
    if(prioridad==2) apilar(pila1,valor);
}

void reclasifica_pilas(struct Pila &pila1,struct Pila &pila2){
    ordenarPilas(pila2,longitud(pila2));
    pasarReclasificacionPilas(pila1,pila2,longitud(pila2));
}



int main(int argc, char** argv) {
    struct Cola cola;
    struct Pila pila1,pila2;
    int cantColas=8;
    construir(cola);
    construir(pila1);
    construir(pila2);
    int dato,i=0;
    cout<<"Ingrese los datos: ";
    //INGRESO LOS DATOS
    do{
        cin>>dato;
        encolar(cola,dato);
        i++;
    }while(i<cantColas);
    int prioridad,numeroAtencion;
    do{
        cin>>dato;
        prioridad = (int)dato/100;
        
        if(prioridad==1){
            apilar(pila1,dato);
        }else{
            apilar(pila2,dato);
        }
        if(pila1.lista.longitud ==3 || pila2.lista.longitud ==3) break;
    }while(1);
   
    cout<<"INICIAL:"<<endl;
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila 1: ";
    imprimir(pila1);
    cout<<"Pila 2: ";
    imprimir(pila2);
    cout<<endl<<endl;

    reinicia_cola(cola,cantColas,pila1,pila2);
    cout<<"REINICIA COLA:"<<endl;
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila 1: ";
    imprimir(pila1);
    cout<<"Pila 2: ";
    imprimir(pila2);
    cout<<endl<<endl;
    reclasifica_pilas(pila1,pila2);
    cout<<"RECLASIFICA PILA:"<<endl;
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila 1: ";
    imprimir(pila1);
    cout<<"Pila 2: ";
    imprimir(pila2);
    return 0;
}

