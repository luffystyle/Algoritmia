
#include <iostream>
#include <iomanip>

using namespace std;
#include "funcionesListas.h"




void invierteLista(Lista &ptrLista){   
    Nodo *ptrrec,*ptrant=NULL,*ptrini;
    int i,j,n;
    n = ptrLista.longitud;
    for(i=1;i<n;i++)
    {   ptrrec=ptrLista.cabeza;
        for(j=i;j<n;j++)
        {   ptrant=ptrrec; 
            ptrrec=ptrrec->sig;
        }
        if(i==1)
            ptrini=ptrrec;
        ptrrec->sig=ptrant;
    }
    if(i!=1)
        ptrant->sig=NULL;
    ptrLista.cabeza=ptrini;
}
//---------------------------------------------------------
Nodo* inviertereal(Nodo *lista){
    Nodo *ptrini;
    
    if(lista==NULL) return NULL;
    if(lista->sig==NULL) return lista;
    ptrini = inviertereal(lista->sig);
    lista->sig->sig = lista;
    lista->sig = NULL;
    
    return ptrini;
}
void invierterecursivamente(Lista &lista){
    Nodo* ptrini,*ptrfin, *pU;   
    pU = ubicarUltimo(lista);
    
    ptrfin= lista.cabeza;
    ptrini= inviertereal(lista.cabeza);
    lista.cabeza = ptrini;
    pU = ptrfin;
}
//---------------------------------------------------------


void fusion(Lista &L1, Lista &L2) {
    Nodo *pU1, *pU2;
    pU1 = ubicarUltimo(L1);
    pU2 = ubicarUltimo(L2);
    
    if(pU1->elem < L2.cabeza->elem) { // el último elemento de de la L1 es menor que la cabeza de L2
        pU1->sig = L2.cabeza;
        L1.longitud += L2.longitud;
    } else {
        if( L2.cabeza->elem < L1.cabeza->elem) {
            pU2->sig = L1.cabeza;
            L1.cabeza = L2.cabeza;
            L1.longitud += L2.longitud;
        } else {
            Nodo *pIni = NULL;
            Nodo *pFin = NULL;
            while(esListaVacia(L1) && esListaVacia(L2)) {
                if()
            }
        }
    }
}

void juntarListas(Lista &L1, Lista &L2) {
    Nodo *pU1, *pU2;
    pU1 = ubicarUltimo(L1);
    pU2 = ubicarUltimo(L2);
    

    pU1->sig = L2.cabeza;
    L1.longitud += L2.longitud;
    
    
}



int main(int argc, char** argv) {

    Lista lunes, martes, miercoles, jueves, viernes;
    
    construir(lunes);
    insertarAlFinal(lunes, 8);
    insertarAlFinal(lunes, 10);
    insertarAlFinal(lunes, 12);
    //ordenarDeMayorAMenor(lunes);
    cout << "Lunes: ";
    mostrar(lunes);
    
    construir(martes);
    insertarAlFinal(martes, 5);
    insertarAlFinal(martes, 7);
    //ordenarDeMayorAMenor(martes);
    cout << "Martes: ";
    mostrar(martes);
    
    construir(miercoles);
    insertarAlFinal(miercoles, 8);
    insertarAlFinal(miercoles, 9);
    insertarAlFinal(miercoles, 10);
    //ordenarDeMayorAMenor(miercoles);
    cout << "Miercoles: ";
    mostrar(miercoles);
    
    construir(jueves);
    insertarAlFinal(jueves, 15);
    insertarAlFinal(jueves, 16);
    insertarAlFinal(jueves, 14);
    //ordenarDeMayorAMenor(jueves);
    cout << "Jueves: ";
    mostrar(jueves);
    
    construir(viernes);
    insertarAlFinal(viernes, 17);
    insertarAlFinal(viernes, 18);
    insertarAlFinal(viernes, 19);
    //ordenarDeMayorAMenor(viernes);
    cout << "Viernes: ";
    mostrar(viernes);
    cout << "----------------------------------" << endl;
    fusion(lunes, martes);
    mostrar(lunes);    

    return 0;
}

