#include <iostream>

using namespace std;

struct Nodo{
    int nivel_impacto;
    char categoria;
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
struct Nodo * crearNodo(int nivel_impacto, char categoria, struct Nodo * siguiente){

    struct Nodo * nuevoNodo = new struct Nodo;
    
    nuevoNodo->nivel_impacto = nivel_impacto;
    nuevoNodo->categoria = categoria;
    nuevoNodo->siguiente = siguiente; 
    return nuevoNodo;
}


/*INSERTA UN ELEMENTO AL FINAL DE LA LISTA*/
void insertarAlFinal(struct Lista & lista, int nivel_impacto, char categoria){
    struct Nodo * nuevoNodo = crearNodo(nivel_impacto, categoria, NULL);
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
    return lista.cabeza->nivel_impacto;
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
            cout<<recorrido->categoria<<"("<<recorrido->nivel_impacto<<") ->";
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


void reorganizar(Lista & L1, Lista & L2){
	//Primera Opción: L1 tiene todos elemento mayores a los elementos de L2, entonces O(1)
	if (L1.cola->nivel_impacto >= L2.cabeza->nivel_impacto){
		//Si son iguales, doy prioridad a L1 que viene a ser el de mayor Categoría: A > B > C > D > E
		L1.cola->siguiente= L2.cabeza;
		L1.cola=L2.cola;
	}
	else{
	//Segunda Opción: L2 tiene todos elemento mayores a los elementos de L1, entonces O(1)
		if (L2.cola->nivel_impacto > L1.cabeza->nivel_impacto){
			L2.cola->siguiente= L1.cabeza;
			L1.cabeza=L2.cabeza;
		}
		else{
		
			//Tercera Opción: L1 y L2 tienen niveles de impacto que se traslapan: Complejidad O(n)
			Lista LFinal;
			LFinal.cabeza=NULL;
			LFinal.cola=NULL;
			
			while ((L1.cabeza)!=NULL && (L2.cabeza)!=NULL){
				if (L1.cabeza->nivel_impacto >= L2.cabeza->nivel_impacto){//L1.cabeza es mayor a L2.cabeza
				//Si son iguales, doy prioridad a L1 que viene a ser el de mayor Categoría: A > B > C > D > E
					if (LFinal.cabeza==NULL){//Es el primer elemento de LFinal
						LFinal.cabeza=L1.cabeza;
						LFinal.cola=L1.cabeza;	
					}
					else{//Si es que ya hay elementos en LFinal
						LFinal.cola->siguiente=L1.cabeza;
						LFinal.cola=L1.cabeza;
					}
					L1.cabeza=L1.cabeza->siguiente;//avanzamos en L1 (como en el merge())	
				}
				else if (L1.cabeza->nivel_impacto < L2.cabeza->nivel_impacto){//L2.cabeza es mayor a L1.cabeza
					if (LFinal.cabeza==NULL){//Es el primer elemento de LFinal
						LFinal.cabeza=L2.cabeza;
						LFinal.cola=L2.cabeza;	
					}
					else{//Si es que ya hay elementos en LFinal
						LFinal.cola->siguiente=L2.cabeza;
						LFinal.cola=L2.cabeza;
					}
					L2.cabeza=L2.cabeza->siguiente;//avanzamos en L2 (como en el merge())	
				}
			}
			//Volvemos a recorrer L1 por si tenemos elementos aún en esa lista
			while (L1.cabeza!=NULL){
				if (LFinal.cabeza==NULL){
					LFinal.cabeza=L1.cabeza;
					LFinal.cola=L1.cabeza;	
				}
				else{//Si es que ya hay elementos en LFinal
					LFinal.cola->siguiente=L1.cabeza;
					LFinal.cola=L1.cabeza;
				}
				L1.cabeza=L1.cabeza->siguiente;//avanzamos en L1 (como en el merge())
			}
			//Volvemos a recorrer L2 por si tenemos elementos aún en esa lista
			while (L2.cabeza!=NULL){
				if (LFinal.cabeza==NULL){
					LFinal.cabeza=L2.cabeza;
					LFinal.cola=L2.cabeza;	
				}
				else{//Si es que ya hay elementos en LFinal
					LFinal.cola->siguiente=L2.cabeza;
					LFinal.cola=L2.cabeza;
				}
				L2.cabeza=L2.cabeza->siguiente;//avanzamos en L2 (como en el merge())
			}
			
			//LFinal tiene la lista reorganizada, la cual la devolvemos en L1 (primer argumento)
			L1.cabeza=LFinal.cabeza;
			L1.cola=LFinal.cola;
		}
	}
}
	


int main(int argc, char** argv) {
	int i;
    Lista CategoriaA, CategoriaB, CategoriaC, CategoriaD, CategoriaE;
    int numCategoriaA, numCategoriaB, numCategoriaC, numCategoriaD, numCategoriaE;
    
    construir(CategoriaA);
    construir(CategoriaB);
    construir(CategoriaC);
    construir(CategoriaD);
    construir(CategoriaE);
    
    cout << "Cantidad de PSI de Categoría A:";
	cin >> numCategoriaA;    
	
	cout << "Ingrese los niveles de impacto:";
	for (i=0; i<numCategoriaA; i++){
		int nivel_impacto;
		cin >> nivel_impacto;
		insertarAlFinal(CategoriaA, nivel_impacto, 'A');
	}
	
	 cout << "Cantidad de PSI de Categoría B:";
	cin >> numCategoriaB;    
	
	cout << "Ingrese los niveles de impacto:";
	for (i=0; i<numCategoriaB; i++){
		int nivel_impacto;
		cin >> nivel_impacto;
		insertarAlFinal(CategoriaB, nivel_impacto, 'B');
	}
	
	 cout << "Cantidad de PSI de Categoría C:";
	cin >> numCategoriaC;    
	
	cout << "Ingrese los niveles de impacto:";
	for (i=0; i<numCategoriaC; i++){
		int nivel_impacto;
		cin >> nivel_impacto;
		insertarAlFinal(CategoriaC, nivel_impacto, 'C');
	}
	
	 cout << "Cantidad de PSI de Categoría D:";
	cin >> numCategoriaD;    
	
	cout << "Ingrese los niveles de impacto:";
	for (i=0; i<numCategoriaD; i++){
		int nivel_impacto;
		cin >> nivel_impacto;
		insertarAlFinal(CategoriaD, nivel_impacto, 'D');
	}
	
	 cout << "Cantidad de PSI de Categoría E:";
	cin >> numCategoriaE;    
	
	cout << "Ingrese los niveles de impacto:";
	for (i=0; i<numCategoriaE; i++){
		int nivel_impacto;
		cin >> nivel_impacto;
		insertarAlFinal(CategoriaE, nivel_impacto, 'E');
	}
	
	imprime( CategoriaA );
	imprime( CategoriaB );
	imprime( CategoriaC );
	imprime( CategoriaD );
	imprime( CategoriaE );
	
	cout << endl;
	
	reorganizar (CategoriaA, CategoriaB);
	reorganizar (CategoriaA, CategoriaC);
	reorganizar (CategoriaA, CategoriaD);
	reorganizar (CategoriaA, CategoriaE);
	
	imprime( CategoriaA );
	
    return 0;
}


