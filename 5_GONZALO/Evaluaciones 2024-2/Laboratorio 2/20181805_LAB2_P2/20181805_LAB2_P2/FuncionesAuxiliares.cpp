/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: Gonzalo Quinteros Mostacero
 *
 * Creado el 12 de octubre de 2024, 08:37 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstring>
#include "Lista.h"
#include "funciones.h"
#include "FuncionesAuxiliares.h"

using namespace std;

void cargarDatosLista(struct Lista &listaPedidos){
    ifstream archPedidos("Pedidos.txt", ios::in);
    if (!archPedidos){
        cout<<"ERROR: No se pudo abrir el archivo Pedidos.txt"<<endl;
        exit(1);
    }
    char id[5];
    char complejidadPrep;
    int hayDisponibilidad;
    double distancia;
    int esHoraPunta;
    int tiempoPreparacion, tiempoEstimadoViaje;
    struct Pedido pedido;
    while (1){
        archPedidos>>id;
        if (archPedidos.eof()) break;
        archPedidos>>ws>>complejidadPrep>>hayDisponibilidad;
        archPedidos>>distancia>>esHoraPunta;
        calcularTiempos(complejidadPrep, hayDisponibilidad, distancia, 
                esHoraPunta, tiempoPreparacion, tiempoEstimadoViaje);
        strcpy(pedido.id, id);
        pedido.tiempoPreparacion = tiempoPreparacion;
        pedido.tiempoEstimadoViaje = tiempoEstimadoViaje;
        pedido.tiempoEstimadoTotal = (tiempoPreparacion+tiempoEstimadoViaje);
        insertarAlFinal(listaPedidos, pedido);
    }
    archPedidos.close();
}

void calcularTiempos(char complejidadPrep, int hayDisponibilidad, 
                     double distancia, int esHoraPunta, 
                     int &tiempoPreparacion, int &tiempoEstimadoViaje){
    double tiempoViaje;
    // Calcular el tiempo de preparacion
    if (complejidadPrep == 'b'){
        tiempoPreparacion = 10;
    } else if (complejidadPrep == 'm'){
        tiempoPreparacion = 20;
    } else if (complejidadPrep == 'a'){
        tiempoPreparacion = 30;
    }
    if (not hayDisponibilidad){
        tiempoPreparacion += 5;
    }
    // Calcular el tiempo estimado de viaje
    tiempoViaje = (distancia/45)*60;
    if (esHoraPunta) tiempoViaje += 10;
    tiempoEstimadoViaje = trunc(tiempoViaje);
}

void ordenarLista(struct Lista &listaPedidos){
    struct Lista digitoUnidades[10];
    struct Lista digitoDecenas[10];
    struct Pedido pedido;
    int cifraUnidades, cifraDecenas;
    for(int i=0; i<10; i++) construir(digitoUnidades[i]);
    for(int i=0; i<10; i++) construir(digitoDecenas[i]);
    while (not esListaVacia(listaPedidos)){
        pedido = retornaCabeza(listaPedidos);
        eliminaCabeza(listaPedidos);
        cifraUnidades = (pedido.tiempoEstimadoTotal%10);
        insertarAlFinal(digitoUnidades[cifraUnidades], pedido);
    }
    for(int i=0; i<10; i++){
        if (longitud(digitoUnidades[i])>0){
            while (not esListaVacia(digitoUnidades[i])){
                pedido = retornaCabeza(digitoUnidades[i]);
                eliminaCabeza(digitoUnidades[i]);
                cifraDecenas = (pedido.tiempoEstimadoTotal/10);
                insertarAlFinal(digitoDecenas[cifraDecenas], pedido);
            }
        }
    }
    
    for(int i=0; i<10; i++){
        if (longitud(digitoDecenas[i])>0){
            while (not esListaVacia(digitoDecenas[i])){
                pedido = retornaCabeza(digitoDecenas[i]);
                eliminaCabeza(digitoDecenas[i]);
                insertarAlFinal(listaPedidos, pedido);
            }
        }
    }
    
}