/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gianfranco Moises Poma Canchari
 * Code: 20185721
 * Created on 26 de septiembre de 2023, 11:38 AM
 */

#include <iostream>
#define N 15

using namespace std;


//int merge(int *arr,int ini,int medio,int fin){
//    
//    int sumaIzq=0;
//    
//    int sumaIzqMayor=-999;
//    
//    int  sumaDerMayor=-999;
//    
//    //              0          1         3
//    //              i=1;    i>0     ;i--
//    
//    	/*Izquierda*/
//    
//        //  0  1   2  3  4
//    
//    
//    //  0    1   3
//    
//    //  0     1     
//    
//    cout<<ini<<" "<<medio<<" "<<fin<<endl;
//	for (int i=medio; i>ini; i--){
//            
//            for(int j=i-1;j>=ini;j--){
//                
//                 cout<<arr[j]<<" "<<arr[i]<<" Comp"<<endl;
//                
//                if(arr[i]<arr[j]){
//                    sumaIzq++;
//                 }
//                
//            }
//			
//           
//            
////            if(arr[ini]>arr[i]){
////                sumaIzq++;
////            }
//            
//	}
//    
//     //  0    1   3
//    
//    //2       
//    
//    	/*Derecha*/
//	int sumaDer = 0;
//	for (int i=medio+1; i<fin; i++){
//            
//            for(int j=i+1;j<=fin;j++){
//                
//                   cout<<arr[i]<<" "<<arr[j]<<" Comp2"<<endl;
//                
//                 if(arr[j]<arr[i]){
//                    sumaDer++;
//                 }
//                
//            }
//          
//            
////            if(arr[fin]<arr[i]){
////                sumaDer++;
////            }
//			
//	}
//        cout<<endl;
//        
//    //    cout<<sumaIzq<<" "<<sumaDer<<"*"<<endl;
//        
//       int sumaTotal=sumaIzq+sumaDer;
////        
//       
//        return sumaTotal;
//    
//}





int mezcla(int arr[],int ini,int medio,int fin){
	int i,cizq=0,cder=0;
	int entroDer=0;
        
        cout<<ini<<" "<<medio<<" "<<fin<<endl;
	
		//printf("---------------\n");
	for(i=medio;i>ini;i--){
		
		if(arr[i]<arr[i-1]){
			
			cizq++;
		
		}else{
				
				//cizq+=arr[medio];
				
				break;
		}
			
	}
	
	for(i=medio;i<fin;i++){
		
		if(arr[i+1]<arr[i]){
				cder++;
		}else{

			break;
		}
		
		 
	}

        int contador=0;
//	printf("---------------\n");
//	printf("(izq  %d der %d)",cizq,cder);
//	printf("suma izq y der : %d\n",cder+cizq);
        
        
        if(arr[ini]>arr[fin]){
            contador++;
        }
		
	return cder+cizq+contador;
	
}


int intervalomax(int arr[],int ini,int fin){
	int medio,izq,der,centro;
	if(ini==fin) return 0;
	
	
	medio = (ini+fin)/2;
	izq=intervalomax(arr,ini,medio);
	// printf("izq: %d %d\n",ini,medio);
	der=intervalomax(arr,medio+1,fin);
   	//printf("der: %d %d\n",medio+1,fin);
	centro=mezcla(arr,ini,medio,fin);
	//printf("mezcla:%d %d %d\n",ini,medio,fin);
	//printf("argumento masx :%d %d %d \n",izq,der,centro);
	return izq+der+centro;
	
	
}


int main(){
	

	int arr[]={-1,3,5,-2,1};
        
        //{-1 2 5 -2}
        
        int n=5;
	
	//printf("Numero de inversiones:%d\n",intervalomax(arr,0,n-1));
        
        cout<<intervalomax(arr,0,n-1);
	
	return 0;
}