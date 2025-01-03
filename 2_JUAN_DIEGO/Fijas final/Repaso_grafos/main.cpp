/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 3 de julio de 2024, 04:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <climits>
#define V 9
#define M 6


using namespace std;

/*
 * 
 */

void mostrarSolucion(int*distancias){
    for(int i=0;i<V;i++){
        cout<<i+1<<" "<<distancias[i]<<endl;
    }
}
int minimo(int*distancias,bool*visitados){
    int indiceMin,distanciaMenor=INT_MAX;
    for(int i=0;i<V;i++){
        if(visitados[i]==false and distancias[i]<=distanciaMenor){
            distanciaMenor=distancias[i];
            indiceMin=i;
        }
    }
    return indiceMin;
}

void dijkstra(int grafo[][V],int origen){
    int distancias[V];
    bool visitados[V];
    
    for(int i=0;i<V;i++){
        distancias[i]=INT_MAX;
        visitados[i]=false;
    }
    distancias[origen]=0;
    for(int vertice=0;vertice<V-1;vertice++){
        int distanciaMinVert=minimo(distancias,visitados);
        visitados[distanciaMinVert]=true;
        for(int i=0;i<V;i++){
            if(!visitados[i] 
                && grafo[distanciaMinVert][i]
                && distancias[distanciaMinVert]!=INT_MAX
                && distancias[distanciaMinVert]+grafo[distanciaMinVert][i]<distancias[i])
                distancias[i]=distancias[distanciaMinVert]+grafo[distanciaMinVert][i];
        }
    }
    mostrarSolucion(distancias);
}
/*============================================================================*/
/*============================================================================*/
/*============================================================================*/
void mostrar(int*distancias){
    for(int i=0;i<M;i++){
        cout<<i+1<<" "<<distancias[i]<<endl;;
    }
}
int buscaMin(int*distancias,bool*visitados,int*traficos){
    int indiceMin,distMin=INT_MAX;
    for(int i=0;i<M;i++){
        if(visitados[i]==false && distancias[i]*traficos[i]<=distMin){
            distMin=distancias[i]*traficos[i];
            indiceMin=i;
        }
    }
    return indiceMin;
}
void dijkstra2(int grafo2[][M],int origen){
    int distancias[M];
    bool visitados[M];
    int traficos[M];
    
    for(int i=0;i<M;i++){
        distancias[i]=INT_MAX;
        visitados[i]=false;
        traficos[i]=INT_MAX;
    }
    distancias[origen]=0;
    traficos[origen]=0;
    for(int vertice=0;vertice<M-1;vertice++){
        int distMinVert=buscaMin(distancias,visitados,traficos);
        visitados[distMinVert]=true;
        for(int i=0;i<M;i++){
            if(!visitados[i]
                && grafo2[distMinVert][i]
                && distancias[distMinVert]!=INT_MAX
                && (distancias[distMinVert]*traficos[distMinVert])+ ((grafo2[distMinVert][i]/10)*(grafo2[distMinVert][i]%10)) < distancias[i])
                distancias[i]=(distancias[distMinVert]*traficos[distMinVert]) + ((grafo2[distMinVert][i]/10)*(grafo2[distMinVert][i]%10));
        }
    }
    mostrar(distancias);    
}

int main(int argc, char** argv) {
    int grafo[V][V]={{0,3,0,0,0,0,0,8,0},
                     {3,0,5,0,0,0,0,11,0},
                     {0,5,0,7,0,4,0,0,2},
                     {0,0,7,0,9,14,0,0,0},
                     {0,0,0,9,0,10,0,0,0},
                     {0,0,4,14,10,0,2,8,0},
                     {0,0,0,0,0,2,0,1,6},
                     {8,11,0,0,0,0,1,0,7},
                     {0,0,2,0,0,0,6,7,0}};
    //Primero encontrar los caminos mas cortos
//    dijkstra(grafo,0);
    
//    int grafo2[M][M]={{0,32,0,71,0,61},
//                      {32,0,42,21,0},//no se puede ir
//                      {0,42,0,51,61},
//                      {71,21,51,31,42},
//                      {0,0,61,42,0,92},
//                      {61,0,0,31,92,0}};
    
    int grafo2[M][M]={{0,32,0,71,0,41},
                      {32,0,42,21,0,0},//no se puede ir
                      {0,42,0,51,61,0},
                      {71,21,51,0,42,31},
                      {0,0,61,42,0,92},
                      {41,0,0,31,92,0}};
    
    dijkstra2(grafo2,0);
    
    
    return 0;
}

