/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 6 de abril de 2024, 01:46 AM
 */

#include <cstdlib>
#include<iostream>
#define n 10

using namespace std;

int ciudad[n][n]={{0,0,42,0,35,0,0,10,0,0},
                  {0,0,0,0,0,0,0,0,0,0},
                  {0,27,0,0,0,0,50,0,0,0},
                  {0,0,30,0,0,0,0,0,0,0},
                  {0,0,0,0,38,0,0,42,0,0},
                  {15,0,0,50,0,0,0,50,0,0},
                  {0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,50,0,37,0,0,0},
                  {0,18,0,17,0,0,0,0,50,0},
                  {0,0,0,0,0,0,0,0,0,0}};
int x,y;
int superfly=0;

/*
 * 
 */

void leonardo(int poder){
    if(poder<ciudad[y][x+1]){
        return;
    }     
    if(ciudad[y][x+1]>0){
        if(ciudad[y][x+1]==50){
            poder=poder-ciudad[y][x+1];
            superfly++;
        }
        poder=poder-ciudad[y][x+1]; 
    }
    x++;
    leonardo(poder);    
}
/*============================================================================*/
void rafael(int poder){
    if(poder<ciudad[y+1][x]){
        return;
    }       
    if(ciudad[y+1][x]>0){
        if(ciudad[y+1][x]==50){
            poder=poder-ciudad[y+1][x];
            superfly++;
        }
        poder=poder-ciudad[y+1][x]; 
    }
    y++;
    rafael(poder);
}
/*============================================================================*/
void donatello(int poder){
    if(poder<ciudad[y][x+1]){
        return;
    }
    if(ciudad[y][x+1]>0){
        if(ciudad[y][x+1]==50){
            poder=poder-ciudad[y][x+1];
            superfly++;
        }
        poder=poder-ciudad[y][x+1]; 
    }
    x++;
    donatello(poder);
}
/*============================================================================*/
void miguelAn(int poder){
    if(poder<ciudad[y][x+1]){
        return;
    }
    if(ciudad[y][x+1]>0){
        if(ciudad[y][x+1]==50){
            poder=poder-ciudad[y][x+1];
            superfly++;
        }
        poder=poder-ciudad[y][x+1]; 
    }
    x++;
    miguelAn(poder);
}
void imprime(){
    cout<<"Las tortuninjas lograron vencer a SuperFly"<<endl;
}
int main(int argc, char** argv) {
    
    int fila=0;
    int columna=0;
    leonardo(75);
    if(superfly==1){
        imprime();
    }
    rafael(58);
    if(superfly==1){
        imprime();
    }
    donatello(65);
    if(superfly==1){
        imprime();
    }
    miguelAn(80);
    if(superfly==1){
        imprime();
    }else if(superfly==0){
       cout<<"Mission failed"<<endl;
    }
    
    return 0;
}

