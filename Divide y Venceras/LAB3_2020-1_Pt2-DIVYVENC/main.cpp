
#include <iostream>

using namespace std;
#define N 8


void merge(int A[], int inicial, int medio, int final){
	int longitud1, longitud2, i, p, q;
	
    longitud1=(medio+1)-inicial;//primera mitad del arreglo
    longitud2=final-medio;//segunda mitad del arreglo

    int P[longitud1+1];
    int Q[longitud2+1];
    //agrego los valores mayores de ambos arreglos
    P[longitud1]=999999;
    Q[longitud2]=999999;
    //copiamos los valores desde A hacia los arreglos auxiliares P y Q
    for (i=inicial;i<=medio;i++) P[i-inicial]=A[i];
    for (i=medio+1;i<=final;i++) Q[i-(medio+1)]=A[i];
    p=q=0;
    for (i=inicial;i<=final;i++){
        if (P[p]<Q[q]) A[i]=P[p++];
        else A[i]=Q[q++];
    }
}

void mergeSort(int A[], int inicial, int final){
    if (inicial==final) return;	
    int medio=(inicial+final)/2;
    mergeSort(A,inicial, medio);//logn
    mergeSort(A,medio+1, final);//logn
    merge(A, inicial, medio, final);
}




void ordenarAreglos(int codigos[], int anhos[], int niveles[], int sueldos[]) {
    mergeSort(codigos, 0, N-1);
    mergeSort(anhos, 0, N-1);
    mergeSort(niveles, 0, N-1);
    mergeSort(sueldos, 0, N-1);
        
    for( int i = 0; i<N; i++) cout << codigos[i] << " ";
    cout << endl;
    for( int i = 0; i<N; i++) cout << anhos[i] << " ";
    cout << endl;
    for( int i = 0; i<N; i++) cout << niveles[i] << " ";
    cout << endl;
    for( int i = 0; i<N; i++) cout << sueldos[i] << " ";
    cout << endl;
}

int cumpleAnho(int anhos[], int ini, int fin) {
    
}

int cumpleNivel(int niveles[], int ini, int fin) {
    
}

int cumplePrepuesto(int sueldos[], int ini, int fin) {
    
}


int obtenerCantConsultores(int anho, int nivel, int presupuesto, int anhos[], int niveles[],  int sueldos[], int ini, int fin, int cont) {
    
    int medio = (ini + fin)/2 ;
    
    if(ini > fin ) return cont;
    
    
    
}



int main(int argc, char** argv)
{

    int codigos[N] = {1320, 1317, 1021, 1909, 1000, 1989, 1590, 1489};
    int anhos[N] = {10, 12, 10, 3, 10, 2, 5, 4};
    int niveles[N] = {2, 3, 3, 2, 2, 1, 1, 1};
    int sueldos[N] = {5, 8, 7, 6, 6, 3, 4, 4};
    int contador = 0;
    int anho = 5, nivel = 2, P = 12; 

    ordenarAreglos(codigos, anhos, niveles, sueldos);

    //cin >> anho >> nivel >> presupuesto;
    int cantConsultores = obtenerCantConsultores(anho, nivel, P, anhos, niveles, sueldos, 0, N-1, contador);
     
    

    return 0;
}

