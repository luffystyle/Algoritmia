/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gianfranco Moises Poma Canchari
 * Code: 20185721
 * Created on 26 de septiembre de 2023, 04:59 PM
 */

#include <iostream>
#define N 40

using namespace std;


//Ordenacion por mezcla

//void merge(int A[], int posicion_inicial, int posicion_medio, int posicion_final){
//	int i, p, q;
//	int longitud1, longitud2;//dimensiones de los subarreglos, izquierda y derecha respectivamente
//	
//	longitud1=(posicion_medio+1)-posicion_inicial;//dimensión subarreglo izquierdo
//	longitud2=posicion_final-posicion_medio;//dimensión subarreglo derecho
//	
//	//arreglos auxiliares para hacer el merge
//	int P[longitud1+1];//Un elemento más en el subarreglo que va a tener un valor muy grande
//	int Q[longitud2+1];//Un elemento más en el subarreglo que va a tener un valor muy grande
//	
//	P[longitud1]=999999;
//	Q[longitud2]=999999;
//	
//	//Copiamos en los dos subarreglos auxiliares
//	for (i=posicion_inicial;i<=posicion_medio;i++)
//		P[i-posicion_inicial]=A[i];
//	for (i=posicion_medio+1;i<=posicion_final;i++)
//		Q[i-(posicion_medio+1)]=A[i];
//	//Hasta aquí tenemos copiados nuestros subarreglos desde el arreglo original A[]
//	
//	p=q=0;//índices de los dos subarreglos
//	//Recorremos todo el arreglo A[], insertando los menores de cada subarreglo P[] y Q[]
//	for (i=posicion_inicial; i<=posicion_final;i++)
//		if (P[p]<Q[q])
//			//Si el menor a insertar es el menor de P[]
//			A[i]=P[p++];
//			//P[p++] se ejecuta de la siguiente manera
//			//Primero asigna P[p] y luego aumenta p++ 
//		else
//			//Si el menor a insertar es el menor de Q[]
//			A[i]=Q[q++];
//}

void merge(int *arr,int ini,int medio,int fin){
    
        int i, p, q;
	int longitud1, longitud2;//dimensiones de los subarreglos, izquierda y derecha respectivamente
	
	longitud1=(medio+1)-ini;//dimensión subarreglo izquierdo
	longitud2=fin-medio;//dimensión subarreglo derecho
        
        //arreglos auxiliares para hacer el merge
	int P[longitud1+1];//Un elemento más en el subarreglo que va a tener un valor muy grande
	int Q[longitud2+1];//Un elemento más en el subarreglo que va a tener un valor muy grande
        
        P[longitud1]=999999;
	Q[longitud2]=999999;
        
        
        //Copiamos en los dos subarreglos auxiliares
	for (i=ini;i<=medio;i++){
            
            P[i-ini]=arr[i];
            cout<<P[i-ini]<<" ";
        }
        cout<<" P "<<endl;
        
        for (i=medio+1;i<=fin;i++){
            
            Q[i-(medio+1)]=arr[i];
            cout<<Q[i-(medio+1)]<<" ";
        }
        cout<<" Q "<<endl;		
        
        
        
        
        
        
        
//	//Hasta aquí tenemos copiados nuestros subarreglos desde el arreglo original A[]
        
        
        p=q=0;//índices de los dos subarreglos
//      Recorremos todo el arreglo arr[], insertando los menores de cada subarreglo P[] y Q[]
        
        for (i=ini; i<=fin;i++)
		if (P[p]<Q[q])
			//Si el menor a insertar es el menor de P[]
			arr[i]=P[p++];
			//P[p++] se ejecuta de la siguiente manera
			//Primero asigna P[p] y luego aumenta p++ 
		else
			//Si el menor a insertar es el menor de Q[]
			arr[i]=Q[q++];
        
    
    
}


 void mergeSort(int *arr,int ini,int fin){
     
     //Caso base
     if(ini==fin){
         return;
     }
     
     int medio=(ini+fin)/2;
     
     mergeSort(arr,ini,medio);
     mergeSort(arr,medio+1,fin);
     merge(arr,ini,medio,fin);
     
     
 }

int main(int argc, char** argv) {
    
    
    int arr[N]={2,1,5,3,4,10};
    
    int n=6;
    
    mergeSort(arr,0,n-1);
    

    for (int i=0;i<n;i++)
		cout << arr[i]<< " ";
    cout<<endl;
    
    return 0;
}

