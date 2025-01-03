/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 1 de julio de 2024, 08:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    char palabra[3][10];
    for(int i=0;i<3;i++){
        cin>>palabra[i];
    }
    for(int j=0;j<3;j++){
        cout<<strlen(palabra[j])<<" ";
    }
    return 0;
}

