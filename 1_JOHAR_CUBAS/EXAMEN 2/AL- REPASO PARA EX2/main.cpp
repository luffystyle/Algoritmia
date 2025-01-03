/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "NodoArbol.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"

int validarLetra(char * palabra,char letra){
    int valido = 0;
    for(int i = 0;palabra[i]!='\0';i++){
        if(letra == palabra[i]){
            valido = 1;
            break;
        }        
    }
    return valido;
}

int validarPalabraExiste(char *palabra,char *palabraAux,int pos){
    char aux[pos];
    for(int i=0;i<pos;i++) aux[i]=palabraAux[i];
    int existe,contador =0;
    for(int i=0;palabra[i]!='\0';i++){
        existe = 0;
        contador++;
        for(int j=0;j<pos;j++){
            if(palabra[i] == aux[j]){
                existe=1;
                aux[j]=' ';
                break;
            }
        }
        if(existe==0){
            break;
        }
    }
    if(contador == pos and existe ==1){
        return 1;
    }else{
        return 0;
    }
    
}

int validarPalabra(struct NodoArbol *raiz, char *palabra,char *palabraAux,int pos){
    if(raiz == nullptr) return 0;
    
    if(validarLetra(palabra,raiz->letra)==1){
        palabraAux[pos++] = raiz->letra;
    }else{
        return 0 ;
    }
    if(raiz->derecha==nullptr and raiz->izquierda == nullptr){
        if(validarPalabraExiste(palabra,palabraAux,pos)==1){
            return 1;
        }else{
            return 0;
        }
    }
    
    return validarPalabra(raiz->izquierda,palabra,palabraAux,pos) + validarPalabra(raiz->derecha,palabra,palabraAux,pos);
}

int main(int argc, char** argv) {
    
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,30,'L');
    insertar(arbol,20,'D');
    insertar(arbol,40,'I');
    insertar(arbol,15,'E');
    insertar(arbol,23,'E');
    insertar(arbol,22,'R');
    insertar(arbol,25,'G');
    insertar(arbol,24,'T');
    insertar(arbol,38,'C');
    insertar(arbol,37,'C');
    insertar(arbol,36,'O');
    insertar(arbol,45,'N');
    insertar(arbol,43,'A');
    insertar(arbol,42,'F');
    insertar(arbol,44,'T');
    
    recorrerEnOrden(arbol.arbolBinario);
    
    char palabra[6][8]={{'H','I','J','O','\0'},
                        {'F','I','N','A','L','\0'},
                        {'M','U','N','D','O','\0'},
                        {'D','E','L','\0'},
                        {'D','I','A','\0'},
                        {'C','I','C','L','O','\0'}};
    int cantiPalabras=6;
    char palabraAux[6];
    for(int i=0;i<cantiPalabras;i++){
        int valido = validarPalabra(arbol.arbolBinario.raiz,palabra[i],palabraAux,0);
        if(valido == 1){
            for(int j = 0;palabra[i][j]!='\0';j++){
                cout<<palabra[i][j];
            }
            cout<<" ";
        }
    }
    
    
    return 0;
}

