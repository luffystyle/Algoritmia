/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int calculoDecrecimiento(int *arrProd,int ini,int fin){
    if(ini>=fin){
        return ini;
    }
    int med= (ini+fin)/2;
    
    if(arrProd[med]>arrProd[med+1]){
        return calculoDecrecimiento(arrProd,ini,med);
    }else{
        return calculoDecrecimiento(arrProd,med+1,fin);
    }
}

int buscaPosicion(int productBuscado,int ini,int fin,int *arr){
    if(ini>fin) return -1;
    int med=(ini+fin)/2;
    if(arr[med]==productBuscado){
        return med;
    }else{
        if(arr[med]<productBuscado){
            return buscaPosicion(productBuscado,med+1,fin,arr);
        }else{
            return buscaPosicion(productBuscado,ini,med-1,arr);
        } 
    } 
}

int buscaPosicionInversa(int productBuscado,int ini,int fin,int *arr){
    if(ini>fin) return -1;
    int med=(ini+fin)/2;
    if(arr[med]==productBuscado){
        return med;
    }else{
        if(arr[med]<productBuscado){
            return buscaPosicion(productBuscado,ini,med-1,arr);
        }else{
            return buscaPosicion(productBuscado,med+1,fin,arr);
        } 
    } 
}

void calculoDeEstock(int *arrProd,int *arrStock,int cantProduct,int productBuscado){
    int cantidCajas;
    //primero debo ubicar la posicion donde decrece;
    int posDecrecimiento=calculoDecrecimiento(arrProd,0,cantProduct-1);
    int posProd1=buscaPosicion(productBuscado,0,posDecrecimiento,arrProd);
    int posProd2=buscaPosicionInversa(productBuscado,posDecrecimiento,cantProduct-1,arrProd);
    cantidCajas=arrStock[posProd1]+arrStock[posProd2];
    
    //cout<<posDecrecimiento<<endl;
    
    
    cout<<"La cantidad de Stock del producto "<<productBuscado<<" es: "<<cantidCajas<<endl;
    cout<<"Se encuentra en las posiciones: "<<posProd1<<" y "<<posProd2<<" dentro del almacén"<<endl;
}

int main(int argc, char** argv) {
    int cantProduct=10;
    int productBuscado=20;
    int arrProd[cantProduct]={10,15,20,80,1000,200,100,50,20,10};
    int arrStock[cantProduct]={20,20,30,10,10,10,20,20,20,10};
    
    calculoDeEstock(arrProd,arrStock,cantProduct,productBuscado);

    return 0;
}

