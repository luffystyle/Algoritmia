/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 25 de agosto de 2023, 08:40 PM
 */

#include <cstdlib>
#include <iostream>
#include "ListaD.h"
using namespace std;
#include "funcionesListaDoble.h"

/*
 * LISTA DOBLEMENTE ENLAZADA - TORNEO DE EQUIPOS
 * EL EJERCICIO SE REALIZA CON INSERTAR ORDENADO
 * SIN EMBARGO, SE UTILIZA EL EJERCICIO PARA PROBAR 
 * OTRAS FUNCIONES DE LA LISTA DOBLE
 */
int main(int argc, char** argv) {

    struct Lista lista;
    /*CONSTRUIR LA LISTA*/
    construir(lista);
        
    /*INSERTA EN ORDEN LA LISTA DOBLE LOS EQUIPOS*/
    insertarEnOrden(lista, "GutterBall", 9);
    insertarEnOrden(lista, "KingPins", 8);
    insertarEnOrden(lista, "PinDoctors", 7);
    insertarEnOrden(lista, "Scorecards", 10);
    insertarEnOrden(lista, "Spares", 5);
    insertarEnOrden(lista, "Splits", 4);
    insertarEnOrden(lista, "Tenpins", 13);
    insertarEnOrden(lista, "Woodsplitters", 6);
    insertarEnOrden(lista, "Lions", 1);
    insertarEnOrden(lista, "Tigers", 2);
    
//    /*ELIMINA EL PRIMER ELEMENTO DE LA LISTA*/
  //  eliminaCabeza(lista);
    
//    /*ELIMINA EL ÚLTIMO ELEMENTO DE LA LISTA*/
    eliminaCola(lista);
    
//   /*ELIMINA EL ELEMENTO CUYO NOMBRE COINCIDE CON EL DE LA LISTA*/
//   eliminaNodo(lista, "Tenpins");
//   eliminaNodo(lista, "Spares");
  
    /*IMPRIME LA LISTA DESDE EL INICIO*/
    imprime(lista);
    /*IMPRIME LA LISTA DESDE EL FINAL*/
   // imprimeDesdeFinal(lista);
    /*IMPRIME LA PRIMERA FECHA DEL TORNEO*/
    imprimePrimerafecha(lista);
    /*LIBERA MEMORIA*/
    destruirLista(lista);
    
    return 0;
}

