#include "cola.h"


void construir( Cola &pC )
{
    // se crea la cola vacia
    pC.frente= NULL;
    pC.final = NULL;
    pC.longitud = 0;
}

bool esColaVacia( Cola C )
{
    return C.frente == NULL;
    // return C.final == NULL;
    // return C.longitud == 0;
}

int obtenerLongitud( Cola C )
{
    return C.longitud;
}

NodoC* crearNodo( ElemPro e, NodoC *s )
{
    NodoC *p;
    p = new NodoC; // se crea un nodo y su direccion se almacena en p
    p->elem = e;
    p->sig = s;
    return p;  // retorna la dirección del nodo creado
}

void encolar( Cola &pC, ElemPro e )
{
    NodoC *p, *pU;
    p = crearNodo( e, NULL);
    if ( esColaVacia(pC) )
    {
        pC.frente = p;
    }
    else
    {
        pU = pC.final;
        pU->sig = p;
    }
    pC.final = p;
    pC.longitud++;
}



void encolarConPrioridad( Cola &pC, ElemPro e )
{
    NodoC *p, *pU;
    p = crearNodo( e, NULL);
    
    if ( esColaVacia(pC) ){
        pC.frente = p;
        pC.final = p;
    }else{
        NodoC *aux = pC.frente;
        NodoC *ant=NULL;
        while(aux!=NULL){
            if(aux->elem.tipoLote < p->elem.tipoLote){
                ant = aux;
                aux = aux->sig;
                if(aux==NULL){
                    ant->sig = p;
                    pC.final = p;                            
                }                
                
            }else{
                if(aux->elem.tipoLote > p->elem.tipoLote){
                    if(ant==NULL){
                        p->sig = pC.frente;
                        pC.frente = p;
                    }else{
                        p->sig = ant->sig;
                        ant->sig = p;                        
                    }
                    break;
                    
                }else if(aux->elem.tipoLote == p->elem.tipoLote){
                    if(aux->elem.codigo > p->elem.codigo){
                        p->sig = aux;
                        if(ant==NULL){
                            pC.frente = p;
                        }else{
                            ant->sig = p;
                        }
                        break;
                        
                    }else if(aux->elem.codigo < p->elem.codigo){
                        if(aux->sig==NULL){
                            aux->sig = p;
                            pC.final = p;
                            break;
                        }
                        if(p->elem.codigo < aux->sig->elem.codigo || aux->sig->elem.tipoLote != p->elem.tipoLote){
                            p->sig = aux->sig;
                            aux->sig = p; 
                            break;
                        }else{
                            aux = aux->sig;
                        }                                                       
                    }
                }
            }           
        }
    } 
    pC.longitud++;
}



void mostrar( Cola C )
{
    NodoC *p;
    if ( esColaVacia(C) )
        cout << "La cola esta vacia" << endl;
    else
    {
        p = C.frente;
        while ( p!= NULL )
        {
            cout << p->elem.tipoLote<<" "<<p->elem.codigo;
            p = p->sig;
            if(p!=NULL) cout<<", ";
        }
        cout << endl;
        cout<<"-----------------------------------------------------------------------";
        cout << endl;
    }
}

// esta funcion solo sera invocada previa verificacion de que la cola no esta vacia
ElemPro desencolar( Cola &pC )
{
    ElemPro x;
    NodoC *p;
    p = pC.frente;
    if ( p->sig == NULL ) // hay un solo nodo en la Cola
        pC.final = NULL;
    pC.frente = p->sig;
    x = p->elem;
    pC.longitud--;
    delete p;
    return x;
}

void destruir( Cola &pC )
{
    int i;
    NodoC *p, *q;
    if ( !esColaVacia(pC) )
    {
        p = pC.frente;
        for(i=1; i<=pC.longitud; i++)
        {
            q = p->sig;
            delete p;
            p = q;
        }
        pC.frente = NULL;
        pC.final = NULL;
        pC.longitud = 0;
    }
}