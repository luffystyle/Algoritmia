/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 29 de abril de 2024, 12:06 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int max(int a,int b){
    if(a>b)return a;
    return b;
}
/*
 * 
 */
int maxcentro(int *arr,int ini,int med,int fin){
    int contIzq=1,contDer=1;
    
    if(arr[med]>arr[med+1])
        return 1;
    
    for(int i=med;i>ini;i--){
        if(arr[i]>arr[i-1])
            contIzq++;
        else
            break;
    }
    
    for(int i=med+1;i<fin;i++){
        if(arr[i+1]>arr[i])
            contDer++;
        else
            break;
    }
    return contIzq+contDer;
}

int cuentaIncremento(int *arr,int ini, int fin){
    
    if(ini==fin)return 1;
    int med=(ini+fin)/2;
    int izq=cuentaIncremento(arr,ini,med);
    int der=cuentaIncremento(arr,med+1,fin);
    int centro=maxcentro(arr,ini,med,fin);
    
    return max(max(izq,der),centro);
}

int main(int argc, char** argv) {
    int n=8;
    int arr[]={10,20,15,10,12,30,13,18};
    
    cout<<(1.0)*cuentaIncremento(arr,0,n-1)/n<<endl;
    return 0;
}

