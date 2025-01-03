/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

void llenarArrglos(int *arr,int matriz_reg[][6]){
    int k=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            arr[k]=matriz_reg[i][j];
            k++;
        }
    }
    
}

void merge(int *arr_R,int *arr_L,int ini,int med,int fin){
    int p1=med-ini+1;
    int p2=fin-med;
    int aux1[p1+1];
    int aux2[p2+1];
    int aux1_L[p1+1];
    int aux2_L[p2+1];
    
    for(int i=ini;i<=med;i++){
        aux1[i-ini]=arr_R[i];
        aux1_L[i-ini]= arr_L[i];
    }
    for(int i=med+1;i<=fin;i++){
        aux2[i-med-1]=arr_R[i];
        aux2_L[i-med-1]=arr_L[i];
    }
    
    aux1[p1]=99999;
    aux1_L[p1]=99999;
    aux2[p2]=99999;
    aux2_L[p2]=99999;
    int p=0,q=0,m=0,n=0;
    
    for(int i=ini;i<=fin;i++){
        if(aux1[p]<aux2[q]){
            arr_R[i]=aux1[p];
            arr_L[i]=aux1_L[m];
            m++;
            p++;
        }else{
            arr_R[i]=aux2[q];
            arr_L[i]=aux2_L[n];
            q++;
            n++;
        }
    }
    
    
    
    
}


void mergeSort(int *arr_R,int *arr_L,int ini,int fin){
    if(ini==fin) return;
    int med=(ini+fin)/2;
    mergeSort(arr_R,arr_L,ini,med);
    mergeSort(arr_R,arr_L,med+1,fin);
    merge(arr_R,arr_L,ini,med,fin);
}

int sumaDeCodigosVirus(int *arr_R,int *arr_L,int ini,int fin,int codigo){
    if(ini>fin) return 0; 
    int med=(ini+fin)/2;
    
    if(arr_R[med]==codigo){          
        int a =sumaDeCodigosVirus(arr_R,arr_L,ini,med-1,codigo); 
        int b =sumaDeCodigosVirus(arr_R,arr_L,med+1,fin,codigo); 
        return arr_L[med] + a + b ;
    }else{
        int a = sumaDeCodigosVirus(arr_R,arr_L,ini,med-1,codigo);
        int b = sumaDeCodigosVirus(arr_R,arr_L,med+1,fin,codigo) ;
        return  a+b ;
    }
    
}



int main(int argc, char** argv) {
    
    int matriz_reg[5][6]={ {-1,-2,-3,-4,-5,-6},
                           {-7,-8,1,-9,2,-10},
                           {-11,1,2,-12,-13,-14},
                           {-15,-16,-17,1,-18,-19},
                           {-20,1,2,-21,-22,-23}};
    
    
    int matriz_lineas[5][6]={ {10,5,8,9,8,1},
                              {10,5,2,8,2,3},
                              {4,2,1,4,8,1},
                              {1,2,4,3,5,3},
                              {8,3,3,8,5,3}};
    
    int cantidad=5*6;
    int arr_Regis[cantidad];
    int arr_Lineas[cantidad];
    
    llenarArrglos(arr_Regis,matriz_reg);
    llenarArrglos(arr_Lineas,matriz_lineas);
    int codigo;
    mergeSort(arr_Regis,arr_Lineas,0,cantidad-1);
    cout<<"Ingresa el codigo de virus a elegir"<<endl;
    cin>>codigo;
    
    int cant=sumaDeCodigosVirus(arr_Regis,arr_Lineas,0,cantidad-1,codigo);
    
    cout<<"La cantidad es:"<<cant<<endl;
    for(int i=0;i<cantidad;i++){
        cout<<arr_Regis[i]<<" ";
    } 
    cout<<endl;
    for(int i=0;i<cantidad;i++){
        cout<<arr_Lineas[i]<<" ";
    }    
    return 0;
}

