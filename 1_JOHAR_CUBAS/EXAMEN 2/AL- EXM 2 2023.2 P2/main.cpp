/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"

using namespace std;

struct NodoArbol * crearNuevoNodoArbolNew(struct NodoArbol * arbolIzquierdo, 
                               char letra, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->letra = letra;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBinarioNew(struct NodoArbol* &raiz, struct NodoArbol *arbolIzquierdo,
                         char letra, struct NodoArbol *arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbolNew(arbolIzquierdo, letra, arbolDerecho);
    raiz = nuevoNodo;
}

int validaLetraExiste(char *palabras,char letra){
    for(int i=0;palabras[i]!='\0';i++){
        if(palabras[i] == letra){
            return 1;
        }
    }
    return 0;
}

int validacionPalabra(char *palabra,char *letras,int pos){
    char aux[pos];
    for(int i=0;i<pos;i++) aux[i]=letras[i];
    int contador =0;
    int existe;
    for(int i=0;palabra[i]!='\0';i++){
        existe=0;
        contador++;
        for(int j=0;j<pos;j++){
            if(palabra[i]==letras[j]){
                letras[j]=' ';
                existe = 1;
                break;
            }
        }
        if(existe==0){
            break;
        }
    }
    if(existe ==1 and contador == pos){
        return 1;
    }else{
        return 0;
    }
    
}

int existePalabra(char *letras,char *palabras,int cantPalabras,struct NodoArbol *raiz,int pos){
    if(raiz == nullptr){
        return 0;
    }
    if(validaLetraExiste(palabras,raiz->letra)==1){
        letras[pos++]= raiz->letra;
    }else{
        return 0;
    }
    if(raiz->izquierda == nullptr and raiz->derecha == nullptr){
        if(validacionPalabra(palabras,letras,pos)==1){
            return 1;
        }else {
            return 0;
        }
    }
    
    
    return existePalabra(letras,palabras,cantPalabras,raiz->izquierda,pos) + existePalabra(letras,palabras,cantPalabras,raiz->derecha,pos) ;
}






int main(int argc, char** argv) {
    int cantPalabras = 6;
    char palabras[6][7]={{'H','I','J','O','\0'},
                         {'F','I','N','A','L','\0'},
                         {'M','U','N','D','O','\0'},
                         {'D','E','L','\0'},
                         {'D','I','A','\0'},
                         {'C','I','C','L','O','\0'}};
    
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
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha,nullptr,'N',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda,nullptr,'C',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->izquierda->izquierda->izquierda,nullptr,'O',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda,nullptr,'A',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda->izquierda,nullptr,'F',nullptr);
    plantarArbolBinarioNew(arbol.raiz->derecha->derecha->izquierda->derecha,nullptr,'T',nullptr);
    
    char letras[7];
    for(int i=0;i<cantPalabras;i++){
        int valido = existePalabra(letras,palabras[i],cantPalabras,arbol.raiz,0);
        if(valido!=0){
            for(int j=0;palabras[i][j]!='\0';j++){
                cout<<palabras[i][j];
            }
            cout<<endl;
        }
    }
    
    return 0;
}






























