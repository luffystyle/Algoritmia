/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo> 20175525
 * Created on December 3, 2024, 12:53 PM
 */

#include <iostream>
#include <algorithm>

using namespace std;

int encontrarMinimo(int *arr, int ini, int fin) { //LOG(N)
    
    int izq, der, med;
    
    if(ini == fin) return arr[ini];
    med = (ini+fin)/2;
    
    //CUANDO NO SE DIVIDE EN DOS CAMINOS LA COMPLEJIDAD ES LOG(N)
    izq = encontrarMinimo(arr, ini, med);
    der = encontrarMinimo(arr, med+1, fin);
    
    return min(izq, der);
}

int encontrarMaximo(int *arr, int ini, int fin) { 
    
    int izq, der, med;
    
    if(ini == fin) return arr[ini];
    med = (ini+fin)/2;
    
    izq = encontrarMaximo(arr, ini, med);
    der = encontrarMaximo(arr, med+1, fin);
    
    return max(izq, der);
}




int mezklita(int *arr, int ini, int med, int fin, int minimoValor) {
    
    int cantIzq = 0, cantDer = 0;
    
    for(int i = med; i>=ini; i--) {
        if(minimoValor == arr[i]) {
            cantIzq++;
        } else break; //ESTO INTERRUMPE LA CONSECUCION
    }
    
    for(int i = med+1; i<=fin; i++) {
        if(minimoValor == arr[i]) {
            cantDer++;
        } else break;
    }
    return cantIzq+cantDer;
}

int maximoIntervalo(int *arr, int ini, int fin, int minimoValor) {
    
    int med, izq, der, centro;
    
    if(ini == fin) {
        if(arr[ini] == minimoValor) return 1; // cuenta uno si es igual
        else return 0;
    }
    
    med = (ini+fin)/2;
    
    izq = maximoIntervalo(arr, ini, med, minimoValor);
    der = maximoIntervalo(arr, med+1, fin, minimoValor);
    centro = mezklita(arr, ini, med, fin, minimoValor);

    return max(izq, max(der, centro));
}

int buscarSolo(int *arr, int ini, int fin) {
    
    if(ini == fin) {
        return arr[ini];
    }
    if(ini>fin) return -1;
    int med = (ini+fin)/2;
    if(med%2==0) { // que sea par
        if(arr[med] == arr[med-1])
            return buscarSolo(arr, med+1, fin);
        else
            return buscarSolo(arr, ini, med);
    } else {
        if(arr[med] == arr[med+1])
            return buscarSolo(arr, med+2, fin);
        else
            return buscarSolo(arr, ini, med);
    }
}


int main(int argc, char** argv) {

    
    int arr[] = {98, 95, 92, 89, 91, 92, 89, 89, 92, 93, 94, 92, 91, 90, 88, 88, 88, 89, 90, 91, 88, 88, 90, 90,
                92, 89, 90, 88, 90, 91};
//    int arr2[] = {98, 95, 92, 89, 91, 92, 89, 89, 92, 93, 94, 92, 91, 90, 88, 88, 88, 89, 90, 91, 88, 88, 90, 90,
//                92, 89, 90, 88, 90, 91};
    
    // ESTO ES EN EL CASO QUE POR EJEMPLO A LA DERECHA HAYA MAS QUE EN EL CENTRO
//    int arr2[] = {98, 95, 92, 89, 91, 92, 89, 89, 92, 93, 94, 92, 91, 90, 88, 88, 88, 89, 90, 91, 88, 88, 88, 88,
//                88, 88, 88, 88, 90, 91}
    
    
    //int arr[] = {};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    
    int ini = 0, fin = n-1;
    
    
    int minimo = encontrarMinimo(arr,  ini, fin);
//    for(int i = 0; i<n; i++) cout << arr[i] << " ";
    
    
    cout << "El peso menor fue " << minimo << endl;   
    cout << maximoIntervalo(arr, ini, fin, minimo);
    
    return 0;
}

