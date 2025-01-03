/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 8 de abril de 2024, 03:50 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int espacios=0;

/*
 * 
 */
void bahias(int n,int m,int a,int max){
    
    if(n==m+1){
        return;
    }    
    cout<<"Entrada"<<endl;
    espacios++;
    for(int i=0;i<m;i++){
        cout<<" * ";
    }
    espacios++;
    cout<<endl;
    if(espacios<a-1){
        for(int j=0;j<m;j++){
            cout<<" * ";
        }
        espacios++;
        cout<<endl;
    }
    
    bahias(n,m-1,a,max);
    
    if(espacios<a-1){
        cout<<"Entrada"<<endl;
        espacios++;
    }
    if(espacios<a-2 && m<max){
        for(int i=0;i<m+1;i++){
            cout<<" * ";
        }
        espacios++;
        cout<<endl;
    }
    if(espacios<a-1 && m<max){
        for(int j=0;j<m+1;j++){
            cout<<" * ";
        }
        espacios++;
        cout<<endl;
    }
}
int main(int argc, char** argv) {
    
    int n=3;
    int m=6;
    int a=12;
    int max=m;
    
    cout<<"=========================="<<endl;    
    bahias(n,m,a,max);
    cout<<"=========================="<<endl;
    cout<<espacios;
    return 0;
}

