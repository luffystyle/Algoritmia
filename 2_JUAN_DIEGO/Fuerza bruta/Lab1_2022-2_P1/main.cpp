/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 11 de abril de 2024, 08:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#define n 8

using namespace std;

/*
 * 
 */

void cargaBin(int*cromosoma,int longitud,int num){
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
    
    int maxTipos=4;
    int presupuesto=19;
    
    int tipo[n]={1,2,3,4,5,6,7,8};
    int precio[n]={4,5,4,2,6,3,4,1};
    int cantRenovar[n]={3,2,1,1,3,3,2,4};
    
    int cromosoma[n];
    int costo;
    int renovar;
    int tipos;
    int mayor=0;
    int mejorSol;
    
    int combinaciones=pow(2,n);
    
    for(int i=0;i<combinaciones;i++){
        cargaBin(cromosoma,n,i);
        costo=0;
        renovar=0;
        tipos=0;
        for(int j=0;j<n;j++){
            if(cromosoma[j]){
                if(costo<19){
                    costo+=precio[j]*cantRenovar[j];
                    renovar+=cantRenovar[j];
                    tipos++;
                }
            }
        }
        if(renovar>mayor){
            mayor=renovar;
            mejorSol=i;            
        }
        
        if(tipos==maxTipos && costo<=presupuesto){
        cout<<"Mejor solucion: "<<endl;
        for(int k=0;k<8;k++){
            if(cromosoma[k]){
            cout<<k+1<<" ";
            }
        }
        cout<<endl;  
        }
    }      
    return 0;
}

