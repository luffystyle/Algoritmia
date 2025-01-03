
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 14 de septiembre de 2024, 08:09 AM
 */
//PREGUNTA 1 fuerza bruta

#include <iostream>
#include <cmath>

using namespace std;

//NECESITO ALMACENAR ESA ARREGLO DE LETRAS
// como hecho en clase
void inicializarPalabra(char palabra[], char palGuardad[], int max_palabra) {
    for(int i = 0; i<max_palabra; i++) {
        palabra[i] = palGuardad[i];
    }
}

bool pertenece(int cromosoma[], char letras[], char palabra[], int pos, int cantPalabra ){
    //disminuimos
    for(int i = 0; i<cantPalabra; i++) {
        if(letras[pos] == palabra[i]) {
            palabra[i] = '-'; // le pongo guion
            return true; // es decir pertenece
        }
    }
    return false;
}


void cargaBinaria(int cromosoma[], int num, int n){
    int i;
    for( i = 0; i<n; i++) cromosoma[i] = 0;
    i = 0;
    while(num>0) {
        cromosoma[i] = num%2;
        num = num/2;
        i++;
    }
}


int main(int argc, char** argv) {

    int max_palabra = 8;
    int max_cant_Pal = 8;
    int max_letras_Producir = 10;// es 10;
    char letras[] = {'G', 'A', 'L', 'A', 'O', 'G', 'L', 'M'};
    
    
//    char palabra[] = {'G', 'O', 'L'}; 
//    char palabraOriginal[]  = {'G', 'O', 'L'}; 
    
    char palabra[] = {'G', 'A', 'L', 'A'}; 
    char palabraOriginal[]  = {'G', 'A', 'L', 'A'}; 
    
//    char palabra[] = { 'A', 'L', 'A'}; 
//    char palabraOriginal[]  = { 'A', 'L', 'A'};
    
//    char palabra[] = { 'L', 'O', 'M', 'A'}; 
//    char palabraOriginal[]  = { 'L', 'O', 'M', 'A'}; 
    
   
    int contador = 0;
    int canPalabra = 4;
    int cantLetras = 8;
    int guardarCantidad = 0;
    int comb = (int) pow(2, cantLetras);
    int cromosoma[cantLetras];
    int p = 0;
    for(int i = 0; i<comb; i++) {
        inicializarPalabra(palabra, palabraOriginal, canPalabra);
        cargaBinaria(cromosoma, i, cantLetras);
        //recorrer cromoso
        // voy borrando las letras segun busco y cuando temrine el cromo lo inicializo
        // hecho como en clase del profesor
        //inicializarPalabra(palabra, palabraOriginal, canPalabra);
        //contador = 0;
        p = 0;
        for(int j = 0; j<cantLetras; j++) { // recorre el cromosoma
            
            if(cromosoma[j] == 1){
                //p = 0; // contador de las letras que son validas
                if(pertenece(cromosoma, letras, palabra, j, canPalabra)) {
                    p++;
                } 
            }
            
        }
        if(p == canPalabra ) { // encontró
            guardarCantidad++;
            break;
        }
        
        
        
    }
    cout << "La palabra " ;
    for(int k = 0; k<canPalabra; k++) {
        cout << palabraOriginal[k];
    }
    cout << " tiene " << guardarCantidad << " combinaciones de letras" << endl;
    
    return 0;
}

