/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 5 de abril de 2024, 12:32 AM
 */

#include <cstdlib>
#include <iostream>
#define maximo 10
using namespace std;

/*
 * 
 */
 int contador = 0;

 int servidor[maximo][maximo]{{0,0,0,0,0,0,0},
                    {10,0,20,30,0,20,40},
                    {0,0,0,0,0,100,0},
                    {0,0,0,0,0,80,0},
                    {50,10,5,10,0,100,4},
                    {100,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0}};
 
 int servidor2[maximo][maximo]{{0,10,10,10,20,10,10},
                     {10,0,20,30,0,20,40},
                     {0,0,0,0,0,100,0},
                     {0,0,0,0,0,80,0},
                     {50,10,5,10,0,100,4},
                     {100,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0}};
 
int buscarSkynerd(int pos,int n,int m){    
    if(m==0){
        return n;
    }     
    if(servidor[n][m]==0){
       return buscarSkynerd( pos, n-1, m-1);
    }else{
       return buscarSkynerd(pos,n, m-1);
    }    
 }

int  main(int argc, char** argv) {    
    
    int sospechoso;    
    int pos=0; 
    int n=7;
    int valido=0;
    sospechoso=buscarSkynerd(pos,n,n-1);
    cout<<sospechoso<<endl;
    for(int i=0;i<n;i++){
        if(servidor[i][sospechoso]==0 and (servidor[sospechoso][i]>0 or servidor[sospechoso][sospechoso]==0))
            valido=1;
        else{
            valido=0;
            break;
        }            
    }
    
    if(valido){
       cout<<"SkyNerd ha sido detectado en el servidor: "<<sospechoso+1<<endl; 
    }else{
        cout<<"SkyNerd no está en la red"<<endl;
    }
    return 0;
}

