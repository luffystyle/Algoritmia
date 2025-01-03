/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "NodoArbol.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"

void lecturaLetras(ifstream &arch,struct ArbolBinarioBusqueda &arb,int cantLetras,int cont){
    if(cont<cantLetras){
        int numero;
        char letra;
        arch>>numero>>letra;
        insertar(arb,numero,letra);
        lecturaLetras(arch,arb,cantLetras,cont+1);
    }
    
}

void lecturaArchivo(struct ArbolBinarioBusqueda &arbol,int &cantLetras){
    ifstream archPalabra;
    archPalabra.open("Palabra.txt",ios::in);
    if(archPalabra){
        archPalabra>>cantLetras;
        lecturaLetras(archPalabra,arbol,cantLetras,0);
    }else{
        exit(1);
    }
    archPalabra.close();
}

int contadorLetras(char *arrLetras,int pos){
    if(arrLetras[pos]=='\0'){
        return pos;
    }
    return contadorLetras(arrLetras,pos+1);
    
}
//busco que la letra este dentro del ABB y que si no se encuentra el esvalido quedara como -1
void validacion2(struct NodoArbol * nodo,int dato,char letra,int &esvalido){
    if(not esNodoVacio(nodo)){
        if(dato == nodo->elemento and nodo->letra == letra){
            esvalido = 1;
            return ;
        }else{
            if(nodo->letra == letra and dato !=nodo->elemento){
                esvalido = 0;
            }
        }
        validacion2(nodo->izquierda,dato,letra,esvalido);
        validacion2(nodo->derecha,dato,letra,esvalido);
    }
    
}


/// donde se imprime las letras 
void validacionLetrasPosiciones(struct ArbolBinarioBusqueda arbol,char * letrasIngresadas,int pos,int cantTotal,int esValido,int &cantidad){
    if(pos<cantTotal){
        int bandera =-1;
        validacion2(arbol.arbolBinario.raiz,pos+1,letrasIngresadas[pos],bandera);
        if(bandera==1){
            cout<<letrasIngresadas[pos]<<" ";
            esValido++;
            cantidad = esValido;
        }else{
            if(bandera==0){
                cout<<letrasIngresadas[pos]<<"(X) ";
            }else {
                if(bandera==-1){
                    cout<<"_ ";
                }
            }
        }
        validacionLetrasPosiciones(arbol,letrasIngresadas,pos+1,cantTotal,esValido,cantidad);
    }
    
}

void validacionPalabra(struct ArbolBinarioBusqueda arbol,int cantLetras,int cantIntentos,int pos){
    if(pos>cantIntentos){
        cout<<"Lo siento, se agotaron los intentos"<<endl;
        return;
    }
    char letrasIngresadas[8];
    int cantLetrasIngresadas,esValido;
    cout<<"Intento "<<pos<<": ";
    cin.getline(letrasIngresadas,'\n');
    //contamos cuantos numeros hay en mi arreglo de cadena
    cantLetrasIngresadas = contadorLetras(letrasIngresadas,0);
    if(cantLetrasIngresadas == cantLetras){
        esValido=0;
        validacionLetrasPosiciones(arbol,letrasIngresadas,0,cantLetrasIngresadas,0,esValido);
        cout<<endl;
        if(esValido == cantLetrasIngresadas){
            cout<< "Felicitaciones por haber resuelto el reto"<<endl;
            return ;
        }
    }else{
        if(cantLetrasIngresadas>cantLetras){
            cout<<"La longitud de la palabra ingresada no es la correcta. Vuelva a intentarlo."<<endl;
            pos--;
        }
    }
    validacionPalabra(arbol,cantLetras,cantIntentos,pos+1);
    
    
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    int cantLetras,cantIntentos=5;
    lecturaArchivo(arbol,cantLetras);
    cout<<"BIENVENIDO AL JUEGO DE BALWORD"<<endl;
    cout<<"Descubre la palabra de 5 letras. Tiene maximo 5 intentos"<<endl;
    cout<<"- - - - -"<<endl;
    validacionPalabra(arbol,cantLetras,cantIntentos,1);
    
    return 0;
}

