/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

void llenarValores(vector<vector<int>> &mapa,int cantAristas,int verticies[][2]){
    
    for(int i=0;i<cantAristas;i++){
        int a=verticies[i][0]-1;
        int b=verticies[i][1];
        mapa[a].push_back(b);
    }
}

void ponerEtiketas(vector<vector<int>> &mapa,int *arrVALORES,int nVertices){
    for(int i=0;i<nVertices;i++){
        
        for(int j=0;j<mapa[i].size();j++){
            if(mapa[i][j]>i+1){
                if(arrVALORES[mapa[i][j]-1]==arrVALORES[i]){
                    arrVALORES[mapa[i][j]-1]++;
                }
                
            }
        }        
    }

    
    
    
}

int mindistancia(int dist[], bool visitado[]){
    int indmin,min = INT_MAX;

    for (int i = 0; i < 9; i++)
        if (visitado[i] == false && dist[i] <= min){
            min = dist[i];
            indmin = i;
        }    
    return indmin;
}


void dijkstra(int grafo[][9], int src){
    int dist[9]; 
    bool visitado[9];
    for (int i = 0; i < 9; i++){
        dist[i] = INT_MAX;
        visitado[i] = false;
    }    
    dist[src] = 0;
    for (int count = 0; count < 8; count++) {
        int u = mindistancia(dist, visitado);
        visitado[u] = true;
        for (int i = 0; i < 9; i++)
            if (!visitado[i] && grafo[u][i] && dist[u] != INT_MAX && dist[u] + grafo[u][i] < dist[i])
                dist[i] = dist[u] + grafo[u][i];
    }
    //la distancia desde el vertice i y el otro es la distancia minima del 0 hasta ese i
    
    for (int i = 0; i < 9; i++)
        cout << i+1 << " --> " << dist[i] << endl;

}




int distanciMinim(int grafo[][9],int ini,int fin){
    
    if(ini == fin) return 0;
    int min = INT_MAX;
    for(int i=ini+1;i<=fin;i++){
        if(grafo[ini][i]!=0){
            int dist = grafo[ini][i] + distanciMinim(grafo,i,fin);
            if(min>dist){
                min=dist;
            }
        }
    }
    return min;
    
    
}


int main(int argc, char** argv) {
    int verticies[][2]={{1,2},{1,4},{1,9},
                        {2,1},{2,3},{2,4},{2,9},
                        {3,2},{3,4},{3,5},{3,6},{3,7},{3,8},{3,9},
                        {4,1},{4,2},{4,3},{4,5},
                        {5,3},{5,4},{5,6},
                        {6,3},{6,5},{6,7},
                        {7,3},{7,6},{7,8},
                        {8,3},{8,7},{8,9},
                        {9,1},{9,2},{9,3},{9,8}};
    
    int cantAristas = sizeof(verticies)/sizeof(verticies[0]);
    int cantVertices = 9;
    vector<vector<int>>mapa(cantVertices);
    //LLENAMOS LOS VALORES QUE ESTAN RELACIONADOS CON CADA VERTICE
    llenarValores(mapa,cantAristas,verticies);
    for(int i=0;i<cantVertices;i++){
        cout<< "Vertice "<<i+1<<": ";
        for(int j=0;j<mapa[i].size();j++){
            cout<<mapa[i][j]<<" ";
        }
        cout<<endl;
    }
    int arrVALORES[9];
    for(int i=0;i<cantVertices;i++) arrVALORES[i]=1;
    cout<<"VALORES:"<<endl;
    ponerEtiketas(mapa,arrVALORES,cantVertices);
    for(int i=0;i<cantVertices;i++){
        cout<<i+1<<" ";
    }
    cout<<endl;
    for(int i=0;i<cantVertices;i++){
        cout<<arrVALORES[i]<<" ";
    }
    cout<<endl<<endl;
    
    int grafo[9][9]={{0,2,0,6,0,0,0,0,2},
                     {7,0,5,2,0,0,0,0,7},
                     {0,3,0,2,3,8,9,7,5},
                     {2,7,5,0,2,0,0,0,0},
                     {0,0,5,3,0,4,0,0,0},
                     {0,0,9,0,6,0,2,0,0},
                     {0,0,3,0,0,7,0,4,0},
                     {0,0,4,0,0,0,9,0,9},
                     {5,3,6,0,0,0,0,4,0}};
    
    dijkstra(grafo, 0);
    cout<<endl<<"Distancia minima total del 0 - 9:"<<endl;
    cout<<distanciMinim(grafo,0,9-1);
    return 0;
}

