/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int mayorCantProduccion(int *arr,int ini,int fin){ //Complejidad O(n);
    if(ini>=fin) return arr[ini];
    int med=(ini+fin)/2;
    
    if(arr[med]<arr[med+1]){
        int a =mayorCantProduccion(arr,med+1,fin);
        int b= mayorCantProduccion(arr,ini,med-1);
        if(a>b) return a;
        else
            return b;
    }else{
        int a =mayorCantProduccion(arr,med+1,fin);
        int b= mayorCantProduccion(arr,ini,med-1);
        if(a>b) return a;
        else
            return b;
    }
    
}
int mayorCant(int *arr,int ini,int med,int fin){//logn
    if(arr[med]>arr[med+1]) 
        return 1;
    
    int aux=-9999;
    for(int i=med;i>=ini;i--){
        if(aux < arr[i]){
            aux=arr[i];
        }
    }
    for(int i=med+1;i<=fin;i++)
        if(aux<arr[i])
            aux=arr[i]; 
    
    return aux;
}

int mayorCantProduccion2(int *arr,int ini,int fin){ // complejidad total : O(n*logn)
    if(ini==fin) return 1;
    int med=(ini+fin)/2;
    int izq = mayorCantProduccion2(arr,ini,med);
    int der = mayorCantProduccion2(arr,med+1,fin);
    int cen = mayorCant(arr,ini,med,fin); // complejidad : O(Logn)
    
    return max(max(izq,der),cen);
}
int min(int a,int b){
    if(a<b)return a;
    else
        return b;
            
}

int calculoCantHoras(int cantProd1,int *arr,int ini,int med,int fin){
    int izq=0,der=0;
    if(arr[med]!=cantProd1){
        return 0;
    }
    for(int i=med;i>=ini;i--){
        if(arr[i]==cantProd1){
            izq++;
        }else
            break;
    }
    
    for(int i=med+1;i<=fin;i++){
        if(arr[i]==cantProd1){
            der++;
        }else 
            break;
    }
    
   return izq+der; 
}


int calculoHorasMaximaProduccion(int cantProd1,int *arr,int ini,int fin){
    if(ini==fin) return 0;
    //con esto calculo las cantidad de horas con respecto a la cantidad de produccion maxima ya encontrada
    int med = (ini+fin)/2;
    int izq= calculoHorasMaximaProduccion(cantProd1,arr,ini,med);
    int der= calculoHorasMaximaProduccion(cantProd1,arr,med+1,fin);
    int centro= calculoCantHoras(cantProd1,arr,ini,med,fin);
    
    return max(max(izq,der),centro);
}



int empresaElegida(int cantProd1,int cantProd2,int cantProd3,int *arr1,int *arr2,int *arr3,int ini,int fin){
 
    int a=calculoHorasMaximaProduccion(cantProd1,arr1,ini,fin);
    int b=calculoHorasMaximaProduccion(cantProd2,arr2,ini,fin);
    int c=calculoHorasMaximaProduccion(cantProd3,arr3,ini,fin);
    int menor = min(min(a,b),c);
    if(c==menor) return 3;
    if(b==menor) return 2;
    if(a==menor) return 1;
}


int main(int argc, char** argv) {
    int arr1[10]={15,12,10,17,15,18,18,18,12,16};
    int horas=10;
    int arr2[10]={14,17,17,17,17,12,14,14,12,12};
    int arr3[10]={16,18,20,20,15,18,16,18,18,16};
    int cantProd1=0,cantProd2=0,cantProd3=0;
    cout<<"Calcular la mayor cantidad de produccion:"<<endl;
    //se crea una funcion donde encuentre la mayor cantidad de produccion de cada empresa 
    cantProd1=mayorCantProduccion2(arr1,0,horas-1);
    cantProd2=mayorCantProduccion2(arr2,0,horas-1);
    cantProd3=mayorCantProduccion2(arr3,0,horas-1);
    cout<<cantProd1<<" "<<cantProd2<<" "<<cantProd3;
    //se crea una funcion donde se ve que empresa eliga skypper 
    cout<<endl<<"Empresa a elegir es la numero: "<<endl;
    cout<<empresaElegida(cantProd1,cantProd2,cantProd3,arr1,arr2,arr3,0,horas-1);
    return 0;
}

