/* 
 * File:   main.cpp
 * Author: Miguel ANgel Torre Villanueva
 * Codigo : 20175525
 * Created on 7 de diciembre de 2024, 09:52 AM
 */
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
// PROBLEMA 1b


struct Plato{
    string nombre;
    int cantidadDisponible;
    int cantidadReservada;
    double porcentajeReservas;
};


void ordenar(double *arr, int ini, int med, int fin, double pivote) {
    

    int contadorizq = 0;
    int contdaroDer = 0;
    int variable;
    for(int i = ini; i<=fin; i++){
        variable = arr[i];
        if(arr[i] < pivote) {
             arr[ini + contadorizq] = arr[i];
             arr[i] = variable;
             contadorizq++;
        }
        if(arr[i] > pivote) {
             arr[contdaroDer+med] = arr[i];
             arr[i] = variable;
             contdaroDer++;
        }
    }
    
}


void solucion(double *arr, int ini,int fin, double pivote) {
    
    
    if(ini == fin) return;
    int med = (ini+fin)/2;
    
    solucion(arr, ini, med, pivote);
    solucion(arr, med+1, fin, pivote);
    ordenar(arr, ini, med, fin, pivote);
    
}


int main(int argc, char** argv) {

    
    Plato plato1 = {"Lomo Saltado", 50, 30, ((double)30/50)*100};
    Plato plato2 = {"Ceviche", 40, 35, ((double)35/40)*100};
    Plato plato3 = {"Aji de Gallina", 30, 10, ((double)10/30)*100};
    Plato plato4 = {"Causa Limeña", 20, 20, ((double)20/20)*100};
    Plato plato5 = {"Arroz Con Pollo", 60, 45, ((double)45/60)*100};
    
    
    int n = 5;
    
    double arreglo[5] = {plato1.porcentajeReservas, plato2.porcentajeReservas,
                    plato3.porcentajeReservas, plato4.porcentajeReservas, plato5.porcentajeReservas};
    
    for(int i = 0; i<5; i++) 
        cout << arreglo[i] << " "; 
    cout << endl; 
    
    // EL PIVOETE es arreglo[n-1]
    solucion(arreglo, 0, n-1, arreglo[n-1]);
    
    for(int i = 0; i<5; i++) 
        cout << arreglo[i] << " "; 
    cout << endl; 
    
    
    cout << "Top " << 3 << " platos con mayor pocertanje  de reservas" << endl;
//    for(int i = 0; i<3; i++) {
//        cout <<
//    }
    
    cout << plato4.nombre << "-" << plato4.porcentajeReservas << "%" << endl;
    cout << plato2.nombre << "-" << plato2.porcentajeReservas << "%" << endl;
    cout << plato5.nombre << "-" << plato5.porcentajeReservas << "%" << endl;
    
    return 0;
}

