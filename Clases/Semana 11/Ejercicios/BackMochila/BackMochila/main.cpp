/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 23 de octubre de 2023, 12:40 PM
 */

#include <iostream>

using namespace std;

int empaca(int i,int n,int *paq,int peso){
    
    if(i==n||peso<0) return 0;
    if(peso==paq[i]) return 1;
    if(empaca(i+1,n,paq,peso-paq[i])) return 1;
    else  return empaca(i+1,n,paq,peso);
}


int main(int argc, char** argv) {
    int peso=70, n = 5;
    int paq[]={80,20,30,50,60};
    
    cout <<empaca(0,n,paq,peso);
    

    return 0;
}

