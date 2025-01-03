/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <cmath>
#include "Funciones.h"

using namespace std;

int verificaVampiro(int numero){
    int cantDigitosNum, cantDigitosMult1, cantDigitosMult2;
    int numCombMult1, numCombMult2;
    int mult1, mult2, producto;
    int valido;
    cantDigitosNum = contarDigitos(numero);
    if ((cantDigitosNum%2)==0){
        cantDigitosMult1 = cantDigitosNum/2;
        cantDigitosMult2 = cantDigitosNum/2;
        int multiplicando1[cantDigitosMult1];
        int multiplicando2[cantDigitosMult2];
        numCombMult1 = (int)pow(10,cantDigitosMult1);
        numCombMult2 = (int)pow(10,cantDigitosMult1);
        for(int i=0; i<numCombMult1; i++){
            cargarBase(i, multiplicando1, cantDigitosMult1);
            for(int j=0; j<numCombMult2; j++){
                cargarBase(j, multiplicando2, cantDigitosMult2);
                mult1 = obtenerMultiplicando(multiplicando1, cantDigitosMult1);
                mult2 = obtenerMultiplicando(multiplicando2, cantDigitosMult2);
                producto = mult1*mult2;
                if (producto==numero){
                    valido = verificarNumeros(numero, cantDigitosNum, 
                            multiplicando1, cantDigitosMult1, multiplicando2, 
                            cantDigitosMult2);
                    if (valido) {
                        return 1;
                    }
                }
            }
        }
    } else {
        return 0;
    }
    return 0;
}

int contarDigitos(int numero){
    int cantDigitos = 0;
    while (numero>0){
        cantDigitos++;
        numero /= 10;
    }
    return cantDigitos;
}

void cargarBase(int numero, int *cromosoma, int n){
    int res, i;
    for(i=0; i<n; i++) cromosoma[i] = 0;
    i = n-1;
    while (numero>0){
        res = numero%10;
        cromosoma[i] = res;
        numero /= 10;
        i--;
    }
}

int obtenerMultiplicando(int *multiplicando, int cantDigitosMult){
    int numero=0;
    for(int i=0; i<cantDigitosMult; i++){
        numero += (multiplicando[i]*((int)pow(10,(cantDigitosMult-i-1))));
    }
    return numero;
}

int verificarNumeros(int numero, int cantDigitosNum, int *multiplicando1, 
                     int cantDigitosMult1, int *multiplicando2, 
                     int cantDigitosMult2){
    int digitosNumero[cantDigitosNum];
    int digitosContenidos[cantDigitosNum];
    int seEncontro;
    extraerDigitos(numero, digitosNumero, cantDigitosNum);
    for(int i=0; i<cantDigitosNum; i++) digitosContenidos[i] = 0;
    for(int i=0; i<cantDigitosMult1; i++){
        seEncontro = buscarDigito(multiplicando1[i], digitosNumero, 
                digitosContenidos, cantDigitosNum);
        if (not seEncontro) return 0;
    }
    for(int i=0; i<cantDigitosMult2; i++){
        seEncontro = buscarDigito(multiplicando2[i], digitosNumero, 
                digitosContenidos, cantDigitosNum);
        if (not seEncontro) return 0;
    }
    return 1;
}

void extraerDigitos(int numero, int *digitosNumero, int cantDigitosNum){
    int i, res;
    for(i=0; i<cantDigitosNum; i++) digitosNumero[i] = 0;
    i = cantDigitosNum-1;
    while (numero>0){
        res = numero%10;
        digitosNumero[i] = res;
        numero /= 10;
        i--;
    }
}

int buscarDigito(int digitoMultiplicando, int *digitosNumero, 
                 int *digitosContenidos, int cantDigitosNum){
    for(int i=0; i<cantDigitosNum; i++){
        if (digitosNumero[i]==digitoMultiplicando){
            if (digitosContenidos[i]==0){
                digitosContenidos[i] = 1;
                return 1;
            }
        }
    }
    return 0;
}