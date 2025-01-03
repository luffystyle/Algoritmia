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
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int min(int a,int b){
   if(a>b){
        return b;
    }else{
        return a;
    }
}

int calculoDeMayorproduccion(int *arr,int ini,int fin){//complejidad O(n)
    int med,izq,der;
    if(ini==fin) return arr[ini];
    med=(ini+fin)/2;
    izq=calculoDeMayorproduccion(arr,ini,med);
    der=calculoDeMayorproduccion(arr,med+1,fin);
    return max(izq,der);
}

int calculoMayor(int *arr,int ini,int fin){ // complejidad O(n)
    if(ini==fin) return arr[ini];
    int med = (ini+fin)/2;
    int izq=calculoMayor(arr,ini,med) ;
    int der=calculoMayor(arr,med+1,fin) ;
    
    return max(izq,der);
}

int maximoCalculo(int n,int *arr,int ini,int med,int fin){ //O(logn)
    if(arr[med]!=n) return -1;
    int cont=0;
    for(int i=med;i>=ini;i--){
        if(arr[i]==n){
            cont++;
        }
    }
    for(int i=med+1;i<=fin;i++){
        if(arr[i]==n){
            cont++;
        }
    }
    return cont;
    
}
int calculoDeCantidad(int n,int *arr,int ini,int fin){ //O(nlogn)
    if(ini>fin) return -1;
    int med= (ini+fin)/2;
    if(ini==fin) return 1;
    int izq=calculoDeCantidad(n,arr,ini,med);
    int der=calculoDeCantidad(n,arr,med+1,fin);
    int cent=maximoCalculo(n,arr,ini,med,fin);
    
    return max(max(izq,der),cent);
}




int main(int argc, char** argv) {
    int cant=10;
    int horas[cant]={2,3,4,5,6,7,8,9,10,11};
    int arr1[cant]={15,12,10,17,15,18,18,18,12,16};
    int arr2[cant]={14,17,17,17,17,12,14,14,12,12};
    int arr3[cant]={16,18,20,20,15,18,16,18,18,16};
    
    int mayorProduc1=calculoDeMayorproduccion(arr1,0,cant-1);
    int mayorProduc2=calculoDeMayorproduccion(arr2,0,cant-1);
    int mayorProduc3=calculoDeMayorproduccion(arr3,0,cant-1);
    cout<<"Mayor produccion de la empresa 1: "<<mayorProduc1<<endl;
    cout<<"Mayor produccion de la empresa 2: "<<mayorProduc2<<endl;
    cout<<"Mayor produccion de la empresa 3: "<<mayorProduc3<<endl;
    int cantidad1=calculoDeCantidad(mayorProduc1,arr1,0,cant-1);
    int cantidad2=calculoDeCantidad(mayorProduc2,arr2,0,cant-1);
    int cantidad3=calculoDeCantidad(mayorProduc3,arr3,0,cant-1);
    //cout<<cantidad1<<endl;
    int menor= min(min(cantidad1,cantidad2),cantidad3);
    cout<<"La empresa a donde debe comprar es: ";
    if(menor==cantidad1){
        cout<<"1"<<endl;
    }else if(menor==cantidad2){
        cout<<"2"<<endl;
    }else if(menor==cantidad3){
        cout<<"3"<<endl;
    }
    return 0;
}

