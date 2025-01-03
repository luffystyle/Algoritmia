/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 18 de mayo de 2024, 08:12 AM
 */

#include <cstdlib>
#include <iostream>
#define maximo 5

using namespace std;


/*
 * 
 */
///////////////////////////*Merge sort Nivel de riesgo*/////////////////////////////////////
void merge(int*ID,int*impacto,int*riesgo,int ini,int med,int fin){
    int i,p,q;
    int long1,long2;
    
    long1=(med+1)-ini;
    long2=fin-med;
    
    int P[long1+1],P2[long1+1],P3[long1+1];
    int Q[long2+1],Q2[long1+1],Q3[long1+1];
    
    P3[long1+1]=99999;
    Q3[long2+1]=99999;
    
    for(int i=ini;i<med+1;i++){
        P[i-ini]=ID[i];
        P2[i-ini]=impacto[i];
        P3[i-ini]=riesgo[i];
    }
    for(int i=med+1;i<=fin;i++){
        Q[i-(med+1)]=ID[i];
        Q2[i-(med+1)]=impacto[i];
        Q3[i-(med+1)]=riesgo[i];
    }
    
    p=q=0;
    
    for(int i=ini;i<=fin;i++){
        if(P3[p]<Q3[q]){
            ID[i]=P[p];
            impacto[i]=P2[p];
            riesgo[i]=P3[p];
            p++;
        }
        else {
            ID[i]=Q[q];
            impacto[i]=Q2[q];
            riesgo[i]=Q3[q];
            q++;
        }
    }
}

void mergesortNR(int*ID,int*impacto,int*riesgo,int ini,int fin){
    
    if(ini==fin)return;
    
    int med=(ini+fin)/2;
    
    mergesortNR(ID,impacto,riesgo,ini,med);
    mergesortNR(ID,impacto,riesgo,med+1,fin);
    merge(ID,impacto,riesgo,ini,med,fin);
}

///////////////////////*Merge sort Nivel de impacto*////////////////////////////
void mergeNI(int*ID,int*impacto,int*riesgo,int ini,int med,int fin){
    int i,p,q;
    int long1,long2;
    
    long1=(med+1)-ini;
    long2=fin-med;
    
    int P[long1+1],P2[long1+1],P3[long1+1];
    int Q[long2+1],Q2[long1+1],Q3[long1+1];
    
    P2[long1+1]=99999;
    Q2[long2+1]=99999;
    
    for(int i=ini;i<med+1;i++){
        P[i-ini]=ID[i];
        P2[i-ini]=impacto[i];
        P3[i-ini]=riesgo[i];
    }
    for(int i=med+1;i<=fin;i++){
        Q[i-(med+1)]=ID[i];
        Q2[i-(med+1)]=impacto[i];
        Q3[i-(med+1)]=riesgo[i];
    }    
    
    p=q=0;    
    
    for(int i=ini;i<=fin;i++){
        if(P2[p]<Q2[q]){
            ID[i]=P[p];
            impacto[i]=P2[p];
            riesgo[i]=P3[p];
            p++;
        }
        else {
            ID[i]=Q[q];
            impacto[i]=Q2[q];
            riesgo[i]=Q3[q];
            q++;
        }
    }
}

void mergesortNI(int*ID,int*impacto,int*riesgo,int ini,int fin){
    
    if(ini==fin)return;
    
    int med=(ini+fin)/2;
    
    mergesortNI(ID,impacto,riesgo,ini,med);
    mergesortNI(ID,impacto,riesgo,med+1,fin);
    mergeNI(ID,impacto,riesgo,ini,med,fin);
}

///////////////////////////*Merge sort ID de riesgo*/////////////////////////
void mergeID(int*ID,int*impacto,int*riesgo,int ini,int med,int fin){
    int i,p,q;
    int long1,long2;
    
    long1=(med+1)-ini;
    long2=fin-med;
    
    int P[long1+1],P2[long1+1],P3[long1+1];
    int Q[long2+1],Q2[long1+1],Q3[long1+1];
    
    P[long1+1]=99999;
    Q[long2+1]=99999;
    
    for(int i=ini;i<med+1;i++){
        P[i-ini]=ID[i];
        P2[i-ini]=impacto[i];
        P3[i-ini]=riesgo[i];
    }
    for(int i=med+1;i<=fin;i++){
        Q[i-(med+1)]=ID[i];
        Q2[i-(med+1)]=impacto[i];
        Q3[i-(med+1)]=riesgo[i];
    }
    
    p=q=0;
    
    for(int i=ini;i<=fin;i++){
        if(P[p]<Q[q]){
            ID[i]=P[p];
            impacto[i]=P2[p];
            riesgo[i]=P3[p];
            p++;
        }
        else {
            ID[i]=Q[q];
            impacto[i]=Q2[q];
            riesgo[i]=Q3[q];
            q++;
        }
    }
}

void mergesortID(int*ID,int*impacto,int*riesgo,int ini,int fin){
    
    if(ini==fin)return;
    
    int med=(ini+fin)/2;
    
    mergesortID(ID,impacto,riesgo,ini,med);
    mergesortID(ID,impacto,riesgo,med+1,fin);
    mergeID(ID,impacto,riesgo,ini,med,fin);
}
////////////////////////////*Mostra los resultados*/////////////////////////////
void mostrar(int*ID,int*impacto,int*riesgo,int n){
    for(int i=0;i<7;i++){
        cout<<"["<<ID[i]<<"-"<<impacto[i]<<"-"<<riesgo[i]<<"]";    
    }
//    for(int i=0;i<7;i++){
//        cout<<"["<<ID[i]<<"]";    
//    }
}


int main(int argc, char** argv) {
    
    int n=7;
    
//    int arr[7][3]={{4,1,3},{1,2,4},{5,3,9},{7,2,2},{6,3,6},{3,2,6},{2,1,2}};
    int ID[n]={4,1,5,7,6,3,2};
    int impacto[n]={1,2,3,2,3,2,1};
    int riesgo[n]={3,4,9,2,6,6,2};
    
    cout<<"Lista de riesgos: (ID - Impacto - Nivel de riesgo)"<<endl;
    mostrar(ID,impacto,riesgo,n);
    cout<<endl;
//    ordenamos por ID
    mergesortNR(ID,impacto,riesgo,0,n-1);
    mostrar(ID,impacto,riesgo,n);
    cout<<"  "<<"por Nivel de Riesgo";
    cout<<endl;
    mergesortNI(ID,impacto,riesgo,0,n-1);
    mostrar(ID,impacto,riesgo,n);
    cout<<"  "<<"por Impacto ";
    cout<<endl;
    mergesortID(ID,impacto,riesgo,0,n-1);
    mostrar(ID,impacto,riesgo,n);
    cout<<"  "<<"por ID de Riesgo";
    
    cout<<endl; 

    return 0;
}

