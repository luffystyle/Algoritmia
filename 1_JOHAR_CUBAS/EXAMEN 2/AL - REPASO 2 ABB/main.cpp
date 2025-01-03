/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#define N 5
#include <climits>
#include "funcionesArbolesBB.h"
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "Cola.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"
using namespace std;

//void validarLetras(struct Cola &cola,char letra,int &valido){
//    if(esColaVacia(cola)) return;
//    char valor = desencolar(cola);
//    validarLetras(cola,letra,valido);
//    if(letra != valor){
//        encolar(cola,valor);
//    }else{
//        valido =1;
//    }
//    
//}
//
//int validarPalabra(struct Cola &cola,struct NodoArbol *raiz,int cont){
//    
//    if(raiz!= nullptr){
//        int valido =0 ;
//        validarLetras(cola,raiz->letra,valido);
//        if(valido ==1){
//            cont++;
//            if(esColaVacia(cola)) return 1;
//        }else{
//            return 0;
//        }
//    }else{
//        return 0;
//    }
//    
//    
//    return validarPalabra(cola,raiz->izquierda,cont) + validarPalabra(cola,raiz->derecha,cont);
//}
//
//
//int main(int argc, char** argv) {
//    struct ArbolBinarioBusqueda arbol;
//    construir(arbol);
//    insertar(arbol,30,'M');
//    insertar(arbol,20,'U');
//    insertar(arbol,40,'I');
//    insertar(arbol,15,'E');
//    insertar(arbol,23,'N');
//    insertar(arbol,22,'R');
//    insertar(arbol,25,'D');
//    insertar(arbol,24,'O');
//    insertar(arbol,38,'C');
//    insertar(arbol,37,'C');
//    insertar(arbol,36,'O');
//    insertar(arbol,45,'N');
//    insertar(arbol,43,'A');
//    insertar(arbol,42,'F');
//    insertar(arbol,44,'T');
//    Cola cola[3];
//    construir(cola[0]);
//    construir(cola[1]);
//    construir(cola[2]);
//    
//    encolar(cola[0],'M');
//    encolar(cola[0],'U');
//    encolar(cola[0],'N');
//    encolar(cola[0],'D');
//    encolar(cola[0],'O');
//    imprime(cola[0]);
//    //cout<<desencolar(cola[0]);
//    
//    int valido = validarPalabra(cola[0],arbol.arbolBinario.raiz,0);
//    if(valido ==1){
//        cout<<"MUNDO"<<endl;
//    }else{
//        cout<<"No se encontro"<<endl;
//    }
//    return 0;
//}

void mostrarSolu(int distacia[], int valor[]){
    for(int i=0;i<N;i++){
        cout<<i<<" "<<distacia[i]<<"  "<<valor[i] <<endl;
    }
}
int minimaDistancia(int distacia[],bool visitado[]){
    int ind_min,min_dist=INT_MAX;
    for(int i=0;i<N;i++){
        if(visitado[i]==false && distacia[i]<=min_dist){
            min_dist=distacia[i];
            ind_min=i;
        }
        
    }
    return ind_min;
}

void minimo(int mapa[][N], int valor[][N],int ini){
    int distacia[N];
    bool visitado[N];
    int valorfin[N];
    
    for(int i=0;i<N;i++){
        distacia[i]=INT_MAX;
        visitado[i]=false;
        valorfin[i]=0;
    }
    distacia[ini]=0;
    
    for(int vertice=0; vertice<N-1;vertice++){
        int vert_min_dist=minimaDistancia(distacia,visitado);
        visitado[vert_min_dist]=true;
        
        for(int i=0; i<N; i++){
            if(!visitado[i] && mapa[vert_min_dist][i] 
                    && distacia[vert_min_dist]!=INT_MAX
                    && mapa[vert_min_dist][i] + distacia[vert_min_dist]<distacia[i] ){
                
                distacia[i]=distacia[vert_min_dist]+ mapa[vert_min_dist][i];
                valorfin[i]=valorfin[vert_min_dist]+ valor[vert_min_dist][i];
            }
        }
    }
    mostrarSolu(distacia,valorfin);
    
}
int main(int argc, char** argv) {
    int mapa[N][N]={{0,3,0,7,0},
                    {3,0,4,2,0},
                    {0,4,0,5,6},
                    {7,2,5,0,4},
                    {0,0,6,4,0}};
    
    int valor[N][N]={   {0,30,0,7,0},
                        {3,0,4,20,0},
                        {0,4,0,5,6},
                        {7,2,5,0,40},
                        {0,0,6,4,0}};
    
    minimo(mapa,valor,0);
    
    

    return 0;
}

