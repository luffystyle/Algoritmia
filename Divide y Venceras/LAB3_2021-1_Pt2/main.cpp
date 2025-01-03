#include <iostream>
#define M 6
#define N 8
#define Porc 0.7
using namespace std;

void merge(int A[], int ini, int med, int fin) {
    
    int t1, t2, i, p, q;
    t1 = med - ini + 1;
    t2 = fin -med;
    
    int P[t1+1];
    int Q[t2+1];
    
    for(i = ini; i <= med; i++) P[i - ini] = A[i];
    for(i = med+1; i <= fin; i++) Q[i-(med+1)] = A[i];
    
    P[t1] = 9999999; Q[t2] = 9999999;
    p = q = 0;
    for( i= ini; i <= fin; i++) {
        if( P[p]< Q[q]) A[i] = P[p++];
        else A[i] = Q[q++];
    }   
}

void mergeSort(int A[], int ini, int fin) {
    
    if( ini == fin) return;
    int med = (ini + fin)/2;
    mergeSort(A, ini, med);
    mergeSort(A, med+1, fin);
    merge(A, ini, med, fin);
}

int procesar(int lote[], int ini, int fin, int contador) {
    
    int medio = (fin + ini)/2;
    
    if(ini == fin) {
        if(lote[medio] == 1)
            contador ++;
        
        return contador;
    } 

    if( lote[medio] == 1 ){
        contador += fin - medio + 1;
        procesar(lote, ini, medio-1, contador);
    } else{
        
        procesar(lote, medio + 1, fin, contador);
    }
}

// CUANDO USAS LOGARITMOS EN COMPLEJIJDAD ES PORQUE ES DIVIDE Y VENCERAS EN LA SOLUCION
int main(int argc, char** argv) {

    int matriz[][8] = {  {0, 0, 0, 1, 1, 0, 2, 2},
                         {1, 0, 1, 1, 1, 0,  1,  0},
                         {0, 1, 1, 1, 1, 1,  1,  1},                     
                         {1, 1, 1, 1, 1, 0,  1, 2},
                         {1, 0, 0, 0, 0, 1, 2, 2},
                         {1, 1, 0, 1, 0, 1,  1, 2}
        };

    // estoy llenando los valores que no pasan como 0,
    // y tbm solo los valores que están, sin el -1, por ejemplo en la primera fila
    // hay 6 valores de 8   
    int resultado[][2] = {  {6, 0},
                            {8, 0},
                            {8, 0},
                            {7, 0},
                            {6, 0},
                            {7, 0},
                            };

    //tenemos que ordenar cada uno de los lotes
    
    for( int i = 0; i<M; i++) {
        // para ordenar usamos el merge sort
        mergeSort(matriz[i], 0, resultado[i][0]-1);
    }
    
    for(int i = 0; i<M; i++) {
        for( int j = 0; j < resultado[i][0]; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }

    double porcentaje;
    char estado;
    cout << "LOTE "<< "   ESTADO" << endl;
    for( int i = 0; i<M; i++) {
        resultado[i][1] = procesar(matriz[i], 0, resultado[i][0] - 1, 0);
        porcentaje = (double)resultado[i][1]/resultado[i][0];
        cout << i + 1;
        if(porcentaje>=Porc){
            cout << "       APROBADO";
        } else {
            cout << "       RECHAZADO";
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}

