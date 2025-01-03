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
#include "funcionesCola.h"
#include "funcionesLista.h"

void ordenarCola(struct Cola &cola){
    int longi= longitud(cola);
    int aux1,aux2;
    for(int i=0;i<longi;i++){
        aux1 = desencolar(cola);
        for(int j=0;j<longi-1;j++){
            aux2 = desencolar(cola);
            if(aux1>aux2){
                encolar(cola,aux2);
            }else{
                encolar(cola,aux1);
                aux1 = aux2;
            }
            
        }
        encolar(cola,aux1);
    }

}

void ordenar(struct Cola &cola,int n){
    int aux,mayor, i=1;
    if(esColaVacia(cola)) return;
    mayor = desencolar(cola);
    while(i<n){
        aux=desencolar(cola);
        if(mayor<aux){
            encolar(cola,mayor);
            mayor=aux;
        }else{
            encolar(cola,aux);
        }
        i++;
    }
    ordenar(cola,n-1);
    encolar(cola,mayor);
    
}

void ordenar(struct Cola &cola,int n ){
    if(esColaVacia(cola)) return;
    
    int aux,mayor,i=1,prioridad1,prioridad2;
    char pri1,pri2;
    mayor = desencolar(cola,pri2);
    if(pri2 =='V') prioridad2 =1;
    if(pri2 =='C') prioridad2 =2;
    if(pri2!='V' and pri2!='C') prioridad2=3;
    while(i<n){
        aux=desencolar(cola,pri1);
        if(pri1 =='V') prioridad1 =1;
        if(pri1 =='C') prioridad1 =2;
        if(pri1!='V' and pri1!='C') prioridad1=3;
        
        if(prioridad2<prioridad1){
            encolar(cola,mayor,pri2);
            mayor = aux;
            pri2 = pri1;
            prioridad2 = prioridad1;
        }else{
            encolar(cola,aux,pri1);
        }
        
//        if(mayor<aux){
//            encolar(cola,mayor,pri2);
//            mayor = aux;
//            pri2 = pri1;
//        }else{
//            encolar(cola,aux,pri1);
//        }
        i++;
    }
    ordenar(cola,n-1);
    encolar(cola,mayor,pri2);
    
}


int main(int argc, char** argv) {
    
    struct Cola cola;
    construir(cola);
    encolar(cola,15,'V');
    encolar(cola,10,'C');
    encolar(cola,19,'F');
    encolar(cola,35,'F');
    encolar(cola,12,'V');
    encolar(cola,18,'V');
    encolar(cola,88,'C');
    encolar(cola,8,'C');
    encolar(cola,25,'F');
    encolar(cola,38,'C');
    encolar(cola,89,'F');
    encolar(cola,10,'F');
    encolar(cola,89,'V');
    
    imprime(cola);
    ordenar(cola,longitud(cola));
    imprime(cola);
    
    
    return 0;
}























