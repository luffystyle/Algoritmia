
/* 
 * File:   funciones.h
 * Author: Miguelito
 *
 * Created on October 7, 2023, 11:16 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

// esto es un nodo del problema del ascensor con dos valores
typedef struct nodo {
    int piso;
    int direccion;
    struct nodo *sig;
} Nodo;

typedef struct {
    Nodo* cabeza;
    Nodo* cola;
    int longitud;
}Cola;

void construir(Cola *);
bool esColaVacia(Cola );
int obtenerLongitud(Cola );
Nodo* crearNodo(int , int , Nodo *);
void mostrar( Cola ); 
void encolar( Cola &, int , int);
int desencolar(Cola &);
void ordenarec(Cola &, int );
void ordenarCola(Cola &, int );

#endif /* FUNCIONES_H */

 