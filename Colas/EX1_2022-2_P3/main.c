/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Codigo: 20201294
 *         Nombre: Christian Leonardo Rosales Ventocilla
 * Usuario
 *
 * Created on 13 de diciembre de 2022, 16:42
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "cola.h"
#include "pila.h"
/*
 * 
 */
void inicializarLista(int n,Lista *ptrLista){
	int i;
	for (i=2; i<=n; i++){
		insertar_al_final(ptrLista,i);
	}
}

void limpiaCola(Cola *ptrCola){
	if (!es_cola_vacia(*ptrCola)){
		int elemento = avanzar(ptrCola);
		limpiaCola(ptrCola);
	}
}

void tachaNodos(NodoLista *ptrRecorrido,Lista *ptrLista,int elemento,Cola *ptrCola){
	if (ptrRecorrido!=NULL){
		if (ptrRecorrido->sig!=NULL){
			if (ptrRecorrido->sig->elemento % elemento==0){
				pide_vez(ptrCola,ptrRecorrido->sig->elemento);
				elimina_nodo(ptrLista,ptrRecorrido->sig->elemento);
			}
			tachaNodos(ptrRecorrido->sig,ptrLista,elemento,ptrCola);
		}
	}
}

void procesoCribaEratostenes(NodoLista *ptrRecorrido,Lista *ptrLista,int elemento,Cola *ptrCola){
	if (ptrRecorrido!=NULL){
		tachaNodos(ptrRecorrido,ptrLista,elemento,ptrCola);
		printf("Numero Procesado: %d\n",elemento);
		printf("Numeros Tachados para el %d: ",elemento);
		imprime(ptrCola->contenido);
		limpiaCola(ptrCola);
		ptrRecorrido = ptrRecorrido->sig;
		procesoCribaEratostenes(ptrRecorrido,ptrLista,ptrRecorrido->elemento,ptrCola);
	}
}
int main(int argc, char** argv) {
    int n;
    Lista ptrLista;
    Cola ptrCola;
    NodoLista *ptrRecorrido;
    printf("Ingrese el n: ");
    scanf("%d",&n);
    construir_lista(&ptrLista);
    construir_cola(&ptrCola);
    /*Parte b*/
    inicializarLista(n,&ptrLista);
    /*Parte c*/
    ptrRecorrido = ptrLista.cabeza;
    procesoCribaEratostenes(ptrRecorrido,&ptrLista,ptrRecorrido->elemento,&ptrCola);
    imprime(ptrLista);
    destruir_lista(&ptrLista);
    destruir_cola(&ptrCola);    
        
    return (EXIT_SUCCESS);
}

