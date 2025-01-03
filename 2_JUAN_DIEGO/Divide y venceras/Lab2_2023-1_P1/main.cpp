/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juanD
 *
 * Created on 7 de mayo de 2024, 08:06 AM
 */

#include <cstdlib>
#include <iostream>
#define MAX 25
//Para terminarrrrrr
using namespace std;

/*
 * 
 */


void mostrarMatriz(int matriz[][25], int filas,int columnas){
    cout<<"Matriz:"<<endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
        	if (matriz[i][j]<0)
        		if (matriz[i][j]<10)
        			cout<<"";
        		else
        			cout<<" ";
        	else
        		if (matriz[i][j]<10)
        			cout <<" "; 
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void pasaMatrizArreglo(int matriz[][25],int *arreglo,int filas,int columnas){
    int i,j;
    int a=0;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            arreglo[a]=matriz[i][j];
            a++;
        }
    }
}
void pasaArregloMatriz(int matriz[][25],int*arreglo,int filas,int columnas){
    int i,j;
    int a=0;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            matriz[i][j]=arreglo[a];
            a++;
        }
    }
}
void merge(int arreglo1[], int arreglo2[], int posicion_inicial, int posicion_medio, int posicion_final){
	int i, p, q; //índices para los 3 arreglos
	//i es para arreglo[]
	//p es para arreglo[], mitad de la izquierda
	//q es para arreglo[], mitad de la derecha
	
	int longitud1, longitud2;
	longitud1=(posicion_medio+1)-posicion_inicial;
	longitud2=posicion_final-posicion_medio;
	
	//establecemos 2 arreglos auxiliares para reordenar el arreglo[]
	int P1[longitud1+1], P2[longitud1+1];//Un elemento más en el subarreglo con valor muuuuuy grande
	int Q1[longitud2+1], Q2[longitud2+1];//Un elemento más en el subarreglo con valor muuuuuy grande
	
	P1[longitud1]=999999;
	Q1[longitud2]=999999;
	
	for (i=posicion_inicial;i<posicion_medio+1;i++){
		P1[i-posicion_inicial]=arreglo1[i];//restamos posicion_inicial al índice para que comience desde 0 para P[]
		P2[i-posicion_inicial]=arreglo2[i];//restamos posicion_inicial al índice para que comience desde 0 para P[]
	}
	
		
	for (i=posicion_medio+1;i<=posicion_final;i++){
		Q1[i-(posicion_medio+1)]=arreglo1[i];//restamos posicion_medio+1 al índice para que comience desde 0 para Q[]
		Q2[i-(posicion_medio+1)]=arreglo2[i];//restamos posicion_medio+1 al índice para que comience desde 0 para Q[]
	}
		
	p=q=0;
	
	for (i=posicion_inicial; i<=posicion_final; i++)
		if (P1[p]<Q1[q]){//Si el elemento de P[] es el menor, insertamos en arreglo[]
			arreglo1[i]=P1[p];
			arreglo2[i]=P2[p];
			p++;
		}
		else{//Si el elemento de Q[] es el menor, insertamos en arreglo[]
			arreglo1[i]=Q1[q];
			arreglo2[i]=Q2[q];
			q++;
		}
}

void mergesort(int*arreglo1,int*arreglo2,int posicion_inicial,int posicion_final){
    if(posicion_inicial==posicion_final)
        return;
    
    int posicion_medio=(posicion_inicial+posicion_final)/2;
    
    mergesort(arreglo1, arreglo2, posicion_inicial, posicion_medio);
    mergesort(arreglo1, arreglo2, posicion_medio+1, posicion_final);
    
    merge(arreglo1, arreglo2, posicion_inicial, posicion_medio, posicion_final);
}

int EncontrarEnMatriz(int reg[][25],int inst[][25],int n,int  fila_ini,int fila_fin,int col_ini,int col_fin){
    
    int fila_med,col_med;
    int submat1,submat2,submat3,submat4,submat5,submat6;
    
    submat1=submat2=submat3=submat4=submat5=submat6=0;
    
    fila_med=(fila_ini+fila_fin)/2;
    col_med=(col_ini+col_fin)/2;
    
    //Caso base
    if(fila_ini==fila_fin && col_ini==col_fin){
        if(n==reg[fila_ini][col_ini])
            return inst[fila_ini][col_ini];
        else
            return 0;
    }
    //cuando queda una columna
    if(fila_ini==fila_fin){
        submat5=EncontrarEnMatriz(reg, inst, n, fila_ini, fila_fin,col_ini,col_med);
        submat6=EncontrarEnMatriz(reg, inst, n, fila_ini, fila_fin,col_med+1,col_fin);
        return submat5+submat6;
    }
    //cuando queda una fila
    if(col_ini==col_fin){
        submat5=EncontrarEnMatriz(reg, inst, n, fila_ini, fila_med,col_ini,col_fin);
        submat6=EncontrarEnMatriz(reg, inst, n, fila_med+1, fila_fin,col_ini,col_fin);
        return submat5+submat6;
    }
    //submatrices habituales
    //Cuadrante 2
    if(n>=reg[fila_ini][col_ini] && n<=reg[fila_med][col_med]){
        submat1=EncontrarEnMatriz(reg, inst, n, fila_ini, fila_med,col_ini,col_med);
    }
    //Cuadrante 3
    if(n>=reg[fila_med+1][col_ini] && n<=reg[fila_fin][col_med]){
        submat2=EncontrarEnMatriz(reg, inst, n, fila_med+1, fila_fin,col_ini,col_med);
    }
    //Cuadrante 1
    if(n>=reg[fila_ini][col_med+1] && n<=reg[fila_med][col_fin]){
        submat3=EncontrarEnMatriz(reg, inst, n, fila_ini, fila_med,col_med+1,col_fin);
    }
    //Cuadrante 4
    if(n>=reg[fila_med+1][col_med+1] && n<=reg[fila_fin][col_fin]){
        submat4=EncontrarEnMatriz(reg, inst, n, fila_med+1, fila_fin,col_med+1,col_fin);
    }
    return submat1+submat2+submat3+submat4;
}


int main(int argc, char** argv) {
    int Registro[MAX][MAX]={{-1,-2,-3,-4,-5,-6},
                              {-7,-8,1,-9,2,-10},
                              {-11,1,2,-12,-13,-14},
                              {-15,-16,-17,1,-18,-19},
                              {-20,1,2,-21,-22,-23}};

    int LineasInstruccion[MAX][MAX]={{10,5,8,9,8,1},
                                     {10,5,2,8,2,3},
                                     {4,2,1,4,8,1},
                                     {1,2,4,3,5,3},
                                     {8,3,3,8,5,3}};
    int n=5;
    int m=6;
    int arregloID[n*m];
    int arregloInst[n*m];
    int registro, cantidadInstrucciones;
    //Mostramos las matrices
    mostrarMatriz(Registro,n,m);
    mostrarMatriz(LineasInstruccion,n,m);
    //ordenamos las matrices
    //se pueden utilizar arrreglos paara ordenar las matrices
    pasaMatrizArreglo(Registro,arregloID,n,m);
    pasaMatrizArreglo(LineasInstruccion,arregloInst,n,m);
    //utilizamos mergesort() modificado, ya que tienen que ordenarse las dos matrices en paralelo
    
    mergesort(arregloID,arregloInst,0,n*m-1);
    //una vez ordenado, pasamos nuevamente a matrices
    pasaArregloMatriz(Registro,arregloID,n,m);
    pasaArregloMatriz(LineasInstruccion,arregloInst,n,m);
    //Despues de ordenar , busco en la matriz de ID's los que son posibles virus
    //Mostramos las matrices
    mostrarMatriz(Registro,n,m);
    mostrarMatriz(LineasInstruccion,n,m);
    registro = 1;
    
    cantidadInstrucciones=EncontrarEnMatriz(Registro, LineasInstruccion, registro, 0, n-1,0,m-1);
    cout<<"Cantidad instrucciones= "<<cantidadInstrucciones<<endl;
    if (cantidadInstrucciones>=10)
	cout<<"El archivo tiene un posible código malicioso del virus con registro "<< registro<<endl;
    else
	cout<<"El archivo NO tiene un posible código malicioso del virus con registro "<< registro<<endl;
    return 0;
}

