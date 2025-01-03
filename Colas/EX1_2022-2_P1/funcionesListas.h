/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#ifndef FUNCIONESLISTAS_H
#define FUNCIONESLISTAS_H

typedef int Elemento;

typedef struct nodo {
    int elem;
    struct nodo *sig;
} Nodo;

typedef struct {
    Nodo* cabeza;
    int longitud;
} Lista;


void construir(Lista &) ;
bool esListaVacia(Lista );
int obtenerLongitud(Lista );
Nodo* crearNodo(Elemento , Nodo* );
void insertarAlComienzo(Lista &, Elemento );
void mostrar(Lista );
Nodo* ubicarUltimo(Lista );
void insertarAlFinal(Lista &, Elemento );
Nodo* ubicarAnterior( Lista , Elemento );
Nodo* ubicar( Lista , Elemento );
void eliminar(Lista &, Elemento );
void destruir(Lista &);

#endif /* FUNCIONESLISTA_H */

