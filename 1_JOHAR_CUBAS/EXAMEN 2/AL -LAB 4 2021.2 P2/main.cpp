/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */
//examen final 2023.2


#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstddef>

using namespace std;
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "NodoArbol.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"


struct NodoArbol * crearNuevoNodoArbolNew(struct NodoArbol * arbolIzquierdo, 
                               char letra, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->letra = letra;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBinarioNew(struct NodoArbol* & arbol, struct NodoArbol * arbolIzquierdo,
                         char letra, struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNew(arbolIzquierdo, letra, arbolDerecho);
    arbol = nuevoNodo;
}

int letraExiste(char *palabra,char letra){
    int existe =0;
    for(int i=0;palabra[i]!='\0';i++){
        if(letra == palabra[i]){
            existe = 1;
        }
    }
    return existe;
}



int validaLetras(char *palabra,char *palabraAux,int cont){
    char aux[cont];
    int existe,contador=0;
    for(int i=0;i<cont;i++) aux[i]=palabraAux[i];
    for(int i=0;palabra[i]!='\0';i++){
        existe = 0;
        contador++;
        for(int j=0;j<cont;j++){
            if(aux[j]==palabra[i]){
                existe =1;
                aux[j]=' ';
                break;
            }
        }
        if(existe !=1){
            break;
        }
        
    }
    if(existe ==1 and contador == cont){
        return 1;
    }else{
        return 0;
    }
    
}

int validarExistenciaPalabras(struct NodoArbol *raiz,char *palabra,char *palabraAux,int cantPalabras,int cont){
    if(raiz == nullptr) return 0;
    
    if(letraExiste(palabra,raiz->letra)==1){
        palabraAux[cont++] = raiz->letra;
    }else{
        return 0;
    }
    
    if(raiz->derecha==nullptr and raiz->izquierda == nullptr){
        if(validaLetras(palabra,palabraAux,cont)==1){
            return 1;
        }else{
            return 0;
        }
    }
    
    return validarExistenciaPalabras(raiz->izquierda,palabra,palabraAux,cantPalabras,cont) + validarExistenciaPalabras(raiz->derecha,palabra,palabraAux,cantPalabras,cont);
    
}



int main(int argc, char** argv) {
    struct ArbolBinario arbol;
    construir(arbol);
    
    plantarArbolBinarioNew(arbol.raiz,nullptr,'L',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda,nullptr,'D',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->izquierda,nullptr,'E',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha,nullptr,'E',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->izquierda,nullptr,'R',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->derecha,nullptr,'G',nullptr);
    plantarArbolBinarioNew(arbol.raiz->izquierda->derecha->derecha->izquierda,nullptr,'T',nullptr);
    
    plantarArbolBinarioNew(arbol.raiz->derecha,nullptr,'I',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda,nullptr,'C',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda,nullptr,'C',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda->izquierda,nullptr,'O',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha,nullptr,'N',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda,nullptr,'A',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda->izquierda,nullptr,'F',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda->derecha,nullptr,'T',nullptr);
    
    char palabra[6][8]={{'H','I','J','O','\0'},
                        {'F','I','N','A','L','\0'},
                        {'M','U','N','D','O','\0'},
                        {'D','E','L','\0'},
                        {'D','I','A','\0'},
                        {'C','I','C','L','O','\0'}};
    int cantPalabras=6;
    char letras[7];
    for(int i=0;i<cantPalabras;i++){
        int valido = validarExistenciaPalabras(arbol.raiz,palabra[i],letras,cantPalabras,0);
        if(valido ==1){
            for(int j=0;palabra[i][j]!='\0';j++){
                cout<<palabra[i][j];
            }
            cout<<endl;
        }
        
    }
    
    return 0;
}

















