/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 31 de agosto de 2023, 11:13 PM
 */

#include <cstdlib>
#include "Lista.h"
using namespace std;
#include "funcionesLista.h"
/*
* LISTAS CIRCULARES SIMPLES
 * El ejercicio consiste en realizar un sorteo, cuya dinámica empieza formando 
 * una ronda con los participantes. Para elegir al ganador, dado un número (k), 
 * partiendo del inicio se van retirando de la ronda los participantes cuya 
 * posición sea igual sea múltiplo de k. Por ejemplo, para k = 3, el primer 
 * participante en salir será el de la posición 3, el siguiente será el 6 y así 
 * sucesivamente, hasta que quede un solo participante, ese será el ganador.
 */
int main(int argc, char** argv) {
    
    struct Lista lista;
    construir(lista);
    /*m es la cantidad de jugadores*/
    int m = 12; 
    
    /*A cada jugador se le entrega un ticket con un número, i representa el número
     de ticket*/
    
    /*INSERTAR AL INICIO DE LA LISTA CIRCULAR*/
//    for(int i = 12; i >= 1; i--)
//        insertarAlInicio(lista, i);
//    
    /*INSERTAR AL FINAL DE LA LISTA CIRCULAR*/
    for(int i = 1; i < m + 1; i++)
        insertarAlFinal(lista, i);
    
    /*INSERTAR EN ORDEN EN LA LISTA CIRCULAR*/
//    insertarEnOrden(lista, 5);
//    insertarEnOrden(lista, 4);
//    insertarEnOrden(lista, 1);
//    insertarEnOrden(lista, 3);
//    insertarEnOrden(lista, 2);
    
    /*ELIMINAR UN ELEMENTO DADO DE LA LISTA CIRCULAR*/
////    eliminaNodo(lista, 2);
//    eliminaNodo(lista, 4);
    /*Empieza el juego con k = 3, k es el avance para sacar del juego 
      un participante*/
    /*RESUELVE EL PROBLEMA DEL SORTEO CIRCULAR- PROBLEMA BASADO EN JOSEFO*/
    problemaJosefo(lista, 3); 
    
    /*Al final solo debe quedar un participante*/
    /*IMPRIME LOS ELEMENTOS DE LA LISTA CIRCULAR*/
    imprime(lista);
    
    /*LIBERA LA MEMORIA*/
    destruirLista(lista);
    return 0;
    
}

/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 31 de agosto de 2023, 11:15 PM
 */

#ifndef NODO_H
#define NODO_H

struct Nodo{
    int elemento;
    struct Nodo * siguiente;
};

#endif /* NODO_H */

/* 
 * File:   Lista.h
 * Author: ANA RONCAL
 * Created on 31 de agosto de 2023, 11:15 PM
 */

#ifndef LISTA_H
#define LISTA_H
/*LISTAS CIRCULARES SIMPLES*/
/*Listas circulares, la principal ventaja es que permiten la navegación en 
     * un sentido a través de la misma, además, se puede recorrer toda la lista
     * partiendo de cualquier elemento (Nodo) siempre que tengamos un apuntador
     * a este. Se deben establecer condiciones adecuadas para evitar caer en 
     * ciclos infinitos*/
struct Lista{
    struct Nodo * cabeza; /*apunta al inicio de la lista*/
    int longitud; /*guarda la longitud de la lista*/
};

#endif /* LISTA_H */

/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 31 de agosto de 2023, 11:16 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);
bool esListaVacia(const struct Lista &);
int longitud(const struct Lista & );
struct Nodo * crearNuevoNodo(int , struct Nodo * );
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int );
void insertarAlInicio(struct Lista & , int );
void insertarAlFinal(struct Lista  & , int );
void insertarEnOrden(struct Lista & , int );
void imprime(const struct Lista & );
void problemaJosefo(struct Lista & , int );
void eliminaNodo(struct Lista & , int );
void destruirLista(struct Lista  & );

#endif /* FUNCIONESLISTA_H */

/* 
 * File:   funcionesLista.cpp
 * Author: ANA RONCAL
 * Created on 31 de agosto de 2023, 11:17 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Nodo.h"
#include "Lista.h"
using namespace std;
#include "funcionesLista.h"

/*INICIALIZA LOS VALORES DE LA LISTA*/
void construir(struct Lista & tad){
    /*Igual que una lista simplemente enlazada*/
    tad.cabeza = nullptr;
    tad.longitud = 0;    
}

/*DEVUELVE EL TAMAÑO DE LA LISTA*/
int longitud(const struct Lista & tad){
    return tad.longitud;
}

/*NOS DICE SI SE ENCUENTRAN ELEMENTOS EN LA LISTA*/
bool esListaVacia(const struct Lista & tad){
    /*Igual que una lista simplemente enlazada*/
    return tad.cabeza == nullptr;
}

/*SE CREA EL ELEMENTO CON VALORES INICIALES*/
struct Nodo * crearNodo(int elemento, struct Nodo * siguiente){
    /*Igual que una lista simplemente enlazada*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

/*DEVUELVE EL ÚLTIMO ELEMENTO DE LA LISTA*/
struct Nodo * obtenerUltimoNodo(const struct Lista & tad){
    //si la cabeza es nula entonces no existe ningún elemento en la lista	
    if (esListaVacia(tad)) /*primero preguntamos si hay elementos en la lista*/
        return nullptr;
    struct Nodo * ultimo = nullptr;
    struct Nodo * recorrido = tad.cabeza;
    do{
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    } while(recorrido != tad.cabeza); /*CONDICION DIFERENTE A LA LISTA SIMPLE
                                cuando llegue a cabeza que acabe el recorrido*/
    return ultimo;
}

/*INSERTA DESDE CABEZA DE LA LISTA CIRCULAR SIMPLE*/
void insertarAlInicio(struct Lista & tad, int elemento){
    /*se crea el nodo apuntando a la cabeza*/
    struct Nodo * nuevoNodo = crearNodo(elemento, tad.cabeza);
    struct Nodo * ultimo;
    
    if (tad.cabeza == nullptr){
        /*Como es el primero se apunta a si mismo*/
        tad.cabeza = nuevoNodo;
    	nuevoNodo->siguiente = nuevoNodo;   
    }
    else{
    	ultimo = obtenerUltimoNodo(tad);
    	ultimo->siguiente = nuevoNodo;
        tad.cabeza = nuevoNodo;
    }
    tad.longitud++;
}

/*SE INSERTA AL FINAL DE LA LISTA CIRCULAR SIMPLE*/
void insertarAlFinal(struct Lista  & tad, int elemento){
    
    struct Nodo * ultimoNodo = obtenerUltimoNodo(tad);    
    struct Nodo * nuevoNodo = crearNodo(elemento, tad.cabeza);
    /*se crea el nodo apuntando a la cabeza*/
   
    if (ultimoNodo == nullptr){
        tad.cabeza = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
    }
    else{
    	ultimoNodo->siguiente = nuevoNodo;
    }            
    tad.longitud++;  
}

struct Nodo * obtenerNodoAnterior(const struct Lista & tad, int elemento){
    if (esListaVacia(tad))
	return nullptr;
    struct Nodo * anterior = nullptr;
    struct Nodo * recorrido = tad.cabeza;
    do{
    	if(recorrido->elemento < elemento){
	    anterior = recorrido;        
	    recorrido = recorrido->siguiente;
        }                                      /*De menor a mayor*/
    } while(recorrido != tad.cabeza and recorrido->elemento < elemento);
    return anterior;    
}

void insertarEnOrden(struct Lista & tad, int elemento){	
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);
    struct Nodo * nodoAnterior = obtenerNodoAnterior(tad, elemento);  
    
    if (nodoAnterior == nullptr){       	            
    	struct Nodo * ultimoNodo = obtenerUltimoNodo(tad);
    	nuevoNodo->siguiente = tad.cabeza;
    	tad.cabeza = nuevoNodo;
    	if (ultimoNodo != NULL)
            ultimoNodo->siguiente = nuevoNodo;
    	else
            nuevoNodo->siguiente = nuevoNodo;
    }else{    
        nuevoNodo->siguiente = nodoAnterior->siguiente;
        nodoAnterior->siguiente = nuevoNodo;
    }
    tad.longitud++;   
}

/*RESULVE EL PROBLEMA DEL SORTEO CIRCULAR*/
void problemaJosefo(struct Lista & tad, int i){
    
    struct Nodo * recorrido = new struct Nodo;
    struct Nodo * siguiente = new struct Nodo;

    recorrido = tad.cabeza; /*empezamos el recorrido*/
    int longitud = tad.longitud; /* hallamos la longitud*/
    do{
        for(int j = 1; j < i; j++) /*cantidad de veces que avanzo*/
            recorrido = recorrido->siguiente;
        siguiente = recorrido->siguiente; /*guardo el siguiente*/
        cout<<"Se elimina: "<<recorrido->elemento<<endl;   
        if(recorrido == tad.cabeza) /*guardo la cabeza*/
            tad.cabeza = recorrido->siguiente; /*para no perder la cabeza*/
        eliminaNodo(tad, recorrido->elemento); /*elimino el nodo i en i */
        recorrido = siguiente;/*paso al siguiente*/        
       
    }while(tad.longitud != 1); /*acabo cuando me quede uno*/
 
    
}
/*DEVUELVE EL ELEMENTO QUE COINCIDE CON LA BÚSQUEDA*/
struct Nodo * seEncuentra(const struct Lista & tad, int llave){
    if (esListaVacia(tad))
        return nullptr;
    struct Nodo * recorrido = tad.cabeza;
    do{        
    	if (recorrido->elemento == llave) /*SON IGUALES*/
            return recorrido;
        recorrido = recorrido->siguiente;
    } while(recorrido != tad.cabeza);  /*mientras no llegue a cabeza*/
    return nullptr;        /*En caso que no lo encuentre*/
}

/*MUESTRA LOS ELEMENTOS DE LA LISTA CIRCULAR SIMPLE*/
void imprime(const struct Lista & tad){
    struct Nodo * recorrido = tad.cabeza;
    int estaImprimiendoLaCabeza = 1;
    cout<<"[";
    if (recorrido != nullptr)
        do{
            if(!estaImprimiendoLaCabeza)
                cout<<", ";
            estaImprimiendoLaCabeza = 0;
            cout<<recorrido->elemento;        
            recorrido = recorrido->siguiente;
        } while(recorrido != tad.cabeza); /*condición de una vuelta*/
    cout<<"]\n";
}

/*ELIMINA UN ELEMENTO DE LA LISTA CIRCULAR, EL ELEMENTO COINCIDE CON LA BÚSQUEDA*/
void eliminaNodo(struct Lista & tad, int elemento){
    struct Nodo * ultimo = nullptr;
    struct Nodo * recorrido = tad.cabeza;  /*empezamos en cabeza*/
    int encontrado = 0;
    do {
    	if (recorrido->elemento == elemento){
            encontrado = 1;
            break; /*sale del do si lo encuentra*/
    	}
        ultimo = recorrido;        
        recorrido = recorrido->siguiente; /*avanza*/
    } while(recorrido != tad.cabeza); /* busca el elemento */

    if (encontrado){
        if (ultimo == nullptr){ /*estoy al inicio de la lista*/
            if (recorrido == recorrido->siguiente)
                    tad.cabeza = nullptr; /*elimina la cabeza*/
            else{
                struct Nodo * ultimoNodo = obtenerUltimoNodo(tad);
                tad.cabeza = recorrido->siguiente; /*salva la cabeza*/
                if (ultimoNodo != nullptr)
                    ultimoNodo->siguiente = tad.cabeza;
            }
        }
        else{
            ultimo->siguiente = recorrido->siguiente;
        }
        delete recorrido;
        tad.longitud--;
    }
}

/*LIBERA ESPACIO DE MEMORIA*/
void destruirLista(struct Lista  & tad){
    struct Nodo * recorrido = tad.cabeza;
    if (recorrido == nullptr)
        return;
    do{
        struct Nodo * nodoEliminar = recorrido;        
        recorrido = recorrido->siguiente;
        delete nodoEliminar;
    } while(recorrido != tad.cabeza);
    tad.cabeza = nullptr;
    tad.longitud = 0;
}