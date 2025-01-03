/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#define MAXCAM 9

using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "funcionesLista.h"



void ordenarDeMayor_Menor(struct Lista &lista){
    struct Nodo* recorrido = lista.cabeza;
    int aux;
    while(recorrido!=nullptr){
        struct Nodo* siguiente = recorrido->siguiente;
        
        while(siguiente!=nullptr){
            aux = siguiente->elemento;
            if(recorrido->elemento < siguiente->elemento){
                siguiente->elemento = recorrido->elemento;
                recorrido->elemento = aux;
            }
            
            siguiente = siguiente->siguiente;
        }
        
        recorrido = recorrido->siguiente;
    }
}

void ordenarDeMenor_Mayor(struct Lista &lista){
    struct Nodo* recorrido = lista.cabeza;
    int aux;
    while(recorrido!=nullptr){
        struct Nodo* siguiente = recorrido->siguiente;
        
        while(siguiente!=nullptr){
            aux = siguiente->elemento;
            if(recorrido->elemento > siguiente->elemento){
                siguiente->elemento = recorrido->elemento;
                recorrido->elemento = aux;
            }
            
            siguiente = siguiente->siguiente;
        }
        
        recorrido = recorrido->siguiente;
    }
}
//lista de menor a mayor ; //lista de mayor a menor
void intercalarListas(struct Lista &lista1, struct Lista &lista2 ){
    struct Nodo* recorrido = lista1.cabeza;
    struct Nodo* siguiente = nullptr;
    struct Nodo* camion = lista2.cabeza;
    struct Nodo* nodoInsertado = nullptr;
    while(recorrido != nullptr ){
        //siguiente = recorrido->siguiente;
        if(camion ==nullptr) break;
        nodoInsertado = camion;
        camion =  camion->siguiente; 
        
        nodoInsertado->siguiente = recorrido->siguiente;  
        recorrido->siguiente =  nodoInsertado;
        recorrido = nodoInsertado;
        
        recorrido = recorrido->siguiente;
    }
    if(!esListaVacia(lista2)){
        struct Nodo *ultimoNodo = obtenerUltimoNodo(lista1);
        ultimoNodo->siguiente = camion;
        
    }
    
}

void cargaBin(int cromo[], int numero, int cant, int base){
    for(int i=0;i<cant;i++) cromo[i] = 0;
    int i=0;
    while(numero>0){
        cromo[i] = numero%base;
        numero /=base;
        i++;
    }
}
void impresionTortuningas(int cromo[],int cantCamiones,struct Lista *arrCamiones){
    int cantD=0,cantR=0,cantL=0,cantMA=0,y;
  
    for(int i=0;i<cantCamiones;i++){
        if(cromo[i]==0 and cantL==0){
            
            cout<<"Leonardo: ";
            if(i!=cantCamiones-1){
                for(int j=i+1;j<cantCamiones;j++){
                    if((cromo[j]==0)){
                        cantL++;
                        y=j;
                    }    
                }
            }
            if (cantL !=0){
                ordenarDeMenor_Mayor(arrCamiones[i]);
                ordenarDeMayor_Menor(arrCamiones[y]);
                intercalarListas(arrCamiones[i],arrCamiones[y]);
            }
            imprime(arrCamiones[i]);
                            
        }
        if(cromo[i]==1 and cantR==0){
            
            cout<<"Rafael: ";
            if(i!=cantCamiones-1){
                for(int j=i+1;j<cantCamiones;j++){
                    if((cromo[j]==1)){
                        cantR++;
                        y=j;
                    }    
                }
            }
            if (cantR !=0){
                ordenarDeMenor_Mayor(arrCamiones[i]);
                ordenarDeMayor_Menor(arrCamiones[y]);
                intercalarListas(arrCamiones[i],arrCamiones[y]);
            }
            imprime(arrCamiones[i]);
                            
        }
        
        if(cromo[i]==2 and cantD==0){
            
            cout<<"Donatelo: ";
            if(i!=cantCamiones-1){
                for(int j=i+1;j<cantCamiones;j++){
                    if((cromo[j]==2)){
                        cantD++;
                        y=j;
                    }    
                }
            }
            if (cantD !=0){
                ordenarDeMenor_Mayor(arrCamiones[i]);
                ordenarDeMayor_Menor(arrCamiones[y]);
                intercalarListas(arrCamiones[i],arrCamiones[y]);
            }
            imprime(arrCamiones[i]);
                            
        }
        if(cromo[i]==3 and cantMA==0){
            
            cout<<"Miguel Anguel: ";
            if(i!=cantCamiones-1){
                for(int j=i+1;j<cantCamiones;j++){
                    if((cromo[j]==3)){
                        cantMA++;
                        y=j;
                    }    
                }
            }
            if (cantMA !=0){
                ordenarDeMenor_Mayor(arrCamiones[i]);
                ordenarDeMayor_Menor(arrCamiones[y]);
                intercalarListas(arrCamiones[i],arrCamiones[y]);
            }
            imprime(arrCamiones[i]);
                            
        }
        
    }
}


int main(int argc, char** argv) {
    int cantCamiones,capLeo,capRafa,capDona,capMigu;
    struct Lista arrCamiones[MAXCAM];
    cout<<"Ingrese la cantidad de camiones: ";
    cin>>cantCamiones;
    cout<<"Ingrese la capacidad maxima de carga de Leonardo: ";
    cin>>capLeo;
    cout<<"Ingrese la capacidad maxima de carga de Rafael: ";
    cin>>capRafa;
    cout<<"Ingrese la capacidad maxima de carga de Donatelo: ";
    cin>>capDona;
    cout<<"Ingrese la capacidad maxima de carga de Miguel Anguel: ";
    cin>>capMigu;
            
    for(int i=0;i<cantCamiones;i++){
        construir(arrCamiones[i]);
    }   
    int j=1,dato,suma;
    for(int i=0;i<cantCamiones;i++){
        cout<<"Ingrese los Pesos del Bus Nro."<<j<<": ";
        suma=0;
        do{
            cin>>dato;
            if(dato == 0) break;
            suma += dato;
            insertarAlFinal(arrCamiones[i],dato); 
        }while(dato!=0);
        arrCamiones[i].sumaPesos = suma ;
        
        j++;
    }
    int base=4;
    int opcion = pow(base,cantCamiones);
    int cromo[cantCamiones];
    int sumaL,sumaR,sumaD,sumaMA;
    int mcomb=-1;
    for(int i=0;i<=opcion;i++){
        cargaBin(cromo,i,cantCamiones,base);
        sumaL=sumaD=sumaR=sumaMA = 0;
        for(int j=0;j<cantCamiones;j++){
            if(cromo[j]==0) sumaL += arrCamiones[j].sumaPesos;
            if(cromo[j]==1) sumaR += arrCamiones[j].sumaPesos;
            if(cromo[j]==2) sumaD += arrCamiones[j].sumaPesos;
            if(cromo[j]==3) sumaMA += arrCamiones[j].sumaPesos;
            
        }
        if(sumaL!=0 and sumaR!=0 and sumaD!=0 and sumaMA!=0){
            
            if(sumaL<=capLeo and sumaR<=capRafa and sumaD<=capDona and sumaMA<=capMigu){
                mcomb = i;
                break;
            }
            
            
        }
        
    }
    cout<<"Resultado"<<endl;
    cargaBin(cromo,mcomb,cantCamiones,base);
    if(mcomb == -1){
        cout<<"Las tortuninjas fracasaron en su misión "<<endl;
    }else{
        cout<<"Las TortuNinjas completaron su misión."<<endl;
        cout<<"Los camiones a salvar son :"<<endl;
        impresionTortuningas(cromo,cantCamiones,arrCamiones);
        //for(int i=0;i<cantCamiones;i++) cout<<cromo [i]<<endl;
    }
    
    
    
    
    
    
//    struct Lista lista1,lista2;
//    construir(lista1);
//    construir(lista2);
//    insertarAlFinal(lista1,8);
//    insertarAlFinal(lista1,9);
//    insertarAlFinal(lista1,10);
//    insertarAlFinal(lista1,12);
//    insertarAlFinal(lista1,17);
//    insertarAlFinal(lista1,20);
//    insertarAlFinal(lista2,6);
//    insertarAlFinal(lista2,5);
//    insertarAlFinal(lista2,3);
//    
//    imprime(lista1);
//    imprime(lista2);
//    cout<<"Lista fusionada"<<endl;
//    intercalarListas(lista1,lista2);
//    imprime(lista1);
    
    return 0;
}

