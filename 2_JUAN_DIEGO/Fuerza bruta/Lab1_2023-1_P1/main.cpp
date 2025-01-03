/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 26 de marzo de 2024, 07:13 AM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#define n 4
using namespace std;

/*
 * 
 */

int cargaBin(int cromosoma[],int longitud,int num){
    int i;
    for(int j=0;j<longitud;j++){
        cromosoma[j]=0;
    }
    i=0;
    while(num>0){
        cromosoma[i]=num%2;
        num=num/2;
        i++;
    }
}
int main(int argc, char** argv) {
    
    int pesos[n*n]={20,20,20,20,10,30,10,30,10,10,10,10,15,15,15,15};
    int valores[n*n]={10,10,10,50,80,10,10,20,20,20,20,20,50,50,50,50};
    
    int cromosoma[n*n];
    int mayor_ganancia=0;
    int mejor_combinacion=0;
    
    int combinaciones=pow(2,n*n);
     
    for(int i=0;i<combinaciones;i++){
        int ganancia;
        int peso;
        cargaBin(cromosoma,n*n,i);
        ganancia=0;
        peso=0;
        for(int j=0;j<n*n;j++){            
            int ganancia_parcial=0;
            int peso_parcial=0;
            if(cromosoma[j]){
                peso_parcial=pesos[j];
                peso+=peso_parcial;
                if(peso<=100){
                    ganancia_parcial=valores[j];
                    ganancia+=ganancia_parcial;
                }                
            }             
        }
        if(ganancia>=mayor_ganancia && peso==100){
            mayor_ganancia=ganancia;
            mejor_combinacion=i;
        }
    }
    cargaBin(cromosoma,n*n,mejor_combinacion);
    cout<<"Ganancia total: "<<mayor_ganancia<<endl;
    for(int k=0;k<n*n;k++){        
        if(cromosoma[k]){
            cout<<pesos[k]<<" ";
        }else{
            cout<<0<<" ";
        }        
        if((k+1)%4==0){
            cout<<"\n";
        }
    } 
    cout<<endl;
    for(int k=0;k<n*n;k++){        
        if(cromosoma[k]){
            cout<<valores[k]<<" ";
        }else{
            cout<<0<<" ";
        }        
        if((k+1)%4==0){
            cout<<"\n";
        }
    }

    return 0;
}

