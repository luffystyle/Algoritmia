
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void cargaBinaria(int *cromosoma, int numero, int n, int cantEstados) {
    int i;
    for( i = 0; i<n; i++) cromosoma[i] = 0;
    i = 0;
    //i = n-1;
    while(numero>0) {
        cromosoma[i] = numero%cantEstados;
        numero = numero/cantEstados;
        i++;
    }
}

void HallarMenoryMayor(int *diff, int &mayor, int &menor, int m) {
    
    for( int i = 0; i<m; i++) {
        if(i == 0) {
            mayor = diff[i];
            menor = diff[i];
        } else {
            if(mayor < diff[i]) mayor = diff[i];
            if(menor > diff[i]) menor = diff[i];
        }
    }
}

// |1|0|4|2|1| puede ser un cromosomas
void solucion(int *cromosoma, int *camiones, int *paquetes, int n, int m, int &minimaDiff,int *solucionPaquetes){
    
    int auxCamion[m], mayor, menor ; // este auxiliar vamos ir cambiando porque las capacidades se actualizan
    for(int i = 0; i<m; i++) auxCamion[i] = camiones[i]; // lo guardo en un arreglo auxiliar
    int postCamion;
    for(int k = 0; k<n; k++) { // estoy recorriendo mi arreglo cromosoma
        postCamion = cromosoma[k]; // es un posicion o indice 
        if(paquetes[k]<=auxCamion[postCamion] ) {
            auxCamion[postCamion] =  auxCamion[postCamion] - paquetes[k];//actualizao mi arrcamionesAux
        } else return; // Peso del paquetes mayor al camion, me vuelvo al otor cromosoma porque estaria incorrecto  
    }
    int flag = 0;
    for(int i = 0; i<m; i++) {
        if(camiones[i] == auxCamion[i]) flag = 1; // esto NO usa todos los camiones
    }
    
    if(flag == 0) {
        HallarMenoryMayor(auxCamion, mayor, menor, m);
        if(minimaDiff > mayor - menor) {
            minimaDiff = mayor - menor;
            for( int j = 0; j<n; j++) solucionPaquetes[j] = cromosoma[j];
        }
    }
}

int main(int argc, char** argv) {
    int m = 4, n = 5;
    int cantEstados = 4;
    int cromosoma[n], solucionPaquetes[n];
    int camiones[m] = {25, 50, 100, 100};
    int paquetes[n] = {50, 20, 30, 50, 20};
    int combinaciones = (int)pow(m, n); 
    int minimaDiff = 99999;
    for( int i = 0; i<combinaciones; i++) {
        cargaBinaria(cromosoma, i, n, cantEstados); // llené el arreglo
        solucion(cromosoma, camiones, paquetes, n,  m, minimaDiff, solucionPaquetes);
    }
    // Solucion del problema
    cout << "Solucion: "  <<endl;
    for( int i = 0; i<n; i++) cout <<right<< setw(13) << "Paquete " << i + 1 ;
    cout << endl;
    for( int i = 0; i<n; i++) cout <<right<< setw(13)<< "Camion " << solucionPaquetes[i] + 1;
    cout << endl << endl <<"La máxima diferencia es " << minimaDiff << endl;    
    
    return 0;
}

