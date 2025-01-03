/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "funcionesArbolesBinarios.h"
#include "NodoArbol.h"
#include "ArbolBinario.h"
#include "funcionesArbolesBB.h"

int main(int argc, char** argv) {
    
    struct ArbolBinario arbol;
    construir(arbol);
    
    esArbolVacio(arbol);
    cout<<"Es árbol vacio: "<<esArbolVacio(arbol)<<endl;
    //plantarArbolBinario(arbol,nullptr,100,nullptr);
   
    //imprimeRaiz(arbol);
    cout<<endl;
    //siempre primero se ingresa las hojas del arbol
    struct ArbolBinario arbol1, arbol2, arbol3, arbol4,arbol5,arbol6;
    plantarArbolBinario(arbol1, nullptr, 25, nullptr);
    plantarArbolBinario(arbol2, nullptr, 75, nullptr);
    plantarArbolBinario(arbol3, arbol1, 50, arbol2);
    plantarArbolBinario(arbol5,nullptr,11,nullptr);
    plantarArbolBinario(arbol6,nullptr,160,nullptr);
    plantarArbolBinario(arbol4, arbol5, 150, arbol6);
    plantarArbolBinario(arbol, arbol3, 100, arbol4);
    cout<<"Es árbol vacio: "<<esArbolVacio(arbol)<<endl;
    //esta funcion es para que imprima la raiz de cada rama 
    cout<<"Raiz: "<<endl;
    imprimeRaiz(arbol1);
    //recorrer en orden:  hI - subraiz - hd - raizprincipal - hI - subraiz - hD
    cout<<endl<<"Recorrer en orden: "<<endl;
    recorrerEnOrden(arbol); cout<<endl;
    // recorrer desde la raiz y luegi izquierda y derecha
    cout<<"Recorrer en pre orden: "<<endl;
    recorrerPreOrden(arbol); cout<<endl;
    // primero todos los hijos del arbol hacia arriba
    cout<<"Recorrer en post orden: "<<endl;
    recorrerPostOrden(arbol); cout<<endl;
//    
    cout<<"ALTURA arbol: "<<altura(arbol)<<endl;
    //numero de las subraices
    cout<<"NúMERO DE HOJAS: "<<numeroHojas(arbol)<<endl;
    //numero de raizes total
    cout<<"NúMERO DE NODOS: "<<numeroNodos(arbol)<<endl;
    cout<<"ES EQUILIBRADO: "<<esEquilibrado(arbol)<<endl;
//  verifica si esa sub raiz no tiene ramificaciones o hijitas dentro de ella
    cout<<"Es hoja: "<<esHoja(arbol1)<<endl;
    //
    cout<<"Suma de Nodos: "<<sumarNodos(arbol)<<endl;
    destruirArbolBinario(arbol);

        
    cout<<"Es árbol vacio: "<<esArbolVacio(arbol)<<endl;
    
    
    
    return 0;
}

