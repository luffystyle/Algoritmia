/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gianfranco Moises Poma Canchari
 * Code: 20185721
 * Created on 24 de septiembre de 2023, 08:00 PM
 */

#include <iostream>
#define N 15

using namespace std;

//3. Un arreglo está rotado en algún punto desconocido. Encontrar el
//elemento mínimo del arreglo. Asumir que todos los elementos son
//distintos.
//Ejemplo:
//Entrada: {5, 6, 1, 2, 3, 4}
//Salida: 1

//          {5,6,7,8,9,2,3,4}

//          {8,9,2,3,4,5,6,7}


int funcionRotado(int *arr,int ini,int fin){
    
    //Caso base
    if(ini>fin){
        return -1;
    }
    
    int medio=(ini+fin)/2;
    
    if(arr[medio]<arr[medio+1]&&arr[medio]<arr[medio-1]){
        return arr[medio];
    }else if(arr[fin]<arr[medio]){
        return funcionRotado(arr,medio+1,fin);
    }else{
        return funcionRotado(arr,ini,medio-1);
    }
    
}

int main(int argc, char** argv) {
    
    
    int arr[N]={8,9,10,11,6,7};
    
    int n=6;
    
    cout<<funcionRotado(arr,0,n-1);
    
    
    

    return 0;
}

