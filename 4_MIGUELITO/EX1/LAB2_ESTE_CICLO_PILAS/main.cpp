/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Miguelito
 *
 * Created on October 18, 2024, 9:17 PM
 */

#include <iostream>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

struct Efectivo {
    int id;
    int grado;
    int tiempo;
};

// Función para contar grupos
int contarGrupos(Efectivo efectivos[], int n) {
    int totalGrupos = 0;
    Pila pila;
    construir(pila); // Inicializa la pila

    for (int i = 0; i < n; ++i) {
        apilar(pila, efectivos[i].id); // Apila el efectivo actual
        totalGrupos++; // Contamos el grupo del efectivo individual

        // Contamos grupos adicionales
        int maxGrado = efectivos[i].grado;
        int maxTiempo = efectivos[i].tiempo;

        for (int j = i + 1; j < n; ++j) {
            // Solo continuamos si el siguiente efectivo tiene menor grado
            // o si tiene el mismo grado pero menor tiempo
            if (efectivos[j].grado < maxGrado || 
                (efectivos[j].grado == maxGrado && efectivos[j].tiempo < maxTiempo)) {
                
                apilar(pila, efectivos[j].id); // Apila el siguiente efectivo
                totalGrupos++; // Contamos el nuevo grupo formado
                // Actualizamos el máximo grado y tiempo
                if (efectivos[j].grado > maxGrado || 
                    (efectivos[j].grado == maxGrado && efectivos[j].tiempo > maxTiempo)) {
                    maxGrado = efectivos[j].grado;
                    maxTiempo = efectivos[j].tiempo;
                }
            } else {
                break; // Rompemos si encontramos un efectivo que no cumple
            }
        }

        // Desapilamos todos los elementos para la siguiente iteración
        while (!esPilaVacia(pila)) {
            desapilar(pila);
        }
    }

    return totalGrupos;
}

void formarGrupos(Efectivo efectivos[], int n, int index, Pila &pila, int &totalGrupos) {
    // Imprimimos el grupo actual que está en la pila
    cout << "{ ";
    imprimir(pila);  // Imprime los elementos actuales en la pila
    cout << " }" << endl;
    totalGrupos++;  // Cuenta cada combinación válida

    // Intentamos agregar más efectivos al grupo actual
    for (int i = index; i < n; ++i) {
        if (esPilaVacia(pila) || 
            (efectivos[i].grado <= efectivos[cima(pila)].grado && 
             efectivos[i].tiempo <= efectivos[cima(pila)].tiempo)) {

            apilar(pila, i);  // Añadimos el efectivo actual a la pila
            formarGrupos(efectivos, n, i + 1, pila, totalGrupos);  // Llamada recursiva
            desapilar(pila); // Retrocedemos (backtrack) para probar otra combinación
        }
    }
}

int main() {
    // Datos de entrada: Efectivos con grado y tiempo
    Efectivo efectivos[] = {
        {1, 2, 4},
        {2, 2, 1},
        {3, 1, 3}
    };
    int n = sizeof(efectivos) / sizeof(efectivos[0]);

    Pila pila;  // Inicializamos la pila
    int totalGrupos = 0;

    // Iniciamos la formación de grupos desde el primer efectivo
    formarGrupos(efectivos, n, 0, pila, totalGrupos);

    cout << "Se pueden formar " << totalGrupos << " agrupaciones." << endl;

    return 0;
}
