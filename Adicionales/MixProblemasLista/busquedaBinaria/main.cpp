/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gianfranco Moises Poma Canchari
 * Code: 20185721
 * Created on 26 de septiembre de 2023, 04:40 PM
 */

#include <iostream>
#define N 15

using namespace std;

 int busquedaBinaria(int *arr,int ini,int fin,int numBuscado){
     
     //caso base
     if(ini>fin){
         return -1;
     }
     
     int medio=(ini+fin)/2;
     
     if(arr[medio]==numBuscado){
         return 1;
     }
     
     if(arr[medio]>numBuscado){
         return busquedaBinaria(arr,ini,medio-1,numBuscado);
     }else{
         return busquedaBinaria(arr,medio+1,fin,numBuscado);
     }
     
     
     
 }



int main(int argc, char** argv) {
    
    
    int arr[N]={2,8,10,18,19,20,35};
    
    
    int n=7;
    
    int num=25;
    
    cout<<busquedaBinaria(arr,0,n-1,num);
    
    
    

    return 0;
}

