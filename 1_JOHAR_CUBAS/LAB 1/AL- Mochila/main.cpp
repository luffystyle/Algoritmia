/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <complex>

using namespace std;

void cargarBin(int cromo[],int numero,int n){
    for(int k=0;k<n;k++) cromo[k]=0;
    int i=0,res;
    while(numero>0){
        res = numero%2;
        numero = numero/2;
        cromo[i]= res;
        i++;
    }
}



int main(int argc, char** argv) {
    int peso=15,n=5;
    int paq[]={1,2,4,12,1};
    char letra[]={'A','B','C','D','E'};
    int cromo[n],pesoParcial,mejorpeso=0,mejorCombi;
    int opcion= (int)pow(2,n);
    
    for(int i=0;i<opcion;i++){
        cargarBin(cromo,i,n);
        pesoParcial=0;
        for(int j=0;j<n;j++){
            pesoParcial=cromo[j]*paq[j] + pesoParcial;
            
        }
        
        //                                <=  para que salga el mejor resultado
        //                                <  para q salga el primer resultado 
        if(pesoParcial<=peso and mejorpeso<=pesoParcial){
                mejorpeso=pesoParcial;
                mejorCombi=i;
                
        }
        //para que salga los dos pasos
        if(pesoParcial==peso){
            cout<<mejorpeso<<" "<<mejorCombi<<endl;
            cargarBin(cromo,mejorCombi,n);
            for(int i=0;i<n;i++){
                if(cromo[i]!=0){
                    cout<<letra[i]<<" ";
                }
            }
            cout<<endl;
        }
        
    }
    //cout<<mejorpeso<<" "<<mejorCombi<<endl;
    
    return 0;
}

