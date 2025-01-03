/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gianfranco Moises Poma Canchari
 * Code: 20185721
 * Created on 25 de septiembre de 2023, 10:21 AM
 */

#include <iostream>
#define N 15

using namespace std;


//4. Se tiene un arreglo que puede contener números positivos y 
//negativos. Encontrar la suma de números contiguos que tengan la 
//suma máxima.
//
//Ejemplo:
//Entrada: {-2, -5, 6, -2, -3, 1, 5, -6}


// si {-2, -5, 6, -2}

//      0     1     3
// izq  0     0     1                  der    2     2     3
// izq  000    der  1   1   1         izq1    2   2   2          der1   3     3     3


//int cuenta(int arreglo[N], int inicio, int medio, int fin){
//	int cuentaIzq = 1;
//	/*Izquierda*/
//	for (int i=medio; i>inicio; i--){
//		if (arreglo[i-1]<arreglo[i]){
//			cuentaIzq++;
//		}
//		else
//			break;
//	}
//	
//	/*Derecha*/
//	int cuentaDerecha = 1;
//	for (int i=medio+1; i<fin; i++){
//		if (arreglo[i]<arreglo[i+1]){
//			cuentaDerecha++;
//		}
//		else
//			break;
//	}
//	
//	if (arreglo[medio]<arreglo[medio+1]){
//		return cuentaIzq + cuentaDerecha;
//	}
//	
//	return 1;
//}


int merge(int *arr,int ini,int medio,int fin){
    
    int sumaIzq=0;
    
    int sumaIzqMayor=-999;
    
    
    int  sumaDerMayor=-999;
    
    
    //              0          1         3
    //              i=1;    i>0     ;i--
    
    	/*Izquierda*/
	for (int i=medio; i>=ini; i--){		
			sumaIzq+=arr[i];
                        if(sumaIzq>sumaIzqMayor){
                            sumaIzqMayor=sumaIzq;
                            cout<<sumaIzqMayor<<" parcial ";
                        }
		
	}
    
    	/*Derecha*/
	int sumaDer = 0;
	for (int i=medio+1; i<=fin; i++){
			sumaDer+=arr[i];
                        if(sumaDer>sumaDerMayor){
                            sumaDerMayor=sumaDer;
                            cout<<sumaIzqMayor<<" parcial ";
                        }
	}
        cout<<endl;
        
        cout<<sumaIzqMayor<<" "<<sumaDerMayor<<"*"<<endl;
        
       int sumaTotal=sumaIzqMayor+sumaDerMayor;
//        
        if(sumaIzqMayor>=sumaDerMayor&&sumaIzqMayor>=sumaTotal){
            return sumaIzqMayor;
        }else if(sumaDerMayor>=sumaIzqMayor&&sumaDerMayor>=sumaTotal){
            
            
            return sumaDerMayor;
        }else{
            return sumaTotal;
        }
        
       // cout<<sumaTotal<<endl;
        //return sumaTotal;
    
}


 int  funcionContiguos(int *arr,int ini,int fin){
     
     int izquierda=-99999,derecha=-99999;
     int centro=-999;
     
     //Caso base
     if(ini==fin){
         return arr[ini];
     }
     
     int medio=(ini+fin)/2;
     
     izquierda=funcionContiguos(arr,ini,medio);
     derecha=funcionContiguos(arr,medio+1,fin);
     centro=merge(arr,ini,medio,fin);
     
     
     cout<<izquierda<<" "<<derecha<<" "<<centro<<" --------------"<<endl;
     
     
     if(izquierda>=derecha&&izquierda>=centro){
         return izquierda;
     }else if(derecha>=izquierda&&derecha>=centro){
         return derecha;
     }else{
         return centro;
     }
     
      
 }

int main(int argc, char** argv) {
    
    int arr[N]={-2, -5, 6, -2, -3, 1, 5, -6};
    
   //int arr[N]={-1,2,5,-2,9,-1,10};
    
    //int arr[N]={10,-2,15,-5,-1,-3};
    
    //      0   1   3
    //  izq 0   0   1                           der 2   2   3 
    //  izq 0   0   0   der 1   0    1          izq 2   2   2      der 3   3      3
    
    
    int n=8;
    
    cout<<funcionContiguos(arr,0,n-1);
    
    
    

    return 0;
}

//Salida: 7 (Los elementos que suman el máximo son 6, -2, -3, 1, 5)
