#include <iostream>
#include <cstdlib>

#define N 7

using namespace std;

/*Parte a, faltaria incluir la sucursal*/
struct Nodo{
    int elemento; /*Recuerde que este es el dato o los datos que maneja el nodo*/
    struct Nodo * siguiente;
};

/*Parte a*/
struct Lista{
    struct Nodo * cabeza;
    struct Nodo * cola;
    int longitud;
};

/*Parte a*/
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

void construir(struct Cola & cola){
    construir(cola.lista);
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
    Nodo * ultimoNodo = lista.cola; /*obtiene el �ltimo nodo*/
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
        cout<<"No existe la cabeza por que la cola est� vac�a"<<endl;
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
        cout<<"La cola esta vac�a"<<endl;
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

int buscaElemento(int elemento, const struct Lista & lista){
	if (esListaVacia(lista)){
        cout<<"La Lista esta vac�a"<<endl;
    }
    else{
        struct Nodo * recorrido = lista.cabeza;
        while(recorrido != NULL){
            if (recorrido->elemento == elemento){
            	return 1;
			}
            recorrido = recorrido->siguiente;
        }   
    }	
    return 0;
}

/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & tad, int elemento){
    /*Crea un nuevo nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo = crearNodo(elemento, tad.cabeza);
    
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

void eliminaNodo(struct Lista & tad, int elemento){
	struct Nodo * ultimo = NULL;
	struct Nodo * recorrido = tad.cabeza;
	/*Avanzo hasta encontrar el elemento*/
	/*Si no lo encuentra no elimina nada*/
	while((recorrido != NULL) and (recorrido->elemento != elemento)){
		ultimo = recorrido;
		recorrido = recorrido->siguiente;
	}
	
	if (recorrido != NULL){
		if (ultimo == NULL) /*Estoy al inicio de la lista*/
			tad.cabeza = recorrido->siguiente;
		else
			ultimo->siguiente = recorrido->siguiente;
		delete recorrido; /*libera la memoria*/
		tad.longitud--;
	}
}

void encolar(struct Cola & cola, int elemento){
    insertarAlFinal(cola.lista, elemento);
}

bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

void imprime(const struct Cola & cola){
    imprime(cola.lista);
}

void eliminarMultiplos(struct Lista & ptrCriba,int elemento,struct Cola & ptrCola, Nodo *ptrRecorrido){
	if (ptrRecorrido!=NULL){
		if (ptrRecorrido->elemento%elemento==0){
			int elementoEliminar = ptrRecorrido->elemento;
			encolar(ptrCola,ptrRecorrido->elemento);
			ptrRecorrido = ptrRecorrido->siguiente;	
			eliminaNodo(ptrCriba,elementoEliminar);	
		}
		else {
			ptrRecorrido = ptrRecorrido->siguiente;	
		}
		eliminarMultiplos(ptrCriba,elemento,ptrCola,ptrRecorrido);
	}
}

int desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola est� vac�a no se puede desencolar"<<endl;
        exit(1);
    }
    int elemento = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return elemento;
}

/*constructor de Pila*/
void construir(struct Pila & pila){
    construir(pila.lista);
}

/*Determina si la pila est� vac�a*/
bool esPilaVacia(const struct Pila & pila){
    return esListaVacia(pila.lista);
}

/*Determina el n�mero de elementos de la pila*/
int longitud(const struct Pila  & pila){
    return longitud(pila.lista);
}

/*push, a�ade un elemento a la parte superior de la pila*/
void apilar(struct Pila & pila, int elemento){
    insertarAlInicio(pila.lista, elemento);
  //  cout<<"Apilar: "<<elemento<<endl;
}


/*examina un elemento situado en la parte superior de la pila*/
int cima(const struct Pila & pila){
    if (esPilaVacia(pila)){
	cout<<"La pila est� vac�a por lo tanto no posee cima"<<endl;
	exit(12);
    }		
    return retornaCabeza(pila.lista);
}

/*pop, elimina un elemento de la parte superior de la pila*/
int desapilar(struct Pila & pila){
    if (esPilaVacia(pila)){
        cout<<"La pila est� vac�a, por lo tanto no se puede desapilar"<<endl;
	exit(11);
    }	
    int elemento = cima(pila);
    eliminaCabeza(pila.lista);
    return elemento;
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

/*destruye la pila*/
void destruirPila(struct Pila & pila){
    destruir(pila.lista);
}

/*Recordar que las Pilas no se recorren en forma secuencial*/
/*Se va utilizar solo para mostrar los valores*/
void imprimir(const struct Pila & pila){
    imprime(pila.lista);
}

void fusion(struct Lista &ptrLista1,struct Lista &ptrLista2){
	/*Este caso es el de disjuntos con complejidad O(1)*/
	if (ptrLista1.cola->elemento < ptrLista2.cabeza->elemento){
		ptrLista1.cola->siguiente = ptrLista2.cabeza;
		ptrLista1.cola = ptrLista2.cola;
	}
	else {
		/*Este caso es el de disjuntos con complejidad O(1)*/
		if (ptrLista2.cola->elemento < ptrLista1.cabeza->elemento){
			ptrLista2.cola->siguiente = ptrLista1.cabeza;
			ptrLista1.cabeza = ptrLista2.cabeza;
		}
		else {
			Nodo *ptrInicio = NULL;
			Nodo *ptrFin = NULL;
			while (!esListaVacia(ptrLista1) && !esListaVacia(ptrLista2)){
				if (ptrLista1.cabeza->elemento<=ptrLista2.cabeza->elemento){
					if (ptrInicio==NULL){
						ptrInicio = ptrLista1.cabeza;
						ptrFin = ptrLista1.cabeza;
					}
					else {
						ptrFin->siguiente = ptrLista1.cabeza;
						ptrFin = ptrLista1.cabeza;
					}
					ptrLista1.cabeza = ptrLista1.cabeza->siguiente;	
				}
				else {
					if (ptrInicio==NULL){
						ptrInicio = ptrLista2.cabeza;
						ptrFin = ptrLista2.cabeza;
					}
					else {
						ptrFin->siguiente = ptrLista2.cabeza;
						ptrFin = ptrLista2.cabeza;
					}
					ptrLista2.cabeza = ptrLista2.cabeza->siguiente;
				}	
			}
			/*Tendria que ver en cual quedo elementos*/
			if (!esListaVacia(ptrLista1)){
				ptrFin->siguiente = ptrLista1.cabeza;
				ptrFin = ptrLista1.cola;
			}
			else {
				ptrFin->siguiente = ptrLista2.cabeza;
				ptrFin = ptrLista2.cola;
			}
			ptrLista1.cabeza = ptrInicio;
			ptrLista1.cola = ptrFin;
		}
	}
}

void juntarListar(struct Lista &ptrLista1,struct Lista &ptrLista2) {
	ptrLista1.cola->siguiente = ptrLista2.cabeza;
	ptrLista1.cola = ptrLista2.cola;
}

int main(){
	Lista ptrLunes, ptrMartes, ptrMiercoles, ptrJueves, ptrViernes;
	construir(ptrLunes);
	construir(ptrMartes);
	construir(ptrMiercoles);
	construir(ptrJueves);
	construir(ptrViernes);
	insertarAlFinal(ptrLunes,8);
	insertarAlFinal(ptrLunes,10);
	insertarAlFinal(ptrLunes,12);
	insertarAlFinal(ptrMartes,9);
	insertarAlFinal(ptrMartes,11);
	insertarAlFinal(ptrMiercoles,8);
	insertarAlFinal(ptrMiercoles,9);
	insertarAlFinal(ptrMiercoles,10);
	insertarAlFinal(ptrJueves,14);
	insertarAlFinal(ptrJueves,15);
	insertarAlFinal(ptrJueves,16);
	insertarAlFinal(ptrViernes,17);
	insertarAlFinal(ptrViernes,18);
	insertarAlFinal(ptrViernes,19);
	imprime(ptrLunes);
	imprime(ptrMartes);
	imprime(ptrMiercoles);
	imprime(ptrJueves);
	imprime(ptrViernes);
	fusion(ptrLunes,ptrMartes);
	fusion(ptrLunes,ptrMiercoles);
	fusion(ptrLunes,ptrJueves);	
	fusion(ptrLunes,ptrViernes);
	imprime(ptrLunes);
	return 0;
}
