/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 20 de junio de 2024, 08:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#define N 9

using namespace std;

/*
 * 
 */
void llenarListasAdy(int listas[][2],vector<vector<int>>&mapa,int numAristas,int numVertices){
    for(int i=0;i<numAristas;i++){
        int u=listas[i][0]-1;
        int v=listas[i][1]-1;
        mapa[u].push_back(v);
//        mapa[v].push_back(u);
    }
}
void llenarArr(int*arr,int num){
    for(int i=0;i<num;i++){
        arr[i]=0;
    }
}
void etiquetar(vector<vector<int>> mapa,int numVertices,int*arr){
    int etiq;
    for(int i=0;i<numVertices;i++){
        etiq=1;
        for(int j=0;j<mapa[i].size();j++){
            if(arr[mapa[i][j]]==etiq){                
                etiq++;
            }            
        }
        arr[i]=etiq;
    }
}
int buscaMax(int * arr,int num){
    int mayor=0;
    for(int i=0;i<num;i++){
        if(arr[i]>mayor){
            mayor=arr[i];
        }
    }
    return mayor;
}
int main(int argc, char** argv) {
    
    int numAristas=34;//debido a que el grafo no es dirigido, las aristas se cuentan 2 veces
    int numVertices=N;
    int cantEtiquietas=3;//cantidad de etiquetas ingresadas por el usuario
    
    //utilizando listas de adyasencia para el manejo de grafos
    int listas[][2]={{1,2},{1,4},{1,9},
                     {2,1},{2,3},{2,4},{2,9},
                     {3,2},{3,4},{3,5},{3,6},{3,7},{3,8},{3,9},
                     {4,1},{4,2},{4,3},{4,5},
                     {5,3},{5,4},{5,6},
                     {6,3},{6,5},{6,7},
                     {7,3},{7,6},{7,8},
                     {8,3},{8,7},{8,9},
                     {9,1},{9,2},{9,3},{9,8}};
    vector<vector<int>>mapa(numVertices);
    llenarListasAdy(listas,mapa,numAristas,numVertices);
    
    for(int i=0;i<numVertices;i++){
        cout<<i+1<<": ";
        for(int j=0;j<mapa[i].size();j++){
            cout<<mapa[i][j]+1<<" ";
        }
        cout<<endl;
    }
    /*Operando las etiquetas y usando un arreglo auxiliar*/
    int arr[N];
    llenarArr(arr,numVertices);
    //funcion que etiqueta los vertices deacuerdo a las restricciones
    etiquetar(mapa,numVertices,arr);
    cout<<"[";
    for(int i=0;i<numVertices;i++){
        cout<<arr[i]<<" ";
    }cout<<"]"<<endl;
    //busca la etiqueta maxima en el arreglo para compararlo con la eqtiqueta ingresada por el usuario
    int maximo=buscaMax(arr,numVertices);
    
    /*Validando*/
    if(maximo==cantEtiquietas){
        cout<<"Si existe solucion."<<endl;
    }else{
        cout<<"No existe solucion."<<endl;
    }
    
    return 0;
}

