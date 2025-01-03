/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int encontrarProductoEquivocado(int *arrProd,int ini,int fin){
    if(ini==fin) return arrProd[ini];
    int med=(ini+fin)/2;
    
    if(med%2==0){
        if(arrProd[med]==arrProd[med+1]){
            return encontrarProductoEquivocado(arrProd,med+2,fin);
        }else
            return encontrarProductoEquivocado(arrProd,ini,med);
    }else{
        if(arrProd[med-1]==arrProd[med]){
            return encontrarProductoEquivocado(arrProd,med+1,fin);
        }else{
            return encontrarProductoEquivocado(arrProd,ini,med-1);
        }
    }
    
}

void productoNodeseado(int *arrProd,int ini,int fin,int &pos){
    if(ini==fin){
        cout<<"El producto no deseado es : "<<arrProd[ini]<<endl;
        pos=arrProd[ini];
        //siempre te da la repeticion del ultimo de las 3 repetciones
        cout<<"Los posiciones estan: "<<ini<<" ";
        cout<<ini-1<<" "<<ini-2<<endl;
        return;
    }
    int med=(ini+fin)/2;
    
    if(med%2==0){
        if(arrProd[med]==arrProd[med+1]){
            productoNodeseado(arrProd,med+2,fin,pos);
        }else
            productoNodeseado(arrProd,ini,med,pos);
    }else{
        if(arrProd[med-1]==arrProd[med]){
             productoNodeseado(arrProd,med+1,fin,pos);
        }else{
            productoNodeseado(arrProd,ini,med-1,pos);
        }
    }
}
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}


int main(int argc, char** argv) {
    int cantPro=11;
    int arrStock[cantPro]={20,20,30,10,10,10,20,20,20,10,10};
    int arrProd[cantPro]={1,1,2,2,4,4,5,5,5,6,6};
    int codigo,sumaStock=0;
    int codigoProductNoEs=encontrarProductoEquivocado(arrProd,0,cantPro-1);
    //si deseo que se muestre lo cambio a void
    productoNodeseado(arrProd,0,cantPro-1,codigo);
    cout<<codigo<<endl;
    
    return 0;
}

