#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

struct NodoArbol{
    int elemento;  //Este dato representa el Elemento, que en este caso es el Lote
    int cantidad;  //Parte a. Este dato es la cantidad adicional que nos pide el enunciado
    struct NodoArbol * izquierda;  //puntero al hijo izquierdo
    struct NodoArbol * derecha;   //puntero al hijo derecho
};

struct ArbolBinario{
    struct NodoArbol * raiz;
};

struct ArbolBinarioBusqueda{
    struct ArbolBinario arbolBinario;
};

struct Nodo{
    struct NodoArbol * nodo; /*aquí se cambia por el Elemento que se desee manejar*/
    struct Nodo * siguiente;
};

struct Lista{
    struct Nodo * cabeza;
    struct Nodo * cola;
    int longitud;
};

struct Cola{
    struct Lista lista;
};

struct Pila{
    struct Lista lista;
};

/*Valores iniciales de la lista*/
void construir(struct Lista & lista){
    lista.cabeza = NULL;
    lista.cola = NULL;
    lista.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
bool esListaVacia( struct Lista  lista){
    return lista.cabeza == NULL;
}

/*DEVUELVE LA CANTIDAD DE ELEMENTOS DE LA LISTA*/
int longitud(struct Lista tad ){
    return tad.longitud;
}

/*CREA UN NUEVO ELEMENTO CON VALORES INICIALES*/
struct Nodo * crearNodo(struct NodoArbol * nodo, struct Nodo * siguiente){

    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->nodo = nodo;
    nuevoNodo->siguiente = siguiente; 
    return nuevoNodo;
}

/*INSERTA UN ELEMENTO AL FINAL DE LA LISTA*/
void insertarAlFinal(struct Lista & lista, struct NodoArbol * nodo){
   
    struct Nodo * nuevoNodo = crearNodo(nodo, NULL);
    Nodo * ultimoNodo = lista.cola; /*obtiene el último nodo*/
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

struct NodoArbol * retornaCabeza( struct Lista  lista){
    if (esListaVacia(lista)){
        cout<<"No existe la cabeza por que la cola está vacía"<<endl;
        exit(1);
    }
   
    return lista.cabeza->nodo;
}

/*ELIMINA EL PRIMER ELEMENTO DE LA LISTA*/
void eliminaCabeza(struct Lista  & lista){
    struct Nodo * nodoEliminar = lista.cabeza;
    if (nodoEliminar == NULL ){
        cout<<"No se puede eliminar la cabeza pues la lista estÃ¡ vacÃ­a";
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

void imprime(struct Lista lista){
       
    if (esListaVacia(lista)){
        cout<<"La cola esta vacía"<<endl;
    }
    else{
        struct Nodo * recorrido = lista.cabeza;
        while(recorrido != NULL){
           // imprimeNodo(recorrido->nodo);
            recorrido = recorrido->siguiente;
        }   
    }
    cout<<endl;
}

void construir(struct Cola & cola){
    construir(cola.lista);
}

bool esColaVacia( struct Cola  cola){
    return esListaVacia(cola.lista);
}

int longitud(struct Cola cola){
    return longitud(cola.lista);
}

void encolar(struct Cola & cola, struct NodoArbol * nodo){
    insertarAlFinal(cola.lista, nodo);
}

struct NodoArbol *  desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(1);
    }
    
    struct NodoArbol * nodo = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return nodo;
}

void destruirCola(struct Cola & cola){
    destruirLista(cola.lista);
}

void imprime( struct Cola  cola){
    imprime(cola.lista);
}

/*Valores iniciales de la lista*/
void construirP(struct Lista & tad){
    tad.cabeza = NULL;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
bool esListaVaciaP(struct Lista  tad){
    return tad.cabeza == NULL;
}

/*devuelve la longitud de la lista*/
int longitudP( struct Lista tad){
    return tad.longitud;
}

struct NodoArbol * retornaCabezaP(struct Lista tad){
    if (esListaVaciaP(tad)){
        cout<<"No existe la cabeza por que la cola está vacía"<<endl;
        exit(1);
    }
    return tad.cabeza->nodo;
}

/*Crea un nuevo nodo con los datos dados como parÃ¡metros*/
struct Nodo * crearNodoP(struct NodoArbol * nodo, struct Nodo * siguiente){
    
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->nodo = nodo;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & tad, struct NodoArbol * nodo){
  
    /*Crea un nuevo nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo = crearNodoP(nodo, tad.cabeza);
    
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

void eliminaCabezaP(struct Lista  & lista){
    struct Nodo * nodoEliminar = lista.cabeza;
    if (nodoEliminar == NULL ){
        cout<<"No se puede eliminar la cabeza pues la lista estÃ¡ vacÃ­a";
        exit(1);
    }
    else{
        lista.cabeza = lista.cabeza->siguiente;
        delete nodoEliminar;
        lista.longitud--;
    }
}

void destruir(struct Lista & tad){
    /*recorrido apunta al inicio del tad*/
    struct Nodo * recorrido = tad.cabeza;
    
    while(recorrido != NULL){
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;        
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    tad.cabeza = NULL;
    tad.longitud = 0;
}

void imprimeNodo(struct NodoArbol * nodo){
    cout<<setw(5)<<nodo->elemento;
}

void imprimeNodoNew(struct NodoArbol * nodo){
    cout<<setw(5)<<nodo->elemento << "-" << nodo->cantidad << " ";
}

/*Recordar que las Pilas no se recorren en forma secuencial*/
/*Se va utilizar solo para mostrar los valores*/
void imprimeP( struct Lista  tad){

    if (esListaVaciaP(tad)){
        cout<<"La Pila está vacía"<<endl;
    }
    else{
        
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout<<"[";

        while(recorrido != NULL){
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout<<", ";
            estaImprimiendoLaCabeza = 0;
            imprimeNodo(recorrido->nodo);    
            recorrido = recorrido->siguiente;
        }
        cout<<"]"<<endl;
    }
}

/*constructor de Pila*/
void construir(struct Pila & pila){
    construirP(pila.lista);
}

/*Determina si la pila está vacía*/
bool esPilaVacia( struct Pila  pila){
    return esListaVaciaP(pila.lista);
}

/*Determina el número de elementos de la pila*/
int longitud( struct Pila   pila){
    return longitudP(pila.lista);
}

/*push, añade un elemento a la parte superior de la pila*/
void apilar(struct Pila & pila, struct NodoArbol * nodo){
    insertarAlInicio(pila.lista, nodo);
}


/*examina un elemento situado en la parte superior de la pila*/
struct NodoArbol * cima(struct Pila pila){
    if (esPilaVacia(pila)){
	cout<<"La pila está vacía por lo tanto no posee cima"<<endl;
	exit(12);
    }		
    return retornaCabezaP(pila.lista);
}
/*pop, elimina un elemento de la parte superior de la pila*/
struct NodoArbol * desapilar(struct Pila & pila){
    if (esPilaVacia(pila)){
        cout<<"La pila está vacía, por lo tanto no se puede desapilar"<<endl;
	exit(11);
    }	
    struct NodoArbol * nodo = cima(pila);
    eliminaCabezaP(pila.lista);
    return nodo;
}

/*destruye la pila*/
void destruirPila(struct Pila pila){
    destruir(pila.lista);
}

/*Recordar que las Pilas no se recorren en forma secuencial*/
/*Se va utilizar solo para mostrar los valores*/
void imprimir(const struct Pila & pila){
    imprimeP(pila.lista);
}

///*imprime desapilando*/
//void imprime(struct Pila & pila){
//    
//    while(not esPilaVacia(pila)){
//        cout<<cima(pila)<<"-";
//        desapilar(pila);
//    }
//}

void construir(struct ArbolBinario & arbol ){
    arbol.raiz = NULL;
}

bool esNodoVacio(struct NodoArbol * nodo){
    return nodo == NULL;
}

bool esArbolVacio( struct ArbolBinario arbol){
    return esNodoVacio(arbol.raiz);
}

struct NodoArbol * crearNuevoNodoArbol(struct NodoArbol * arbolIzquierdo, 
                               int elemento, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct NodoArbol * arbolIzquierdo,
                         int elemento, struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo, elemento, arbolDerecho);
    arbol.raiz = nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct ArbolBinario arbolIzquierdo,
                         int elemento, struct ArbolBinario arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo.raiz, elemento, arbolDerecho.raiz);
    arbol.raiz = nuevoNodo;
}

int raiz(struct NodoArbol * nodo){
    if (esNodoVacio(nodo)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    return nodo->elemento;
}

struct NodoArbol * hijoDerecho(struct ArbolBinario arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    return arbol.raiz->derecha;
}

struct  NodoArbol * hijoIzquierdo(struct ArbolBinario arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    
    return arbol.raiz->izquierda;
 }

void imprimeRaiz(struct ArbolBinario arbol){
    imprimeNodo(arbol.raiz);
}

void recorrerEnOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimeNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

/*En árbol, se lleva a cabo visitando el hijo izquierdo del nodo, luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerEnOrden(struct ArbolBinario arbol){
    /*Imprime en orden*/
    if (not esArbolVacio(arbol)){
        recorrerEnOrdenRecursivo(arbol.raiz);
    }
    cout<<endl;
}

void recorrerEnPreOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        imprimeNodo(nodo);
        recorrerEnPreOrdenRecursivo(nodo->izquierda);
        recorrerEnPreOrdenRecursivo(nodo->derecha);
    }
}

void recorrerEnPreOrdenRecursivoNew(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        imprimeNodoNew(nodo);
        recorrerEnPreOrdenRecursivoNew(nodo->izquierda);
        recorrerEnPreOrdenRecursivoNew(nodo->derecha);
    }
}

/*recorrido descendente, se lleva a cabo visitando cada nodo, seguido de sus hijos,
 luego todos los restantes, comenzando por la raíz*/
void recorrerPreOrden(struct ArbolBinario arbol){
    if (not esArbolVacio(arbol)){
        recorrerEnPreOrdenRecursivo(arbol.raiz);
    }
    cout<<endl;
}

void recorrerPreOrdenNew(struct ArbolBinario arbol){
    if (not esArbolVacio(arbol)){
        recorrerEnPreOrdenRecursivoNew(arbol.raiz);
    }
    cout<<endl;
}

void recorrerEnPostOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        recorrerEnPostOrdenRecursivo(nodo->izquierda);
        recorrerEnPostOrdenRecursivo(nodo->derecha);
        imprimeNodo(nodo);
    }
}

/*recorrido ascendente, se lleva a cabo visitando los hijos, y luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerPostOrden(struct ArbolBinario arbol){
   
    if (not esArbolVacio(arbol)){
        recorrerEnPostOrdenRecursivo(arbol.raiz);
    }
    cout<<endl;
}

int maximo(int a, int b){
    return a>=b ? a: b;
}

int alturaRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if(esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 0; 
    else
        return 1 + maximo( alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int altura(struct ArbolBinario arbol){
    return alturaRecursivo(arbol.raiz); //como el arbol ha sido construido no va apuntar a NULL
}

int numeroNodosRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);   
}

/*Determina el número de elementos del árbol*/
int numeroNodos(struct ArbolBinario arbol){
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if ( esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha) )
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}

int numeroHojas(struct ArbolBinario arbol){
    return numeroHojasRecursivo(arbol.raiz);
}

int sumarNodosRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else
        return nodo->elemento + sumarNodosRecursivo(nodo->izquierda) + sumarNodosRecursivo(nodo->derecha);
}

int sumarNodos(struct ArbolBinario arbol){
    return sumarNodosRecursivo(arbol.raiz);
}

int esEquilibradoRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 1;
    else{
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia<=1 and 
               esEquilibradoRecursivo(nodo->izquierda) and 
               esEquilibradoRecursivo(nodo->derecha);
    }        
}

int esEquilibrado(struct ArbolBinario arbol ){
    return esEquilibradoRecursivo(arbol.raiz);
}

int esHoja(struct ArbolBinario arbol){
    if(esArbolVacio(arbol))
        return 0;
    else
        return esNodoVacio(arbol.raiz->izquierda) and esNodoVacio(arbol.raiz->derecha);
}

void destruirRecursivo(struct NodoArbol * nodo){
    if(not (esNodoVacio(nodo))){
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
        nodo = NULL;
    }
}

void destruirArbolBinario(struct ArbolBinario arbol){
    destruirRecursivo(arbol.raiz);
    arbol.raiz = NULL;
}

/*recorre el árbol por niveles usando una cola*/
void recorridoPorNivel(struct ArbolBinario arbol){
    struct Cola cola; /*Se usa una cola para acceder a los nodos*/
    construir(cola);
    if(not esArbolVacio(arbol)){
        encolar(cola, arbol.raiz);
        while(not esColaVacia(cola)){
            struct NodoArbol * nodo = desencolar(cola);
            imprimeNodo(nodo);
            if (not esNodoVacio(nodo->izquierda)){
                encolar(cola, nodo->izquierda);
            }
            if (not esNodoVacio(nodo->derecha)){
                encolar(cola, nodo->derecha);  
            }
        }
    }
    cout<<endl;
    destruirCola(cola);   
}

void enOrdenIterativo(struct ArbolBinario arbol){
    struct Pila pila; /*Se usa una pila para acceder a los nodos*/
    construir(pila);
    int fin = 0;
    do{
        while (not esArbolVacio(arbol)){
            apilar(pila, arbol.raiz);
            arbol.raiz = arbol.raiz->izquierda;
        }
        if (esPilaVacia(pila))
            fin = 1;
        else{
            arbol.raiz = desapilar(pila);
            imprimeRaiz(arbol);
            arbol.raiz = arbol.raiz->derecha;
        }
    } while(fin == 0);
    destruirPila(pila);
    cout<<endl;
}

void preOrdenIterativo(struct ArbolBinario arbol){
    struct Pila pila;  /*Se usa una pila para acceder a los nodos*/
    construir(pila);
    if (not esArbolVacio(arbol)){        
        apilar(pila, arbol.raiz);
        while(not esPilaVacia(pila)){
            struct NodoArbol * nodo = desapilar(pila);
            imprimeNodo(nodo);
            if (not esNodoVacio(nodo->derecha))
                apilar(pila, nodo->derecha);
            if (not esNodoVacio(nodo->izquierda))
                apilar(pila, nodo->izquierda);           
        }
    }
    cout<<endl;
    destruirPila(pila);   
}

void construir(struct ArbolBinarioBusqueda & arbol){
    construir(arbol.arbolBinario);
}

bool esArbolVacio(struct ArbolBinarioBusqueda  arbol){
    esArbolVacio(arbol.arbolBinario);
}

void plantarArbolBB(struct NodoArbol *& arbol, 
                         struct NodoArbol * arbolIzquierdo, int elemento, 
                         struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    arbol = nuevoNodo;
}

/*Parte a*/
void plantarArbolBBNew(struct NodoArbol *& arbol, 
                         struct NodoArbol * arbolIzquierdo, int elemento, int cantidad, 
                         struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->cantidad = cantidad;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    arbol = nuevoNodo;
}

void insertarRecursivo(struct NodoArbol *& raiz, int elemento){
    if(raiz == NULL)
        plantarArbolBB(raiz, NULL, elemento, NULL);
    else
        if (raiz->elemento > elemento)
            insertarRecursivo(raiz->izquierda, elemento);
        else
            insertarRecursivo(raiz->derecha, elemento);
}

/*Parte a*/
void insertarRecursivoNew(struct NodoArbol *& raiz, int elemento, int cantidad){
    if(raiz == NULL)
        plantarArbolBBNew(raiz, NULL, elemento, cantidad, NULL);
    else
        if (raiz->elemento > elemento)
            insertarRecursivoNew(raiz->izquierda, elemento, cantidad);
        else
            insertarRecursivoNew(raiz->derecha, elemento, cantidad);
}

void insertar(struct ArbolBinarioBusqueda & arbol, int elemento){
    insertarRecursivo(arbol.arbolBinario.raiz, elemento);
}

/*Parte a*/
void insertarNew(struct ArbolBinarioBusqueda & arbol, int elemento, int cantidad){
    insertarRecursivoNew(arbol.arbolBinario.raiz, elemento, cantidad);
}

/*Parte c*/
void enOrden(struct ArbolBinarioBusqueda arbol){
    recorrerEnOrden(arbol.arbolBinario);
}

void preOrden(struct ArbolBinarioBusqueda arbol){
    recorrerPreOrden(arbol.arbolBinario);
}

void preOrdenNew(struct ArbolBinarioBusqueda arbol){
    recorrerPreOrdenNew(arbol.arbolBinario);
}

void postOrden(struct ArbolBinarioBusqueda arbol){
    recorrerPostOrden(arbol.arbolBinario);
}

void destruirArbolBB(struct ArbolBinarioBusqueda arbol){
    destruirArbolBinario(arbol.arbolBinario);
}

int minimoABBRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo)){
        cout<<"El árbol está vacío"<<endl;
        exit(1);
    }
    if(esNodoVacio(nodo->izquierda))
        return nodo->elemento;
    minimoABBRecursivo(nodo->izquierda);
}

int comparaABB(int elementoA, int elementoB ){
    if(elementoA == elementoB) return 0;
    else if(elementoA < elementoB) return -1;
    else if (elementoA > elementoB) return 1;
}

int minimoABB(struct ArbolBinarioBusqueda arbol){
    return minimoABBRecursivo(arbol.arbolBinario.raiz);
}

int maximoABBRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo)){
        cout<<"El árbol está vacío"<<endl;
        exit(1);
    }
    if(esNodoVacio(nodo->derecha))
        return nodo->elemento;
    maximoABBRecursivo(nodo->derecha);
}

int maximoABB(struct ArbolBinarioBusqueda arbol){
    return maximoABBRecursivo(arbol.arbolBinario.raiz);
}

/*Parte b*/

struct NodoArbol *  minimoArbol(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->izquierda))
        return nodo;
    minimoArbol(nodo->izquierda);
}

struct NodoArbol * borraNodoRecursivo(struct NodoArbol * nodo, int dato){
    if(esNodoVacio(nodo))
        return nodo;
    if(comparaABB(nodo->elemento, dato) == 1){ //nodo mayor que el dato
        nodo->izquierda = borraNodoRecursivo(nodo->izquierda, dato);
    }
    else{
        if(comparaABB(nodo->elemento, dato) == -1){ //nodo menor que el dato
            nodo->derecha = borraNodoRecursivo(nodo->derecha, dato);
        }
        else{
            if(esNodoVacio(nodo->izquierda)){
                struct NodoArbol * elimina = nodo->derecha;
                delete nodo;
                nodo = NULL;
                return elimina;
            }
            else{
                if(esNodoVacio(nodo->derecha)){
                    struct NodoArbol * elimina = nodo->izquierda;
                    delete nodo;
                    nodo = NULL;
                    return elimina;
                }
                else{
                    struct NodoArbol * temp = minimoArbol(nodo->derecha);
                    nodo->elemento = temp->elemento;
                    nodo->derecha = borraNodoRecursivo(nodo->derecha, temp->elemento);
                }
            }
        }
    }
    return nodo;
}

void borraNodo(struct ArbolBinarioBusqueda &arbol, int dato){
    arbol.arbolBinario.raiz = borraNodoRecursivo(arbol.arbolBinario.raiz, dato);
}

bool buscaArbolRecursivo(struct NodoArbol * nodo, int dato){
    if(esNodoVacio(nodo)){
        return false;
    } 
    if(comparaABB(nodo->elemento, dato) == 0)
        return true;
    if(comparaABB(nodo->elemento, dato) == 1)
        return buscaArbolRecursivo(nodo->izquierda, dato);
    else
        if(comparaABB(nodo->elemento, dato) == -1) 
            return buscaArbolRecursivo(nodo->derecha, dato);
}

bool buscaArbol(struct ArbolBinarioBusqueda arbol ,int dato){
    return buscaArbolRecursivo(arbol.arbolBinario.raiz, dato);
}
void recorridoPorNivel(struct ArbolBinarioBusqueda arbol){
    recorridoPorNivel(arbol.arbolBinario);
}

int sumarNodos(struct ArbolBinarioBusqueda arbol){
    return sumarNodos(arbol.arbolBinario);
}

int main(){
	struct ArbolBinarioBusqueda arbol;
	construir(arbol);
	insertarNew(arbol, 20170620, 20);
	insertarNew(arbol, 20170810, 20);
	insertarNew(arbol, 20180211, 20);
	insertarNew(arbol, 20180409, 10);
	preOrdenNew(arbol);
	/*Parte c*/
	int cantProductos = 35;
	while (cantProductos>0){
		NodoArbol *loteMinimo = minimoArbol(arbol.arbolBinario.raiz);
		if (loteMinimo->cantidad <= cantProductos){
			cantProductos = cantProductos - loteMinimo->cantidad;
			borraNodo(arbol,loteMinimo->elemento);
		}
		else {
			loteMinimo->cantidad = loteMinimo->cantidad - cantProductos;
			cantProductos = 0;
		}
	}
	preOrdenNew(arbol);
	return 0;
}
