#include <iostream>

using namespace std;

struct Nodo{
    int elemento;
    struct Nodo * siguiente;
};

struct Lista{
    struct Nodo * cabeza;
    struct Nodo * cola;
    int longitud;
};

/*Valores iniciales de la lista*/
void construir(struct Lista & lista){
    lista.cabeza = NULL;
    lista.cola = NULL;
    lista.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
bool esListaVacia(const struct Lista & lista){
    return lista.cabeza == NULL;
}

/*DEVUELVE LA CANTIDAD DE ELEMENTOS DE LA LISTA*/
int longitud(struct Lista tad ){
    return tad.longitud;
}

/*CREA UN NUEVO ELEMENTO CON VALORES INICIALES*/
struct Nodo * crearNodo(int elemento, struct Nodo * siguiente){

    struct Nodo * nuevoNodo = new struct Nodo;
    
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente; 
    return nuevoNodo;
}


/*INSERTA UN ELEMENTO AL FINAL DE LA LISTA*/
void insertarAlFinal(struct Lista & lista, int elemento){
    struct Nodo * nuevoNodo = crearNodo(elemento, NULL);
    Nodo * ultimoNodo = lista.cola; /*obtiene el Ãºltimo nodo*/
    if (ultimoNodo == NULL){
        lista.cabeza = nuevoNodo;
        lista.cola = nuevoNodo;
    }
    else{
        ultimoNodo->siguiente = nuevoNodo;
        lista.cola = nuevoNodo;
    }            
    lista.longitud++;  
}

int retornaCabeza(const struct Lista & lista){
    if (esListaVacia(lista)){
        cout<<"No existe la cabeza por que la lista está vacía"<<endl;
        exit(1);
    }
    return lista.cabeza->elemento;
}

/*ELIMINA EL PRIMER ELEMENTO DE LA LISTA*/
void eliminaCabeza(struct Lista  & lista){
    struct Nodo * nodoEliminar = lista.cabeza;
    if (nodoEliminar == NULL ){
        cout<<"No se puede eliminar la cabeza pues la lista está vacía";
        exit(1);
    }
    else{
        lista.cabeza = lista.cabeza->siguiente;
        if(lista.cabeza == NULL)
            lista.cola = NULL;
        delete nodoEliminar;
        lista.longitud--;
    }
}

/*LIBERA LA MEMORIA*/
void destruirLista(struct Lista & tad){
    struct Nodo * recorrido = tad.cabeza;
    struct Nodo * eliminarNodo;
    
    while(recorrido != NULL){
        eliminarNodo = recorrido;        
        recorrido = recorrido->siguiente;
        delete eliminarNodo;
    }
    tad.cabeza = NULL;
    tad.cola = NULL;
    tad.longitud = 0;
}

void imprime(const struct Lista & lista){
       
    if (esListaVacia(lista)){
        cout<<"La lista esta vacía"<<endl;
    }
    else{
        struct Nodo * recorrido = lista.cabeza;
        while(recorrido != NULL){
            cout<<recorrido->elemento<<" ";
            recorrido = recorrido->siguiente;
        }   
    }
    cout<<endl;
}


void invierte(Lista &ptrLista)
{   Nodo *ptrrec,*ptrant=NULL,*ptrini;
    int i,j,n;
    
    n = ptrLista.longitud;
    for(i=1;i<n;i++)
    {   ptrrec=ptrLista.cabeza;
        for(j=i;j<n;j++)
        {   ptrant=ptrrec; 
            ptrrec=ptrrec->siguiente;
        }
        if(i==1)
            ptrini=ptrrec;
        ptrrec->siguiente=ptrant;
    }
    if(i!=1)
        ptrant->siguiente=NULL;
    ptrLista.cabeza=ptrini;
}

Nodo* recorre(Nodo* ptrlista){
    Nodo* ptrini;
    
    if(ptrlista==NULL) return NULL;
    if(ptrlista->siguiente == NULL) return ptrlista;
    ptrini = recorre(ptrlista->siguiente);
    ptrlista->siguiente->siguiente = ptrlista;
    ptrlista->siguiente = NULL;
    return ptrini;
}

void invierterec(Lista &ptrlista){
    Nodo *ptrini;
    
    ptrini = recorre(ptrlista.cabeza);
    
    ptrlista.cabeza = ptrini;
}





int main(int argc, char** argv) {
    Lista lista1;
    
    construir(lista1);
    imprime( lista1 );
    insertarAlFinal( lista1, 50);
    insertarAlFinal( lista1, 37);
    insertarAlFinal( lista1, 23);
    insertarAlFinal( lista1, 59);
    imprime( lista1 );

    invierte(lista1);
    imprime( lista1 );
    invierterec(lista1);
    imprime( lista1 );
    
    return 0;
}


