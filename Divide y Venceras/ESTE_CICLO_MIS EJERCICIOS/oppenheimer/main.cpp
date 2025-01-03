
/* 
 * File:   main.cpp
 * Author: miguel
 *
 * Created on November 2, 2024, 6:18 AM
 */

#include <iostream>

using namespace std;

int buscarIni(int *arr, int n) {
    int ini = 0, fin = n;
    while(ini<fin) {
        int med = (ini + fin)/2;
        if(arr[med] > 0) fin = med;
        else ini = med+1;
    }
    return ini;
}


int buscarIniRec(int *arr, int ini, int fin) {
    if (ini >= fin) return ini;  // Caso base: ini apunta a la posición que buscamos
    
    int med = (ini + fin) / 2;
    if (arr[med] > 0) return buscarIniRec(arr, ini, med);      // Llama a la mitad izquierda
    else return buscarIniRec(arr, med + 1, fin);               // Llama a la mitad derecha
}


int potenciaMaxima(int *arr, int ini, int fin) {
    
    if(ini == fin) return arr[ini];
    
    int med = (ini + fin)/2;
    
    if(arr[med]>arr[med+1])
        return potenciaMaxima(arr, ini, med);
    else 
        return potenciaMaxima(arr, med+1, fin);
    
}
void buscarTriple(int *arr, int ini, int fin) {
    if (ini > fin) return;  // Caso base de fin de búsqueda
    if (ini == fin) {
        cout << "El número que aparece tres veces es: " << arr[ini] << endl;
        return;
    }
    
    int med = (ini + fin) / 2;
    
    // Caso donde `med` está en la posición inicial del trío de elementos iguales
    if (med % 2 == 0) {
        if (arr[med] == arr[med + 1]) {
            buscarTriple(arr, med + 2, fin);  // Continuar en la mitad derecha
        } else {
            buscarTriple(arr, ini, med);      // Buscar en la mitad izquierda
        }
    }
    // Caso donde `med` está en la posición media de los tres elementos
    else {
        if (arr[med] == arr[med - 1]) {
            buscarTriple(arr, med + 1, fin);  // Continuar en la mitad derecha
        } else {
            buscarTriple(arr, ini, med - 1);  // Buscar en la mitad izquierda
        }
    }
}

void buscaSolo(int *arr,int ini,int fin){
   if(ini>fin) return; 
   if(ini==fin){
       cout <<"El solitario es: "<<arr[ini] << endl;
       return;
   }   
    int med=(ini+fin)/2;
   
   if(med%2==0){
       if(arr[med]==arr[med+1])
           buscaSolo(arr,med+2,fin);
       else
           buscaSolo(arr,ini,med);
    }   
    else{
       if(arr[med]==arr[med-1])
           buscaSolo(arr,med+1,fin);
       else
           buscaSolo(arr,ini,med-1);
   }
}



int main(int argc, char** argv) {
    
    int arr[] = {0, -1, 0, -1, 0, 1, 1, 2, 2, 3, 2, 2, 1, 1};
    //int arr[] = {-1, 0, -1, 0, 1, 1, 2, 2, 3, 3, 4, 3, 3, 2, 2, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    //cout << buscarIni(arr, n)<< endl;
    int pos =  buscarIniRec(arr, 0, n-1);
    cout << pos << endl;
    cout << "la potencia es " << potenciaMaxima(arr, pos, n-1) <<endl;
            
    //pos =  buscarIniRec(arr, 0, n-1);
    //buscaSolo(arr, pos, n-1);
    
    int arreglo[] = {1, 1, 2, 2, 2, 3, 3, 5, 5, 6, 6, 7, 7};
    int m = sizeof(arreglo)/sizeof(arreglo[0]);
    buscaSolo(arr, pos, n-1);
    buscarTriple(arreglo, 0, m-1);
    
    return 0;    
}

