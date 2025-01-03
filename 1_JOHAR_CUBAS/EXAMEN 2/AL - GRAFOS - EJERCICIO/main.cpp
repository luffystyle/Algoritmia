/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

int recorridoMin(int mapa[][5],int ini,int fin){
    int min = INT_MAX;
    if(ini == fin) return 0;
    for(int i= ini +1;i<=fin;i++){
        if(mapa[ini][i]!=0){
            int dist = mapa[ini][i] + recorridoMin(mapa,i,fin);
            if(dist < min ){
                min=dist;
            }
            
        }
    }
    return min;
}

int main(int argc, char** argv) {
    
    int mapa[5][5]={{0,3,0,7,0},{3,0,4,2,0},{0,4,0,5,6},{7,2,5,0,4},{0,0,6,4,0}};
    
    int min = recorridoMin(mapa,0,4);
    cout<<min;
    
    
    return 0;
}

