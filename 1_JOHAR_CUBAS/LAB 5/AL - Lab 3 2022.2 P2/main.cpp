/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"


void determinarBomba(int *arr, int ini, int fin, int &col, int &max) {
    // Caso base: cuando ini es igual a fin
    if (ini == fin) {
        if (arr[ini] > max) {
            max = arr[ini];
            col = ini;
        }
        return;
    }
    int med = (ini + fin) / 2;
    
    // Verificar si el elemento en med es un pico
    if (( arr[med] > arr[med - 1]) && (arr[med] > arr[med + 1])) {
        if (arr[med] > max) {
            max = arr[med];
            col = med;
        }
        return;
    }

    // Si no, decidir hacia qué lado moverse
    if (arr[med] < arr[med + 1]) {
        determinarBomba(arr, med + 1, fin, col, max);
    } else {
        determinarBomba(arr, ini, med - 1, col, max);
    }
}


int subeyBaja(int *arr,int ini,int fin){
    if(ini==fin){
        return arr[ini];
    }
    int med=(ini+fin)/2;
    if(arr[med] > arr[med-1] and arr[med] > arr[med+1]){
        return arr[med];
    }
    if(arr[med]<arr[med+1]){
        return subeyBaja(arr,med+1,fin);
    }else{
        return subeyBaja(arr,ini,med-1);
    }
}
void columnasEncontrado(int matriz[][7],int ini,int fin,int col,int fil,int &encontrado){ //O(logn)
    if(ini == fin){
        encontrado = ini;
        return;
    }
    int med = (ini+fin)/2;
    if(( matriz[med][col] > matriz[med - 1][col]) && (matriz[med][col] > matriz[med + 1][col])){
        encontrado = med;
        return ;
    }
    if(matriz[med][col]<matriz[med+1][col]){
        columnasEncontrado(matriz,med+1,fin,col,fil,encontrado);
    }else{
        columnasEncontrado(matriz,ini,med-1,col,fil,encontrado);
    }
}

int encontrarFila(int matriz[][7],int col,int fil){ // O(logn)
    int encontrado = -1;
    columnasEncontrado(matriz,0,fil-1,col,fil,encontrado);
    return encontrado;
}

void  hallarBomba(int matriz[][7],int m,int n){
   //filas
    int col,max=-999999;
    int medio=(0 + n-1)/2;
    for(int i=0;i<m;i++){
        if(matriz[i][medio+1]!=0 || matriz[i][medio-1]!=0){
            determinarBomba(matriz[i],0,n-1,col,max);
        }
    }
    cout << "La columna con la mayor potencia de bomba es: " << col << " con una potencia de: " << max << endl;
//parte b)
    cout<<"La fila con el mayor impacto es la "<<encontrarFila(matriz,col,m);
}



int main(int argc, char** argv) {
    int matriz[10][7]={{0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0},
                       {0,0,0,0,1,1,1},
                       {0,0,0,0,1,2,2},
                       {0,0,0,0,1,2,3},
                       {0,0,0,0,1,2,2},
                       {0,0,0,0,1,1,1},
                       {0,0,0,0,0,0,0}};
    int filas=10,colums=7;
    
   hallarBomba(matriz,filas,colums);
   int arr[7]={0,0,0,0,0,0,0};
   cout<<endl<<subeyBaja(arr,0,6); 
    return 0;
}

