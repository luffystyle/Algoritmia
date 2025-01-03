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

void cargarBin(int cromo[],int numero,int cantProd){
    for(int i=0;i<cantProd;i++)cromo[i]=0;
    int i=0;
    while(numero>0){
        cromo[i]= numero%2;
        numero /= 2;
        i++;
    }
    
    
}




int main(int argc, char** argv) {
    int cantProd,m,pesoTotal;
    cout<<"Ingrese la cantidad de productos:"<<endl;
    cin>>cantProd;
    cout<<"Ingrese las diviciones:"<<endl;
    cin>>m;
    cout<<"Ingrese el peso total en toneladas:"<<endl;
    cin>>pesoTotal;
    
    int n=12;
    int bahia[]={2,5,6,10,7,8,15,3,11,9,6,4};
    int cromo[n];
    int opcion = (int)pow(2,n);
    int pesoParcial,cantidad;
    
    for(int i=0;i<opcion;i++){
        cargarBin(cromo,i,cantProd);
        pesoParcial=0;
        cantidad =0;
        for(int j=0;j<12;j++){
            pesoParcial = pesoParcial +cromo[j]*bahia[j];
            cantidad = cantidad + cromo[j];
        }
        //validamos que se tome al menos uno en cada bahia:
        int cont=0,cont1=0,cont2=0;
        for(int x=0;x<4;x++){
            if(cromo[x]==1) cont++;
        }
        for(int x=4;x<8;x++){
            if(cromo[x]==1) cont1++;
        }
        for(int x=8;x<12;x++){
            if(cromo[x]==1) cont2++;
        }
        
        if(cantidad ==m and pesoParcial==pesoTotal){
            cout<<"Soluciones : "<<endl;
            for(int j=0;j<12;j++){
                double division= (1.0*j)/4;
                if(division==0) cout<<"Bahia 1: ";
                    if(division==1) cout<<"Bahia 2: ";
                    if(division==2) cout<<"Bahia 3: ";
                if(cromo[j]==1){
                    if(j>=0 and j<4){
                        cout<<bahia[j]<<" ";
                    }else if(j>=4 and j<8){
                        cout<<bahia[j]<<" ";
                    }else if(j>=8 and j<12){
                        cout<<bahia[j]<<" ";
                    }
                }
            }
            cout<<endl;
        }
    }
    
    
    
    
    
    
    return 0;
}

