/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 6 de mayo de 2024, 05:05 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int max(int a,int b){
    if(a>b){
        return a;
    }else
        return b;
}
int menorPeso(int*arr,int ini,int fin){
    
    if(ini==fin)return arr[ini];
    
    int med=(ini+fin)/2;
    
    int izq=menorPeso(arr,ini,med);
    int der=menorPeso(arr,med+1,fin);
    
    if(der<izq){
        return der;
    }else{
        return izq;
    }  

}

int maxCentro(int*arr,int ini,int med,int fin,int menor){
    
    int contIzq=0;
    int contDer=0;
    
    for(int i=med;i>ini;i--){
        if(arr[i]==menor){
            contIzq++;
        }else{
            break;
        }
    }
    
    for(int i=med+1;i<fin;i++){
        if(arr[i]==menor){
            contDer++;
        }else{
            break;
        }
    }
    return contIzq + contDer;
}

int maxCantNum(int*arr,int ini,int fin,int menor,int*dias,int*diasConsec){
    if(ini==fin){
        if(arr[ini]==menor){
            diasConsec[ini]=dias[ini];
        }
        return 1;
    }    
    
    int med=(ini+fin)/2;
    
    int izq=maxCantNum(arr,ini,med,menor,dias,diasConsec);
    int der=maxCantNum(arr,med+1,fin,menor,dias,diasConsec);
    int centro=maxCentro(arr,ini,med,fin,menor);
    
    return max(max(izq,der),centro);
}
int main(int argc, char** argv) {
    
    int arr[]={98,95,92,89,91,92,89,89,92,93,94,92,91,90,88,88,88,89,90,91,88,88,90,90,92,89,90,88,90,91};
    int n=30;
    int menor;
    int num;
    int dias[n];//dias del mes
    int diasConsec[n];
    
    for(int i=0;i<n;i++){
        dias[i]=i+1;
    }
    for(int i=0;i<n;i++){
        diasConsec[i]=0;
    }
    
    menor=menorPeso(arr,0,n-1);
    
    cout<<"El menor peso fue de "<<menor<<". ";
    
    num=maxCantNum(arr,0,n-1,menor,dias,diasConsec);

    cout<<"Cantidad de dias que logro su menor fueron "<<num<<". \n";

    int contador=0;
    for(int i=0;i<n;i++){
        contador=0;
        if(diasConsec[i]>0){//encuentra un dia en el que tuvo el menor peso
            contador++;
            for(int j=1;j<num;j++){//comprobamos si los dias son igual a la cantidad maxima de dias que tuvo el menor peso
                if(diasConsec[i+1]>0){
                    contador++;
                    i++;
                }
            }
            if(contador==num){//Si cumple que el contador y la cantidad maxima de dias son iguales, mostramos ese intervalo
                cout<<"El rango de días en que lo obtuvo fue del "<<i-1<<" al "<<i+1<<". ";
            }
        }
    }
//    cout<<"El rango de días en que lo obtuvo fue del "<<diasConsec[0]<<" al "<<diasConsec[num-1]<<". ";
    
    return 0;
}

