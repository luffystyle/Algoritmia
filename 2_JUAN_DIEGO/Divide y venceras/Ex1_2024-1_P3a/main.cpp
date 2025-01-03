/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 27 de junio de 2024, 08:25 PM
 */

#include <cstdlib>
#include <iostream>
#define N 7
using namespace std;

/*
 * 
 */
void merge(int*arr,int*arr2,int*arr3,int ini,int med,int fin,int index){
    int i,p,q;
    int long1,long2;
    
    long1=(med+1)-ini;
    long2=fin-med;
    
    int P[long1+1],P2[long1+1],P3[long1+1];
    int Q[long2+1],Q2[long2+1],Q3[long2+1];
    
    if(index==1){  
        
        P[long1+1]=9999;
        Q[long2+1]=9999;

        for(int i=ini;i<med+1;i++){
            P[i-ini]=arr[i];
            P2[i-ini]=arr2[i];
            P3[i-ini]=arr3[i];
        }
        for(int i=med;i<=fin;i++){
            Q[i-(med+1)]=arr[i];
            Q2[i-(med+1)]=arr2[i];
            Q3[i-(med+1)]=arr3[i];
        }
        p=q=0;
        for(int i=ini;i<=fin;i++){
            if(P[p]<Q[q]){
                arr[i]=P[p];
                arr2[i]=P2[p];
                arr3[i]=P3[p];
                p++;
            }else{
                arr[i]=Q[q];
                arr2[i]=Q2[q];
                arr3[i]=Q3[q];
                q++;
            }
        }
    }
    if(index==2){
        P2[long1+1]=9999;
        Q2[long2+1]=9999;

        for(int i=ini;i<med+1;i++){
            P[i-ini]=arr[i]; 
            P2[i-ini]=arr2[i];              
            P3[i-ini]=arr3[i];
        }
        for(int i=med+1;i<=fin;i++){
            Q[i-(med+1)]=arr[i];
            Q2[i-(med+1)]=arr2[i];
            Q3[i-(med+1)]=arr3[i];            
        }
        p=q=0;
        for(int i=ini;i<=fin;i++){
            if(P2[p]<Q2[q]){                
                arr[i]=P[p];
                arr2[i]=P2[p];
                arr3[i]=P3[p];                
                p++;
            }else{
                arr[i]=Q[q];
                arr2[i]=Q2[q];
                arr3[i]=Q3[q];
                q++;
            }
        }
    }
    if(index==3){
        P3[long1+1]=9999;
        Q3[long2+1]=9999;

        for(int i=ini;i<med+1;i++){
            P3[i-ini]=arr3[i];
            P[i-ini]=arr[i];
            P2[i-ini]=arr2[i];
        }
        for(int i=med;i<=fin;i++){
            Q3[i-(med+1)]=arr3[i];
            Q[i-(med+1)]=arr[i]; 
            Q2[i-(med+1)]=arr2[i];          
        }
        p=q=0;
        for(int i=ini;i<=fin;i++){
            if(P3[p]<Q3[q]){
                arr[i]=P[p]; 
                arr2[i]=P2[p];  
                arr3[i]=P3[p];            
                p++;
            }else{
                arr[i]=Q[q]; 
                arr2[i]=Q2[q];   
                arr3[i]=Q3[q];
                q++;
            }
        }
    }
}
void mergesort(int*arr,int*arr2,int*arr3,int ini,int fin,int index){
    if(ini==fin)return;
    
    int med=(ini+fin)/2;
    
    mergesort(arr,arr2,arr3,ini,med,index);
    mergesort(arr,arr2,arr3,med+1,fin,index);
    merge(arr,arr2,arr3,ini,med,fin,index);    
}

int main(int argc, char** argv) {
    
    int n=7;
    int index=3;    
    
    for(int j=1;j<=index;j++){
        int ID[N]={4,1,5,7,6,3,2};
        int impacto[N]={1,2,3,2,3,2,1};
        int riesgo[N]={3,4,9,2,6,6,2};
        mergesort(riesgo,impacto,ID,0,n-1,j);
        for(int i=0;i<n;i++){
            cout<<ID[i]<<"-"<<impacto[i]<<"-"<<riesgo[i]<<"  ";
//            cout<<ID[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

