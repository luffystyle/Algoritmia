/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include <cstring>
#include "Cola.h"
#include "Lista.h"
#include "funcionesCola.h"
#include "funcionesLista.h"

using namespace std;

//creamos contadores de prioridad

int cont=0;

int evalPrioridad(int n){
    if(n>=80){
        return 1;
    }
    if(n<=10){
        return 2;
    }else{
        return 3;
    }
}

void encolarPrioridad(Cola & cola, int edad, const char*codigo){
    //obtenemos la prioridad del elemento
    int years;
    int firstYear,firstPriority;
    years=2024-(edad%10000);
    int prioridad=evalPrioridad(years);
    //eEncolamos el primer elemento
    //cola.lista.cola->elemento;
    if(esColaVacia(cola)){
        encolar(cola,edad,codigo);
        cont++;
        return;
    }
    int lastYear=2024-(cola.lista.cola->elemento%10000);
    int lasPriotity=evalPrioridad(lastYear);
    //Aqui encolaremos desde el segundo elemento
    if(prioridad>=lasPriotity){
         encolar(cola,edad,codigo);
    }else{
        //Primera iterativa que coloca el tipo de prioridad en la cola
        while(lasPriotity!=prioridad){            
            encolar(cola,cola.lista.cabeza->elemento,cola.lista.cabeza->codigo);
            eliminaCabeza(cola.lista);
            lastYear=2024-(cola.lista.cola->elemento%10000);            
            lasPriotity=evalPrioridad(lastYear);
        }
        //Segunda iterativa que coloca las prioridades que son iguales en la parte final de la cola
        firstYear=2024-(cola.lista.cabeza->elemento)%10000;
        firstPriority=evalPrioridad(firstYear);
        while(firstPriority==prioridad){
            encolar(cola,cola.lista.cabeza->elemento,cola.lista.cabeza->codigo);
            eliminaCabeza(cola.lista);
        }
        encolar(cola,edad,codigo);
    }
    cont++;
    if(cont==6){        
        while(firstPriority!=1){            
            encolar(cola,cola.lista.cabeza->elemento,cola.lista.cabeza->codigo);
            eliminaCabeza(cola.lista);
            firstYear=2024-(cola.lista.cabeza->elemento)%10000;
            firstPriority=evalPrioridad(firstYear);
        }
    }    
}

int main(int argc, char** argv) {
    struct Cola cola;
    construir(cola);    
    encolarPrioridad(cola,30051943,"BXQ778");//80 años
    encolarPrioridad(cola,20042014,"HRP112");//10 años
    encolarPrioridad(cola,26061975,"PRL625");//49 años
    encolarPrioridad(cola,22101949,"MKP157");//75 años
    encolarPrioridad(cola,13052020,"ARH749");//4 años
    encolarPrioridad(cola,14021930,"HRQ931");//94 años
    
    imprime(cola);
    
    destruirCola(cola);

    return 0;
}

