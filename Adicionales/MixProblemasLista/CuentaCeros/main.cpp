/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gianfranco Moises Poma Canchari
 * Code: 20185721
 * Created on 18 de septiembre de 2023, 10:38 AM
 */

#include <iostream>
#define N 10

using namespace std;

//int cuentaCeros(int arreglo[N], int inicio,int fin,int cuenta){
//    
//    //Caso base
//    if(inicio>fin){
//        return cuenta;
//        
//    }
//    
//    int medio=(inicio+fin)/2;
//    
//    
//    
//    if(arreglo[medio]==0){
//        if(arreglo[medio-1]==1){
//             return cuenta+fin-medio+1;
//        }
//       
//        else{
//            return  cuentaCeros(arreglo,inicio,medio-1,cuenta+fin-medio+1);
//        }
//    }else{
//        return  cuentaCeros(arreglo,medio+1,fin,cuenta);
//    }
//    
//    
//}




int cuentaCeros(int *arreglo,int ini,int fin){
    
   
    //Caso base
    if(ini>fin){
        return 0;
    }
    
    int medio=(ini+fin)/2;
    
   
    
    if(arreglo[medio]==0){
        //cout<<fin-ini<<endl;
        return cuentaCeros(arreglo,ini,medio-1)+fin-medio+1;
    }else{
        return cuentaCeros(arreglo,medio+1,fin);
    }
    
    
}



int main(int argc, char** argv) {
    
    int arreglo[N]={1,1,0,0,0,0,0};
    
//  int arreglo[N]={1,1,1,0,0,0,0,0};
    
    int n=7;
    
    cout<<cuentaCeros(arreglo,0,n-1);
    

    return 0;
}

