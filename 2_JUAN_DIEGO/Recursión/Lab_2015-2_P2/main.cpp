/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 3 de abril de 2024, 12:21 AM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

/*
 * 
 */

void patron(int n, int i){
    
    if(i==n)return;
    
    for(int j=0;j<i;j++){
        cout<<" ";
    }
    cout<<"*"<<endl;
    /*------------------------------------------------------------------------*/
    for(int j=0;j<i;j++){
        cout<<" ";
    }
    cout<<"**"<<endl;
    /*------------------------------------------------------------------------*/
    for(int j=0;j<i;j++){
        cout<<" ";
    }
    cout<<" *"<<endl;
    /*------------------------------------------------------------------------*/   
    
    if(18%(i-1)==0){
        for(int k=0;k<i*2+4;k++){
            cout<<"*";
        }
        cout<<endl;
    }
    patron(n,i+2);
}
int main(int argc, char** argv) {
    int i=0;
    int n=8;
    
    patron(n,i);
    return 0;
}

