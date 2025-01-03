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
#include "funciones.h"


int calculoCantidadBuenos(int primerElemnt,int *arr,int ini,int fin,int cont){
    if(ini > fin) return cont;
    int med = (ini+fin)/2;
    if(primerElemnt == 1){
        if(arr[med]== 1){
            return calculoCantidadBuenos(primerElemnt,arr,med+1,fin,med+1);
        }else{
            return calculoCantidadBuenos(primerElemnt,arr,ini,med-1,cont);
        }
    }else{
        if(arr[med]== 1){
            return calculoCantidadBuenos(primerElemnt,arr,ini,med-1,cont+fin-med+1);
        }else{
            return calculoCantidadBuenos(primerElemnt,arr,med+1,fin,cont);
        }
    }
    
}

void llenarFajas(struct Lista &faja,int *estado,int *bandeja,int n){
    for(int i=0;i<n;i++){
        if(estado[i]== 1){
            insertarAlFinal(faja,bandeja[i]);
        }
    }
       
}

void unirFajaPrincipal(struct Lista &faja,struct Lista &faja1,struct Lista &faja2,struct Lista &faja3,struct Lista &faja4){
    if(faja1.cabeza!=nullptr){
        faja.cabeza = faja1.cabeza;
        faja.cola = faja1.cola;
    }
    if(faja2.cabeza!=nullptr){
        faja.cola->siguiente = faja2.cabeza;
        faja.cola = faja2.cola;
    }
    if(faja3.cabeza!=nullptr){
        faja.cola->siguiente = faja3.cabeza;
        faja.cola = faja3.cola;
    }
    if(faja4.cabeza!=nullptr){
        faja.cola->siguiente = faja4.cabeza;
        faja.cola = faja4.cola;
    }
    
    
}

int main(int argc, char** argv) {
    int n=7;
    int bandeja1[7]={2,1,3,2,3,1,1};
    int estado1[7]= {1,1,1,0,0,0,0};
    
    int bandeja2[7]={1,2,3,3,3,2,1};
    int estado2[7]= {1,1,1,1,1,1,0};
    
    int bandeja3[7]={1,2,1,1,3,1,2};
    int estado3[7]={1,1,1,1,1,0,0};
    
    int bandeja4[7]={3,1,3,2,3,3,1};
    int estado4[7]={0,0,1,1,1,1,1};
    
    int cant1 = calculoCantidadBuenos(estado4[0],estado4,0,n-1,0);
    Lista faja,faja1,faja2,faja3,faja4;
    construir(faja);
    construir(faja1);
    construir(faja2);
    construir(faja3);
    construir(faja4);
    
    llenarFajas(faja1,estado1,bandeja1,n);
    llenarFajas(faja2,estado2,bandeja2,n);
    llenarFajas(faja3,estado3,bandeja3,n);
    llenarFajas(faja4,estado4,bandeja4,n);
    
    unirFajaPrincipal(faja,faja1,faja2,faja3,faja4);
//    cout<<cant1<<endl;
    imprime(faja);
    
    return 0;
}




































