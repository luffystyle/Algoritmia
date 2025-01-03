/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 14 de octubre de 2023, 10:10 AM
 */

#include <iostream>
#include <fstream>
using namespace std;
#include <cmath>
#include "funcionesLista.h"
#include "Lista.h"
#include "Nodo.h"
/*
 * 
 */
void LeerDatos(int N,int* tortugas,Lista* camiones,const char* nomArch);
void BubleSortMayor(Lista &LS);
void BubleSortMenor(Lista &LS);
void cargaBin(int *cromo,int num,int N);
bool DeterminarSalvacion(int *Pesos,int comb,int N,int *tortugas);

int main(int argc, char** argv) {
    int N;
    int tortugas[4]; //L 0,R 1,D 2,M 3
    cout << "Ingrese la cantidad de camiones: ";
    cin >> N;
    int i;
    for(i=0;i<4;i++){
        cout <<"Ingrese la capacidad maxima de la tortuga "<<i+1<<":";
        cin>>tortugas[i];
    }
    Lista camiones[N];
    cout << "Se llenaran los camiones en base al contenido del archivo Datos.txt"<<endl;
    for(i=0;i<N;i++){
        construir(camiones[i]);
    }
    LeerDatos(N,tortugas,camiones,"Datos.txt");
    int Pesos[N];
    for(i=0;i<N;i++){
        Pesos[i] = camiones[i].pesoTotal;
//        cout << Pesos[i]<<' ';
    }
//    cout << endl;
    int comb = (int)pow(2,N);
    int cromo[N];
    bool PuedenSalvar=DeterminarSalvacion(Pesos,comb,N,tortugas);
    if(PuedenSalvar)cout << "Las TortuNinjas completaron su misión";
    else cout << "Las TortuNinjas NO completaron su misión";
    return 0;
}

void LeerDatos(int N,int* tortugas,Lista* camiones,const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if(not arch.is_open()){
        cout << "Error: "<<nomArch<<endl;
        exit(1);
    }
    int peso;
    char c;
    int i,k;
    for(i=0;i<N;i++){
        while(true){
            arch>>peso;
            insertarAlFinal(camiones[i],peso);
            c = arch.get();
            if(c == '\n')break;
        }
    }
//    for(i=0;i<N;i++){
//        imprime(camiones[i]);
//    }
}



void BubleSortMayor(Lista &LS){
    Nodo* r,*Ar,*sup,*inter1,*inter2,*aux;
    for(int i=0;i<=LS.longitud-2;i++){
        r = LS.cabeza;Ar = nullptr;
        for(int k=0;k<=LS.longitud-i-2;k++){
            if(r->siguiente->elemento < r->siguiente->elemento){
                sup = Ar;
                inter1 = aux = r;
                inter2 = r->siguiente;
                if(sup == nullptr)LS.cabeza = inter2;
                else sup->siguiente = inter2;
                inter1->siguiente = inter2->siguiente;
                inter2->siguiente = aux;
                r = inter2;
                Ar = inter1;
            }
            Ar = r;
            r = r->siguiente;
        }
    }
}
void BubleSortMenor(Lista &LS){
    Nodo* r,*Ar,*sup,*inter1,*inter2,*aux;
    for(int i=0;i<=LS.longitud-2;i++){
        r = LS.cabeza;Ar = nullptr;
        for(int k=0;k<=LS.longitud-i-2;k++){
            if(r->siguiente->elemento > r->siguiente->elemento){
                sup = Ar;
                inter1 = aux = r;
                inter2 = r->siguiente;
                if(sup == nullptr)LS.cabeza = inter2;
                else sup->siguiente = inter2;
                inter1->siguiente = inter2->siguiente;
                inter2->siguiente = aux;
                r = inter2;
                Ar = inter1;
            }
            Ar = r;
            r = r->siguiente;
        }
    }
}

bool DeterminarSalvacion(int *Pesos,int comb,int N,int *tortugas){
    int pesoPermitido,pesoparcial,ganador;
    int cromo[N];
    int verificador[4]{};
    int prueba[N];
    for(int j=0;j<N;j++){
            prueba[j]=Pesos[j];
    }
    for(int i=0;i<4;i++){
        pesoPermitido = tortugas[i];
        pesoparcial = 0;
        ganador = -1;
        
        for(int j=0;j<comb;j++){
            cargaBin(cromo,j,N);
            pesoparcial = 0;
            for(int k=0;k<N;k++){
                pesoparcial = prueba[k]*cromo[k];
            }
            if(pesoparcial<=pesoPermitido){
                ganador = j;
            }
        }
        if(ganador != -1){
            verificador[i]=1;
            cargaBin(cromo,ganador,N);
            for(int k=0;k<N;k++){
                if(cromo[k]==1){
                    prueba[k]=99999;
                }
            }
        }else verificador[i]=0;
    }
    int suma=0;
    for(int i=0;i<4;i++){
        suma += verificador[i];
    }
    if(suma==4){
        return true;
    }else return false;
}

void cargaBin(int *cromo,int num,int N){
    int i,res;
    for(i=0;i<N;i++)cromo[i]=0;
    i=0;
    while(num>0){
        res = num%2;
        num /=2;
        if(res == 1)cromo[i]=1;
        else cromo[i]=0;
        i++;
    }
}

void AgregarCamiones(Lista &Principla,Lista &Secundaria){
    
}

