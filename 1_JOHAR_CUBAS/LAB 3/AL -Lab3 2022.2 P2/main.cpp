/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int max(int a, int b){
    if(a>b){
        return a;
    }else
        return b;
}

//parte2A: para hallar la maxima radiacion con su respectiva columna
void determinarPotenciaAlta(int matriz[],int ini,int fin,int &col,int &max){
    
    int med= (ini+fin)/2;
    if(ini==fin){
        //voy comparando por tado el recorrido de cada fila de la matriz y comparo para tener la columna afiliada con la fila donde halle el max mayor
        if(matriz[ini]>max){
            max=matriz[ini];
            col=ini;
            return;
        }else{
            return ;
        }
    }
    if(matriz[med]< matriz[med+1] ){
        determinarPotenciaAlta(matriz,med+1,fin,col,max);
    }else{
        determinarPotenciaAlta(matriz,ini,med,col,max);
    }
    
}

int encontrado(int matriz[][7],int col,int ini,int med,int fin,int max){
//    if(matriz[med][col]!=max){
//        return -1;
//    }
    int encontrado =-1;
    for(int i=med;i>=ini;i--){
        if(matriz[i][col]==max){
            encontrado=i;
        }
    }
    for(int i=med+1;i<=fin;i++){
        if(matriz[i][col]==max){
            encontrado=i;
        }
    }
    return encontrado;
}

//en esta parte 2b: como ya tengo mi columna definida, solamente parto de esa columna y hago un divide
// y venceras en toda esa columna para encontrar la posicion el numero mayor
int filaMayorInpacto(int matriz[][7],int col,int ini,int fin,int max){
    if(ini==fin) {
        if(matriz[ini][col]==max){
            return ini;
        }else
            return -1;
    }
    int med =(ini+fin)/2;
    int izq= filaMayorInpacto(matriz,col,ini,med,max);
    int der= filaMayorInpacto(matriz,col,med+1,fin,max);
    int cen= encontrado(matriz,col,ini,med,fin,max);
    if(izq>der and izq>cen){
        return izq;
    }else if(der>izq and der>cen){
        return der;
    }else if(cen>der and cen>izq){
        return cen;
    }
}


int main(int argc, char** argv) {
    int n=8,m=7;
//    cout<<"Ingrese fila y columna:";
//    cin>>n>>m;
    int matriz[8][7]={{0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0},
                      {0,1,1,1,0,0,0},
                      {0,1,2,1,0,0,0},
                      {0,1,1,1,0,0,0},
                      {0,0,0,0,0,0,0}};

    int col,fila,max=0;
    for(int i=0;i<n;i++){
        determinarPotenciaAlta(matriz[i],0,n-1,col,max);  

        cout<<max<<endl;
    }
    cout<<"Para este juego de datos la potencia mas alta de bomba es "<<max<<", y la columna donde se ubica es ";
    cout<<col<<endl;
    //para la parte b)
    cout<<"La fila de mayor inpacto es la "<<filaMayorInpacto(matriz,col,0,m-1,max)<<endl;
    

    
    
    
    
    
    return 0;
}

