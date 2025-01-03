/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 25 de agosto de 2023, 08:40 PM
 */

#include <cstdlib>
#include <iostream>
#include "ListaD.h"
using namespace std;
#include "funcionesListaDoble.h"

/*
 * LISTA DOBLEMENTE ENLAZADA - TORNEO DE EQUIPOS
 * EL EJERCICIO SE REALIZA CON INSERTAR ORDENADO
 * SIN EMBARGO, SE UTILIZA EL EJERCICIO PARA PROBAR 
 * OTRAS FUNCIONES DE LA LISTA DOBLE
 */
int main(int argc, char** argv) {

    struct Lista lista;
    /*CONSTRUIR LA LISTA*/
    construir(lista);
    
    /*INSERTA AL INICIO DE LA LISTA DOBLE LOS EQUIPOS*/
//    insertarAlInicio(lista, "GutterBall", 9);
//    insertarAlInicio(lista, "KingPins", 8);
//    insertarAlInicio(lista, "PinDoctors", 7);
//    insertarAlInicio(lista, "Scorecards", 10);
//    insertarAlInicio(lista, "Spares", 5);
//    insertarAlInicio(lista, "Splits", 4);
//    insertarAlInicio(lista, "Tenpins", 13);
//    insertarAlInicio(lista, "Woodsplitters", 6);
//    insertarAlInicio(lista, "Lions", 1);
//    insertarAlInicio(lista, "Tigers", 2);
    
    /*INSERTA AL FINAL DE LA LISTA DOBLE LOS EQUIPOS*/
//    insertarAlFinal(lista, "GutterBall", 9);
//    insertarAlFinal(lista, "KingPins", 8);
//    insertarAlFinal(lista, "PinDoctors", 7);
//    insertarAlFinal(lista, "Scorecards", 10);
//    insertarAlFinal(lista, "Spares", 5);
//    insertarAlFinal(lista, "Splits", 4);
//    insertarAlFinal(lista, "Tenpins", 13);
//    insertarAlFinal(lista, "Woodsplitters", 6);
//    insertarAlFinal(lista, "Lions", 1);
//    insertarAlFinal(lista, "Tigers", 2);
    
    /*INSERTA EN ORDEN LA LISTA DOBLE LOS EQUIPOS*/
    insertarEnOrden(lista, "GutterBall", 9);
    insertarEnOrden(lista, "KingPins", 8);
    insertarEnOrden(lista, "PinDoctors", 7);
    insertarEnOrden(lista, "Scorecards", 10);
    insertarEnOrden(lista, "Spares", 5);
    insertarEnOrden(lista, "Splits", 4);
    insertarEnOrden(lista, "Tenpins", 13);
    insertarEnOrden(lista, "Woodsplitters", 6);
    insertarEnOrden(lista, "Lions", 1);
    insertarEnOrden(lista, "Tigers", 2);
    
    /*ELIMINA EL PRIMER ELEMENTO DE LA LISTA*/
    eliminaCabeza(lista);
    
    /*ELIMINA EL ÚLTIMO ELEMENTO DE LA LISTA*/
    eliminaCola(lista);
    
    /*ELIMINA EL ELEMENTO CUYO NOMBRE COINCIDE CON EL DE LA LISTA*/
    eliminaNodo(lista, "Tenpins");
    eliminaNodo(lista, "Spares");
  
    /*IMPRIME LA LISTA DESDE EL INICIO*/
    imprime(lista);
    /*IMPRIME LA LISTA DESDE EL FINAL*/
    imprimeDesdeFinal(lista);
    /*IMPRIME LA PRIMERA FECHA DEL TORNEO*/
    imprimePrimerafecha(lista);
    /*LIBERA MEMORIA*/
    destruirLista(lista);
    
    return 0;
}

/* 
 * File:   Equipo.h
 * Author: ANA RONCAL
 * Created on 31 de agosto de 2023, 01:22 PM
 */

#ifndef EQUIPO_H
#define EQUIPO_H

struct Equipo{
    char * nombre; /*Nombre del equipo*/
    int victorias; /*cantidad de victorias*/
};

#endif /* EQUIPO_H */

/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 25 de agosto de 2023, 08:41 PM
 */

#ifndef NODO_H
#define NODO_H
/*LISTA DOBLEMENTE ENLAZADA*/
struct Nodo{
    struct Equipo equipo;
    struct Nodo * anterior;   /*apunta a su predecesor*/
    struct Nodo * siguiente;  /*apunta a su sucesor*/
};

#endif /* NODO_H */

/* 
 * File:   ListaD.h
 * Author: ANA RONCAL
 * Created on 25 de agosto de 2023, 08:41 PM
 */

#ifndef LISTAD_H
#define LISTAD_H
/*LISTA DOBLEMENTE ENLAZADAS*/
struct Lista{
    struct Nodo * cabeza; /*apunta al inicio de la lista*/
    /*Para tener un fácil acceso a la información de la lista es recomendable
     usar dos apuntadores*/
    struct Nodo * cola;   /*apunta al fin de la lista*/
    int longitud;  /*guarda la longitud de la lista doble*/
};

#endif /* LISTAD_H */

/* 
 * File:   funcionesListaDoble.h
 * Author: ANA RONCAL
 * Created on 25 de agosto de 2023, 08:41 PM
 */

#ifndef FUNCIONESLISTADOBLE_H
#define FUNCIONESLISTADOBLE_H

void construir(struct Lista & tad);
bool esListaVacia(const struct Lista &);

void imprimePrimerafecha(const struct Lista &);
void imprimeDesdeFinal(const struct Lista &);
void imprime(const struct Lista &);

struct Nodo * obtenerNodoAnterior(const struct Lista & , int);
struct Nodo * crearNodo(const char * , int , struct Nodo * , struct Nodo *);

void insertarAlFinal(struct Lista & , const char * , int );
void insertarEnOrden(struct Lista & , const char *, int);
void insertarAlInicio(struct Lista & , const char *, int );

struct Nodo * seEncuentra(const struct Lista & , const char * );
void eliminaCabeza(struct Lista  & );
void eliminaCola(struct Lista  & );
void eliminaNodo(struct Lista  & , const char * );

void destruirLista(struct Lista & );

#endif /* FUNCIONESLISTADOBLE_H */

/* 
 * File:   funcionesListaDoble.cpp
 * Author: ANA RONCAL
 * Created on 27 de agosto de 2023, 02:06 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Equipo.h"
#include "Nodo.h"
#include "ListaD.h"
using namespace std;
#include "funcionesListaDoble.h"

void construir(struct Lista & tad){
    tad.cabeza = nullptr;
    tad.cola = nullptr; /* para un mejor manejo de la lista*/
    tad.longitud = 0;
}
/*DETERMINA SI LA LISTA ESTÁ VACÍA*/
bool esListaVacia(const struct Lista & tad){
    return tad.cabeza == nullptr;
}

/*CREA UN NUEVO ELEMENTO CON VALORES INICIALES*/
struct Nodo * crearNodo(const char * nombre, int victorias, 
                        struct Nodo * anterior, struct Nodo * siguiente){
    /*Igual a la lista simplemente enlazada*/
    struct Nodo * nuevoNodo = new struct Nodo;
    
    /*NOMBRE TIENE UNA ASIGNACIÓN DINÁMICA*/
    nuevoNodo->equipo.nombre = new char[strlen(nombre)+1];
    strcpy(nuevoNodo->equipo.nombre, nombre);
    nuevoNodo->equipo.victorias = victorias;
    nuevoNodo->anterior = anterior;   /*Lista doblemente enlazada*/
    nuevoNodo->siguiente = siguiente; 
    return nuevoNodo;
}

/*DEVUELVE LA CANTIDAD DE ELEMENTOS DE LA LISTA*/
int longitud(struct Lista tad ){
    return tad.longitud;
}

/*OBTIENE EL ÚLTIMO ELEMENTO DE LA LISTA*/
/*PARA LA LISTA QUE HEMOS IMPLEMENTADO NO ES NECESARIA ESTÁ FUNCIÓN
 *POR CONTAR CON UN PUNTERO A COLA*/
struct Nodo * obtenerUltimoNodo(const struct Lista & tad){
    /*Igual que la lista simplemente enlazada*/
    struct Nodo * ultimo = nullptr;
    struct Nodo * recorrido = tad.cabeza;
    while(recorrido != nullptr){
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

/*OBTIENE EL ELEMENTO ANTERIOR SEGÚN UN CRITERIO DE BÚSQUEDA*/
struct Nodo * obtenerNodoAnterior(const struct Lista & tad, int victorias){
    /*Igual que la lista simplemente enlazada*/
    struct Nodo * anterior = nullptr;
    struct Nodo * recorrido = tad.cabeza;
                                                  /*ordena de mayor a menor*/
    while(recorrido != nullptr and (recorrido->equipo.victorias > victorias)){
        anterior = recorrido;        
        recorrido = recorrido->siguiente;
    }
    return anterior;    
}

/*INSERTA UN ELEMENTO AL INICIO DE LA LISTA DOBLE*/
void insertarAlInicio(struct Lista & tad, const char * nombre, int victorias){
    struct Nodo * nuevoNodo = crearNodo(nombre, victorias, nullptr, nullptr);
    if (tad.cabeza != nullptr)
        tad.cabeza->anterior = nuevoNodo;
    nuevoNodo->siguiente = tad.cabeza;
    tad.cabeza = nuevoNodo;    
    if(nuevoNodo->siguiente == nullptr)
         tad.cola = nuevoNodo;
    
    tad.longitud++;
}

/*INSERTA UN ELEMENTO AL FINAL DE LA LISTA DOBLE*/
void insertarAlFinal(struct Lista & tad, const char * nombre, int victorias){
    struct Nodo * nuevoNodo = crearNodo(nombre, victorias, nullptr, nullptr);
    Nodo * ultimoNodo = tad.cola; /*obtiene el último nodo*/
    if (ultimoNodo == nullptr){
        tad.cabeza = nuevoNodo;
        tad.cola = nuevoNodo;
    }
    else{
        ultimoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimoNodo;
        tad.cola = nuevoNodo;
    }            
    tad.longitud++;  
}

/*INSERTA EN ORDEN (DE MAYOR A MENOR O VICEVERSA) UN ELEMENTO A LA LISTA*/
void insertarEnOrden(struct Lista & tad, const char * nombre, int victorias){
    /*Diferente a la lista simplemente enlazada*/
    struct Nodo * nodoAnterior = obtenerNodoAnterior(tad, victorias);    
    struct Nodo * nuevoNodo = crearNodo(nombre, victorias, nullptr, nullptr);
    
    if (nodoAnterior == nullptr){
        nuevoNodo->siguiente = tad.cabeza;
        if (tad.cabeza != nullptr){ /*lista con datos*/
            tad.cabeza->anterior = nuevoNodo;
            //tad.cola = nuevoNodo;   /*va en la cola*/
        }
        tad.cabeza = nuevoNodo;  /*ambos apuntan a nuevoNodo*/
        if(tad.cabeza->siguiente == nullptr) /*apunta la primera vez a cabeza*/
            tad.cola = nuevoNodo;
    }else{    
        nuevoNodo->siguiente = nodoAnterior->siguiente;
        if (nodoAnterior->siguiente != nullptr)
            nodoAnterior->siguiente->anterior = nuevoNodo; /*insertar antes del final*/
        else
            tad.cola = nuevoNodo; /*va en la cola*/
        nodoAnterior->siguiente = nuevoNodo;
        nuevoNodo->anterior = nodoAnterior;
    }
    tad.longitud++;     
}

/*MUESTRA LOS EQUIPOS DE LA PRIMERA FECHA DEL TORNEO, UTILIZA LOS PUNTEROS CABEZA
 Y COLA*/
void imprimePrimerafecha(const struct Lista & tad){
    /*Muestra los resultados de la primera ronda de equipos*/
    struct Nodo * arriba = tad.cabeza;
    struct Nodo * abajo = tad.cola;
    
    cout<<endl<<"PRIMERA FECHA DEL PARTIDO"<<endl<<endl;
    int max = tad.longitud / 2;
    
    for(int i = 0; i < max; i++){
        cout<<"PARTIDO "<<i+1<<endl;
        cout<<arriba->equipo.nombre<<endl;
        arriba = arriba->siguiente;
        cout<<abajo->equipo.nombre<<endl;
        abajo = abajo->anterior;
        cout<<endl;
    }
}

/*Se recorre la lista en forma secuencial*/
/*CONST se utiliza para no modificar la estructura, la proteje de ti mismo
 Si se quiere acceder a los datos, por ejemplo tad.longitud = 20, no te deja
 dado que la estructura es de lectura solamente con const aquello que pasas 
 no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista & tad){
    
    cout<<"IMPRIME DESDE EL INICIO"<<endl;
    if (esListaVacia(tad)){
        cout<<"La lista está vacía"<<endl;
    }
    else{
        struct Nodo * recorrido = tad.cabeza;
        cout<<"EQUIPOS "<<" Victorias"<<endl;
        while(recorrido != nullptr){
            cout<<left<<setw(15)<<recorrido->equipo.nombre;
            cout<<right<<setw(3)<<recorrido->equipo.victorias<<endl;
            recorrido = recorrido->siguiente;
        }   
    }
    cout<<endl;
}

/*IMPRIME DESDE EL FINAL DE LA LISTA DOBLE*/
void imprimeDesdeFinal(const struct Lista & tad){
    /*Se puede hacer uso de la función que obtiene el último nodo*/
    //struct Nodo * recorrido = obtenerUltimoNodo(tad);
    /*SIN EMBARGO, VAMOS A UTILIZAR EL PUNTERO COLA*/
    struct Nodo * recorrido = tad.cola;
    cout<<"IMPRIME DESDE EL FINAL"<<endl;
    cout<<"EQUIPOS "<<" Victorias"<<endl;
    while(recorrido != nullptr){
        cout<<left<<setw(15)<<recorrido->equipo.nombre<<"  ";
        cout<<right<<setw(3)<<recorrido->equipo.victorias<<endl;
        recorrido = recorrido->anterior;
    }
    cout<<endl;
}

/*LIBERA LA MEMORIA*/
void destruirLista(struct Lista & tad){
    struct Nodo * recorrido = tad.cabeza;
    struct Nodo * eliminarNodo;
    
    while(recorrido != nullptr){
        eliminarNodo = recorrido;        
        recorrido = recorrido->siguiente;
        delete eliminarNodo;
    }
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.longitud = 0;
}
/*DEVUELVE EL NODO (ELEMENTO) QUE COINCIDE CON LA BÚSQUEDA (NOMBRE)*/
struct Nodo * seEncuentra(const struct Lista & tad, const char * nombre){
    struct Nodo * recorrido = tad.cabeza;
    /*Mientras sea diferente a nombre que avance*/
    while(recorrido != nullptr and strcmp(recorrido->equipo.nombre, nombre) != 0){        
        recorrido = recorrido->siguiente;
    }
    return recorrido;
}

/*ELIMINA EL PRIMER ELEMENTO DE LA LISTA*/
void eliminaCabeza(struct Lista  & tad){
    struct Nodo * nodoEliminar = tad.cabeza;
    if (nodoEliminar == nullptr ){
        cout<<"No se puede eliminar la cabeza pues la lista está vacía";
        exit(1);
    }
    tad.cabeza = tad.cabeza->siguiente;
    if(tad.cabeza != nullptr)
        tad.cabeza->anterior = nullptr;
    delete nodoEliminar;
    tad.longitud--;
}

/*ELIMINA EL ÚLTIMO ELEMENTO DE LA LISTA*/
void eliminaCola(struct Lista  & tad){
    /*COMO SE CUENTA CON UN PUNTERO A COLA, LO USAMOS*/
    struct Nodo * nodoAEliminar = tad.cola; /* va al final de la lista*/
     if (nodoAEliminar == nullptr ){
        cout<<"No se puede eliminar la cola pues la lista está vacía";
        exit(1);
    }
    if(tad.cola != nullptr){
        tad.cola = nodoAEliminar->anterior;
        if(tad.cola == nullptr)
            tad.cabeza = tad.cola; // se quedó vacía la lista
        delete nodoAEliminar;
        if(tad.cola != nullptr)
            tad.cola->siguiente = nullptr; /* cambio */
        tad.longitud--;
    }
}

/*ELIMINA EL NODO QUE COINCIDE CON LA BÚSQUEDA*/
void eliminaNodo(struct Lista  & tad, const char * nombre){
    struct Nodo * ultimo = nullptr;
    struct Nodo * recorrido = tad.cabeza;
    while(recorrido != nullptr and strcmp(recorrido->equipo.nombre, nombre) != 0){
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    if (recorrido != nullptr){
        if (ultimo == nullptr){
            tad.cabeza = recorrido->siguiente;
            if (tad.cabeza != nullptr)
                tad.cabeza->anterior = nullptr;
        }
        else{    
            ultimo->siguiente = recorrido->siguiente;
            if (recorrido->siguiente != nullptr)
                recorrido->siguiente->anterior = ultimo;
            if(ultimo->siguiente == nullptr)
                tad.cola = ultimo;
        }
        delete recorrido;
        tad.longitud--;

    }
}