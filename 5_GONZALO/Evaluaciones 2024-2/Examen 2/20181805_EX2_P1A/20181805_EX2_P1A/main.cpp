/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 7 de diciembre de 2024, 09:40 AM
 */

#include <iostream>
#include <iomanip>
#include "Lote.h"
#include "Funciones.h"

using namespace std;

int main(int argc, char** argv) {
    struct Lote arrLotes[] = {{15872, 3}, 
                              {15865, 4}, 
                              {15866, 4}, 
                              {14357, 6}, 
                              {14365, 6}, 
                              {14368, 6}, 
                              {14370, 6}, 
                              {19258, 8}, 
                              {19260, 8}};
    int n = 9;
    
    int cantProductos = 3;
    
    cout << "Para encontrar los lotes de " << cantProductos << " productos:" << endl;
    int loteInicial = encontrarLoteInicial(cantProductos, arrLotes, 0, n-1);
    cout << "Lote Inicial: " << loteInicial << endl;
    
    int loteFinal = encontrarLoteFinal(cantProductos, arrLotes, 0, n-1);
    cout << "Lote Final: " << loteFinal << endl;
    return 0;
}

