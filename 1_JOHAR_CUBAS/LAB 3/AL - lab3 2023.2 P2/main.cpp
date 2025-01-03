/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#define M 8
#define N 11
using namespace std;

void buscarBocaditosDemas(char matriz[][11],int fila,int ini,int fin){ // complejidad (longn)
    if(ini>fin){
        cout<<"Todo esta en orden"<<endl;
        return ;
    }
    if(ini==fin){
        cout<<"La fila "<<fila+1<<" tiene un "<<matriz[fila][ini]<<" adicional"<<endl;
        return;
    }
    int med = (ini+fin)/2;
    if(med%2==0){
        if(matriz[fila][med]==matriz[fila][med+1] and matriz[fila][med-1]!=matriz[fila][med] ){
            buscarBocaditosDemas(matriz,fila,med+2,fin);
        }else{
            buscarBocaditosDemas(matriz,fila,ini,med);
        }
    }else{
        if(matriz[fila][med]==matriz[fila][med-1] and matriz[fila][med]!=matriz[fila][med+1]){
            buscarBocaditosDemas(matriz,fila,med+1,fin);
        }else{
            buscarBocaditosDemas(matriz,fila,ini,med-1);
        }
    }
    
    
}

int mayorBocadito(int pasaj[][5],int fil,int ini,int med,int fin,int &cont){
    //esto es para que te retorne el numero dentro de la matriz
    
    int auxMayor=-999999;
    for(int i=med;i>=ini;i--){
        if(auxMayor<pasaj[fil][i]){
            auxMayor=pasaj[fil][i];
            cont=i;
        }
    }
    for(int i=med+1;i<=fin;i++){
        if(auxMayor<pasaj[fil][i]){
            auxMayor=pasaj[fil][i];
            cont=i;
        }
    }
    return auxMayor;
    
    
}


int asientoBocaditosMay(int pasaj[][5],int fil,int ini,int fin, int cont){
    if(ini==fin) return cont;
    int med= (ini+fin)/2;
    int izq=asientoBocaditosMay(pasaj,fil,ini,med,cont);
    int der=asientoBocaditosMay(pasaj,fil,med+1,fin,cont);
    int cen=mayorBocadito(pasaj,fil,ini,med,fin,cont);
    
    int mayor= max(max(izq,der),cen);
    //esto lo hago para que me de la posicion del numero mayor donde se encuentra

    if(mayor==izq) return cont;
    if(mayor==der) return cont;
    if(mayor==cen) return cont;
}



int main(int argc, char** argv) {
    char matriz[M][N]={ {'O','O','C','C','A','A','E','E','R','R','R'},
                       {'C','C','A','A','R','R','E','E','B','B','0'},
                       {'R','R','E','E','C','C','F','F','A','A','0'},
                       {'E','E','F','F','A','A','A','B','B','R','R'},
                       {'C','C','C','A','A','R','R','O','O','E','E'},
                       {'O','O','C','C','A','A','R','R','E','E','0'},
                       {'E','E','A','A','O','O','B','B','F','F','0'}};
    
    int cant;
    cant=N;
    //COMPLEJIDAD O(n logn);
    for(int i=0;i<M-1;i++){
        if(matriz[i][N-1]!='0'){
            buscarBocaditosDemas(matriz,i,0,N-1);
        } 
    }
    //pregunta 2b:
    int pasaj[8][5]= {{1,2,3,2,1},
                      {2,3,2,2,1},
                      {1,2,2,5,3},
                      {2,5,3,3,1},
                      {2,2,3,2,1},
                      {1,2,3,2,1},
                      {3,5,2,1,1},
                      {2,3,2,1,1}};
// omplejidad total : O(m*logn)
    for(int i=0;i<8;i++){ //complejidad: O(m)
        cout<<"En la fila "<<i+1<<", el pasajero del asietnto del asiento "<<asientoBocaditosMay(pasaj,i,0,4,0)+1;//complejidad (logn)
        cout<<" tiene el bocadito mas caro que sus dos vecinos"<<endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

