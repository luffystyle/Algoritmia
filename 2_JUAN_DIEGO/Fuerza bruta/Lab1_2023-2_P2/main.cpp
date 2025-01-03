/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 11 de abril de 2024, 05:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#define n 8

using namespace std;


/*
 * 
 */
void cargabin(int*cromosoma,int longitud,int num){
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
int evaluarRequisito(int requisitos[][n],int num,int*reqCumplido){
    int req=0;
    int valido=0;
    
    if(requisitos[num][0]==0){
        valido=1;
    }else if(requisitos[num][0]>0 && requisitos[num][1]>0){
        for(int i=0;i<2;i++){
            req=requisitos[num][i];
            if(reqCumplido[req-1]==1){
                valido=1;
            }else{
                valido=0;
            }
        }
    }else if(requisitos[num][0]>0 && requisitos[num][1]==0){
        req=requisitos[num][0];
        if(reqCumplido[req-1]==1){
            valido=1;
        }else{
            valido=0;
        }
    }
    
    return valido;
}

void llenarArreglo(int*reqCumplido){
    for(int i=0;i<n;i++){
        reqCumplido[i]=0;
    }
}

int main(int argc, char** argv) {
    
    int controlesSegurdiad=8;
    int presupuesto=100;//presupuesto eesta en miles de dolares
    int inversion[n]={32,8,40,40,20,4,16,16};
    int beneficio[n]={60,32,120,60,32,20,48,60};
    int requisitos[n][n]={{0,0},{0,0},{1,2},{0,0},{0,0},{2,0},{6,0},{6,0}};
    
    int cromosoma[n];
    int valido;  
    int total;
    int benef;
    int beneficioMayor=0;
    int reqCumplido[n];
    int mejorSolu;
    
    
    int combinaciones=pow(2,n);
    
    for(int i=0;i<combinaciones;i++){
        cargabin(cromosoma,n,i);
        total=0;
        benef=0;
        llenarArreglo(reqCumplido);
        for(int j=0;j<n;j++){
            if(cromosoma[j]){
                valido=evaluarRequisito(requisitos,j,reqCumplido);
                if(valido){                    
                    total+=inversion[j];
                    benef+=beneficio[j];
                    reqCumplido[j]=1;
                }
            }            
        }
        if(total==presupuesto){
            cout<<"Controles: ";
            for(int j=0;j<n;j++){                
                if(reqCumplido[j]>0){
                    cout<<j+1<<" ";
                }
            }
            cout<<"Beneficio: "<<benef<<endl;
            if(benef>beneficioMayor){
                beneficioMayor=benef;
                mejorSolu=i;
            }           
        }        
    }
    cargabin(cromosoma,n,mejorSolu);
    cout<<"Beneficio mayor: "<<beneficioMayor<<endl;
    cout<<"Mejor combinacion: ";
    for(int j=0;j<n;j++){
        if(cromosoma[j]>0){
            cout<<j+1<<" ";
        }        
    }
    cout<<endl;    
    return 0;
}

