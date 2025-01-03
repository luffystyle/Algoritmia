// PREDECESORES


#include <iostream>
#define MAX 10
int lista[MAX];
int x = 0, y = 0;
int max_beneficio = 0;
int mejor_solucion[MAX];

using namespace std;

int valida(int k, int n, int requisitos[][3], int control[]) {
    
    int i, contador = 0;
    if(requisitos[k][0] == -1) return 1;
    
    for(i = 0; i < 3; i++) {
        if( requisitos[k][i] == -1) break;
        for(int j = 0; j < n; j++) {
            if( requisitos[k][i] == lista[j]) {
                contador++;
                break;
            }
        }
    }
    if( contador == i) return 1;
    return 0;
}


void empaca(int i, int n, int presupuesto, int inversion[], int requisitos[][3], int control[], int beneficio[]) {
    
    int z, beneficio_total;
    // Caso base: si se ha alcanzado el final del arreglo o el peso disponible es negativo, retorna
    if( i == n || presupuesto < 0) return;
    if( inversion[i] == presupuesto && valida(i, y, requisitos, control)) {
        // Si el presupuesto actual es igual al presupuesto disponible y cumple con las restricciones previas
        lista[y] = control[i]; // Se agrega el elemento a la lista de solución
        beneficio_total = 0;// Variable para almacenar el beneficio total de la solución actual
        for( z = 0; z <= y; z++) {
            cout << "Control: " << lista[z] + 1 << " ";
            beneficio_total += beneficio[lista[z]];// Calcula el beneficio total sumando los retornos individuales de los controles
        }
        cout << " - Retorno de la inversión: " << beneficio_total << endl;
        
        if( beneficio_total > max_beneficio) {
            max_beneficio = beneficio_total;
            for( z = 0; z <= y; z++) 
                mejor_solucion[z] = lista[z]; // Almacena el conjunto de controles con el máximo beneficio de inversión
            mejor_solucion[z] = -1; // Marca el final del conjunto de controles con -1
        }   
    }
    
    lista[y++] = control[i];
    if( valida(i, y, requisitos, control) ) 
        empaca(i+1, n, presupuesto - inversion[i], inversion, requisitos, control, beneficio);
    // BACKTRACKING
    y--;
    empaca(i+1, n, presupuesto, inversion, requisitos, control, beneficio);
    
}

int main(int argc, char** argv) {

    int n = 8;
    int control[] = {0, 1, 2, 3, 4, 5, 6, 7}; //proyectos
    int inversion[] = {32, 8, 40, 40, 20, 4, 20, 20}; //costo
        
    int requisitos[][3] = { {-1, -1, -1},  //predecesores
                            {-1, -1, -1}, 
                            { 0,  1, -1}, 
                            {-1, -1, -1}, 
                            {-1, -1, -1}, 
                            { 1, -1, -1}, 
                            { 5, -1, -1}, 
                            { 5, -1, -1}   };
    int presupuesto = 100;    
    
    int beneficio[] = {60, 32, 120, 60, 32, 20, 48, 60}; // retorno

    empaca(0, n, presupuesto, inversion, requisitos, control, beneficio);
    
    cout << endl << "Conjunto de controles con mayor retorno de inversion: ";
    for( int i = 0; mejor_solucion[i] != -1; i++) cout << "P" << mejor_solucion[i] << " ";
    cout <<" - Retorno de la inversion: " << max_beneficio << endl;
    
    return 0;
}

