/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 10 de abril de 2024, 04:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#define n 10
#define m 6

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
int maxPeso(int*robots){
    int mayor=0;
    int i;
    while(i<m){
        if(robots[i]>mayor){
            mayor=robots[i];
        }
        i++;
    }
    return mayor;
}
int main(int argc, char** argv) {
    
    int niveles=5;
    int cantRobots=6;
    int contador=0;
    int vidrios[n][2]={{100,0},{90,1},{90,0},{98,1},{95,0},{75,1},{85,0},{96,1},{105,0},{93,1}};
    
    int robots[m]={77,82,81,90,92,75};
    int pasos[m];
    int p=0;
    int pos;
    
    int combinaciones=pow(2,n);
    int cromosoma[n];
    int maxPesoRobot=maxPeso(robots);
    
    for(int i=0;i<combinaciones;i++){
        cargaBin(cromosoma,n,i);
        p=0;
        for(int j=0;j<n;j++){
            if(cromosoma[j]){
                if(maxPesoRobot<vidrios[j][0]){
                    if(p<niveles){
                        pasos[p]=vidrios[j][1];
                        p++;
                        pos=j;                       
                    }                
                }
            }            
        }
        if(p==5 && pos>7){
            for(int k=0;k<niveles;k++){
                if(pasos[k]==0){
                    cout<<"Izquierda ";
                }else{
                    cout<<"Derecha ";
                }
            }
            cout<<endl;
        }       
    }
    
    return 0;
}

