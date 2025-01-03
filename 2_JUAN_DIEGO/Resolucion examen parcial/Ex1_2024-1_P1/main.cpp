/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Lista.h"
#include "funciones.h"
#define M 4
using namespace std;


/*
 * IMPLEMENTACIÓN DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */

void mostrarListas(Lista *arr,int n){
    for(int i=0;i<n;i++){
        imprime(arr[i]);
    }
}
int existeSolu(Lista & lista,Lista & newList,int cant,int maxProd){
    int suma=0;
    int mayor=0;
    Nodo * nodo = lista.cabeza;
    for(int i=0;i<cant;i++){
        insertarAlFinal(newList,nodo->elemento);
        suma+=nodo->elemento;
        nodo=nodo->siguiente;
        if(i+1==cant-1){
            if((suma+nodo->elemento)>maxProd){
                return 0;
            }
            //comprobamos el producto con la mayor caloria posible
            while(nodo!=nullptr &&(suma+nodo->elemento)<=maxProd){                
                mayor=nodo->elemento;
                nodo=nodo->siguiente;  
            }            
            insertarAlFinal(newList,mayor);
            break;
        }        
    }    
}
void mezclaProd(Lista & L1,Lista & L2){
    if(L1.cola->elemento<L2.cabeza->elemento){
        L1.cola->siguiente=L2.cabeza;
        L1.cola=L2.cola;
    }else if(L2.cola->elemento<L1.cabeza->elemento){
        L2.cola->siguiente=L1.cabeza;
        L2.cola=L1.cola;
    }
    struct Nodo * ini,* fin;
    ini=NULL;
    fin=NULL;
    while(!esListaVacia(L1) && !esListaVacia(L2)){
        if(L1.cabeza->elemento<=L2.cabeza->elemento){
            if(ini==NULL){
                ini=L1.cabeza;
                fin=L1.cabeza;
            }else{
                fin->siguiente=L1.cabeza;
                fin=L1.cabeza;
            }
            L1.cabeza=L1.cabeza->siguiente;
        }else{
            if(L1.cabeza->elemento>L2.cabeza->elemento){
                if(ini==NULL){
                    ini=L2.cabeza;
                    fin=L2.cabeza;
                }else{
                    fin->siguiente=L2.cabeza;
                    fin=L2.cabeza;
                }
                L2.cabeza=L2.cabeza->siguiente;
            }
        }
    }
    if(!esListaVacia(L1)){
        fin->siguiente=L1.cabeza;
        fin=L1.cola;
    }else{
        fin->siguiente=L2.cabeza;
        fin=L2.cola;
    }
    L1.cabeza=ini;
    L1.cola=fin;
        
}
int main(int argc, char** argv) {
    
    struct Lista prodA,prodD,prodB,prodH;
    struct Lista arrList[M];  
    char productos[M]={'A','D','B','H'};
    int cantidad;
    int caloria;
    
    construir(prodA);
    construir(prodD);
    construir(prodB);
    construir(prodH); 
    
    arrList[0]=prodA;
    arrList[1]=prodD;
    arrList[2]=prodB;
    arrList[3]=prodH;
    
    for(int j=0;j<M;j++){        
        cout<<"Ingrese la cantdad de prouctos de tipo "<<productos[j]<<" ";
        cin>>cantidad;
        cout<<"Calorias de los productos "<<productos[j]<<":";
        for(int k=0;k<cantidad;k++){
            cin>>caloria;
            insertarAlFinal(arrList[j],caloria);
        }
    }
    cout<<endl;
    for(int i=0;i<M;i++){
        cout<<"Tipo de producto: "<<productos[i]<<endl;
        cout<<"Calorias de los productos "<<productos[i]<<":";
        imprime(arrList[i]);
    }
    cout<<endl;
    //////////////
    //Seleccion///
    //////////////
    cout<<"Formula: "<<endl;
    int cantTipos;
    char tipos;
    int seleccion[M]={0,0,0,0};
    cout<<"Ingrese la cantidad de tipos a seleccionar: ";
    cin>>cantTipos;
    cout<<"Ingrese los tipos: ";
    for(int i=0;i<cantTipos;i++){
        cin>>tipos;
        if(tipos=='A'){
            seleccion[0]=1;
        }
        if(tipos=='D'){
            seleccion[1]=1;
        }
        if(tipos=='B'){
            seleccion[2]=1;
        }
        if(tipos=='H'){
            seleccion[3]=1;
        }
    }
    ///////////////
    //Validacion///
    ///////////////
    int cant;
    int maxProd;
    int validar=1;
    Lista formula[M];
    Lista listA,ListD,ListB,listH;
    
    construir(listA);
    construir(ListD);
    construir(ListB);
    construir(listH); 
    
    formula[0]=listA;
    formula[1]=ListD;
    formula[2]=ListB;
    formula[3]=listH;
    
    for(int j=0;j<M;j++){
        if(seleccion[j]==1){
            cout<<"Tipo de producto: "<<productos[j]<<endl;
            cout<<"Cantidad de productos del Tipo "<<productos[j]<<": ";
            cin>>cant;
            cout<<"Total de calorias maxima de todos los productos "<<productos[j]<<": ";
            cin>>maxProd;
            validar=existeSolu(arrList[j],formula[j],cant,maxProd);
            if(validar){
                continue;
            }else{
                cout<<"No es posible trabajar con el producto: "<<productos[j]<<endl;
            }
        }
    }
    for(int k=0;k<M;k++){
        if(seleccion[k]==1){
            cout<<"Calorias de los Productos "<<productos[k]<<": ";
            imprime(formula[k]);
        }
    }
    int numMezcla=0;
    int principal;
    for(int i=0;i<M;i++){
        if(seleccion[i]==1){
            if(numMezcla==0){
               principal=i; 
            }
            mezclaProd(formula[principal],formula[i]);
            numMezcla++;
        }
    }
    cout<<"Lista final de productos a trabajar: ";
    imprime(formula[principal]);

    return 0;
}

//    
//    insertarAlFinal(prodA,120);
//    insertarAlFinal(prodA,145);
//    insertarAlFinal(prodA,230);
//    insertarAlFinal(prodA,247);
//    insertarAlFinal(prodA,285);
//    
//    insertarAlFinal(prodD,182);
//    insertarAlFinal(prodD,240);
//    insertarAlFinal(prodD,300);
//    
//    insertarAlFinal(prodB,58);
//    insertarAlFinal(prodB,120);
//    insertarAlFinal(prodB,247);
//    insertarAlFinal(prodB,278);
//    
//    insertarAlFinal(prodH,128);
//    insertarAlFinal(prodH,236);
//    insertarAlFinal(prodH,354);
//    insertarAlFinal(prodH,540);
//    insertarAlFinal(prodH,782);
//    
//    arrList[0]=prodA;
//    arrList[1]=prodD;
//    arrList[2]=prodB;
//    arrList[3]=prodH;
//    
////    mostrarListas(arrList,4); 