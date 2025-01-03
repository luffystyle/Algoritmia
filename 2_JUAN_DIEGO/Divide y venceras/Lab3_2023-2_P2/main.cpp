/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 8 de mayo de 2024, 06:18 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#define maximo 11

using namespace std;

/*
 * 
 */
char bocaditos[maximo][maximo]={{'O','O','C','C','A','A','E','E','R','R','R'},
                          {'C','C','A','A','R','R','E','E','B','B','0'},
                          {'R','R','E','E','C','C','F','F','A','A','0'},
                          {'E','E','F','F','A','A','A','B','B','R','R'},
                          {'C','C','C','A','A','R','R','O','O','E','E'},
                          {'O','O','C','C','A','A','R','R','E','E','0'},
                          {'A','A','F','F','R','R','E','E','O','O','0'},
                          {'E','E','A','A','O','O','B','B','F','F','0'}};

int precios[][maximo]={{1,2,3,2,1},
                       {2,3,2,2,1},
                       {1,2,2,5,3},
                       {2,5,3,3,1},
                       {2,2,3,2,1},
                       {1,2,3,2,1},
                       {3,5,2,1,1},
                       {2,3,2,1,1}};

int adicional;
int mayor[]={0};

char maxChar(char a,char b){
    return max(a,b);
}

int maxBocadito(int fila,char letra,int ini,int fin){
    int cont=0;
    for(int i=ini;i<=fin;i++){
        if(bocaditos[fila][i]==letra)cont++;
    }
    return cont;
}
char bocAdicional(int fila,int ini,int fin){
    if(ini==fin)return bocaditos[fila][ini];
    
    int med=(ini+fin)/2;
    
    char izq=bocAdicional(fila,ini,med);
    char der=bocAdicional(fila,med+1,fin);
    
    int contIzq=maxBocadito(fila,izq,ini,fin);
    int contDer=maxBocadito(fila,der,ini,fin);
    
    if(contIzq>contDer){
        return izq;
    }else{
        return der;
    }
}

int bocadoCaro(int fila,int ini,int fin){
    if(ini==fin){        
        return precios[fila][ini];
    }
    
    int med=(ini+fin)/2;
    
    int izq=bocadoCaro(fila,ini,med);
    int der=bocadoCaro(fila,med+1,fin);
    
    if(izq>der){
        mayor[0]=precios[fila][ini];
        return izq;
    }
        
    else{
        return der;
    }
        
}
int buscaPos(int fila,int p,int masCaro){
    for(int i=0;i<p;i++){
        if(precios[fila][i]==masCaro){
            return i;
        }
    }
}
int main(int argc, char** argv) {
    
    int n=11;
    int m=8;
    char bocado;
    
    //impresion de matriz
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<bocaditos[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int k=0;k<m;k++){
        adicional=0;
        bocado=bocAdicional(k,0,n-1); 
        if(bocaditos[k][n-1]!='0'){
            cout<<"La fila "<<k+1<<" tiene un "<<bocado<<" adicional."<<endl;
        }
    }
    cout<<endl;
    //Parte B
    
    int p=5;
    int q=8;
    int masCaro;
    int posicion;
    
    
    for(int j=0;j<q;j++){
        masCaro=bocadoCaro(j,0,p-1);
        posicion=buscaPos(j,p,masCaro);
        cout<<"En la fila "<<j+1<<" el pasajero del asiento "<<posicion+1<<" tiene el bocadito más caro que sus 2 vecinos"<<endl;
    }
    
    return 0;
}

