/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
// lab3 2022.1
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int incremento(int *arr,int ini,int med,int fin){
    int izq=1,der=1;
    if(arr[med]>arr[med+1]){
        return 1;
    }
    for(int i=med;i>ini;i--){
        if(arr[i]>arr[i-1]){
            izq++;
        }else{
            break;
        }
    }
    for(int i=med+1;i<fin;i++){
        if(arr[i]<arr[i+1]){
            der++;
        }else{
            break;
        }
    }
    
    return der+izq;
}

int incrementoDias(int *arr,int ini,int fin){
    if(ini==fin) return 1;
    int med=(ini+fin)/2;
    int izq=incrementoDias(arr,ini,med);
    int der=incrementoDias(arr,med+1,fin);
    int cen=incremento(arr,ini,med,fin);
   
    return max(max(izq,der),cen);
}


int main(int argc, char** argv) {
    int cantD=8;
    int arr[cantD]={10,20,15,10,12,10,13,18};
    
    int calculo = incrementoDias(arr,0,cantD-1);
    
    cout<<"Intervalo de: "<<calculo<<endl;
    cout<<"Indice : "<<(double)calculo/cantD<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

