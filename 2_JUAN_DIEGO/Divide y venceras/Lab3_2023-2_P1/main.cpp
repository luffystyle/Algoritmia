/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 2 de mayo de 2024, 11:58 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int cont=0;

int calculaMayor(int*empresa,int ini,int fin){
    //ooojooo
    int mayor;
    if(ini==fin)return empresa[ini];
    
    int med=(ini+fin)/2;
    
    int der=calculaMayor(empresa,ini,med);
    int izq=calculaMayor(empresa,med+1,fin);
    
    if(der>izq){
        mayor=der;
    }else{
        mayor=izq;
    }
    return mayor;
}

//int cuentaMayor(int*empresa1,int der,int med,int izq,int mayor){
//    
//}
int eleccion(int*empresa,int ini,int fin,int mayor){
    
    if(ini==fin)return empresa[ini];//ooojooo
    
    int med=(ini+fin)/2;
    
    int der=eleccion(empresa,ini,med,mayor);
    int izq=eleccion(empresa,med+1,fin,mayor);
    
    if(der==mayor){
        cont++;
    }
    if(izq==mayor){
        cont++;
    }
    return cont;
}

int main(int argc, char** argv) {
    
    
    int n=10;
    int i=3;
    int empresa1[n]={15,12,10,17,15,18,18,18,12,16};
    int empresa2[n]={14,17,17,17,17,12,14,14,12,12};
    int empresa3[n]={16,18,20,20,15,18,16,18,18,16};
    int maximo;
    
    int mayor1,mayor2,mayor3;
    
    mayor1=calculaMayor(empresa1,0,n-1);
    cout<<"Mayor cantidad de produccion ene empresa 1: "<<mayor1<<endl;
    mayor2=calculaMayor(empresa2,0,n-1);
    cout<<"Mayor cantidad de produccion ene empresa 2: "<<mayor2<<endl;
    mayor3=calculaMayor(empresa3,0,n-1);
    cout<<"Mayor cantidad de produccion ene empresa 3: "<<mayor3<<endl;
    
    /////////*Parte B*//////////////
    int eleccion1,eleccion2,eleccion3;
    
    eleccion1=eleccion(empresa1,0,n-1,mayor1);
    cont=0;
    eleccion2=eleccion(empresa2,0,n-1,mayor2);
    cont=0;
    eleccion3=eleccion(empresa3,0,n-1,mayor3);
    
//    cout<<eleccion1<<endl;
//    cout<<eleccion2<<endl;
//    cout<<eleccion3<<endl;
    
    if(eleccion1<eleccion2 && eleccion1<eleccion3){
        cout<<"El maestro spliner debe comprar en la empresa 1."<<endl;
    }else if(eleccion2<eleccion1 && eleccion2<eleccion3){
        cout<<"El maestro spliner debe comprar en la empresa 2."<<endl;
    }else if(eleccion3<eleccion1 && eleccion3<eleccion1){
        cout<<"El maestro spliner debe comprar en la empresa 3."<<endl;
    }    
    return 0;
    
}

