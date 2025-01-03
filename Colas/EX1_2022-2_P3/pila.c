/* 
 * File:   pila.c
 * Author: Codigo: 20201294
 *         Nombre: Christian Leonardo Rosales Ventocilla
 * Usuario
 *
 * Created on 13 de diciembre de 2022, 16:48
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void construir_pila(Pila *tad){
	//El constructor de la lista espera como parámetro Lista *tad
	//El párametro de esta función es Pila *tad
	//	typedef struct {
	//		Lista contenido;    
	//	} Pila;
	//
	//como a partir de Pila *tad se llega a la lista
	//	tad->contenido es del tipo de dato Lista
	//la dirección de la lista sería (Lista *)
	//	&tad->contenido
	construir_lista(&tad->contenido);
}

void destruir_pila(Pila *tad){
	destruir_lista(&tad->contenido);
}

int es_pila_vacia(Pila tad){
	return es_lista_vacia(tad.contenido);
}

void apilar(Pila *tad, ElementoPila elemento){
	insertar_al_inicio(&tad->contenido, elemento);
}

ElementoPila desapilar(Pila *tad){	
    if (es_pila_vacia(*tad)){
    	printf("La pila está vacía, por lo tanto no se puede desapilar.\n");
    	exit(11);
    }
    ElementoPila elemento=cima(*tad);
    elimina_cabeza(&tad->contenido);
    return elemento;
}

ElementoPila cima(Pila tad){
	if (es_pila_vacia(tad)){
    	printf("La pila está vacía, por lo tanto no posee cima.\n");
    	exit(12);
    }
    //return tad.contenido.cabeza->elemento; //NO SE DEBE HACER	
    return retorna_cabeza(tad.contenido);
}