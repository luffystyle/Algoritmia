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

struct Pila{
    struct Lista lista;
};


struct Cola{
    struct Lista lista;
};


///////////////////////
//// INICIO LISTAS ////
///////////////////////

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


/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & tad, int elemento){
  
    /*Crea un nuevo nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo = crearNodo(elemento, tad.cabeza);
    
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}


/*INSERTA UN ELEMENTO AL FINAL DE LA LISTA*/
void insertarAlFinal(struct Lista & lista, int elemento){
    struct Nodo * nuevoNodo = crearNodo(elemento, NULL);
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

int retornaCabeza(const struct Lista & lista){
    if (esListaVacia(lista)){
        cout<<"No existe la cabeza por que la cola está vacía"<<endl;
        exit(1);
    }
    return lista.cabeza->elemento;
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
        cout<<"La cola esta vacía"<<endl;
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
////////////////////
//// FIN LISTAS ////
////////////////////


//////////////////////
//// INICIO COLAS ////
//////////////////////
void construir(struct Cola & cola){
    construir(cola.lista);
}

bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

int longitud(struct Cola cola){
    return longitud(cola.lista);
}

void encolar(struct Cola & cola, int elemento){
    insertarAlFinal(cola.lista, elemento);
}

int desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(1);
    }
    int elemento = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return elemento;
}

void imprime(const struct Cola & cola){
    imprime(cola.lista);
}

void destruirCola(struct Cola & cola){
    destruirLista(cola.lista);
}
///////////////////
//// FIN COLAS ////
///////////////////


//////////////////////
//// INICIO PILAS ////
//////////////////////

/*constructor de Pila*/
void construir(struct Pila & pila){
    construir(pila.lista);
}

/*Determina si la pila está vacía*/
bool esPilaVacia(const struct Pila & pila){
    return esListaVacia(pila.lista);
}

/*Determina el número de elementos de la pila*/
int longitud(const struct Pila  & pila){
    return longitud(pila.lista);
}

/*examina un elemento situado en la parte superior de la pila*/
int cima(const struct Pila & pila){
    if (esPilaVacia(pila)){
	cout<<"La pila está vacía por lo tanto no posee cima"<<endl;
	exit(12);
    }		
    return retornaCabeza(pila.lista);
}


/*push, añade un elemento a la parte superior de la pila*/
void apilar(struct Pila & pila, int elemento){
    insertarAlInicio(pila.lista, elemento);
  //  cout<<"Apilar: "<<elemento<<endl;
}

/*pop, elimina un elemento de la parte superior de la pila*/
int desapilar(struct Pila & pila){
    if (esPilaVacia(pila)){
        cout<<"La pila está vacía, por lo tanto no se puede desapilar"<<endl;
	exit(11);
    }	
    int elemento = cima(pila);
    eliminaCabeza(pila.lista);
    return elemento;
}


/*destruye la pila*/
void destruirPila(struct Pila & pila){
    destruir(pila.lista);
}

/*Recordar que las Pilas no se recorren en forma secuencial*/
/*Se va utilizar solo para mostrar los valores*/
void imprimir(const struct Pila & pila){
    imprime(pila.lista);
}

///*imprime desapilando*/
//void imprime(struct Pila & pila){
//    
//    while(not esPilaVacia(pila)){
//        cout<<cima(pila)<<"-";
//        desapilar(pila);
//    }
//}

///////////////////
//// FIN PILAS ////
///////////////////


void distribuir(Cola & ptrCola, int n){
	int i, valor,longitud_lote;	
	Pila paux;
	construir(paux); 
	
	longitud_lote=longitud(ptrCola)/3;

	//Eliminamos el lote TIPO C, es decir los que son mayores a 30
	for (i=0; i<n;i++){
		valor=desencolar(ptrCola);
		if (valor<30)
			encolar(ptrCola,valor);
	}
	cout<<endl<<"Eliminamos Tipo C"<<endl;
	cout<<"Cola: ";
	imprime(ptrCola);
	cout<<"Pila: ";
	imprimir(paux);
	
	//Desencolamos Tipo A y apilamos
	for (i=0; i<longitud_lote;i++){
		apilar(paux,desencolar(ptrCola));
	}
	
	cout<<endl<<"Desencolamos Tipo A y apilamos"<<endl;
	cout<<"Cola: ";
	imprime(ptrCola);
	cout<<"Pila: ";
	imprimir(paux);
	
	//Desapilamos Tipo A y encolamos
	for (i=0; i<longitud_lote;i++){
		encolar(ptrCola,desapilar(paux));
	}
	
	cout<<endl<<"Desapilamos Tipo A y encolamos"<<endl;
	cout<<"Cola: ";
	imprime(ptrCola);
	cout<<"Pila: ";
	imprimir(paux);
	
	//Desencolamos Tipo B y apilamos
	for (i=0; i<longitud_lote;i++){
		apilar(paux,desencolar(ptrCola));
	}
	
	cout<<endl<<"Desencolamos Tipo B y apilamos"<<endl;
	cout<<"Cola: ";
	imprime(ptrCola);
	cout<<"Pila: ";
	imprimir(paux);
	
	//Combinamos un elemento de la pila y luego un elemento de la cola
	//1. Desapilamos Tipo B y encolamos
	//2. Desencolamos Tipo A y encolamos
	for (i=0; i<longitud_lote;i++){
		encolar(ptrCola,desapilar(paux));
		encolar(ptrCola,desencolar(ptrCola));
	}
	
	cout<<endl<<"Combinamos un elemento de la pila y luego un elemento de la cola"<<endl;
	cout<<"Cola: ";
	imprime(ptrCola);
	cout<<"Pila: ";
	imprimir(paux);
	
	//Desencolamos TODA la cola y apilamos
	for (i=0; i<longitud_lote*2;i++){
		apilar(paux,desencolar(ptrCola));
	}
	
	cout<<endl<<"Desencolamos TODA la cola y apilamos"<<endl;
	cout<<"Cola: ";
	imprime(ptrCola);
	cout<<"Pila: ";
	imprimir(paux);
	
	//Desapilamos TODA la pila y encolamos
	for (i=0; i<longitud_lote*2;i++){
		encolar(ptrCola,desapilar(paux));
	}
	cout<<endl<<"Desapilamos TODA la pila y encolamos;"<<endl;
	cout<<"Cola: ";
	imprime(ptrCola);
	cout<<"Pila: ";
	imprimir(paux);
	
	//Liberamos memoria de la Pila auxiliar
	destruirPila(paux);
	
}

int main(int argc, char** argv) {
    Cola ptrCola;
    int n;
	
    construir(ptrCola);
    encolar(ptrCola, 11);//A1
    encolar(ptrCola, 12);//A2
    encolar(ptrCola, 13);//A3
    encolar(ptrCola, 14);//A4
    encolar(ptrCola, 21);//B1
    encolar(ptrCola, 22);//B2
    encolar(ptrCola, 23);//B3
    encolar(ptrCola, 24);//B4
    encolar(ptrCola, 31);//C1
    encolar(ptrCola, 32);//C2
    encolar(ptrCola, 33);//C3
    encolar(ptrCola, 34);//C4

    imprime(ptrCola);
    cout << endl;

    distribuir(ptrCola, 12);
    cout << endl;

    imprime(ptrCola);

    return 0;
}

