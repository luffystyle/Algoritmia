/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

void cargarBin(int cromo[],int num,int cant,int base){
    for(int i=0;i<cant;i++) cromo[i]=0;
    int i=0;
    while(num>0){
        cromo[i]= num%base; // sabemos que cuando le damos el resto a uno va a ser asi 0 1 // si la base fuera 3  es 0 1 2 0 1 2
        num /=base;
        i++;
    }
}


int main(int argc, char** argv) {
    // camiones con paquetes
    int m =3,n=4;
    int camiones[]= {100,100,100};
    int paque[]={50,20,30,50};
    int opcion=(int)pow(m,n);
    int cromo[n],arrCam[m],resta,restaMIn=999999;
    int sumaPaq,espacioNoUtiliMax,espacioNoUtilMin,mcombiMin;
    for(int i=0;i<opcion;i++){
        cargarBin(cromo,i,n,m);
        for(int j=0;j<m;j++) arrCam[j]=camiones[j];
        for(int j=0;j<n;j++){
            arrCam[cromo[j]] = arrCam[cromo[j]] - paque[j];            
        }
        espacioNoUtiliMax=arrCam[0];
        espacioNoUtilMin=arrCam[0];
        
        for(int l=0;l<n;l++){
            if(arrCam[l]>espacioNoUtiliMax) espacioNoUtiliMax=arrCam[l];
            if(arrCam[l]<espacioNoUtilMin) espacioNoUtilMin = arrCam[l];
        }
        if(espacioNoUtilMin>=0 and espacioNoUtiliMax>=0) resta= espacioNoUtiliMax-espacioNoUtilMin;
        
        if(resta<restaMIn){
            restaMIn=resta;
            mcombiMin=i;
            break;
        }
        
    }
    cargarBin(cromo,mcombiMin,n,m);
    cout<<"Respuesta de camiones: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Paquete "<<i+1<<": Camion "<<cromo[i]+1<<endl;
    }
    
    
    
    return 0;
}

