/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gianfranco Moises Poma Canchari
 * Code: 20185721
 * Created on 26 de septiembre de 2023, 11:06 AM
 */

#include <iostream>
#define N 15

using namespace std;


//5. Dado un arreglo de enteros el cual primero crece y luego decrece.
//Encontrar el máximo valor en el arreglo.

//Ejemplo:

//Entrada:{8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}
//Salida: 500



int funcionMaxValor(int *arr,int ini,int fin){
    
    
     int medio=(ini+fin)/2;
    
    //Caso base
    if(ini>fin){
        return arr[medio];
    }
    
   
    
//    if(arr[medio]>arr[medio-1]&&arr[medio]>arr[medio+1]){
//        return arr[medio];
//    }
    if(arr[medio]>arr[medio-1]){
        return funcionMaxValor(arr,medio+1,fin);
    }else{
        return funcionMaxValor(arr,ini,medio-1);
    }
    
}


int main(int argc, char** argv) {
    
    
    //int arr[N]={8,10,20,80,7,6,5,4,3,2,1};
    
    int arr[N]={400,500,600,3,2};
    
    //int arr[N]={400,500,600,1};
    
    //   0      2        4
    
    int n=5;
    
    cout<<funcionMaxValor(arr,0,n-1);

    return 0;
}

