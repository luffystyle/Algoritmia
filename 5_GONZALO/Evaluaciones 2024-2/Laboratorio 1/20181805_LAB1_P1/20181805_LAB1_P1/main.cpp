/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 14 de septiembre de 2024, 08:11 AM
 */

#include <iostream>
#include <cmath>
#include "StPalabra.h"

using namespace std;

void cargarBinario(int numero, int *cromosoma, int n){
    int res, i;
    for(i=0; i<n; i++) cromosoma[i] = 0;
    i = n-1;
    while (numero>0){
        res = numero%2;
        cromosoma[i] = res;
        numero /= 2;
        i--;
    }
}

void resetearLetrasEncontradas(int *letrasEncontradas, int cantLetras){
    for(int i=0; i<cantLetras; i++){
        letrasEncontradas[i] = 0;
    }
}

int buscarLetra(char letra, char *palabraEmpaquetar, int *letrasEncontradas, 
                int cantLetrasPalEmp){
    for(int i=0; i<cantLetrasPalEmp; i++){
        if (palabraEmpaquetar[i]==letra){
            if (letrasEncontradas[i]==0){
                return i;
            }
        }
    }
    return -1;
}

int main(int argc, char** argv) {
    
    char letrasFabricadas[10] = {'G','A','L','A','O','G','L','M'};
    int cantLetrasFab = 8;
    int cromosoma[10];
    struct Palabra arrPalabrasEmp[8] = {{{'G','O','L'},3,0},
                                        {{'G','A','L','A'},4,0},
                                        {{'A','L','A'},3,0},
                                        {{'L','O','M','A'},4,0}};
    int cantPalabrasEmp = 4;
    int numCombinaciones;
    int letrasEncontradas[8];
    
    int cantLetrasComb, cantLetrasEnc, posLetra;
    
    numCombinaciones = (int)pow(2,cantLetrasFab);
    
    for(int i=0; i<cantPalabrasEmp; i++){
        for(int j=0; j<numCombinaciones; j++){
            cargarBinario(j, cromosoma, cantLetrasFab);
            cantLetrasComb = 0;
            cantLetrasEnc = 0;
            resetearLetrasEncontradas(letrasEncontradas, 
                    arrPalabrasEmp[i].cantLetras);
            for(int k=0; k<cantLetrasFab; k++) cantLetrasComb += cromosoma[k];
            if (cantLetrasComb==arrPalabrasEmp[i].cantLetras){
                for(int l=0; l<cantLetrasFab; l++){
                    if (cromosoma[l]){
                        posLetra = buscarLetra(letrasFabricadas[l],
                                arrPalabrasEmp[i].palabraEmpaquetar, 
                                letrasEncontradas, arrPalabrasEmp[i].cantLetras);
                        if (posLetra!=-1){
                            letrasEncontradas[posLetra] = 1;
                        } else {
                            break;
                        }
                    }
                }
                for(int l=0; l<arrPalabrasEmp[i].cantLetras; l++) 
                    cantLetrasEnc += letrasEncontradas[l];
                if (cantLetrasEnc==arrPalabrasEmp[i].cantLetras){
                    arrPalabrasEmp[i].cantPalabrasEncontradas++;
                }
            }
        }
    }
    
    for(int i=0; i<cantPalabrasEmp; i++){
        cout<<"La palabra ";
        for(int j=0; j<arrPalabrasEmp[i].cantLetras; j++){
            cout<<arrPalabrasEmp[i].palabraEmpaquetar[j];
        }
        cout<<" tiene ";
        cout<<arrPalabrasEmp[i].cantPalabrasEncontradas
                <<" combinaciones de Letras."<<endl;
    }
    return 0;
}

