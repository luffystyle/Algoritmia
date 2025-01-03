#include <stdio.h>
#include <malloc.h>

/*informacion que se almacenara en el nodo*/
typedef int TInfo;

/*se define el  tipo de dato TNodo que representa a una estructura autoreferenciada*/
typedef struct Nodo{
    TInfo elem;
    struct Nodo* sig;
} TNodo;

/*se define el tipo de dato para gestionar la lista enlazada*/
typedef TNodo* TLista;

int esta_en_lista(TLista ptrLista, TInfo elem){
    TNodo *ptrRec;
    ptrRec = ptrLista;
    
    while (ptrRec){
        if (ptrRec->elem==elem)
            return 1;
        ptrRec = ptrRec->sig;
    }
    return 0;
}

int tamano(TLista ptrLista)
{   TLista ptrrec;
    int cont=0;
    
    ptrrec=ptrLista;
    while(ptrrec)
    {
        ptrrec=ptrrec->sig;
        cont++;
    }
    
    return cont;
}

void crear_lista(TLista *ptrLista){
    *ptrLista = NULL;
}

int esta_vacia(TLista ptrLista){
    return ptrLista==NULL;
}

void insertar_inicio(TLista *ptrLista, TInfo elem){
    TNodo *ptrNuevo;
    ptrNuevo = (TNodo*)malloc(sizeof(TNodo));
    
    ptrNuevo->elem = elem;
    ptrNuevo->sig = *ptrLista;
    *ptrLista = ptrNuevo;
}

void insertar_final(TLista *ptrLista, TInfo elem){
    TNodo *ptrNuevo, *ptrRec, *ptrUltimo;
    ptrNuevo = (TNodo*)malloc(sizeof(TNodo));
    
    ptrNuevo->elem = elem;
    ptrNuevo->sig = NULL;
    //printf("%d %d %d\n",ptrLista,*ptrLista,ptrNuevo);
    ptrRec = *ptrLista;    
    ptrUltimo = NULL;
    while (ptrRec){
        ptrUltimo = ptrRec;
        ptrRec = ptrRec->sig;
    }
    
    if (ptrUltimo)
        ptrUltimo->sig=ptrNuevo;
    else
        *ptrLista = ptrNuevo;
   // printf("%d %d %d\n",ptrLista,*ptrLista,ptrNuevo);
}

void imprimir(TLista ptrLista){
    TNodo *ptrRec;
    ptrRec = ptrLista;
    
    while (ptrRec){
        printf("%d -> ", ptrRec->elem);
        ptrRec = ptrRec->sig;
    }
    printf("NULL\n");
}

void finalizar_lista(TLista ptrLista){
    TNodo *ptrRec, *ptrLiberar;
    ptrRec = ptrLista;
    
    while (ptrRec){
        ptrLiberar = ptrRec;
        ptrRec = ptrRec->sig;
        free(ptrLiberar);
    }
}

int main(){
	TLista ptrConjunto1, ptrConjunto2, ptrInterseccion, ptrUnion;
	TNodo *ptrRecorrido;
	crear_lista(&ptrConjunto1);
	crear_lista(&ptrConjunto2);
	/*Elementos para el conjunto 1*/
	insertar_final(&ptrConjunto1,15);
	insertar_final(&ptrConjunto1,25);
	insertar_final(&ptrConjunto1,5);
	insertar_final(&ptrConjunto1,35);

	/*Elementos para el conjunto 2*/
	insertar_final(&ptrConjunto2,20);
	insertar_final(&ptrConjunto2,25);
	insertar_final(&ptrConjunto2,30);
	insertar_final(&ptrConjunto2,15);
	
	printf("Elementos del conjunto 1: ");
	imprimir(ptrConjunto1);
	
	printf("\nElementos del conjunto 2: ");
	imprimir(ptrConjunto2);
	
	/*Calculamos la interseccion y Union*/
	crear_lista(&ptrInterseccion);
	crear_lista(&ptrUnion);
	
	ptrRecorrido = ptrConjunto1;
	while (ptrRecorrido){
		if (esta_en_lista(ptrConjunto2,ptrRecorrido->elem)){
			insertar_final(&ptrInterseccion,ptrRecorrido->elem);
		}
		insertar_final(&ptrUnion,ptrRecorrido->elem);
		ptrRecorrido = ptrRecorrido->sig;
	}
	
	ptrRecorrido = ptrConjunto2;
	while (ptrRecorrido){
		if (!esta_en_lista(ptrConjunto1,ptrRecorrido->elem)){
			insertar_final(&ptrUnion,ptrRecorrido->elem);
		}
		ptrRecorrido = ptrRecorrido->sig;
	}
	
	printf("La interseccion es: ");
	imprimir(ptrInterseccion);
	
	printf("La union es: ");
	imprimir(ptrUnion);
	
	finalizar_lista(ptrConjunto1);
	finalizar_lista(ptrConjunto2);
	finalizar_lista(ptrInterseccion);
	finalizar_lista(ptrUnion);
	return 0;
}
