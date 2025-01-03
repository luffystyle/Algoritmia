/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: Ariana
 * 
 * Created on 11 de octubre de 2024, 11:23 PM
 */
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Funciones.h"

void declararGanador(int ataque1,int ataque2){
    if(ataque1!=0) cout<<"Gana la batalla Bowser"<<endl;
    if(ataque2!=0) cout<<"Gana la batalla Peach"<<endl;
}

void pelea(int i,Lista &ejercito1,Nodo *&recorrido1,int &ataque1,
        Lista &ejercito2,Nodo *&recorrido2,int &ataque2){
    if(recorrido1!=nullptr){
        if(recorrido2!=nullptr){
            int guerrero1=recorrido1->guerrero;
            int guerrero2=recorrido2->guerrero;
            int ganador;

            if(guerrero1>guerrero2){
                ganador=guerrero1;
                ataque2-=guerrero2;
                sacarDeLista(ejercito2);
            }else{
                ganador=guerrero2;
                ataque1-=guerrero1;
                sacarDeLista(ejercito1);
            }

            recorrido1=recorrido1->siguiente;
            recorrido2=recorrido2->siguiente;
            cout<<"Batalla "<<i<<": "<<guerrero1<<" vs "<<guerrero2
                    <<", gana "<<ganador<<endl;
        }
    }
}

void sacarDeLista(Lista &lista){
    lista.cabeza=lista.cabeza->siguiente;
    lista.longitud--;
}

void integrarEjercito(Lista &ejercito2,int &ataque2,Lista &ejercito3,int ataque3){
    fusionarLista(ejercito2,ejercito3);
    ordenarListas(ejercito2);
    ataque2+=ataque3;
}

void fusionarLista(Lista &lista1,Lista &lista2){
    Nodo *ultimoNodo=devolverUltimoNodo(lista1);
    
    if(ultimoNodo==0){
        lista1.cabeza=lista2.cabeza;
    }else{
        ultimoNodo->siguiente=lista2.cabeza;
    }
    lista1.longitud+=lista2.longitud;
}

void formarEjercitos(Lista &ejercito1,int &ataque1,Lista &ejercito2,int &ataque2,
        Lista &ejercito3,int &ataque3,Lista &guerreros,int cantGuerr){
    int guerrero,ataque;
    Nodo *recorrido=guerreros.cabeza;
    
    while(recorrido!=nullptr){
        guerrero=(recorrido->guerrero)%10;
        ataque=(recorrido->guerrero)/10;
        
        insertarEnEjercito(guerrero,ataque,ejercito1,ataque1,ejercito2,ataque2,
                ejercito3,ataque3);
        
        recorrido=recorrido->siguiente;
    }
    ordenarListas(ejercito1);
    ordenarListas(ejercito2);
    ordenarListas(ejercito3);
    destruirLista(guerreros);
}

void insertarEnEjercito(int guerrero,int ataque,Lista &ejercito1,int &ataque1,
        Lista &ejercito2,int &ataque2,Lista &ejercito3,int &ataque3){
    if(guerrero==1){
        insertarAlFinal(ejercito1,ataque);
        ataque1+=ataque;
    }
    if(guerrero==2){
        insertarAlFinal(ejercito2,ataque);
        ataque2+=ataque;
    }
    if(guerrero==3){
        insertarAlFinal(ejercito3,ataque);
        ataque3+=ataque;
    }
}

void ordenarListas(Lista &lista){
    bool intercambio=true;
    
    if(esListaVacia(lista)) intercambio=false;
    
    while(intercambio){
        Nodo *recorrido=lista.cabeza;
        intercambio=false;
        while(recorrido->siguiente!=nullptr){
            if(recorrido->guerrero > recorrido->siguiente->guerrero){
                intercambio=true;
                int guerrero=recorrido->guerrero;
                recorrido->guerrero=recorrido->siguiente->guerrero;
                recorrido->siguiente->guerrero=guerrero;
            }
            recorrido=recorrido->siguiente;
        }
    }
}

void imprimirLista(Lista &lista){
    if(esListaVacia(lista)){
        cout<<"La lista está vacía, no se puede imprimir";
    }else{
        Nodo *recorrido=lista.cabeza;
        bool flag=false;
        while(recorrido!=nullptr){
            if(flag) cout<<" -> ";
            flag=true;
            cout<<recorrido->guerrero;
            recorrido=recorrido->siguiente;
        }
    }
    cout<<endl;
}

bool esListaVacia(const Lista lista){
    return (lista.cabeza==nullptr);
}

void insertarAlFinal(Lista &lista,int guerrero){
    Nodo *nuevoNodo=crearNuevoNodo(guerrero,nullptr);
    Nodo *ultimoNodo=devolverUltimoNodo(lista);
    
    if(ultimoNodo==nullptr){
        lista.cabeza=nuevoNodo;
    }else{
        ultimoNodo->siguiente=nuevoNodo;
    }
    lista.longitud++;
}

Nodo *devolverUltimoNodo(Lista &lista){
    Nodo *recorrido=lista.cabeza;
    Nodo *ultimoNodo=recorrido;
    
    while(recorrido!=nullptr){
        ultimoNodo=recorrido;
        recorrido=recorrido->siguiente;
    }
    return ultimoNodo;
}

Nodo *crearNuevoNodo(int guerrero,Nodo *siguiente){
    Nodo *nuevoNodo=new Nodo;
    nuevoNodo->guerrero=guerrero;
    nuevoNodo->siguiente=siguiente;
    return nuevoNodo;
}

void construirLista(Lista &lista){
    lista.cabeza=nullptr;
    lista.longitud=0;
}

void destruirLista(Lista &lista){
    while(lista.cabeza!=nullptr){
        lista.cabeza=lista.cabeza->siguiente;
    }
}

void AperturaIf(ifstream &arch,const char *nomb){
    if(!arch){
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
}