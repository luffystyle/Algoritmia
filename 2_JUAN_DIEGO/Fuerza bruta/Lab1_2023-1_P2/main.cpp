/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 26 de marzo de 2024, 07:31 PM
 */

#include <cstdlib>
#include <iostream>
#define n 20
#define m 20

using namespace std;

/*
 * 
 */
void llenarAcido(char*acido){
    for(int i=0;i<3;i++){
        acido[i]=0;
    }
}
void derecha(char*acido,char matriz[][m],int i , int j){
   //derecha
    
        if(matriz[i][j+1]=='S' || matriz[i][j+1]=='O' || matriz[i][j+1]=='H'){
            acido[1]=matriz[i][j+1];
            if((matriz[i][j+2]=='O' || matriz[i][j+2]=='S' || matriz[i][j+2]=='H') && j+2<m){
                acido[2]=matriz[i][j+2]; 
            } 
        } 
       
}
void abajo(char*acido,char matriz[][m],int i , int j){
   //abajo
    
       if(matriz[i+1][j]=='S' || matriz[i+1][j]=='O' || matriz[i+1][j]=='H'){
            acido[1]=matriz[i+1][j];
            if((matriz[i+2][j]=='O' || matriz[i+2][j]=='S' || matriz[i+2][j]=='H') && i+2<n){
                acido[2]=matriz[i+2][j]; 
            } 
        }  
         
}
void izquierda(char*acido,char matriz[][m],int i , int j){
   //izquierda
    
        if(matriz[i][j-1]=='S' || matriz[i][j-1]=='O'|| matriz[i][j-1]=='H'){
            acido[1]=matriz[i][j-1];
            if((matriz[i][j-2]=='O' || matriz[i][j-2]=='S' || matriz[i][j-2]=='H') && j-2>=0){
                acido[2]=matriz[i][j-2]; 
            } 
        } 
        
}
void arriba(char*acido,char matriz[][m],int i , int j){
   //arriba
    
        if(matriz[i-1][j]=='S' || matriz[i-1][j]=='O' || matriz[i-1][j]=='H' ){
            acido[1]=matriz[i-1][j];
            if((matriz[i-2][j]=='O' || matriz[i-2][j]=='S' || matriz[i-2][j]=='H') && i-2>=0){
                acido[2]=matriz[i-2][j]; 
            } 
        }
          
}

bool verificacion(char*acido){
    if(acido[0]!=0 && acido[1]!=0 && acido[2]!=0){
        if(acido[0]!=acido[1] && acido[0]!=acido[2] && acido[1]!=acido[2]){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }    
}
int main(int argc, char** argv) {
    char matriz[n][m]{{'H','C','H','B','Y','S','O','S','O','H'},
                      {'S','C','S','S','Y','Q','O','S','Z','K'},
                      {'O','P','N','Y','O','K','F','H','C','K'},
                      {'O','B','N','I','Y','S','P','O','O','K'}};
    char acido[3]={};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            llenarAcido(acido);
            if(matriz[i][j]=='H' || matriz[i][j]=='S' || matriz[i][j]=='O' ){
                acido[0]=matriz[i][j];
                derecha(acido,matriz,i,j);
                bool verificar=verificacion(acido);
                if (verificar){
                    cout<<i<<","<<j<<" ";
                }
                abajo(acido,matriz,i,j);
                verificar=verificacion(acido);
                if (verificar){
                    cout<<i<<","<<j<<" ";
                }
                izquierda(acido,matriz,i,j);
                verificar=verificacion(acido);
                if (verificar){
                    cout<<i<<","<<j<<" ";
                }
                arriba(acido,matriz,i,j);
                verificar=verificacion(acido);
                if (verificar){
                    cout<<i<<","<<j<<" ";
                }
            }
        }
    }    
    return 0;
}

