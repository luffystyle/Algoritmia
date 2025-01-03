
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 7 de diciembre de 2024, 08:09 AM
 */


// PREGUNTA 1a
#include <iostream>
using namespace std;

int buscarLoteInicial(int *arr, int ini, int fin, int valor) { // Log(n)
    
    if(ini > fin) return -1;
    int med = (ini+fin)/2;
    
    
    if(arr[med] == valor) {
        if(arr[med] != arr[med-1] ) return med;
        return buscarLoteInicial(arr, ini, med, valor);
    }
        
    if(arr[med] > valor) 
        return buscarLoteInicial(arr, ini, med, valor);
    else
        return buscarLoteInicial(arr, med+1, fin, valor);
}

int buscarLoteFinal(int *arr, int ini, int fin, int valor) { // Log(n)
    
    if(ini > fin) return -1;
    int med = (ini+fin)/2;
    
    if(arr[med] == valor) {
        if(arr[med] != arr[med+1]) return med;
        return buscarLoteFinal(arr, med+1, fin, valor);
    }
        
    if(arr[med] > valor) 
        return buscarLoteFinal(arr, ini, med, valor);
    else
        return buscarLoteFinal(arr, med+1, fin, valor);
}

int main(int argc, char** argv) {

    int lote[] = {15872, 15865, 15866, 14357, 14365, 14368, 14370, 19258, 19260};
    int cantidades[] = {3, 4, 4, 6, 6, 6, 6, 8, 8};
    int n = sizeof(lote)/sizeof(lote[0]);
    
    int cantProductos = 8;
    
    int posLoteIni = buscarLoteInicial(cantidades, 0, n-1, cantProductos);
    int posLoteFinal = buscarLoteFinal(cantidades, 0, n-1, cantProductos);
    
    cout << "Para encontrar los lotes de " << cantProductos << " productos." << endl;
    cout << "Lote Inicial: " << lote[posLoteIni] << endl;
    cout << "Lote Final: " << lote[posLoteFinal] << endl;
    
    return 0;
}

