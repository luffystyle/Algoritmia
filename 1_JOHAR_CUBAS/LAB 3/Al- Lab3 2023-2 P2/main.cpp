/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

char calcularBocaditoExtra(char *arr,int ini, int fin){
    if(ini==fin) return arr[ini];
    int med = (ini+fin)/2;
    if(med%2==0){
        if(arr[med]==arr[med+1]){
            return calcularBocaditoExtra(arr,med+2,fin);
        }else{
            return calcularBocaditoExtra(arr,ini,med);
        }
    }else{
       if(arr[med-1]==arr[med]){
           return calcularBocaditoExtra(arr,med+1,fin);
       }else{
           return calcularBocaditoExtra(arr,ini,med-1);
       } 
    }
    
}

int buscaPosicion(int *arr,int ini,int fin){
    if(ini==fin) return ini;
    int med= (ini+fin)/2;
    if(arr[med-1]<arr[med] and arr[med+1]<arr[med]){
        return med;
    }else{
        if(arr[med]<arr[med+1]){
            return buscaPosicion(arr,med+1,fin);
        }else{
            return buscaPosicion(arr,ini,med-1);
        }
    }
    
}


int main(int argc, char** argv) {
    
    char matriz[8][11]={{'O','O','C','C','A','A','E','E','R','R','R'},
                       {'C','C','A','A','R','R','E','E','B','B','0'},
                       {'R','R','E','E','C','C','F','F','A','A','0'},
                       {'E','E','F','F','A','A','A','B','B','R','R'},
                       {'C','C','C','A','A','R','R','O','O','E','E'},
                       {'O','O','C','C','A','A','R','R','E','E','0'},
                       {'E','E','A','A','O','O','B','B','F','F','0'}};
    
    for(int i=0;i<7;i++){
        if(matriz[i][10]!='0'){
            char bocaditoExtra= calcularBocaditoExtra(matriz[i],0,10);
            cout<<"La fila "<<i+1<<" tiene un "<<bocaditoExtra<<" adicional"<<endl;
        }
    }
    
    int bocaditos[8][5]={{1,2,3,2,1},
                        {2,3,2,2,1},
                        {1,2,2,5,3},
                        {2,5,3,3,1},
                        {2,2,3,2,1},
                        {1,2,3,2,1},
                        {3,5,2,1,1},
                        {2,3,2,1,1}};
    
    for(int i=0;i<8;i++){
        int pos= buscaPosicion(bocaditos[i],0,4);
        cout<<"En la fila "<<i+1<<", el pasajero del asiento "<<pos+1<<" tiene el bocadito mas caro que sus 2 vecinos"<<endl;
    }
    
    
    
    
    
    
    
    
    return 0;
}

