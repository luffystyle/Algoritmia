/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 7 de diciembre de 2024, 08:27 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAuxiliares.h"

using namespace std;

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    definirContrasenha(arbol);
    
    int maxIntentos;
    cout << "Ingrese el numero maximo de intentos: ";
    cin >> maxIntentos;
    
    char contrasenhaIng[15];
    int longitudContIng;
    
    int longitudCont = longitudContrasenha(arbol);
    
    int i, cantCaracteresCorrectos;
    bool caracterCorrecto;
    int accesoConcedido = 0;
    
    for(i=0; i<maxIntentos; i++){
        cout << "Intento " << i+1 << "/" << maxIntentos << ". Ingrese la contrasenha: ";
        cin >> contrasenhaIng;
        longitudContIng = strlen(contrasenhaIng);
        cantCaracteresCorrectos = 0;
        if (longitudContIng == longitudCont){
            for(int i=0; i<longitudContIng; i++){
                caracterCorrecto = buscarCaracterIngresado(arbol, contrasenhaIng[i], i+1);
                if (caracterCorrecto){
                    cantCaracteresCorrectos++;
                } else {
                    cout << "Contrasenha incorrecta. Intento fallido." << endl;
                    break;
                }
            }
            if (cantCaracteresCorrectos == longitudCont) {
                accesoConcedido = 1;
                break;
            }
        } else {
            cout << "Longitud incorrecta. Intento fallido." << endl;
        }
    }
    
    if (not accesoConcedido){
        cout << "Se llego al numero de intentos fallidos permitidos." << endl;
    } else {
        cout << "Acceso concedido." << endl;
    }
    return 0;
}

