/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Ariana
 *
 * Created on 11 de octubre de 2024, 12:29 PM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Funciones.h"
/*
 * 
 */
int main(int argc, char** argv) {
    ifstream arch("Guerreros.txt",ios::in);
    AperturaIf(arch,"Guerreros.txt");
    
    Lista guerreros;
    construirLista(guerreros);
    
    int n,cantGuerr,guerr;
    cout<<"Ingrese el valor de n: ";
    arch>>n;
    cout<<n<<endl;
    cout<<"Ingrese la cantidad total de guerreros: ";
    arch>>cantGuerr;
    cout<<cantGuerr<<endl;
    while(1){
        arch>>guerr;
        if(arch.eof()) break;
        insertarAlFinal(guerreros,guerr);
    }
    cout<<"Lista guerreros: ";
    imprimirLista(guerreros);
    cout<<endl;
    
    //Formar ejércitos
    cout<<"Los ejércitos formados son:"<<endl;
    int ataque1=0,ataque2=0,ataque3=0;
    Lista ejercito1,ejercito2,ejercito3;
    construirLista(ejercito1);
    construirLista(ejercito2);
    construirLista(ejercito3);
    formarEjercitos(ejercito1,ataque1,ejercito2,ataque2,ejercito3,ataque3,
            guerreros,cantGuerr);
    
    cout<<"Ejército 1 - Bowser: ";
    imprimirLista(ejercito1);
    cout<<"Nivel de Ataque Total del Ejército 1: "<<ataque1<<endl;;
    cout<<endl;
    ordenarListas(ejercito1);
    
    cout<<"Ejército 2 - Peach: ";
    imprimirLista(ejercito2);
    cout<<"Nivel de Ataque Total del Ejército 2: "<<ataque2<<endl;;
    cout<<endl;
    
    cout<<"Ejército 3 - DonKey Kong: ";
    imprimirLista(ejercito3);
    cout<<"Nivel de Ataque Total del Ejército 3: "<<ataque3<<endl;;
    cout<<endl;
    
    //Batallas
    bool flag=true;
    while(1){
        int i;
        Nodo *recorrido1=ejercito1.cabeza;
        Nodo *recorrido2=ejercito2.cabeza;
        cout<<"Inicia la batalla:"<<endl;
        cout<<"Ejército 1 - Bowser: ";
        imprimirLista(ejercito1);
        cout<<"Ejército 2 - Peach: ";
        imprimirLista(ejercito2);
        
        for (i = 0; i < n; i++) {
            pelea(i+1,ejercito1,recorrido1,ataque1,ejercito2,recorrido2,ataque2);
        }
        
        cout<<"Nivel de Ataque Total del Ejército 1: "<<ataque1<<endl;;
        cout<<"Nivel de Ataque Total del Ejército 2: "<<ataque2<<endl;;
        
        if(esListaVacia(ejercito1) or esListaVacia(ejercito2)){
            declararGanador(ataque1,ataque2);
            break;
        }
        
        if(i==n and ataque1>ataque2){
            if(flag){
                integrarEjercito(ejercito2,ataque2,ejercito3,ataque3);
                cout<<"El ejército de DonKey Kong se une al ejército de Peach"<<endl;
                flag=false;
            }else{
                cout<<"Ya no se puede unir nadie al ejército de Peach"<<endl;
            }
        }
        cout<<endl;
    }
    
    
    return 0;
}

