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
    for(int i = 12; i >= 1; i--)
        insertarAlInicio(lista, i);
    
    /*INSERTAR AL FINAL DE LA LISTA CIRCULAR*/
//    for(int i = 1; i < m + 1; i++)
//        insertarAlFinal(lista, i);
    
    /*INSERTAR EN ORDEN EN LA LISTA CIRCULAR*/
//    insertarEnOrden(lista, 5);
//    insertarEnOrden(lista, 4);
//    insertarEnOrden(lista, 1);
//    insertarEnOrden(lista, 3);
//    insertarEnOrden(lista, 2);
    
    /*ELIMINAR UN ELEMENTO DADO DE LA LISTA CIRCULAR*/
////    eliminaNodo(lista, 2);
    eliminaNodo(lista, 4);
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

