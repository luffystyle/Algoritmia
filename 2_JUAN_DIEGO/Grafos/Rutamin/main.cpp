/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 24 de junio de 2024, 11:09 AM
 */

#include <cstdlib>
#include <iostream>
#include <climits>
#define V 5

using namespace std;

/*
 * 
 */
int recrutamin(int grafo[][V],int ini,int fin){
    int min=INT_MAX;
    int arrDistancias[V];
    if(ini==fin)return 0;
    for(int i=ini+1;i<=fin;i++){
        if(grafo[ini][i]){
            int distancia=grafo[ini][i]+recrutamin(grafo,i,fin);            
            if(min>distancia){
                min=distancia;
            }
        }
    }    
    return min;
}
/*============================================================================*/
void mostrarSolucion(int distancias[]){
    for(int i=0;i<V;i++){
        cout<<i+1<<" "<<distancias[i]<<endl;
    }
}
int minimo(int*distancias,bool*visitados){
    int indiceMin, distMin=INT_MAX;
    for(int i=0;i<V;i++){
        if(visitados[i]==false && distancias[i]<distMin){
            distMin=distancias[i];
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
    distancias[0]=0;
    for(int vertice=0;vertice<V-1;vertice++){
        int distVertMin = minimo(distancias,visitados);
        visitados[distVertMin]=true;
        for(int i=0;i<V;i++){
            if(!visitados[i]
                && grafo[distVertMin][i]
                && distancias[distVertMin]!=INT_MAX
                && distancias[distVertMin]+grafo[distVertMin][i]<distancias[i])
                distancias[i]=distancias[distVertMin]+grafo[distVertMin][i];
        }
    }
    mostrarSolucion(distancias);
}


int main(int argc, char** argv) {
    
    int grafo[V][V]={{0,3,0,7,0},
                     {3,0,4,2,0},
                     {0,4,0,5,6},
                     {7,2,5,0,4},
                     {0,0,6,4,0}};
    
//    cout<<"Ruta minima recursiva: "<<recrutamin(grafo,0,V-1)<<endl;
    /*Menor distancia iterativo*/
    dijkstra(grafo,0);
    
    
    return 0;
}

//////////////////////////*Practicar dijkstra*//////////////////////////////////

//int MinimaDistancia(int*distancias,bool*visitados){
//    int indice_minimo,minima_distancia=INT_MAX;
//    
//    for(int i=0;i<V;i++){
//        if(visitados[i]==false && distancias[i]<=minima_distancia){
//            minima_distancia=distancias[i];
//            indice_minimo=i;
//        }
//    }
//    return indice_minimo;
//}
//
//void dijkstra(int grafo[V][V],int origen){
//    int distancias[V];
//    bool visitados[V];
//    
//    for(int i=0;i<V;i++){
//        distancias[i]=INT_MAX;
//        visitados[i]=false;
//    }
//    distancias[origen]=0;
//    
//    for(int vertice=0;vertice<V-1;vertice++){
//        int vertice_minima_distancia=MinimaDistancia(distancias,visitados);
//        
//        visitados[vertice_minima_distancia]=true;
//        for(int i=0;i<V;i++){
//            if(!visitados[i]
//                && grafo[vertice_minima_distancia][i]
//                && distancias[vertice_minima_distancia]!=INT_MAX
//                && distancias[vertice_minima_distancia]+grafo[vertice_minima_distancia][i]<distancias[i])
//                distancias[i]=distancias[vertice_minima_distancia]+grafo[vertice_minima_distancia][i];
//        }
//    }
//    mostrarSolucion(distancias);
//}