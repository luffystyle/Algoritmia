/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 11 de mayo de 2024, 12:18 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

void merge(int*arr,int ini,int med,int fin){
    int i,p,q;
    int longitud1,longitud2;
    longitud1=(med+1)-ini;
    longitud2=fin-med;
    
    int P[longitud1+1];
    int Q[longitud2+1];
    
    P[longitud1+1]=99999;
    Q[longitud2+1]=99999;
    
    for(i=ini;i<med+1;i++){
        P[i-ini]=arr[i];
    }
    for(i=med+1;i<=fin;i++){
        Q[i-(med+1)]=arr[i];
    }
    p=q=0;
    
    for(i=ini;i<=fin;i++){
        if(P[p]<Q[q]){
            arr[i]=P[p++];
        }else{
            arr[i]=Q[q++];
        }
    }    
}

int buscaPico(int arr[],int ini, int fin){
    int med=(ini+fin)/2;
    if(arr[med]>arr[med-1] and arr[med]>arr[med+1]){
        return arr[med];
    }
    if(arr[med]<arr[med+1])
        return buscaPico(arr,med,fin);
    else
        return buscaPico(arr,ini,med);
}

void mergesort(int*arr,int ini,int fin){
    if(ini==fin)return;
    
    int med=(ini+fin)/2;
    
    mergesort(arr,ini,med);//izquierda
    mergesort(arr,med+1,fin);//derecha
    merge(arr,ini,med,fin);
}

int buscaMax(int*arr,int ini,int fin){
    if(ini>=fin){
        return arr[ini];
    }
    int med=(ini+fin)/2;
    
    int izq=buscaMax(arr,ini,med);
    int der=buscaMax(arr,med+1,fin);
    
    if(izq>der){
        return izq;
    }else{
        return der;
    }
}

int buscaMin(int*arr,int ini,int fin){
    if(ini==fin){
        return arr[ini];
    }
    int med=(ini+fin)/2;
    
    int izq=buscaMin(arr,ini,med);
    int der=buscaMin(arr,med+1,fin);
    
    if(izq<der){
        return izq;
    }else{
        return der;
    }
}

int cuenta_ceros(int*arrCeros,int ini,int fin){
    
    if(ini==fin)return 1-arrCeros[ini];
    
    int med=(ini+fin)/2;
    
    if(arrCeros[med]==0){
        return (fin-med)+cuenta_ceros(arrCeros,ini,med);
    }else{
        return cuenta_ceros(arrCeros,med+1,fin);    
    }
}

int main(int argc, char** argv) {
    /////////////
    //Mergesort//
    /////////////
    int arrMerge[7]={11,2,7,1,2,3,5};
    int n=7;
    cout<<"Arreglo original: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arrMerge[i]<<" ";
    }
    mergesort(arrMerge,0,n-1);
    cout<<endl;
    cout<<"Arreglo ordenado: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arrMerge[i]<<" ";
    }
    cout<<endl;
    ////////////////
    //Busca maximo//
    ///////////////
    int arrMaxMin[]={12,24,15,12,11,10};
    int n2=6;
    cout<<"Maximo: "<<buscaMax(arrMaxMin,0,n2-1)<<endl;
    cout<<"Minimo: "<<buscaMin(arrMaxMin,0,n2-1)<<endl;
    ////////////////
    //Cuenta Ceros//
    ///////////////
    int arrCeros[]={1,1,1,0,0,0,0}; //arreglo
    int n3=7; //longitud del arreglo
    cout<<"Resultado: "<<cuenta_ceros(arrCeros,0, n3-1)<<endl; 
    ////////////////
    //Busca Pico//
    ///////////////
    int arrpico[]={1,2,3,2,1}; //arreglo
    int n4=5; //longitud del arreglo
    cout<<"Pico: "<<buscaPico(arrpico,0, n4-1)<<endl; 

    return 0;
}

