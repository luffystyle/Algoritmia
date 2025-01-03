/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Funciones.h
 * Author: Ariana
 *
 * Created on 11 de octubre de 2024, 11:23 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void AperturaIf(ifstream &arch,const char *nomb);
void construirLista(Lista &lista);
void destruirLista(Lista &lista);
void insertarAlFinal(Lista &lista,int guerrero);
Nodo *crearNuevoNodo(int guerrero,Nodo *siguiente);
Nodo *devolverUltimoNodo(Lista &lista);
void imprimirLista(Lista &lista);
bool esListaVacia(const Lista lista);
void imprimirLista(Lista &lista);
void formarEjercitos(Lista &ejercito1,int &ataque1,Lista &ejercito2,int &ataque2,
        Lista &ejercito3,int &ataque3,Lista &guerreros,int cantGuerr);
void ordenarListas(Lista &lista);
void insertarEnEjercito(int guerrero,int ataque,Lista &ejercito1,int &ataque1,
        Lista &ejercito2,int &ataque2,Lista &ejercito3,int &ataque3);
void fusionarLista(Lista &lista1,Lista &lista2);
void integrarEjercito(Lista &ejercito2,int &ataque2,Lista &ejercito3,int ataque3);
void pelea(int i,Lista &ejercito1,Nodo *&recorrido1,int &ataque1,
        Lista &ejercito2,Nodo *&recorrido2,int &ataque2);
void sacarDeLista(Lista &lista);
void declararGanador(int ataque1,int ataque2);


#endif /* FUNCIONES_H */
