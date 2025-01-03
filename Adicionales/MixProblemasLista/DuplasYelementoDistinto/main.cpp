/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gianfranco Moises Poma Canchari
 * Code: 20185721
 * Created on 22 de septiembre de 2023, 11:34 AM
 */

#include <iostream>
#define N 15

using namespace std;

//ini=0                 0        2         4
//med=2                          5              Encontrado  (si tanto izquierda y derecha son diferentes)               5                
//fin=4                 
//11566


//metodo profe
//                      0      2       4
//                             5             
//                      0      1       2
//                      2      2       2   sin pareja


//ini=0                 0       2       4
//med=2                         ->              Si a su derecha es igual se va a buscar derecha
//fin=4
//11665

                     



//                     3       3        4      Si el medio es impar entonces si a su izquierda
        //                                      es igual busca a la derecha
//                     4       4         4



//ini=0                 0       2       4
//med=2                         <-              Si a su derecha es diferente se va a buscar izquierda   
//fin=4
//51166
//                      0       0       1
//********************************************

//ini=0
//med=3
//fin=6
//1157766               0       3        6
//                      4       5        6
//ini=0
//med=3
//fin=6
//1177665               6       6        6

//ini=0
//med=3
//fin=6
//5117766

void funcionEncuentraDistinto(int *arr,int nNumeros,int ini,int fin){
    
    //Caso base
    if(ini>fin){
        cout<<"Encontrado "<<arr[ini];
        return;
    }
    
    int medio=(ini+fin)/2;
    
    if(medio%2==0){
        
        if(arr[medio]==arr[medio+1]){
            return funcionEncuentraDistinto(arr,nNumeros,medio+1,fin);
        }else{
             return funcionEncuentraDistinto(arr,nNumeros,ini,medio-1);
        }
        
        
    }else{
        
        if(arr[medio]==arr[medio-1]){
            return funcionEncuentraDistinto(arr,nNumeros,medio+1,fin);
        }else{
             return funcionEncuentraDistinto(arr,nNumeros,ini,medio-1);
        }
        
        
        
    }
    
    
    
    
}

//Alternativo profesor


//void busca(int ini,int fin,int arr[]){
//	
//	if(ini==fin){
//		cout << "El sin pareja:"<<arr[ini];
//		return;
//	}
//	int med=(ini+fin)/2;
//	
//	if(med%2==0){
//		if(arr[med]==arr[med+1])
//			busca(med+2,fin,arr);
//		else		
//			busca(ini,med,arr);
//	}
//	else{
//		if(arr[med]==arr[med-1])
//			busca(med+1,fin,arr);
//		else		
//			busca(ini,med-1,arr);		
//	}
//}






int main(int argc, char** argv) {
    
    int arr[N]={1,1,9,9,10,10,15,3,3,4,4};
    
    int n=11;
    
    //funcion
    funcionEncuentraDistinto(arr,n,0,n-1);
    

    return 0;
}


//Entrada: {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}
