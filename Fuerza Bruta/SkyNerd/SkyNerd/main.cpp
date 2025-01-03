/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 25 de septiembre de 2023, 12:30 PM
 */
#include <iostream>
#include "funcionesPila.h"
#include "Pila.h"
#define N 8
using namespace std;

int red[N][N] = {   {0,0,0,0,0,0,0},
                    {10,0,20,30,0,20,40},
                    {0,0,0,0,0,100,0},
                    {0,0,0,0,0,80,0},
                    {50,10,5,10,0,100,4},
                    {100,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0}};

int buscaskynerd(int n){
    Pila server;
    int a,b,candidato;
    construir(server);
    for(int i=0;i<n;i++)apilar(server,i);
    while(server.lista.longitud>1){
        a = desapilar(server);
        b = desapilar(server);
        if(red[a][b]!=0) 
            apilar(server,a);
        else
            apilar(server,b);
    }
    candidato = desapilar(server);
    for(int i=0;i<n;i++){
        if((i!=candidato)&&(!red[candidato][i] || red[i][candidato]))
                return -1;
    }
    return candidato;
}


int main(int argc, char** argv) {
    
    int n=7,server;
 
    server = buscaskynerd(n);
    if (server==-1)
        cout <<"No esta skynerd";
    else
        cout << server + 1;

    return 0;
}

