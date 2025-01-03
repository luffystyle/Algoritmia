#include <iostream>
using namespace std;

typedef int Elemento;

typedef struct nodo {
    Elemento elem;
    struct nodo *ant;
    struct nodo *sig;
}Nodo;

typedef struct{
    Nodo *cabeza;
    int longitud;
} Lista;

void construir(Lista *pL) {
    pL->cabeza = NULL;
    pL->longitud = 0;
}

bool esListaVacia(Lista Lista) {
    if( Lista.cabeza == NULL) return true;
    else return false;
}

int obtenerLongitud(Lista lista) {
    return lista.longitud;
}

Nodo* crearNodo(Elemento elem, Nodo *direcAnterior, Nodo *direcSig) {
    Nodo *p;
    p = new Nodo;
    p->elem = elem;
    p->ant = direcAnterior;
    p->sig = direcSig; 
    return p;
}

void insertarComienzo(Lista *pL, Elemento elem) {
    Nodo *p, *pSiguiente;
    p = crearNodo(elem, NULL, pL->cabeza);// si fuese un solo nodo, el sig y el ant serian NULL
    if( !esListaVacia(*pL)) {
        pSiguiente = pL->cabeza;
        pSiguiente->ant = p;
    }
    pL->cabeza = p;
    pL->longitud ++;   
}

void mostrar( Lista L )
{
    Nodo *p;
    int i;
    if ( esListaVacia(L) )
        cout << "Lista vacia" << endl;
    else
    {
        p = L.cabeza;
        for(i=1; i<=L.longitud; i++)
        {
            cout << p->elem << "  ";
            p = p->sig;
        }
        cout << endl;
    }
}

Nodo* ubicarUltimo( Lista L )
{
    int i;
    Nodo *pU;
    if ( esListaVacia(L) )
        return NULL;
    else
    {
        pU = L.cabeza;
        for(i=1;i<=L.longitud-1;i++)
            pU = pU->sig;
        return pU;
    }
}

void mostrarAlReves(Lista L) {
    
    Nodo *pU;
    
    if(esListaVacia(L)) {
        cout << "La  lista está vacía" << endl;
    } else {
        pU = ubicarUltimo(L);
        for( int i = 1; i <= L.longitud ; i ++) {
            cout << pU->elem << " ";
            pU = pU->ant;
        }
        cout << endl;
    }    
}

Nodo *ubicar(Lista L, Elemento elemento) {
    Nodo *p;
    if(esListaVacia(L)) {
        cout << "No se encontró el nodo" <<endl;
        return NULL;
    } else {
        p = L.cabeza;
        for( int i = 1; i <= L.longitud; i++) {
            if(p->elem == elemento) break;
            p = p->sig;
        }
        return p;
    }
    return NULL;
}

void eliminarNodo(Lista *pL, Elemento elem) {
    Nodo *pAnterior, *p, *pSiguiente;
    
    p = ubicar(*pL, elem); 
    if(p == NULL) { // si tiene un solo Nodo
        cout << "No esta en la lista " << elem;
    } else{
        pAnterior = p->ant;
        pSiguiente = p->sig;
        if(pAnterior == NULL ) pL->cabeza = pSiguiente;
        else pAnterior->sig = pSiguiente;
        if(pSiguiente != NULL) pSiguiente->ant = pAnterior;
        delete p;
        pL->longitud--;
    } 
}

void destruirLista(Lista *pL) {
    Nodo *p, *pAux;
    if(esListaVacia(*pL)){
        cout << "La lista está vacía, no podemos seguir desytruyendola" << endl;
    } else {
        p = pL->cabeza;
        for( int i = 1; i <= pL->longitud; i++) {
            pAux = p;
            delete p;
            p = pAux->sig;
        }
        pL->cabeza = NULL;
    }
}

int main(int argc, char** argv) {

    Lista LDoble;
    construir(&LDoble);
    mostrar(LDoble);
    insertarComienzo(&LDoble, 90);
    insertarComienzo(&LDoble, 57);
    insertarComienzo(&LDoble, 29);
    insertarComienzo(&LDoble, 44);
    insertarComienzo(&LDoble, 70);
    mostrar(LDoble);
    //mostrarAlReves(LDoble);
    
    eliminarNodo(&LDoble, 90);
    mostrar(LDoble);
    eliminarNodo(&LDoble, 57);
    mostrar(LDoble);
    eliminarNodo(&LDoble, 29);
    mostrar(LDoble);
    eliminarNodo(&LDoble, 44);
    mostrar(LDoble);
    eliminarNodo(&LDoble, 70);
    mostrar(LDoble);

//    destruirLista(&LDoble);
//    mostrar(LDoble);
    return 0;
}

