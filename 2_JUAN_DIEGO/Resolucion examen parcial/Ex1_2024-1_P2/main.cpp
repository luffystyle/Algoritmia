/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Pila.h"

using namespace std;
#include "funcionesPila.h"

#define m 10

/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */

///////////////////////////////////////////////////////////
//////////////////*complejidad O(n)*////////////////////////
///////////////////////////////////////////////////////////

void submarinoOn(char*orden,int n,int mov){
    //Construimos una pila auxiliar
    struct Pila pila;
    construir(pila);
    int i=0;
    int flag=0;
    int temp=0;
    int pos=mov+1;//debido a que los movimientos que tendra que hacer son 5, estara en 5 posiciones
    //Se verifica si el primer movimiento es de bajada o subida    
    while(i<pos){
        if((i==0 and orden[i]=='S')or i==pos-1){//            
            cout<<i+1<<" ";
            i++;
            continue;
        }
        if(orden[i]=='S' and flag==0){
            cout<<i+1<<" ";
            i++;
        }else{
            if(esPilaVacia(pila)){
                apilar(pila,i+1);
                temp=0;
                i++;
                flag=1;
                continue;
            }else if(temp==0){
                apilar(pila,i+1);
            }            
            if(orden[i]=='S'){                
                temp=1;
                cout<<desapilar(pila)<<" ";
                if(esPilaVacia(pila)){
                    flag=0;
                    i++;
                }
            }else{
                i++;
            }            
        }
    }          
}
///////////////////////////////////////////////////////////
//////////////////*complejidad O(n^2)*////////////////////////
///////////////////////////////////////////////////////////

void submarinoOn2(char*orden,int n,int mov){
    //Construimos una pila auxiliar
    struct Pila pila;
    construir(pila);
    int i=0;
    int flag=0;
    int temp=0;
    int pos=mov+1;
    
    while(n<=pos){            
        apilar(pila,n);
        if(n==pos){
            while(!esPilaVacia(pila)){
                cout<<desapilar(pila)<<" ";
            }                
        }
        if(orden[i]=='S' and pila.lista.longitud==1){
            cout<<desapilar(pila)<<" ";
        }else if(orden[i]=='S' and pila.lista.longitud>1){
            while(!esPilaVacia(pila)){
                cout<<desapilar(pila)<<" ";
            }
        }            
        i++;
        n++;
    } 
}
///////////////////////////////////////////////////////////
//////////////////*Recursivo complejidad O(n)*////////////////////////
///////////////////////////////////////////////////////////
int rec=0;
void submarinoRec(char*orden,int mov,int index,int baja){
    if(index>mov)return;
    if(orden[index]=='S' || index==mov){
        cout<<index+1<<" ";
        rec=index;
        if(baja<1){
           submarinoRec(orden,mov,index+1,baja);  
        }else{
            return;
        }              
    }else{        
        submarinoRec(orden,mov,index+1,baja+1); 
        cout<<index+1<<" ";
        if(baja<1){
           submarinoRec(orden,mov,rec+1,baja);  
        }
    }       
}

//void submarinoRec(char*orden,int mov,int index,int &visitado){
//    if(index>mov)return;
//    if(orden[index]=='S' || index==mov){
//        if(index!=visitado){
//           cout<<index+1<<" "; 
//           visitado=index;
//        }
//        submarinoRec(orden,mov,index+1,visitado);              
//    }else{        
//        int nextIndex=index+1;
//        while(nextIndex<=mov && orden[nextIndex]!='S'){
//            nextIndex++;
//        }
//        submarinoRec(orden,mov,index,visitado); 
//        if(index!=visitado){
//            cout<<index+1<<" ";
//            visitado=index;
//        }
//    }       
//}

int main(int argc, char** argv) {    
    int n=1;
    
    int mov=5;
//    int mov=3;
//    int mov=7;    
    char orden[n]={'S','S','S','B','S'};
//    char orden[n]={'B','B','S'};
//    char orden[n]={'S','B','S','B','B','S','S'};   
//    submarinoOn(orden,n,mov);
//    cout<<endl;    
//    submarinoOn2(orden,n,mov);
//    cout<<endl;
    
    
    submarinoRec(orden,mov,0,0);
    return 0;
}


///////////////////////////////////////////////////////////
//////////////////*complejidad O(n^2)*////////////////////////
///////////////////////////////////////////////////////////

//while(n<=pos){            
//        apilar(pila,n);
//        if(n==pos){
//            while(!esPilaVacia(pila)){
//                cout<<desapilar(pila)<<" ";
//            }                
//        }
//        if(orden[i]=='S' and pila.lista.longitud==1){
//            cout<<desapilar(pila)<<" ";
//        }else if(orden[i]=='S' and pila.lista.longitud>1){
//            while(!esPilaVacia(pila)){
//                cout<<desapilar(pila)<<" ";
//            }
//        }            
//        i++;
//        n++;
//    } 
