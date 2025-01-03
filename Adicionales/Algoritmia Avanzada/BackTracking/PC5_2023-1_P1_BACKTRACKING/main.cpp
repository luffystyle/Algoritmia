// PROBLEMAS DE GANANCIA CON REQUISITOS O PREDECESORES

#include <iostream>

using namespace std;
#define MAX 10
#define MAX_COLUMN 3

int lista[MAX];
int x = 0, y = 0;
int max_beneficio = 0;
int mejor_solucion[MAX];


int valida(int k, int n, int requisitos[][MAX_COLUMN], int control[]) {
    
    int i, contador = 0;
    if(requisitos[k][0] == -1) return 1;
    
    for(i = 0; i < MAX_COLUMN; i++){
        if(requisitos[k][i] == -1) break;
        for(int j = 0; j < n; j++) {
            if(requisitos[k][i] == lista[j]) {
                contador++;
                break;
            } 
        }
    }
    if( contador == i) return 1;
    return 0;
}


void empaca(int i, int n, int presupuesto, int inversion[], int requisitos[][MAX_COLUMN], 
                                                 int control[], int beneficio[]) {
    
    int z, beneficio_total ;
    
    if( i == n || presupuesto < 0) return ;
    
    if(inversion[i] == presupuesto && valida(i, y, requisitos, control)) {
        lista[y] = control[i];
        beneficio_total = 0;
        for(z = 0; z <= y; z++) {
            cout << "P" << lista[z] + 1<< " ";
            beneficio_total += beneficio[lista[z]];
        }
        cout << " - Retorno de inversion: " << beneficio_total << endl;
        
        if(beneficio_total > max_beneficio) {
            max_beneficio = beneficio_total;
            for( z = 0; z <= y; z++) mejor_solucion[z] = lista[z];
            mejor_solucion[z] = -1;
        }        
    }
    
    lista[y++] = control[i];
    if(valida(i, y, requisitos, control)) empaca(i+1, n, presupuesto - inversion[i], inversion, requisitos, control, beneficio);
    y--;    
    empaca(i+1, n, presupuesto, inversion, requisitos, control, beneficio);
}




int main(int argc, char** argv) {

    int n = 8;
    int control[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int inversion[] = {32, 8, 40, 40, 20, 4, 20, 20};
    int beneficio[] = {60, 32, 120, 60, 32, 20, 48, 60};
    int presupuesto = 100;
    
    int requisitos[][MAX_COLUMN] = {  {-1, -1, -1}, 
                                    {-1, -1, -1}, 
                                    { 0,  1, -1}, 
                                    {-1, -1, -1}, 
                                    {-1, -1, -1},
                                    { 1, -1, -1}, 
                                    { 5, -1, -1}, 
                                    { 5, -1, -1} };

    
    empaca(0, n, presupuesto, inversion, requisitos, control, beneficio);

    cout << "Conjunto de controles con mayor retorno de inversion: ";
    for( int i = 0; mejor_solucion[i] != -1; i++) cout << "P" << mejor_solucion[i] << " ";
    cout <<" - Retorno de la inversion: " << max_beneficio << endl;
    
    return 0;
}

