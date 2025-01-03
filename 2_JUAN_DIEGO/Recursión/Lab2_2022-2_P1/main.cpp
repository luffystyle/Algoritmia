/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 12 de abril de 2024, 07:33 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */
int matrizI[][5]={{0,0,0,0,0},
		  {0,0,0,0,0},
		  {0,0,0,1,0},
		  {0,1,0,0,0},
		  {0,0,0,0,0}};

int matrizP[][6]={{0,0,0,0,0,0},
                  {0,0,0,0,0,0},
		  {0,0,0,1,0,0},
		  {0,1,0,0,0,0},
		  {0,0,0,0,1,0},
		  {0,0,0,0,0,0}};

int pos;
int n=0;
int P=16;

void anaquel(int F,int C,int impar,int par){   
        
    if(C%2!=0){
        if(n==(C/2)+1){
            return;
        }        
        pos=F-impar;
        for(int j=pos;j<F;j++){
            if(matrizI[j][n]==0 && P>0){
                matrizI[j][n]=5;
                P--;                
            }
        }
        n++;
        anaquel(F,C,impar+1,par);
        pos=F-(impar-1);
        for(int j=pos;j<F;j++){
            if(matrizI[j][n]==0 && P>0){
                matrizI[j][n]=5; 
                P--;
            }
        }
        n++;       
    }
    else{
        if(n==(C/2)){
            return;
        }        
        pos=F-par;
        for(int j=pos;j<F;j++){
            if(matrizP[j][n]==0 && P>0){
                matrizP[j][n]=5;
                P--;                
            }
        }
        n++;
        anaquel(F,C,impar,par+1);
        pos=F-(par);
        for(int j=pos;j<F;j++){
            if(matrizP[j][n]==0 && P>0){
                matrizP[j][n]=5; 
                P--;
            }
        }
        n++;         
    }    
}
int main(int argc, char** argv) {
    
    int F=5;
    int C=5;
    int impar=3;
    int par=4;
    
    anaquel(F,C,impar,par);
    for(int i=0;i<F;i++){
        for(int j=0;j<C;j++){
            cout<<matrizI[i][j]<<" ";
        }
        cout<<endl;
    }    
    return 0;
}

