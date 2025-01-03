/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;


void merge(int *arr,char *arrChar,int ini,int med,int fin){
    int p1=med-ini+1;
    int p2=fin-med;
    int arrAux1[p1+1];
    int arrAux2[p2+1];
    char arrAux_1[p1+1];
    char arrAux_2[p2+1];
    for(int i=ini;i<=med;i++){
        arrAux1[i-ini]=arr[i];
        arrAux_1[i-ini]=arrChar[i];
    }
    for(int i=med+1;i<=fin;i++){
        arrAux2[i-med-1]=arr[i];
        arrAux_2[i-med-1]=arrChar[i];
    }
    arrAux1[p1]=99999;
    arrAux2[p2]=99999;
    int p=0,q=0;
    for(int i=ini;i<=fin;i++){
        if(arrAux1[p]<arrAux2[q]){
            arr[i]=arrAux1[p];
            arrChar[i]=arrAux_1[p];
            p++;
        }else{
            arr[i]=arrAux2[q];
            arrChar[i]=arrAux_2[q];
            q++;
        }
        
    }
    
    
}

void mergeSort(int *matriz,char *arrAux,int ini,int fin){
    if(ini==fin) return;
    int med=(ini+fin)/2;
    mergeSort(matriz,arrAux,ini,med);
    mergeSort(matriz,arrAux,med+1,fin);
    merge(matriz,arrAux,ini,med,fin);
}

int buscarPosicion(int *matriz,int ibd,int ini,int fin){
    if(ini>fin) return -1;
    int med= (ini+fin)/2;
    if(matriz[med]==round(ibd)){
        return med;
    }else{
        if(matriz[med]<ibd){
            return buscarPosicion(matriz,ibd,med+1,fin);
        }else{
            return buscarPosicion(matriz,ibd,ini,med-1);
        }
        
    }
    
}


void calculoDeInversion(int matriz[][7],char *val,int cantAcciones,int cantDia,double iBm){
    int sumaIbd;
    char arrAux[cantAcciones];
    cout<<"Dia"<<setw(7)<<"IBd"<<setw(4)<<" "<<setw(3)<<"Descicion"<<setw(4)<<" "<<setw(5)<<"Monto"<<setw(10)<<"Acciones"<<endl;
    for(int i=0;i<cantDia;i++){
        cout<<i+1<<setw(5)<<" ";
        sumaIbd=0;
        for(int j=0;j<cantAcciones;j++){
            sumaIbd += matriz[i][j];
            arrAux[j]=val[j];
        }
        double ibd=(double)sumaIbd/(cantAcciones);
        cout<<fixed<<setprecision(3)<<(double)sumaIbd/(cantAcciones)<<setw(3)<<" ";
        mergeSort(matriz[i],arrAux,0,cantAcciones-1);
        int posicion = buscarPosicion(matriz[i],ibd,0,cantAcciones-1);
        if(ibd<=iBm){//compro
            int montoComp=0;
            for(int j=0;j<=posicion;j++){
                montoComp+=matriz[i][j];
            }
            cout<<setw(8)<<"Compro"<<setw(6)<<montoComp<<setw(3)<<" ";
            for(int j=0;j<=posicion;j++){
                cout<<arrAux[j]<<" ";
            }
        }else{//vendo
            int montoVent=0;
            for(int j=posicion+1;j<cantAcciones;j++){
                montoVent+=matriz[i][j];
            }
            cout<<setw(8)<<"Vendo"<<setw(6)<<montoVent<<setw(3)<<" ";
            for(int j=posicion+1;j<cantAcciones;j++){
                cout<<arrAux[j]<<" ";
            }
        }
        cout<<endl;
        
    }
}



int main(int argc, char** argv) {
    int cantAcciones=7;
    int cantDia=6;
    double iBm=4.2;
    char valores[cantAcciones]={'A','B','C','D','E','F','G'};
    int matriz[6][7]={{8,4,5,6,7,1,2},
                      {3,4,5,7,1,2,6},
                      {5,6,5,2,1,6,8},
                      {3,4,5,6,2,1,9},
                      {3,4,5,4,5,3,2},
                      {3,4,4,8,9,7,6} };
    calculoDeInversion(matriz,valores,cantAcciones,cantDia,iBm);
    
    
    return 0;
}

