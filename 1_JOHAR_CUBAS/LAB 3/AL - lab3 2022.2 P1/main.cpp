/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int numeroMenorPeso(int *arr,int ini,int fin){
     if(ini>=fin) return arr[ini];
    int med= (ini+fin)/2;
    
    if(fin-ini==1){
        if(arr[ini]>arr[fin]){
            return arr[fin];
        }else{
            return arr[ini];
        }
    }
    
    if(arr[med]<arr[med+1] and med-1<=fin){
        return numeroMenorPeso(arr,ini,med);
    }else{
        return numeroMenorPeso(arr,med+1,fin);
    }
}
int max(int a, int b){
    if(a>b){
        return a;
    }else
        return b;
}

int cantidadMaxima(int n,int *pesos,int *dias,int ini,int med,int fin){
    int izq=0,der=0;
    if(pesos[med]!=n){
        return 0;
    }
    for(int i=med;i>=med;i--){
        if(pesos[i]==n){
            izq++;
            dias[i]=i+1;
        }else break;
    }
    for(int i=med+1;i<=fin;i++){
        if(pesos[i]==n){
            dias[i]=i+1;
            der++;
        }else break;
    }
    
    return der+ izq;
}



int cantidadIntervaloMaximo(int n,int *pesos,int *dias,int ini,int fin){
    if(ini==fin) {
        if(pesos[ini]==n){
            cout<<ini<<" ";
        }
        cout<<endl;
        return 0;
    }
    int med =(ini+fin)/2;
    
    
    int izq=cantidadIntervaloMaximo(n,pesos,dias,ini,med);
    int der=cantidadIntervaloMaximo(n,pesos,dias,med+1,fin);
    int cen=cantidadMaxima(n,pesos,dias,ini,med,fin,);
    //int mayor = max(max(izq,der),cen);
    
    return max(max(izq,der),cen);
}

int main(int argc, char** argv) {
    int cant=30;
    int pesos[cant]={98,95,92,89,91,92,89,89,92,93,94,92,91,90,88,88,88,89,90,91,88,88,90,90,92,89,90,88,90,91};
    int numMenor= numeroMenorPeso(pesos,0,cant-1);
    cout<<"El menor peso fue ";
    cout<<numMenor<<endl;
    int dias[cant],intervaloMax;
    for(int i=0;i<cant;i++) dias[i]=0;
    
    intervaloMax = cantidadIntervaloMaximo(numMenor,pesos,dias,0,cant-1);
    cout<<"Cantidad de dias que estuvo al nivel bajo de peso: "<<intervaloMax<<endl;
    cout<<"Los dias fueron: ";
    int j=0;
    for(int i=0;i<cant;i++){
        if(dias[i]!=0 and j<intervaloMax){
            cout<<i+1;
            if(j!=intervaloMax-1) cout<<"-"; 
            j++;
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

