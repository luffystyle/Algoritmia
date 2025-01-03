/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <complex>

using namespace std;

void cargarBase(int *cromo,int cantidad,int base,int num){
    for(int i=0;i<cantidad;i++) cromo[i]=0;
    int i=0;
    while(num>0){
        cromo[i]=num%base ;
        num /=base;
        i++;
    }
    
}


int main(int argc, char** argv) {
    int n,m;
    cout<<"Ingrese datos del ingreso:"<<endl;
    cin>>m>>n;
    int paq[n]={50,20,30,50,20};
    int camion[m]={25,50,100,100};
    int cromo[n];
    int auxCam[m];
    int diferencia;
    //si tenemos n paquetes y estos paquetes deben estar dentro de los m camiones 
    //entonces es n elevado a la m
    int opcion = (int)pow(n,m);
    int mcomb,mDif;
    int maxNoUtil,minUtil,minDiferencia=99999999;
    
    for(int i=0;i<opcion;i++){
        cargarBase(cromo,n,m,i);
        for(int i=0;i<m;i++) auxCam[i]=camion[i];
        //ahora abrimos el cromo que tendra 4 de longitud;
        // ejemplo 0 1 2 0
        for(int j=0;j<n;j++){
            auxCam[cromo[j]] = auxCam[cromo[j]] - paq[j];
        }
        //hallamos el maximo de Espacios No utilizado y min de Espacios Utilizados
        minUtil=9999999;
        maxNoUtil=-9999999;
        int noUtilizado;
        for(int l=0;l<m;l++){
            //hallamos el maximo espacio no utilizado entre los 3 camiones 
            noUtilizado=camion[l] - auxCam[l];
            if(maxNoUtil<=noUtilizado){
                maxNoUtil=noUtilizado;
            }
            //hallamos el minimo espacio utilizado entre los 3 camiones
            if(minUtil>=auxCam[l]){
                minUtil=auxCam[l]; 
            } 
        }
        
        diferencia= maxNoUtil - minUtil;
               
        if(minDiferencia>diferencia){
            minDiferencia=diferencia;
            mcomb=i;
            mDif=minDiferencia;
            
        }
        
        
    }
    cout<<"Resultado:"<<endl;
    cargarBase(cromo,n,m,mcomb);
    for(int i=0;i<n;i++){
        cout<<"Paquete "<<i+1<<" Camion "<<cromo[i]+1<<endl;
    }
    cout<<" Minima Diferencia: "<<mDif<<endl;
    return 0;
}

