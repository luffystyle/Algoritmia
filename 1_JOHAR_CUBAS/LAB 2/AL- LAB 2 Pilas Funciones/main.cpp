/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesLista.h"

using namespace std;

void invertirPilas(struct Pila &pila,int n){
    if(esPilaVacia(pila) or n==1) return ;
    int valor,aux ,i=1;
    struct Pila pila2;
    construir(pila2);
    valor= desapilar(pila);
    while(i<n){
        aux=desapilar(pila);
        apilar(pila2,aux);
        i++;
    }
    apilar(pila,valor);
    while(!esPilaVacia(pila2)){
        apilar(pila,desapilar(pila2));
    }
    destruirPila(pila2);
    invertirPilas(pila,n-1);
    
}

void hanoi(int n,Pila &A,Pila &B,Pila &C){
   if(n==0) return; 
   hanoi(n-1,A,C,B);
   apilar(C,desapilar(A));
   hanoi(n-1,B,A,C); 
    
}


void eliminarPila(struct Pila &pila2,int numero){
    int elemento,n = longitud(pila2),j=0;
    struct Pila pilaAux;
    construir(pilaAux);
    while(!esPilaVacia(pila2)){
        elemento = desapilar(pila2);
        if(elemento!=numero){
            apilar(pilaAux,elemento);
        }
    }
    
    while(!esPilaVacia(pilaAux)){
        apilar(pila2,desapilar(pilaAux));
        j++;
    }
    if(n==j){
        cout<<"No se encontro la Pila que se desea sacar"<<endl;
    }else{
        cout<<"Se saco la pila buscada"<<endl;
    }
}
void eliminarPilaRecursivo(struct Pila &pila2,int numero){
    if(esPilaVacia(pila2)) return;
    int valor ;
    valor=desapilar(pila2);
    eliminarPilaRecursivo(pila2,numero);
    if(valor!=numero) apilar(pila2,valor);
}

void pasaPilaRecursivo(struct Pila &pila,struct Pila &pila2){
    if (esPilaVacia(pila)){
        return ;
    }
    int valor = desapilar(pila);
    pasaPilaRecursivo(pila,pila2);
    apilar(pila2,valor);
}

void pasarPilas(struct Pila &pila1,struct Pila &pila2){
    int valor,n;
    
    while(!esPilaVacia(pila1)){
        valor = desapilar(pila1);
        n=0;
        while(!esPilaVacia(pila1)){
            apilar(pila2,valor);
            valor=desapilar(pila1);
            n++;
        }
        while(!esPilaVacia(pila2) and n>0 ){
            apilar(pila1,desapilar(pila2));
            n--;
        }
        apilar(pila2,valor);
    }
    
    
}



void odenarPilarDesc(struct Pila &pila,int n){
    int menor,aux,i=1;
    struct Pila pila2;
    construir(pila2);
    if(esPilaVacia(pila) or n==1) return;
    menor = desapilar(pila);
    while(i<n){
        aux=desapilar(pila);
        if(menor>aux){
            apilar(pila2,menor);
            menor=aux;
        }else{
            apilar(pila2,aux);
        }
        i++;
    }
    apilar(pila,menor);
    while(!esPilaVacia(pila2)){
        int elemento = desapilar(pila2);
        apilar(pila,elemento);
    }
    destruirPila(pila2);
    odenarPilarDesc(pila,n-1);
    
}



void ordenPilas(struct Pila &pila,int n){
    int mayor, aux, i=1;
    struct Pila pila2;
    construir(pila2);
    if(esPilaVacia(pila)or n==1){
        return;
    }
    mayor = desapilar(pila);
    while(i<n){
        aux=desapilar(pila);
        if(mayor<aux){
            apilar(pila2,mayor);
            mayor = aux;
        }else{
            apilar(pila2,aux);
        }
        i++;
    }
    apilar(pila,mayor);
    
    while(!esPilaVacia(pila2)){
        int elemnt = desapilar(pila2);
        apilar(pila,elemnt);
    }
    destruirPila(pila2);
    ordenPilas(pila,n-1);
    
}

int main(int argc, char** argv) {
    int elemnt;
    struct Pila pila,pila2;
    construir(pila);
    construir(pila2);
    
    apilar(pila,20);
    apilar(pila,10);
    apilar(pila,8);
    apilar(pila,5);
    apilar(pila,9);
    //elemnt = desapilar(pila); 
    imprimir(pila);
    
    cout<<"Ordena las pilas de menor a mayor"<<endl;
    ordenPilas(pila,pila.lista.longitud);
    imprimir(pila);
    cout<<"Ordena las pilas de mayor a menor"<<endl;
    odenarPilarDesc(pila,pila.lista.longitud);
    imprimir(pila);
    
    cout<<"Pasar pila a otra :"<<endl;
    pasarPilas(pila,pila2);
    imprimir(pila2);
    
//    cout<<"Encontrar y eliminar Pila"<<endl;
//    //eliminarPila(pila2,9);
//    eliminarPilaRecursivo(pila2,8);
//    imprimir(pila2);
    
    cout<<"Invertir Pilas"<<endl;
    invertirPilas(pila2,longitud(pila2));
    imprimir(pila2);
    return 0;
}

