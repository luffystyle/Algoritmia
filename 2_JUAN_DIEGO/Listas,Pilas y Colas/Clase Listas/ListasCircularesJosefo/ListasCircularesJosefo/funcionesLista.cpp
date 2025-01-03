/* 
 * File:   funcionesLista.cpp
 * Author: ANA RONCAL
 * Created on 31 de agosto de 2023, 11:17 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

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