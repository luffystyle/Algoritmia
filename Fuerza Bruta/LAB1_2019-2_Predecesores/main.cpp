

/* 
 * File:   main.cpp
 * Author: miguel
 *
 * Created on September 3, 2024, 2:40 PM
 */

#include <iostream>
#include <cmath>

using namespace std;
#define COLUMNAS 5
#define N 8
#define P 250

void cargabinaria(int *cromosoma, int combinaciones, int numero) {
    
    int i;
    //Inicializando
    for(i = 0; i<N; i ++) cromosoma[i] = 0;
    i = 0;
    while(numero>0) {
        cromosoma[i] = numero%2;
        numero = numero/2;
        i++;
    }
}

bool consideroProyecto(int cromosoma[], int j) {
    
    //HAREMOS LOS CASOS CUANDO EL j marque el proyecto y este no cumpla con 
    if(j == 2 ) {
        if(cromosoma[0] == 1 and cromosoma[1] == 1) return true;
        else return false; 
    } 
    
    if(j == 5 ) {
        if(cromosoma[1] == 1) return true;
        else return false;
    } 
    
    if(j == 6 ) {
        if(cromosoma[5] == 1 and cromosoma[1] == 1) return true; 
        else return false;
    }  
    
    if(j == 7) {
        if(cromosoma[5] == 1 and cromosoma[1] == 1) return true;
        else return false;
    } 
    return true;
    
}


int main(int argc, char** argv) {

    int arreglo[][COLUMNAS] = { { 80, 150, 0, 0, 0}, 
                                { 20,  80, 0, 0, 0}, 
                                {100, 300, 1, 2, 0}, 
                                {100, 150, 0, 0, 0}, 
                                { 50,  80, 0, 0, 0}, 
                                { 10,  50, 2, 0, 0},    
                                { 50, 120, 6, 0, 0}, 
                                { 50, 150, 6, 0, 0}} ;
    
    
    // Como es fuerza bruta tengo que evaluar
    int combinaciones = (int)pow(2, N);
    int cromosoma[N], mayorCosto = 0, presu = 0;
    int cromosomaximo[N], sumaDeCostos, ganancias, maximaGanancia = 0;
    
    for(int i = 0; i<combinaciones; i++) {
        
        cargabinaria(cromosoma, combinaciones, i); 
        sumaDeCostos = 0;
        ganancias = 0;
        for(int j = 0; j<N; j++) { // RECORRIENDO EL CROMOSOMA
            
            if(cromosoma[j] == 1) { // Con esto selecciono los valores del cromosoma que son 1
                if(consideroProyecto(cromosoma, j) ) { // Si no lo considero es como el cromosoma[j] == 1, no lo cuento
                    sumaDeCostos += arreglo[j][0];
                    ganancias += arreglo[j][1];
                } else {
                    sumaDeCostos = 0;
                    break;
                }
            }
        }
        if(sumaDeCostos == 250 and ganancias >= maximaGanancia) {
            mayorCosto = sumaDeCostos;
            maximaGanancia = ganancias;
            for(int i = 0; i<N ; i++) cromosomaximo[i] = cromosoma[i]; // Le pasamos todos los valores al cromosoma maximo, guardando el cromo
        }
    }
    
    cout << "El Presupuesto que hemos gastado es " << mayorCosto << endl;
    cout << "La mayor ganancia es " << maximaGanancia << endl;
    for(int i = 0; i<N ; i++) cout << cromosomaximo[i] << " ";
    cout << endl;
    for(int i = 0; i<N ; i++) {
         if(cromosomaximo[i] == 1) cout << arreglo[i][0] << " ";
    }
    cout << endl; 
    
    return 0;
}
