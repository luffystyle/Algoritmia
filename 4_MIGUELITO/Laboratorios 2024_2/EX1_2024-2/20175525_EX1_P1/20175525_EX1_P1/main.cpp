
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 19 de octubre de 2024, 08:47 AM
 */

#include <iostream>

using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

void solucion(int *fila, int n, int & posicion, int &cantPilas) {
    
    Pila P1;
    construir(P1);
    
    int contador;
    int max = 0;
    
    for(int i = 0; i<n; i++) {
//        int valor = fila[i];
//        apilar(P1, fila[i]);
//        
//        while(!esPilaVacia( P1)) desapilar(P1);
        contador = 0;
        if(i == 0) { // miro a la derecha solamente
            if( fila[i] <= fila[i+1]) {
                contador = 1;
                //break;
            } else {
                //recorro hasta que tenga un tope
                for(int j = i+1; j<n; j++) {
                    contador++;
                    if(fila[j] <= fila[j+1]) {
                        break;
                    }
                }
            }
        } else if(i = n -1) { // observo hacia mi izquierda
            if( fila[i] <= fila[i-1]) {
                contador = 1;
                //break;
            } else {
                //recorro hasta que tenga un tope
                for(int j = n-2; j>=0; j--) {
                    contador++;
                    if(fila[j] <= fila[j-1]) {
                        break;
                    }
                }
            }
        } else {
            int miniCont = 0;
            for(int j = 0 ; j<i; j++) {
                apilar(P1, fila[j]); // apilamos para cuando  vayamos a la otra iteracion sepamos cuanto  hemos apilados
                if(fila[j]<= fila[j+1]) break;
            }
             for(int j = i+1 ; j<n; j++) { // desde la posicion hacia la derecha
                 miniCont++;
                if(fila[j]<= fila[j+1]) break;
            }
            contador = P1.lista.longitud +miniCont;
        }
        if(max<contador) { // hallar la maxima
            posicion = i;
            cantPilas = contador;
            max = contador;
        }
    }

}
    
    

int main(int argc, char** argv) {

    
    
    int posicion, cantPilas;
    
    int fila[] = {1, 3, 6, 4};
    int n = 4;
    
    
    solucion(fila, n, posicion, cantPilas);
    
    cout << "Posicion = " << posicion << " , " << cantPilas << " pilas pequeñas alrededos" << endl;
    return 0;
}

