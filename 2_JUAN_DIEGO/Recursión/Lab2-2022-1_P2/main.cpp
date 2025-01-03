/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 8 de abril de 2024, 09:40 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#define max 10

using namespace std;
int presupuesto=200000;
int robtSelecc=0;
int menor=9999;
int mayor=0;
int costoReal=0;
int ahorro=0;
/*
 * 
 */
void obtenerMenor(int precios[][max],int numRobotos,int pos,int m){
    if(m==numRobotos)return;
    if(precios[pos][m]<menor){
        menor=precios[pos][m];
        robtSelecc=m;
    }
    obtenerMenor(precios,numRobotos,pos,m+1);
}

void obtenerMayor(int precios[][max],int numRobotos,int pos,int m){
    if(m==numRobotos)return;
    if(precios[pos][m]>mayor){
        mayor=precios[pos][m];
        robtSelecc=m;
    }
    obtenerMayor(precios,numRobotos,pos,m+1);
}

void obtenerRobots(int numRobotos,int precios[][max],int*eleccion,int*cantidad,int*robDitrib,char*robots,int pos,int n){
    if(cantidad[pos]==n){
        cout<<" "<<costoReal<<" ";
        return ;
    }    
    if(eleccion[pos]==1){
       obtenerMenor(precios,numRobotos,pos,0);
       robDitrib[n]=robtSelecc;
       cout<<robots[robtSelecc];
       //cout<<menor<<" ";
       costoReal+=menor;
       precios[pos][robtSelecc]=9999;
       menor=9999;       
    }else{
        obtenerMayor(precios,numRobotos,pos,0);
        robDitrib[n]=robtSelecc;
        cout<<robots[robtSelecc];
        //cout<<menor<<" ";
        costoReal+=mayor;
        precios[pos][robtSelecc]=0;
        mayor=0;
    }
    obtenerRobots(numRobotos,precios,eleccion,cantidad,robDitrib,robots,pos,n+1);
}
void distribucion(int numRegiones,int numRobotos,char regiones[][max],char*robots,int*porcentaje,int precios[][max],int*eleccion,int*cantidad,int pos){
    if(pos==numRegiones){
        return;
    }
    int robDitrib[max];
    
    cout<<pos+1<<"."<<regiones[pos]<<" ";
    
    cout<<(presupuesto*porcentaje[pos])/100<<" ";
    costoReal=0;
    obtenerRobots(numRobotos,precios,eleccion,cantidad,robDitrib,robots,pos,0);
    ahorro=ahorro+((presupuesto*porcentaje[pos])/100)-costoReal;
    cout<<ahorro<<" ";
    cout<<endl;
    distribucion(numRegiones,numRobotos,regiones,robots,porcentaje,precios,eleccion,cantidad,pos+1);
}

int main(int argc, char** argv) {
    
    
    int numRegiones=7;
    int numRobotos=7;
    /*========================================================================*/
    
    char regiones[max][max]={"Lima","Ica","Arequipa","Moquegua","Tacna","Puno","Cusco"};
    //cout<<regiones[1]<<endl;
    char robots[max]={'A','B','C','D','E','F','G'};
    int porcentaje[max]={30,8,20,8,12,5,17};
    int precios[max][max]={{9100,9500,9400,9800,9000,8900,9200},
                           {8400,8000,8100,7800,8500,8200,8300},
                           {8200,8600,8500,8900,8100,8000,8400},
                           {8400,8900,8100,8800,8500,8200,8300},
                           {8800,9000,8000,8400,8800,8900,8600},
                           {10500,10000,10200,9500,10400,8000,8500},
                           {8500,8400,8700,8200,8500,8600,8700}};
    int eleccion[max]={1,0,1,0,1,0,1};
    int cantidad[max]={6,2,5,2,3,1,4};
    
    distribucion(numRegiones,numRobotos,regiones,robots,porcentaje,precios,eleccion,cantidad,0);

    return 0;
}

