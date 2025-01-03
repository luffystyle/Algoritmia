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
//                                  a                   c                   b
void hanoi(int n, struct Pila & desde, struct Pila & hacia, struct Pila & auxiliar, int valorInsertar){
    
    //caso base
    if (n == 1){
        if(cima(desde)<valorInsertar){
            apilar(hacia, desapilar(desde));
        }
        return;
    }
        //llevo los n-1 discos de A a C
        hanoi(n-1, desde, auxiliar, hacia,valorInsertar);
        //Mover el disco n desde A hacia C
        if(cima(desde)<valorInsertar and cima(desde)!=-1){
            apilar(hacia, desapilar(desde));
        }
        //llevo los n-1 discos de C a B
        hanoi(n-1, auxiliar, hacia, desde,valorInsertar);
}


void hanoi2_quechua(int n,struct Pila &pilaA,struct Pila &pilaB,struct Pila &pilaC,int valor){
    if(n==1){
        if(cima(pilaA)<valor){
            apilar(pilaB,desapilar(pilaA));
        }
        return;
    }
    
    hanoi2_quechua(n-1,pilaA,pilaC,pilaB,valor);
    if(cima(pilaA)<valor){
        apilar(pilaB,desapilar(pilaA));
    }
    hanoi2_quechua(n-1,pilaC,pilaB,pilaA,valor);

}




//void insertarEnPilaAuxilar(struct Pila &pila,struct Pila &pila2,struct Pila &pila3,struct Cola &faja,int n){
//    if(esColaVacia(faja) or n==0) return;
//    int valor= desencolar(faja),aux1,aux2;
//    insertarEnPilaAuxilar(pila,pila2,pila3,faja,n-1);
//    if(esPilaVacia(pila3)){
//        apilar(pila3,valor);
//    }else{
//        if(pila3.lista.longitud==1){
//            aux1=desencolar(faja);
//            aux2=cima(pila3);
//            if(aux2<aux1){
//                apilar(auxA,desapilar(pila3));//aqui muevo ele elemento de la pila principal
//                apilar(brazo,aux1);//aqui almaceno el nuevo valor
//                apilar(brazo,desapilar(auxA));//aqui regreso el valor inicial al brazo
//            }else{
//                apilar(brazo,aux1);
//            }
//
//        }
//        hanoi(longitud(pila3),pila3,pila2,pila,valor);
//    }
//    
//}


int main(int argc, char** argv) {
    struct Cola faja;
    construir(faja);
    struct Pila pila,pila2,pila3;
    construir(pila);
    construir(pila2);
    construir(pila3);
    
    encolar(faja,2);
    encolar(faja,8);
    encolar(faja,10);
    encolar(faja,8);
    encolar(faja,5);
    encolar(faja,3);
    cout<<"Faja:"<<endl;
    imprime(faja);
    //insertarEnPilaAuxilar(pila,pila2,pila3,faja,longitud(faja));
    apilar(pila3,8);
    apilar(pila3,6);
    apilar(pila3,2);
    apilar(pila3,1);
    //apilar(pila2,2);
    hanoi2_quechua(4,pila3,pila2,pila,10);
    imprimir(pila2);
    return 0;
}

