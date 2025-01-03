/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>

#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

using namespace std;

/*constructor de Pila*/
void construir(struct Pila & pila){
    construir(pila.lista);
}

/*Determina si la pila estÃ¡ vacÃ­a*/
bool esPilaVacia(const struct Pila & pila){
    return esListaVacia(pila.lista);
}

/*Determina el nÃºmero de elementos de la pila*/
int longitud(const struct Pila  & pila){
    return longitud(pila.lista);
}

/* push, aÃ±ade un elemento a la parte superior de la pila */
void apilar(struct Pila & pila, int elemento){
    insertarAlInicio(pila.lista, elemento);
    //cout<<"Apilando: "<<elemento<<endl;
}

/* pop, elimina un elemento de la parte superior de la pila*/
int desapilar(struct Pila & pila){
    
    if (esPilaVacia(pila)){
        cout<<"La pila estÃ¡ vacÃ­a, por lo tanto no se puede desapilar"<<endl;
	return -1; //O cualquier otro valor que no se encuentre en la pila
    }	
    else{
        int elemento = cima(pila);
        eliminaCabeza(pila.lista);
        return elemento;
    }
}

/*examina un elemento situado en la parte superior de la pila*/
int cima(const struct Pila & pila){
    
    if (esPilaVacia(pila)){
	cout<<"La pila estÃ¡ vacÃ­a por lo tanto no posee cima"<<endl;
        return -1; //O cualquier otro valor que no se encuentre en la pila
    }		
    return retornaCabeza(pila.lista);
}


/*destruye la pila*/
void destruirPila(struct Pila & pila){
    destruir(pila.lista);
}

/*Recordar que las Pilas no se recorren en forma secuencial*/
/*Se va utilizar solo para mostrar los valores*/
void imprimirPila(const struct Pila & pila){
    if(esPilaVacia(pila)){
        cout<<"La pila estÃ¡ vacÃ­a no se puede mostrar"<<endl;
    }
    else
        imprime(pila.lista);
}

///*imprime desapilando*/
//void imprime(struct Pila & pila){
//    
//    while(not esPilaVacia(pila)){
//        cout<<cima(pila)<<"-";
//        desapilar(pila);
//    }
//}
