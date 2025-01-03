/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int detectorSkinerd(int servidores[][7],int nServidores,int fil,int col){
    int cantNservidor=0,cantEnviadoPaqtes=0;
    int servidorLocalizado;
    //esto es en el caso si skineer no esta en linea
    if(fil==nServidores and col== nServidores) return 0;
    
    //recorro cada columna para ver si tiene la cnatidad de 0 igual al numero de servidores
    //para que si esto pasa retorne 
    for(int i=0;i<nServidores;i++){
        if(servidores[i][col]==0) cantNservidor++; 
    }
    
    if(cantNservidor == nServidores){
        for(int i=0;i<nServidores;i++){
            if(servidores[col][i]!=0 and servidores[col][col]==0 ){
                cantEnviadoPaqtes++;
            }    
        }
    }
    
    if(cantNservidor ==nServidores and cantEnviadoPaqtes == nServidores-1 ){
        return col+1;
    }
    servidorLocalizado = detectorSkinerd(servidores,nServidores,fil+1,col+1);
    
    return servidorLocalizado;
}



int main(int argc, char** argv) {
    int servidores[][7]={  { 0, 0, 0, 0, 0, 0, 0 },
                        {10, 0,20,30, 0,20,40 },
                        { 0, 0, 0, 0, 0,100, 0},
                        { 0, 0, 0, 0, 0,80, 0 },
                        {50,10, 5,10, 0,100, 4},
                       {100, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0 }};
    
int servidor[][7]={    { 0,10,10,10,20,10,10 },
                        {10, 0,20,30, 0,20,40 },
                        { 0, 0, 0, 0, 0,100, 0},
                        { 0, 0, 0, 0, 0,80, 0 },
                        {50,10, 5,10, 0,100, 4},
                       {100, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0 }};

    
    if(detectorSkinerd(servidor,7,0,0)!=0){
        cout<<"SkyNerd ha sido detectado en el servidor: "<<detectorSkinerd(servidor,7,0,0)<<endl;
    }else{
        cout<<"SkyNerd no está en la red"<<endl;
    }
       
    
    
    return 0;
}

