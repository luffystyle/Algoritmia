/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <valarray>
#include <climits>

using namespace std;
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"

int calcularAltura(struct NodoArbol *nodo){
    if(nodo ==nullptr) return 0;
    else{
        int izq = calcularAltura(nodo->izquierda);
        int der = calcularAltura(nodo->derecha);
        return max(izq,der) +1;
    }
    
}

int distanciaMin(int *dist,bool *visitados){
    int min=INT_MAX, indmin;
    for(int i=0;i<9;i++){
        if(min>=dist[i] && visitados[i]!=true){
            min = dist[i];
            indmin = i;
        }
    }
    return indmin;
}

void dijkra(int grafos[][9], int inicio){
    int dist[9];
    bool visitidos[9];
    for(int i=0;i<9;i++){
        dist[i] = INT_MAX;
        visitidos[i]=false;
    }
    dist[inicio]=0;
    for(int cont=0;cont<8;cont++){
        int u = distanciaMin(dist,visitidos);
        visitidos[u]=true;
        for(int i=0;i<9;i++){
            if(grafos[u][i] && !visitidos[i] && dist[u]!=INT_MAX && (dist[u] + grafos[u][i] < dist[i])){
                dist[i] = dist[u] + grafos[u][i];
            }
        }
        
    }
    
    
}





int calcularCantNodos(struct NodoArbol *raiz){
    if(raiz == nullptr) return 0;
    else{
        return 1 +calcularCantNodos(raiz->izquierda) + calcularCantNodos(raiz->derecha);
        
    }
    
}

struct NodoArbol *eliminarNodito(struct NodoArbol * nodo,int elemento){
    if(nodo==nullptr) return nodo;
    
    if(elemento < nodo->elemento){
        nodo->izquierda = eliminarNodito(nodo->izquierda,elemento);
    }else{
        if(elemento > nodo->elemento){
            nodo->derecha = eliminarNodito(nodo->derecha,elemento);
        }else{
            if(nodo->izquierda==nullptr){
                NodoArbol * hijo = nodo->derecha;
                delete nodo;
                return hijo;
            }else{
                if(nodo->derecha == nullptr){
                    NodoArbol *hijo= nodo->izquierda;
                    delete nodo;
                    return hijo;
                }else{
                    NodoArbol *raiz = encontrarMin(nodo->derecha);
                    nodo->elemento = raiz->elemento;
                    nodo->derecha = eliminarNodito(nodo->derecha,raiz->elemento);
                    
                }
            }
            
        }
    }
    return nodo;
}

struct NodoArbol* busca(struct NodoArbol * nodo,int elemento){
    if(nodo==nullptr) return nullptr;
    if(nodo->elemento == elemento){
        return nodo;
    }else{
        if(elemento < nodo->elemento){
            nodo = nodo->izquierda;
        }else{
            nodo = nodo->derecha;
        }
        return busca(nodo,elemento);
    }
    
}

void recorreIteraPorAmplitud(struct ArbolBinario arbol){
    if(esArbolVacio(arbol))return;
    Cola cola;
    construir(cola);
    encolar(cola,arbol.raiz);
    NodoArbol *parbol;
    while(!esColaVacia(cola)){
        parbol = desencolar(cola);
        imprimeNodo(parbol);
        if(!esNodoVacio(parbol->izquierda)){
            encolar(cola,parbol->izquierda);
        }
        if(!esNodoVacio(parbol->derecha)){
            encolar(cola,parbol->derecha);
        }
    }
    
}

void recorridoPostOrden(struct ArbolBinarioBusqueda &arbol){
    if(esArbolVacio(arbol)) return;
    int alto,ultimo=0;
    NodoArbol *parbol = arbol.arbolBinario.raiz;
    Pila pila;
    while(!esPilaVacia(pila)||parbol!=nullptr){
        while(parbol!=nullptr){
            apilar(pila,parbol->elemento);
            parbol = parbol->izquierda;
        }
        alto = cima(pila);
        parbol = busca(arbol.arbolBinario.raiz,alto);
        if(parbol->derecha!=nullptr and ultimo!=parbol->derecha->elemento){
            parbol = parbol->derecha;
        }else{
            ultimo = desapilar(pila);
            cout<<ultimo<<" ";
            parbol = nullptr;
        }
        if(esPilaVacia(pila)) break;
    }
    
    
}

void recorridoIteraEnOrden(struct ArbolBinario &arbol){
    Pila pila;
    construir(pila);
    NodoArbol *parbol=arbol.raiz;
    while(!esPilaVacia(pila)|| parbol!=nullptr){
        while(parbol!=nullptr){
            apilar(pila,parbol->elemento);
            parbol = parbol->izquierda;
        }
        int elemento = desapilar(pila);
        parbol = busca(arbol.raiz,elemento);
        cout<<parbol->elemento<<" ";
        parbol = parbol->derecha;
        
    }
    
}

void recorridoIterativoPreOrden(struct NodoArbol *raiz){
    
    Pila pila;
    construir(pila);
    NodoArbol *parbol ;
    apilar(pila,parbol->elemento);
    while(!esPilaVacia(pila)){
        int elemento = desapilar(pila);
        parbol = buscar(raiz,elemento);
        cout<<parbol->elemento<<" ";
        if(!esNodoVacio(parbol->derecha)){
            apilar(pila,parbol->derecha->elemento);
        }
        if(!esNodoVacio(parbol->izquierda)){
            apilar(pila,parbol->izquierda->elemento);
        }
        
    }
}



int validaLetra(char * palabra,char letra){
    int existe = 0;
    for(int i=0;palabra[i]!='\0';i++){
        if(letra == palabra[i]){
            existe = 1;
            break;
        }
    }
    return existe;
}

int validacionExiste(char * palabra,char *letras,int pos){
    int aux[6];
    for(int i=0;i<pos;i++) aux[i]=letras[i];
    int existe;
    int contador =0;
    for(int i=0;palabra[i]!='\0';i++){
        contador ++;
        existe=0;
        for(int j=0;j<pos;j++){
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
    
    if(existe ==1 and contador == pos){
        return 1;
    }else{
        return 0;
    }

    
}

int validacionPalabra(struct NodoArbol *raiz,char *palabra,char *letras,int pos){
    if(raiz == nullptr){
        return 0;
    }
    
    if(validaLetra(palabra,raiz->letra)==1){
        letras[pos++] = raiz->letra;
    }else{
        return 0;
    }
    
    if(raiz->izquierda == nullptr and raiz->derecha == nullptr){
        if(validacionExiste(palabra,letras,pos)==1){
            return 1;
        }else{
            return 0;
        }
    }
    
    return validacionPalabra(raiz->izquierda,palabra,letras,pos) + validacionPalabra(raiz->derecha,palabra,letras,pos);
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,30,'M');
    insertar(arbol,20,'U');
    insertar(arbol,40,'I');
    insertar(arbol,15,'E');
    insertar(arbol,23,'N');
    insertar(arbol,22,'R');
    insertar(arbol,25,'D');
    insertar(arbol,24,'O');
    insertar(arbol,38,'C');
    insertar(arbol,37,'C');
    insertar(arbol,36,'O');
    insertar(arbol,45,'N');
    insertar(arbol,43,'A');
    insertar(arbol,42,'F');
    insertar(arbol,44,'T');
    
    char palabra[6][8]={{'H','I','J','O','\0'},
                        {'F','I','N','A','L','\0'},
                        {'M','U','N','D','O','\0'},
                        {'D','E','L','\0'},
                        {'D','I','A','\0'},
                        {'C','I','C','L','O','\0'}};
    int cantiPalabras=6;
    char aux[7];
    for(int i=0;i<cantiPalabras;i++){
        int valido = validacionPalabra(arbol.arbolBinario.raiz,palabra[i],aux,0);
        if(valido==1){
            for(int j=0;palabra[i][j]!='\0';j++){
                cout<<palabra[i][j];
            }
            cout<<endl;
        }
        
    }
    
    return 0;
}

