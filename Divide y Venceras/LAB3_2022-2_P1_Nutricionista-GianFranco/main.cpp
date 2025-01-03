/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gianfranco Moises Poma Canchari
 * Code: 20185721
 * Created on 28 de septiembre de 2023, 10:15 AM
 */

#include <iostream>
#define N 40


using namespace std;


int mayorCantGlobal=0;
int posIzqGuardadaGlobal=-1;
int posDerGuardadaGlobal=-1;


//void merge(int *arr,int ini,int medio,int fin){
//    
//        int i, p, q;
//	int longitud1, longitud2;//dimensiones de los subarreglos, izquierda y derecha respectivamente
//	
//	longitud1=(medio+1)-ini;//dimensión subarreglo izquierdo
//	longitud2=fin-medio;//dimensión subarreglo derecho
//        
//        //arreglos auxiliares para hacer el merge
//	int P[longitud1+1];//Un elemento más en el subarreglo que va a tener un valor muy grande
//	int Q[longitud2+1];//Un elemento más en el subarreglo que va a tener un valor muy grande
//        
//        P[longitud1]=999999;
//	Q[longitud2]=999999;
//        
//        
//        //Copiamos en los dos subarreglos auxiliares
//	for (i=ini;i<=medio;i++){
//            
//            P[i-ini]=arr[i];
//            cout<<P[i-ini]<<" ";
//        }
//        cout<<" P "<<endl;
//        
//        for (i=medio+1;i<=fin;i++){
//            
//            Q[i-(medio+1)]=arr[i];
//            cout<<Q[i-(medio+1)]<<" ";
//        }
//        cout<<" Q "<<endl;		
//        
//        
//        
//        
//        
//        
//        
////	//Hasta aquí tenemos copiados nuestros subarreglos desde el arreglo original A[]
//        
//        
//        p=q=0;//índices de los dos subarreglos
////      Recorremos todo el arreglo arr[], insertando los menores de cada subarreglo P[] y Q[]
//        
//        for (i=ini; i<=fin;i++)
//		if (P[p]<Q[q])
//			//Si el menor a insertar es el menor de P[]
//			arr[i]=P[p++];
//			//P[p++] se ejecuta de la siguiente manera
//			//Primero asigna P[p] y luego aumenta p++ 
//		else
//			//Si el menor a insertar es el menor de Q[]
//			arr[i]=Q[q++];
//        
//    
//    
//}




void merge(int *arrPesos,int ini,int medio,int fin){
    
    int long1=medio-ini+1;
    int long2=fin-medio;
    //Primero inicializo arr aux
    int P[long1+1];
    int Q[long2+1];
    
    P[long1]=999999;
    Q[long2]=999999;
//copio los indices del original a la copia
//Copiamos en los dos subarreglos auxiliares
//	for (i=ini;i<=medio;i++){
//            
//            P[i-ini]=arr[i];
//            cout<<P[i-ini]<<" ";
//        }
//        cout<<" P "<<endl;
//        
//        for (i=medio+1;i<=fin;i++){
//            
//            Q[i-(medio+1)]=arr[i];
//            cout<<Q[i-(medio+1)]<<" ";
//        }
    for(int i=ini;i<=medio;i++) P[i-ini]=arrPesos[i];
    for(int j=medio+1;j<=fin;j++) Q[j-(medio+1)]=arrPesos[j];
    
    //inicializo indices
    int p=0;
    int q=0;
// for (i=ini; i<=fin;i++)
//		if (P[p]<Q[q])
//			//Si el menor a insertar es el menor de P[]
//			arr[i]=P[p++];
//			//P[p++] se ejecuta de la siguiente manera
//			//Primero asigna P[p] y luego aumenta p++ 
//		else
//			//Si el menor a insertar es el menor de Q[]
//			arr[i]=Q[q++];
    
    for(int i=ini;i<=fin;i++){
        
        if(P[p]<Q[q]){
            arrPesos[i]=P[p];
            p++; 
        }else{
            arrPesos[i]=Q[q];
            q++; 
        }  
    } 
}


void menorPeso(int *arrPesos,int ini,int fin){
    //Caso base
    if(ini==fin) return;
    
    int medio=(ini+fin)/2;
    menorPeso(arrPesos,ini,medio);
    menorPeso(arrPesos,medio+1,fin);
    merge(arrPesos,ini,medio,fin); 
}

int mergeDiasMenorPeso(int *arrPesos,int ini,int medio,int fin,int pesoBuscado){
    
    int posIzqGuardada=0;
    
    int contSumaIzq=0;
    for(int i=medio;i>=ini;i--) {
        if(arrPesos[i]==pesoBuscado) contSumaIzq++;
        else {
            posIzqGuardada=i+1;
            break;
        } 
    }
    
    int contSumaDer=0;
    int posDerGuardada=0;
    
    for(int i=medio+1;i<=fin;i++) {
        if(arrPesos[i]==pesoBuscado) contSumaDer++;
        else {
            posDerGuardada=i-1;
            break;
        }
    }
    
    if(arrPesos[medio] == pesoBuscado && arrPesos[medio+1] == pesoBuscado){
        if(mayorCantGlobal<(contSumaIzq+contSumaDer)){
            mayorCantGlobal=contSumaIzq+contSumaDer;
            posIzqGuardadaGlobal=posIzqGuardada;
            posDerGuardadaGlobal=posDerGuardada;
        }
        return contSumaIzq+contSumaDer;
    }else return 1;
}

int cantDiasMenorPeso(int *arrPesos,int ini,int fin,int pesoBuscado){
      
    int izq, der, centro;
      
    //Caso base
    if(ini==fin) return 1;
    int medio=(ini+fin)/2;
    
    izq=cantDiasMenorPeso(arrPesos,ini,medio,pesoBuscado);
    der=cantDiasMenorPeso(arrPesos,medio+1,fin,pesoBuscado);
    centro=mergeDiasMenorPeso(arrPesos,ini,medio,fin,pesoBuscado);
      
    if(izq>der&&izq>centro) return izq;
    else if(der>izq&&der>centro) return der;
    else return centro;
}

int main(int argc, char** argv) {
    
    
    int arrPesos[N]={98,95,92,89,91,92,89,89,92,93,94,92,91,
                        90,88,88,88,89,90,91,88,88,90,90,92,
                            89,90,88,90,91};
    
    int arrPesosAux[N]={98,95,92,89,91,92,89,89,92,93,94,92,91,
                        90,88,88,88,89,90,91,88,88,90,90,92,
                            89,90,88,90,91};
    
    int n=30;
    
//    b) Implemente una función, utilizando la técnica de divide y vencerás, para determinar el menor peso
//que logró el paciente en sus evaluaciones, la complejidad máxima para esta parte debe ser O
//(n*log(n)). (3 puntos). 
    
    cout<<"Datos iniciales: "<<endl;
     for(int j=0;j<n;j++){
         cout<<arrPesos[j]<<" ";
    }
    cout<<endl;
    
    //menor peso que logro el paciente
    
    menorPeso(arrPesosAux,0,n-1);
    
    cout<<"El menor peso: "<<arrPesosAux[0]<<endl;
    
    //impresion del arreglo
    
    
    cout<<"Luego de hacer el mergesort (Uso de un arreglo copia para el mergesort)"<<endl;
     for(int j=0;j<n;j++){
         cout<<arrPesosAux[j]<<" ";
    }
    cout<<endl;
    
    
//    c) Implemente una función, utilizando la técnica de divide y vencerás, que determine la cantidad de días
//    consecutivos que logró su menor peso y el rango de días en que lo logró. Debe usar el valor del menor
//    peso de la pregunta b) pero con el arreglo recibido originalmente no lo puede modificar. La
//    complejidad máxima para esta parte debe ser O (n*log(n)) (6 puntos)
    
    
    cout<<"Para este siguiente paso uso el arreglo original."<<endl;
     cout<<"Cantidad dias menor peso: "<<cantDiasMenorPeso(arrPesos,0,n-1,arrPesosAux[0])<<endl;
     
     cout<<"Rango:"<<endl;
     cout<<posIzqGuardadaGlobal<<" "<<posDerGuardadaGlobal<<endl;

    return 0;
}

