/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "funcionesLista.h"

void cargarBase(int *cromo,int num,int cant,int base){
    for(int i=0;i<cant;i++) cromo[i] =0;
    int i=0,numero=num;
    while(numero>0){
        cromo[i]= numero%base;
        numero /=base;
        i++;
    }
}

int esPosibleSalvar(int n){
    if(n!=-1){
        return 1;
    }else{
        return 0;
    }
}

void ordenarAscendentemente(struct Lista &lista){
    struct Nodo * recorrido = nullptr;
    struct Nodo * siguiente = nullptr;
    struct Nodo * anterior = nullptr;
    
    for(int i=0;i<lista.longitud -1;i++){
        recorrido = lista.cabeza;
        siguiente = recorrido->siguiente;
        anterior = nullptr;
        for(int j=0;j<lista.longitud -1-i;j++){
            if(recorrido->elemento > siguiente->elemento ){
                if(anterior != nullptr){
                    anterior->siguiente = siguiente;
                }else{
                    lista.cabeza = siguiente;
                }
                
                Nodo *aux = siguiente;
                siguiente = recorrido;
                recorrido = aux;
                
            }
            anterior = recorrido;
            recorrido = siguiente;
            siguiente = siguiente->siguiente;
        }
           
    }
}

void ordenarDescendente(struct Lista &lista){
    struct Nodo* recorrido =nullptr;
    struct Nodo* siguiente =nullptr;
    struct Nodo* anterior =nullptr;
    for(int i=0;i<lista.longitud - 1; i++){
        recorrido = lista.cabeza;
        siguiente = recorrido->siguiente;
        anterior = nullptr;
        for(int j=0;j<lista.longitud -1 - i;j++){
            if(recorrido->elemento < siguiente->elemento ){
                
                if(anterior!=nullptr){
                    anterior->siguiente = siguiente;
                }else{
                    lista.cabeza = siguiente;
                }
                recorrido->siguiente = siguiente->siguiente;
                siguiente->siguiente =recorrido;
                
                Nodo *aux = siguiente;
                siguiente = recorrido;
                recorrido = aux;
                
            }
            anterior = recorrido;
            recorrido = siguiente;
            siguiente = siguiente->siguiente; 
            
        }
        
    }
}




void ordenarMenor_Mayor(struct Lista &lista){
    struct Nodo *recorrido = lista.cabeza;
    
    while(recorrido!=nullptr){
        struct Nodo *siguiente= recorrido->siguiente;
        int aux= recorrido->elemento;
        
        while(siguiente!=nullptr){
            int aux2 = siguiente->elemento;
            if(aux>siguiente->elemento){
                recorrido->elemento = siguiente->elemento;
                siguiente->elemento = aux;
                aux= aux2;
            }
            siguiente=siguiente->siguiente;
        }
        
        recorrido=recorrido->siguiente;
    }  
}
void ordenarMayor_Menor(struct Lista &lista){
    struct Nodo *recorrido = lista.cabeza;
    
    while(recorrido!=nullptr){
        struct Nodo *siguiente= recorrido->siguiente;
        int aux= recorrido->elemento;
        
        while(siguiente!=nullptr){
            int aux2 = siguiente->elemento;
            if(aux<siguiente->elemento){
                recorrido->elemento = siguiente->elemento;
                siguiente->elemento = aux;
                aux= aux2;
            }
            siguiente=siguiente->siguiente;
        }
        
        recorrido=recorrido->siguiente;
    }
}
void intercalar(struct Lista &lista1,struct Lista &lista2){
    struct Nodo * recorrido = lista1.cabeza;
    struct Nodo * insertarNodo = nullptr;
    struct Nodo * camion = lista2.cabeza;
    
    while(recorrido!=nullptr){
        
        if(camion==nullptr) break;
        insertarNodo=camion;
        camion=camion->siguiente;
        insertarNodo->siguiente= recorrido->siguiente;
        recorrido->siguiente = insertarNodo;
        recorrido = insertarNodo;
        
        recorrido=recorrido->siguiente;
    }
    if(!esListaVacia(lista2)){
        struct Nodo * ultimoNodo= obtenerUltimoNodo(lista1);
        ultimoNodo->siguiente = camion;
    }
}


void imprimirListaCamiones(struct Lista *arrBuses,int *cromo,int mComb,int cantBus){
    cargarBase(cromo,mComb,cantBus,4);
    cout<<"Reusltado:"<<endl;
    cout<<"Las Tortuninjas completaron su misión."<<endl<<endl;
    cout<<"Los camiones a salvar son:"<<endl;
    int cantLeo=0, cantRaf=0, cantDon=0, cantMig=0,j;
    for(int i=0;i<cantBus;i++){
        if(cromo[i]==0){
            cantLeo++;
            if(i!=cantBus-1){
                for(j=i+1;j<cantBus;j++){
                    if(cromo[j]==0){
                        cantLeo++;
                        break;
                    }
                }
            }
            if(cantLeo==2){
                ordenarAscendentemente(arrBuses[i]);
                ordenarMayor_Menor(arrBuses[j]);
                intercalar(arrBuses[i],arrBuses[j]);
                cout<<"Leonardo: ";
                imprime(arrBuses[i]);
            }else if(cantLeo==1){
                cout<<"Leonardo: ";
                imprime(arrBuses[i]);
                cantLeo=-1;
            }  
        }
        if(cromo[i]==1){
            cantRaf++;
            if(i!=cantBus-1){
                for(j=i+1;j<cantBus;j++){
                    if(cromo[j]==1){
                        cantRaf++;
                        break;
                    }
                }
            }
            if(cantRaf==2){
                ordenarMenor_Mayor(arrBuses[i]);
                ordenarMayor_Menor(arrBuses[j]);
                intercalar(arrBuses[i],arrBuses[j]);
                imprime(arrBuses[i]);
            }else if(cantRaf==1){
                cout<<"Rafael: ";
                imprime(arrBuses[i]);
                cantRaf=-1;
            }
        }
        if(cromo[i]==2){
            cantDon++;
            if(i!=cantBus-1){
                for(j=i+1;j<cantBus;j++){
                    if(cromo[j]==2){
                        cantDon++;
                        break;
                    }
                }
            }
            if(cantDon==2){
                ordenarMenor_Mayor(arrBuses[i]);
                ordenarMayor_Menor(arrBuses[j]);
                intercalar(arrBuses[i],arrBuses[j]);
                imprime(arrBuses[i]);
            }else if(cantDon==1){
                cout<<"Donatelo: ";
                imprime(arrBuses[i]);
                cantDon=-1;
            }
        }
        if(cromo[i]==3){
            cantMig++;
            if(i!=cantBus-1){
                for(j=i+1;j<cantBus;j++){
                    if(cromo[j]==3){
                        cantMig++;
                        break;
                    }
                }
            }
            if(cantMig==2){
                ordenarMenor_Mayor(arrBuses[i]);
                ordenarMayor_Menor(arrBuses[j]);
                intercalar(arrBuses[i],arrBuses[j]);
                imprime(arrBuses[i]);
            }else if(cantMig==1){
                cout<<"Miguel Angel: ";
                imprime(arrBuses[i]);
                cantMig=-1;
            }
        }
        
    }
    
}


int main(int argc, char** argv) {
    int cantCam=5;
    int capLeo=34;
    int capRaf=24;
    int capDon=12;
    int capMig=30;
    
    struct Lista arrBuses[cantCam];
    for(int i=0;i<cantCam;i++){
        construir(arrBuses[i]);
    }
    
    insertarAlFinal(arrBuses[0],8);
    insertarAlFinal(arrBuses[0],9);
    insertarAlFinal(arrBuses[1],15);
    insertarAlFinal(arrBuses[1],9);
    insertarAlFinal(arrBuses[2],3);
    insertarAlFinal(arrBuses[2],6);
    insertarAlFinal(arrBuses[3],1);
    insertarAlFinal(arrBuses[3],6);
    insertarAlFinal(arrBuses[3],8);
    insertarAlFinal(arrBuses[3],4);
    insertarAlFinal(arrBuses[3],6);
    insertarAlFinal(arrBuses[4],5);
    insertarAlFinal(arrBuses[4],6);
    insertarAlFinal(arrBuses[4],3);
    
    int cromo[cantCam];
    int opcion=pow(4,cantCam);
    int sumLeo=0,cantLeo=0;
    int sumRaf=0,cantRaf=0;
    int sumDon=0,cantDon=0;
    int sumMig=0,cantMig=0;
    int mComb=-1;
    
    
    for(int i=0;i<opcion;i++){
        cargarBase(cromo,i,cantCam,4);
        sumLeo = sumRaf = sumDon = sumMig =0;
        cantLeo = cantRaf = cantDon = cantMig =0;
        for(int j=0;j<cantCam;j++){
            if(cromo[j]==0){
                sumLeo+= arrBuses[j].suma;
                cantLeo++;
            }
            if(cromo[j]==1){
                sumRaf+= arrBuses[j].suma;
                cantRaf++;
            }
            if(cromo[j]==2){
                sumDon+= arrBuses[j].suma;
                cantDon++;
            }
            if(cromo[j]==3){
                sumMig+= arrBuses[j].suma;
                cantMig++;
            }
        }
        
        if(sumLeo!=0 and sumRaf!=0 and sumDon!=0 and sumMig!=0 and sumLeo<=capLeo and sumRaf<=capRaf and sumDon<=capDon and sumMig<=capMig){
            if(cantLeo<=2 and cantRaf<=2 and cantDon<=2 and cantMig<=2){
                mComb=i;
                break;
            }
        }
        
    }
    
    if(esPosibleSalvar(mComb)==1){
        imprimirListaCamiones(arrBuses,cromo,mComb,cantCam);
    }else{
        cout<<"No es posible salvar los camiones"<<endl;
    }
    
    
//    imprime(arrBuses[0]);
//    cout<<arrBuses[0].suma;
    
    return 0;
}



































