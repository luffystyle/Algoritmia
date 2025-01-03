/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 19 de marzo de 2024, 09:42 AM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#define N 6
#define W 25

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
    
    int objetos[N]={8,2,10,10,5,5};//pesos
    int ganancias[N]={15,20,5,10,8,5};
    int cromosoma[N];
    int costo_total;
    int mayor_ganancia=0;
    int mejor_combinacion=0;
    
    int combinaciones=pow(2,N);
    
    for(int i=0;i<combinaciones;i++){
        int pesoMochila=0;
        int ganancia=0;
        cargaBin(cromosoma,N,i);
        ganancia=0;
        costo_total=0;
        for(int j=0;j<N;j++){
            int ganancia_parcial=0;
            int peso_parcial=0;
            if(cromosoma[j]){
                peso_parcial=objetos[j];
                pesoMochila+=peso_parcial;
                if(pesoMochila<=W){
                    ganancia_parcial=ganancias[j];
                    ganancia+=ganancia_parcial;
                }                
            }            
        }        
        if(ganancia>=mayor_ganancia && pesoMochila==W){
            mayor_ganancia=ganancia;
            mejor_combinacion=i;
        }
        /*if(pesoMochila==W){
            cout<<"Articulos: ";
            for(int k=0;k<N;k++){
                if(cromosoma[k]){
                        cout<<k+1<<" " ;
                }
            }
            cout<<endl;
        }*/
    }
    cargaBin(cromosoma,N,mejor_combinacion);
    cout<<"Articulos: ";
    for(int k=0;k<N;k++){
        if(cromosoma[k]){
                cout<<k+1<<" " ;
        }
    }
    cout<<"Ganancia total: "<<mayor_ganancia<<endl;;

    return 0;
}

