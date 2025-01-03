/* 
 * File:   funcionesPila.cpp
 * Author: ANA RONCAL
 * Created on 7 de abril de 2024, 03:41 PM
 */

#include <iostream>
#include <iomanip>

#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"
#include "Nodo.h"
using namespace std;

/*constructor de Pila*/
void construir(struct Pila & pila){
    construir(pila.lista);
}

/*Determina si la pila está vacía*/
bool esPilaVacia(const struct Pila & pila){
    return esListaVacia(pila.lista);
}

/*Determina el número de elementos de la pila*/
int longitud(const struct Pila  & pila){
    return longitud(pila.lista);
}

/* push, añade un elemento a la parte superior de la pila */
void apilar(struct Pila & pila, int elemento,int cant){
    insertarAlInicio(pila.lista, elemento,cant);
    //cout<<"Apilando: "<<elemento<<endl;
}

/* pop, elimina un elemento de la parte superior de la pila*/
struct Nodo *desapilar(struct Pila & pila){
    
    if (esPilaVacia(pila)){
        cout<<"La pila está vacía, por lo tanto no se puede desapilar"<<endl;
	return nullptr; //O cualquier otro valor que no se encuentre en la pila
    }	
    else{
        struct Nodo* elemento = cima(pila);
        //cout<<elemento->elemento<<endl;
        struct Nodo * copia = new Nodo;
        copia->elemento = elemento->elemento;
        copia->cantidad = elemento->cantidad;
        eliminaCabeza(pila.lista);
        return copia;
    }
}

/*examina un elemento situado en la parte superior de la pila*/
struct Nodo * cima(const struct Pila & pila){
    
    if (esPilaVacia(pila)){
	cout<<"La pila está vacía por lo tanto no posee cima"<<endl;
        return nullptr; //O cualquier otro valor que no se encuentre en la pila
    }		
    return retornaCabeza(pila.lista);
}



/*destruye la pila*/
void destruirPila(struct Pila & pila){
    destruir(pila.lista);
}

/*Recordar que las Pilas no se recorren en forma secuencial*/
/*Se va utilizar solo para mostrar los valores*/
void imprimir(const struct Pila & pila){
    if(esPilaVacia(pila)){
        cout<<"La pila está vacía no se puede mostrar"<<endl;
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

