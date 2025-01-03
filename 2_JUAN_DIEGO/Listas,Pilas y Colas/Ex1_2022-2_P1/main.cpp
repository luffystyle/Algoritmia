/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Lista.h"
#include "funciones.h"
using namespace std;


/*
 * IMPLEMENTACIÓN DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */

void fusionLista(Lista & L1,Lista & L2){//Para hacer la fusion las listas deben estar ordenadas
    if(L1.cola->hora<L2.cabeza->hora){
        L1.cola->siguiente=L2.cabeza;
        L1.cola=L2.cola;
    }else if(L2.cola->hora<L1.cabeza->hora){
        L2.cola->siguiente=L1.cabeza;
        L1.cabeza=L2.cabeza;
    }else{
        struct Nodo *ini,*fin;
        ini=NULL;
        fin=NULL;
        while(!esListaVacia(L1) && !esListaVacia(L2)){
            if(L1.cabeza->hora<=L2.cabeza->hora){
                if(ini==NULL){
                    ini=L1.cabeza;
                    fin=L1.cabeza;
                }else{
                    fin->siguiente=L1.cabeza;
                    fin=L1.cabeza;
                }
                L1.cabeza=L1.cabeza->siguiente;
            }else{
                if(L1.cabeza->hora>L2.cabeza->hora){
                    if(ini==NULL){
                        ini=L2.cabeza;
                        fin=L2.cabeza;
                    }else{
                        fin->siguiente=L2.cabeza;
                        fin=L2.cabeza;
                    }
                }
                L2.cabeza=L2.cabeza->siguiente;
            }
        }
        if(!esListaVacia(L1)){
            fin->siguiente=L1.cabeza;
            fin=L1.cola;
        }else{
            fin->siguiente=L2.cabeza;
            fin=L2.cola;
        }
        L1.cabeza=ini;
        L1.cola=fin;
    }    
}
int main(int argc, char** argv) {

    struct Lista lun,mar,mie,jue,vie;
    /*Construimos la lista, la lista esta vacía*/
    construir(lun);
    construir(mar);
    construir(mie);
    construir(jue);
    construir(vie);
       
    /*Lunes*/
    insertarAlFinal(lun,8,6,"Lunes");
    insertarAlFinal(lun,10,14,"Lunes");
    insertarAlFinal(lun,12,1,"Lunes");
    /*Martes*/
    insertarAlFinal(mar,9,11,"Martes");
    insertarAlFinal(mar,11,8,"Martes");
    /*Miercoles*/
    insertarAlFinal(mie,8,2,"Miercoles");
    insertarAlFinal(mie,9,5,"Miercoles");
    insertarAlFinal(mie,10,10,"Miercoles");
    /*Jueves*/
    insertarAlFinal(jue,14,13,"Jueves");
    insertarAlFinal(jue,15,9,"Jueves");
    insertarAlFinal(jue,16,11,"Jueves");
    /*Viernes*/
    insertarAlFinal(vie,17,4,"Veiernes");
    insertarAlFinal(vie,18,12,"Veiernes");
    insertarAlFinal(vie,19,7,"Veiernes");
    
    fusionLista(lun,mar);
    fusionLista(lun,mie);
    fusionLista(lun,jue);
    fusionLista(lun,vie);
    
    imprime(lun);
    

    return 0;
}

//if(L1.cola->hora<L2.cabeza->hora){
//        L1.cola->siguiente=L2.cabeza;
//        L1.cola=L2.cola;
//    }else if(L2.cola->hora<L1.cabeza->hora){
//        L2.cola->siguiente=L1.cabeza;
//        L1.cabeza=L2.cabeza;
//    }else{
//        struct Nodo *ini , *fin; //el inicio y fin indicara el nodo inicial y el nodo final de la lista
//        ini=NULL;//inicialmento los punteros no apuntaran a ningun sitio
//        fin=NULL;
//        while(!esListaVacia(L1) && !esListaVacia(L2)){//Realizaremos el sigueinte proceso mientras las listas no esten vacias
//            if(L1.cabeza->hora<=L2.cabeza->hora){
//                if(ini==NULL){
//                    ini=L1.cabeza;
//                    fin=L1.cabeza;
//                }else{
//                    fin->siguiente=L1.cabeza;
//                    fin=L1.cabeza;
//                }
//                L1.cabeza=L1.cabeza->siguiente;
//            }
//            else{
//                if(L1.cabeza->hora>L2.cabeza->hora){
//                    if(ini==NULL){
//                        ini=L2.cabeza;
//                        fin=L2.cabeza;
//                    }else{
//                        fin->siguiente=L2.cabeza;
//                        fin=L2.cabeza;
//                    }
//                    L2.cabeza=L2.cabeza->siguiente;
//                }
//            }            
//        }
//        if(!esListaVacia(L1)){
//            fin->siguiente=L1.cabeza;
//            fin=L1.cola;
//        }else{
//            fin->siguiente=L2.cabeza;
//            fin=L2.cola;
//        }
//        L1.cabeza=ini;
//        L1.cola=fin;
//    }