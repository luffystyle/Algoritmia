/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 30 de octubre de 2023, 12:12 PM
 */

#include <iostream>
#include <iomanip>
#define nciu 6
#define nvac 4

using namespace std;
int costototal=0;

int esvalido(int ady[nciu][nciu],int refri[nciu],int visitado[nciu],
        int indice,int vac){
    
    for(int i=0;i<nciu;i++){
        if(ady[indice][i]!=0)
            if(visitado[i]==vac+1) return 0;

        if(ady[i][indice])
            if(visitado[i]==vac+1) return 0;
     
        if(vac==0 && refri[indice]!=1) return 0;
    }
    return 1;    

}

int buscasol(int ady[nciu][nciu],int refri[nciu],
        int costo[nciu],int visitado[nciu],int i){
    
    if(i==nciu){
        for(int j=0;j<nciu;j++) 
            cout << setw(3) <<visitado[j];
        cout <<endl<<"El costo es:"<< costototal<< endl;
        return 0;
    }
    if(visitado[i]==0){
        for(int vac=0;vac<nvac;vac++){
            if(esvalido(ady,refri,visitado,i,vac)){
                visitado[i]=vac+1;
                costototal+=costo[vac];
                if(buscasol(ady,refri,costo,visitado,i+1))             
                    return 1;
                costototal-=costo[vac];
                visitado[i]=0;
            }
        }
    }
    return 0;
            
            
}

int main(int argc, char** argv) {
    int ady[nciu][nciu]={   {0,1,1,0,0,1},
                            {1,0,1,1,0,0},
                            {1,1,0,1,0,1},
                            {0,1,1,0,1,1},
                            {0,0,0,1,0,1},
                            {1,0,1,1,1,1} };
    int refri[nciu]={0,0,1,0,1,0};
    int costo[nvac]={10,5,12,8};
    int visitado[nciu]={0,0,0,0,0,0};
    buscasol(ady,refri,costo,visitado,0);
    
    return 0;
}

