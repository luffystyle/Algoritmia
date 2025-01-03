/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 10 de mayo de 2024, 02:45 PM
 */

#include <cstdlib>
#include <iostream>
#define maximo 10

using namespace std;

int potencia;
int col;

int campo1[10][7]={{0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0},
                            {0,0,0,0,1,1,1},
                            {0,0,0,0,1,2,2},
                            {0,0,0,0,1,2,3},
                            {0,0,0,0,1,2,2},
                            {0,0,0,0,1,1,1},
                            {0,0,0,0,0,0,0}};

int campo2[8][7]={{0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0},
                            {0,1,1,1,0,0,0},
                            {0,1,2,1,0,0,0},
                            {0,1,1,1,0,0,0},
                            {0,0,0,0,0,0,0}};

/*
 * 
 */

int buscaFila(int col,int potencia,int ini,int fin){
    if(ini>fin)return ini;
    int med=(ini+fin)/2;
    if(campo1[med][col]==potencia){
        return med;
    }
    if(campo1[med-1][col]==0)
        return buscaFila(col,potencia,med,fin);
    else
        return buscaFila(col,potencia,ini,med-1);
}
int calculaPeso(int ini_x,int fin_x,int ini_y,int fin_y){
    int peso=0;
    int i,j;
    //realizamos un recorrido y sumamos los pesos de la submtariz
    for(i=ini_y;i<=fin_y;i++){
        for(j=ini_x;j<=fin_x;j++){
            peso+=campo1[i][j];
        }
    }
    return peso;
}

void buscaBomba(int ini_x,int fin_x,int ini_y,int fin_y){
    //Primero dividimos el eje x o columnas
    int ini_x2=ini_x,fin_x2=fin_x;
    //definimos el dio de las columnas
    int med_x=(ini_x+fin_x)/2;
    //Desarrollamos el caso base
    if((ini_x==fin_x) && (ini_y==fin_y)){
        col=ini_x;//guardamos la columna 
        potencia=campo1[ini_y][ini_x+1];//asignamos la ubicacion a la potencia 
        return;
    }
    
    if(ini_x!=fin_x){
        int peso_x_izq=calculaPeso(ini_x,med_x,ini_y,fin_y); //Calculamos el peso de las columnas en la izquierda
        int peso_x_der=calculaPeso(med_x+1,fin_x,ini_y,fin_y);//Calculamos elpeso dee las columnas en la derecha
        
        if(peso_x_izq>peso_x_der){
            fin_x2=med_x;//Si la izquierda tiene mayor peso el valor del medio sera el nuevo fin de las columnas
        }else{
            ini_x2=med_x+1;//Si la derecha tiene mayor peso, el inicio sera el nuevo medio
        }
    }
    //Ahora dividimos las filas para comparar los pesos
    int ini_y2=ini_y,fin_y2=fin_y;
    int med_y=(ini_y+fin_y)/2;
    //Al igual que con las columnas, tambien buscamos el peso entre las filas superiores en inferiores
    if(ini_y!=fin_y){
        int peso_y_up=calculaPeso(ini_x2,fin_x2,ini_y,med_y); //Calculamos el peso arriba reemplzamos los valores del medio de columnas
        int peso_y_down=calculaPeso(ini_x2,fin_x2,med_y+1,fin_y);//Calculamos elpeso abajo, igual reemplazamos los valores de las columnas
        
        if(peso_y_up>peso_y_down){
            fin_y2=med_y;//Si arriba tiene mayor peso el valor del medio sera el nuevo fin de las columnas
        }else{
            ini_y2=med_y+1;//Si abajo tiene mayor peso, el inicio sera el nuevo medio
        }
    }
     buscaBomba(ini_x2,fin_x2,ini_y2,fin_y2);//Llamamos nuevamente a la funcion de manera recursiva, pero esta vez con los valores actuales   
}

int main(int argc, char** argv) {
    int n=7;
    int m=10;
    
    //Parte A    
    buscaBomba(0,n-1,0,m-1);
    //Mostramos la potencia y columna 
    cout<<"Para este juego de datos, la potencia más alta de la bomba es "<<potencia;
    cout<<" y la columna donde se ubica es "<<col+1<<endl;
    
    //Parte B
    //Ahora tendremos que encontrar la fila donde se enceuntra la bomba
    int fila=buscaFila(col+1,potencia,0,m-1);//utilizamos una busqueda con divide y venceras para encontrarlo
    cout<<"La fila con el mayor impacto es la "<<fila<<endl;

    return 0;
}

