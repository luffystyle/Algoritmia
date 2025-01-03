/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include <cmath>
#include "Cola.h"
#include "funcionesCola.h"
#define n 5 
using namespace std;



void ordenaCola(Cola & cola){    
    int m=cola.lista.longitud;
    if(esColaVacia(cola))return; 
    for(int i=m;i>0;i--){
        long long time = desencolar(cola);
        long long mayor = (((time%10000)/100)*60)+(time%100);
        for(int j=1;j<m;j++){
            long long time2 = desencolar(cola);
            long long aux = (((time2%10000)/100)*60)+(time2%100);
            if(aux>mayor){
                encolar(cola,time);
                time=time2;
            }else{
                encolar(cola,time2);
            }
        }
        encolar(cola,time);
    }    
}

void modificaCola(Cola & cola,long long*nuevaLLegada,int num){
    int i=0;
    while(i<num){
        long long codigo=desencolar(cola);
        long long id=codigo/100000000;
        if(id==(nuevaLLegada[i]/100000000)){
            encolar(cola,nuevaLLegada[i]);
            i++;
        }else{
            encolar(cola,codigo);
        }
    }
}


int main(int argc, char** argv) {
    struct Cola cola;
    long long nuevaLLegada[n]={210100550015,210501220210};
    int num=2;//cantidad de modificacones en la hora de llegada
    construir(cola);
    encolar(cola, 210100550055);
    encolar(cola, 110201450145);
    encolar(cola, 411100300030);
    encolar(cola, 210501220122);
    encolar(cola, 310805250525);    
    imprime(cola);
    ordenaCola(cola);
    cout<<"Hora de llegada"<<endl;
    imprime(cola);
    modificaCola(cola,nuevaLLegada,num);
    ordenaCola(cola);
    cout<<"Nueva hora de llegada"<<endl;
    imprime(cola);

    return 0;
}

