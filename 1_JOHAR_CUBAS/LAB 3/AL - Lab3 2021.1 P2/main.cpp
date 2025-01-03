/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <regex>

using namespace std;

void merge(int *arr,int ini,int med,int fin){
    int p1=med-ini+1;
    int p2=fin-med;
    int arrAux1[p1+1];
    int arrAux2[p2+1];
    for(int i=ini;i<=med;i++){
        arrAux1[i-ini]=arr[i];
    }
    for(int i=med+1;i<=fin;i++){
        arrAux2[i-med-1]=arr[i];
    }
    int p=0,q=0;
    arrAux1[p1]=999999;
    arrAux2[p2]=999999;
    
    for(int i=ini;i<=fin;i++){
        if(arrAux1[p]<arrAux2[q]){
            arr[i]=arrAux1[p];
            p++;
        }else{
            arr[i]=arrAux2[q];
            q++;
        }
    }
    
}


void mergesort(int *arr,int ini,int fin){
    if(ini==fin) return;
    int med= (ini+fin)/2;
    mergesort(arr,ini,med);
    mergesort(arr,med+1,fin);
    merge(arr,ini,med,fin);
}

int cuentaCeros(int *arr,int ini,int fin,int cont){//cuenta hasta la posicion ultima del 0
    if(ini>fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==0){
        return cuentaCeros(arr,med+1,fin,med+1);
    }else{
        return cuentaCeros(arr,ini,med-1,cont);
    }
}

int cuentaEspacios(int *arr,int ini,int fin,int cont){
    if(ini>fin) return cont;
    int med=(ini+fin)/2;
    if(arr[med]==-1 ){
        cuentaEspacios(arr,med+1,fin,med+1);       
    }else{
        return cuentaEspacios(arr,ini,med-1,cont);
    }
    
}
void calculoDeEstado(int matriz[][8],double porcent,int lote,int produc, int nlote){
    if(nlote==lote){
        return;
    }
    mergesort(matriz[nlote],0,produc-1);
    int cantF=cuentaCeros(matriz[nlote],0,produc-1,0);
    int cantEspacios=cuentaEspacios(matriz[nlote],0,produc-1,0);//esta por demas
    int cantC= produc - cantF;
    cout<<" "<<nlote+1<<" - ";
    double pi=(1.0)*cantC/produc;
    if(pi>=porcent){
        cout<<pi<<" Aprobado"<<endl;
    }else{
        cout<<pi<<" Rechazado"<<endl;
    }
        
          
    
    calculoDeEstado(matriz,porcent,lote,produc,nlote+1);
}



int main(int argc, char** argv) {
    int lote=6;
    double porcent=0.7;
    int produc=8;
    
    int matriz[6][8]=  {{0,0,0,1,1,0,-1,-1},
                        {1,0,1,1,0,1,1,0},
                        {0,1,1,1,1,1,1,1},
                        {1,1,1,1,1,0,1,-1},
                        {1,0,0,0,0,1,-1,-1},
                        {1,1,0,1,0,1,1,-1}};
    
    cout<<"Lote"<<setw(15)<<"Estado"<<endl;
    calculoDeEstado(matriz,porcent,lote,produc,0);
    //matriz ordenada
    for(int i =0;i<lote;i++){
        for(int j=0;j<produc;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
  
    
    return 0;
}

