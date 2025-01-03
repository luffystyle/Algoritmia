/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 17 de junio de 2024, 11:24 AM
 */
#include <vector>
#include <cstdlib>
#include <iostream>
#define N 4
using namespace std;

/*
 * 
 */
void llenarMatrizAd(int grafo[][N],vector<vector<int> > &mapa,int numvertices){
    for(int i=0;i<numvertices;i++){
        vector<int>vertice;//Para borrar erase(vertice.beging()...end())
        for(int j=0;j<numvertices;j++){
            vertice.push_back(grafo[i][j]);
        }
        mapa.push_back(vertice);
    }
    
}
void llenarListaAd(int listas[][2],int numaristas,vector<vector<int>> &mapaL,int numvertices){
    for(int i=0;i<numaristas;i++){
        int u=listas[i][0];
        int v=listas[i][1];
        mapaL[u].push_back(v);
        mapaL[v].push_back(u);
    }
}
int main(int argc, char** argv) {
    /*Matriz de adyacencia*/
    int grafo[N][N]={{0,1,1,0},
                     {1,0,1,1},
                     {1,1,0,1},
                     {0,1,1,0}};
    int numvertices=N;
    vector<vector<int> >mapa;
    
    llenarMatrizAd(grafo,mapa,numvertices);
    
    for(int i=0;i<numvertices;i++){
        for(int j=0;j<numvertices;j++){
            cout<<mapa[i][j]<<" ";
        }
        cout<<endl;
    }
/*============================================================================*/
    /*Lista  de adyacencia*/
    int listas[][2]={{0,1},{0,2},{1,2},{2,3},{3,1}};
    int numaristas=5;
    
    vector<vector<int>>mapaL(numvertices);
    llenarListaAd(listas,numaristas,mapaL,numvertices);
    cout<<"Listas de adyacencia:"<<endl;
    for(int i=0;i<numvertices;i++){
        cout<<i<<": ";
        for(int j=0;j<mapaL[i].size();j++){
            cout<<mapaL[i][j]<<" ";
        }
        cout<<endl;
    }    
    return 0;
}

