/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "NodoArbol.h"
using namespace std;

void insertanivel(NodoArbol* arbol,int *paq,int ini, int n){
    
    if(ini>=n) return;
    
    inserta_ab_izq(arbol,0,paq[ini]);
    insertanivel(arbol->izquierda,paq,ini+1,n);
    
    inserta_ab_der(arbol,1,paq[ini]);
    insertanivel(arbol->derecha,paq,ini+1,n);
    
}


void creaarbolcromo(ArbolBinario &arbol,int *paq,int n){

    plantarArbolBinario(arbol,nullptr,0,0,nullptr);
    insertanivel(arbol.raiz,paq,0,n);       
        
}

int main(int argc, char** argv) {
    ArbolBinario arbol;
    int paq[]={10,50,20,30,40};
    int n = 5;
    construir(arbol);

    creaarbolcromo(arbol,paq,n);
    recorridoPorNivel(arbol);
    

      
    return 0;
}

