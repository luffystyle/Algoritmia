/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

void cargarBin(int cromo[],int num,int cant){
    for(int i=0;i<cant;i++) cromo[i]=0;
    int i=0;
    while(num>0){
        cromo[i]= num%2;
        num /=2;
        i++;
    }
    
    
}


int main(int argc, char** argv) {
    int cant=16;
    int paq[]={7,17,14,19,8,6,10,12,9,12,11,8,18,7,15,11};
    int opcion = (int)pow(2,cant);
    int cromo[cant],mejorCom;
    int sumPeso,pesoMax=23,sumGanacia;
    int gan[]={10,10,10,5,15,10,10,10,10,20,10,5,10,10,5,10};
    int l=1,ganMax=-99999;
    for(int i=0;i<opcion;i++){
        sumPeso=0;
        sumGanacia=0;
        cargarBin(cromo,i,cant);
        for(int j=0;j<cant;j++){
            sumPeso += cromo[j]*paq[j];
            sumGanacia += cromo[j]*gan[j];
        }
//        if(ganMax<=sumGanacia){
//            ganMax=sumGanacia;
//        }
        
        
        if( ganMax<=sumGanacia and sumPeso<=pesoMax ){
            mejorCom=i;
            ganMax=sumGanacia;
            cout<<"Ganancia: "<<ganMax<<"     ";
            cout<<"Resultado "<<l<<": ";
            for(int d=0;d<cant;d++){
                if(cromo[d]==1){
                    cout<<paq[d]<<"k ";
                }
            }
            cout<<"   Ubicaciones: ";
            for(int k=0;k<cant;k++){    
                if(cromo[k]==1){
                    if(k/4==0) cout<<"IA"<<(k%4)+1<<" - ";
                    if(k/4==2) cout<<"IB"<<(k%4)+1<<" - ";
                    if(k/4==1) cout<<"DA"<<(k%4)+1<<" - ";
                    if(k/4==3) cout<<"DB"<<(k%4)+1<<" - ";
                }
            } 
            cout<<endl;
            l++;
        }
    }
    
    return 0;
}

