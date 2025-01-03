/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: ferhu
 *
 * Created on 1 de abril de 2024, 21:58
 */


#include <iostream>

#include "Lista.h"
using namespace std;
#include "masFuncionesLista.h"
#include "funcionesLista.h"


/*
 * 
 */

void construirEjercitos(Lista & lista, Lista & bowser, Lista & peach, Lista & donkey){
    while(!esListaVacia(lista)){
        int ejerc = lista.cabeza->elemento%10;
        int nivel = lista.cabeza->elemento/10;
        if(ejerc==1){
            bowser.ejercito=1;
            insertarEnOrden(bowser,nivel);
        }else if(ejerc==2){
            peach.ejercito=2;
            insertarEnOrden(peach,nivel);
        }else if(ejerc==3){
            donkey.ejercito=3;
            insertarEnOrden(donkey,nivel);
        }
        eliminaCabeza(lista);
    }
}

void nivelEjercito(Lista & lista){
    if(lista.cabeza==nullptr)return;
    Nodo * aux = lista.cabeza;
    int sumaNivel = 0;
    while(aux!=nullptr){
        sumaNivel+=aux->elemento;
        aux=aux->siguiente;
    }   
    cout<<"Nivel de Ataque total del Ejercito "<<lista.ejercito<<":"<<sumaNivel<<endl;
}
int level(Lista & lista){
    Nodo * aux = lista.cabeza;
    int sumaNivel = 0;
    while(aux!=nullptr){
        sumaNivel+=aux->elemento;
        aux=aux->siguiente;
    }
    return sumaNivel;
}
void fusionar(Lista & L1,Lista & L2){
    if(L1.cola->elemento<L2.cabeza->elemento){
        L1.cola->siguiente=L2.cabeza;
        L1.cola=L2.cola;
    }else if(L2.cola->elemento<L1.cabeza->elemento){
        L2.cola->siguiente=L1.cabeza;
        L2.cola=L1.cabeza;
    }else{
        Nodo * F_ini,*F_fin;
        F_ini=NULL;
        F_fin=NULL;
        while(!esListaVacia(L1) && !esListaVacia(L2)){
            if (L1.cabeza->elemento <= L2.cabeza->elemento) { //Pasa L1
                if (F_ini == NULL) {
                    F_ini = L1.cabeza;
                    F_fin = L1.cabeza;
                } else {
                    F_fin->siguiente = L1.cabeza;
                    F_fin = L1.cabeza;
                }
                L1.cabeza = L1.cabeza->siguiente;
            } else
                if (L1.cabeza->elemento > L2.cabeza->elemento) {
                if (F_ini == NULL) {
                    F_ini = L2.cabeza;
                    F_fin = L2.cabeza;
                } else {
                    F_fin->siguiente = L2.cabeza;
                    F_fin = L2.cabeza;
                }
                L2.cabeza = L2.cabeza->siguiente;
            }
        }
        while (!esListaVacia(L1)) {
            if (F_ini == NULL) {
                F_ini = L1.cabeza;
                F_fin = L1.cabeza;
            } else {
                F_fin->siguiente = L1.cabeza;
                F_fin = L1.cabeza;
            }
            L1.cabeza = L1.cabeza->siguiente;
        }

        while (!esListaVacia(L2)) {
            if (F_ini == NULL) {
                F_ini = L2.cabeza;
                F_fin = L2.cabeza;
            } else {
                F_fin->siguiente = L2.cabeza;
                F_fin = L2.cabeza;
            }
            L2.cabeza = L2.cabeza->siguiente;
        }

        L1.cabeza = F_ini;
        L1.cola = F_fin;
    }
}


void batallas(Lista & bowser,Lista & peach,Lista & donkey,int n){
    bool refuerzo=true;
    while(!esListaVacia(bowser) && !esListaVacia(peach)){
        cout<<"Inicia la Batalla: \n";
        cout<<"Ejercito 1 - Bowser:";
        imprime(bowser);
        cout<<"Ejercito 2 - Peach: ";
        imprime(peach);
        Nodo * guerreroB,*guerreroP;
        guerreroB=bowser.cabeza;
        guerreroP=peach.cabeza;
        int peleadorB = guerreroB->elemento;
        int peleadorP = guerreroP->elemento;
        
        for(int i=0;i<n;i++){
            cout<<"Pelea "<<i+1<<":"<<peleadorB<<" vs "<<peleadorP;
            guerreroB=guerreroB->siguiente;
            guerreroP=guerreroP->siguiente;
        
        if(peleadorB > peleadorP){//gana peleador de bowser
            cout<<",gana "<<peleadorB<<endl;
            eliminaNodo(peach,peleadorP);
        }else if(peleadorB < peleadorP){// gana peleador de peach
             cout<<",gana "<<peleadorP<<endl;
            eliminaNodo(bowser,peleadorB);
        }
        if(guerreroB==nullptr || (guerreroP==nullptr && !refuerzo)){
            break;
        }
        peleadorB=guerreroB->elemento;
        peleadorP=guerreroP->elemento;
        if(level(bowser)<level(peach))continue;           
    }
    nivelEjercito(bowser);
    nivelEjercito(peach);
    if(refuerzo){
        refuerzo=false;
        fusionar(peach,donkey);
        cout << "El ejÃ©rcito de DonKey Kong se une al ejÃ©rcito de Peach" << endl;
        } else {
            cout << "Ya no se puede unir nadie al ejÃ©rcito de Peach" << endl;
        }    
    if(esListaVacia(peach)){
        cout << "Gana la batalla " << bowser.ejercito;
    }else{
        cout << "gana la batalla " << peach.ejercito;
    }
    }
}

int main(int argc, char** argv) {
    struct Lista lista;
    struct Lista bowser,peach,donkey;
    
    /*Construimos la lista, la lista esta vacía*/
    construir(lista);
    construir(bowser);
    construir(peach);
    construir(donkey);
    int n=2;
    int cantGuerreros=12;
    
    insertarAlInicio(lista,241);
    insertarAlInicio(lista,391);
    insertarAlInicio(lista,841);
    insertarAlInicio(lista,561);
    insertarAlInicio(lista,103);
    insertarAlInicio(lista,653);
    insertarAlInicio(lista,352);
    insertarAlInicio(lista,851);
    insertarAlInicio(lista,262);
    insertarAlInicio(lista,123);
    insertarAlInicio(lista,182);
    insertarAlInicio(lista,723); 
    cout<<"Lista de guerreros: ";
    imprime(lista);
    cout<<"Los ejercitos formados son: \n"<<endl;    
    construirEjercitos(lista, bowser,peach,donkey);
    cout<<"Ejercito 1 - Bowser:";
    imprime(bowser);
    nivelEjercito(bowser);
    cout<<endl;
    cout<<"Ejercito 2 - Peach: ";
    imprime(peach);
    nivelEjercito(peach);
    cout<<endl;
    cout<<"Ejercito 3 - Donkey Kong: ";
    imprime(donkey);
    nivelEjercito(donkey);
    batallas(bowser,peach,donkey,n);
            
    

    return 0;
}
