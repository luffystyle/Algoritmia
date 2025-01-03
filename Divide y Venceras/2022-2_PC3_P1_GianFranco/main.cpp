#include <iostream>
#include <iomanip>

using namespace std;

void merge(int A[], int posicion_inicial, int posicion_medio, int posicion_final){
    int i, p, q;
    int longitud1, longitud2;

    longitud1 = (posicion_medio+1)-posicion_inicial;
    longitud2 = posicion_final-posicion_medio;

    int P[longitud1+1];
    int Q[longitud2+1];

    P[longitud1] = 999999;
    Q[longitud2] = 999999;

    for(i=posicion_inicial;i<=posicion_medio;i++) P[i-posicion_inicial]=A[i];
    for(i=posicion_medio+1;i<=posicion_final;i++) Q[i-(posicion_medio+1)]=A[i];
    p=q=0;
    for (i=posicion_inicial; i<=posicion_final;i++)
        if (P[p]<Q[q]) A[i]=P[p++];
        else A[i]=Q[q++];
}

//Todo el algoritmo O(n.logn)
void mergeSort(int A[], int posicion_inicial, int posicion_final){	
    if (posicion_inicial==posicion_final) return;

    int posicion_medio=(posicion_inicial+posicion_final)/2;
    mergeSort(A,posicion_inicial,posicion_medio); //complejidad O(log n)
    mergeSort(A,posicion_medio+1,posicion_final); //complejidad O(log n)	
    merge(A,posicion_inicial, posicion_medio, posicion_final); //complejidad O(n)
}

void pasarDeArregloAarregloAuxiliar(int arreglo[], int arregloAux[], int n) {
    for( int i = 0; i <n; i++) {
        arregloAux[i] = arreglo[i];
    }
}

int mezcla(int arreglo[], int ini, int fin, int medio, int menor_peso) {
    
    int contadorIzquierda = 0;
    int contadorDerecha = 0;
    for( int i = medio; i>=ini; i--) {
        if( arreglo[i] == menor_peso ) contadorIzquierda++;
        else break;
    }
    for( int i = medio+1; i<=fin; i++) {
        if( arreglo[i] == menor_peso ) contadorDerecha++;
        else break;
    }
    
    // Debo verificar que esos dos numero consecutivos son iguales
    if(arreglo[medio] == menor_peso and arreglo[medio+1] == menor_peso) {
        return contadorIzquierda + contadorDerecha;
    }
    
    return 1;
}

int mayor_dias_en_menor_peso(int izquierda, int derecha, int centro) {
    if (izquierda>derecha && izquierda>centro){
        return izquierda;
    }
    else {
        if(derecha>izquierda && derecha>centro) return derecha;
        else return centro; 
    }
}


int mayorTiempo(int arreglo[], int ini, int fin, int menor_peso) {
    
    
    // CASO BASE
    if(ini == fin) return 0;
    int medio;
    medio = (ini + fin)/2;
    
    int izquierda, derecha, centro;
    
    izquierda = mayorTiempo(arreglo, ini, medio, menor_peso);
    derecha = mayorTiempo(arreglo, medio + 1, fin, menor_peso);
    centro = mezcla(arreglo, ini, fin, medio, menor_peso);
    
    return mayor_dias_en_menor_peso(izquierda, derecha, centro);
}


int main(int argc, char** argv) {

//    int n, dia;
//    cout << "Ingrese el número de días: " ;
//    cin >> n;
//    int arreglo[n];
//
//    for( int i = 0; i<n; i++){
//        cin >> dia;
//        arreglo[i] = dia;
//    }
//    for( int i = 0; i<n; i++) cout << arreglo[i]<< " ";
    
    int n = 30;
    int arreglo[] = {98, 95, 92, 89, 91, 92, 89, 89, 92, 93, 94, 92 ,91 ,90, 88, 88, 88, 89, 90, 91,
                     88, 88, 90, 90, 92, 89, 90, 88, 90, 91};
    // Este arreglo auxiliar es donde guardo el original para luego volver al mismo arreglo
    int arregloAux[n];
    pasarDeArregloAarregloAuxiliar(arreglo, arregloAux, n);
    int ini = 0, fin = n-1;
    
    
    //Esto es de Orden O(n*log(n))
    mergeSort(arreglo, ini, fin);
    for( int i = 0; i < n; i++) cout << arreglo[i] << " ";
    cout << endl;
    
    int menor_peso = arreglo[0];// es el menor peso cuando ordenamos, tenemos de menor a mayor
    // entonces, obtenemos el primero del arreglo que es el menor porquqe está ordenado
  
    // con esteo vuelvo al arreglo original, estoy pasando los valores que guardé en arregloAux, para
    // dárselo al original y que vuelva ser como era al principio(original)
    pasarDeArregloAarregloAuxiliar(arregloAux, arreglo, n);
    for( int i = 0; i < n; i++) cout << arreglo[i] << " ";
    cout << endl;
    
    
    cout << "El menor peso registrado es: " << menor_peso << endl; 
    int mayor_tiempo_en_menor_peso = mayorTiempo(arreglo, ini, fin, menor_peso);
    cout << "La cantidad de días consecutivos que estuve en su menor peso es: " << mayor_tiempo_en_menor_peso << endl;
    
    
    
    return 0;
}

