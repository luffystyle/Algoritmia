/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int recursivaInterna(int maquinas[][3],int n,int fil,int col){
    int maxProductos;
    if(col==n-1) return maquinas[fil][col];
    maxProductos = recursivaInterna(maquinas,n,fil,col+1);
    if(maquinas[fil][col]>=maxProductos){
            maxProductos =maquinas[fil][col];
    }
    return maxProductos;
}



int recursion(int maquinas[][3],int n,int fil,int col,int &obrero1,int &obrero2,int &obrero3){
    int maximoProductos;
    int cantProduct=0,arreglo[3]={};
    if(col==n or fil==n) return 0;
    //arreglo[fil]=recursivaInterna(maquinas,n,fil,0);
    cantProduct = recursion(maquinas,n,fil+1,col,obrero1,obrero2,obrero3);
    maximoProductos = recursivaInterna(maquinas,n,fil,0);
    if(fil==2) obrero3=maximoProductos;
    if(fil==1) obrero2=maximoProductos;
    if(fil==0) obrero1=maximoProductos;
    
    return cantProduct + maximoProductos;
}



int main(int argc, char** argv) {
    int maquinas[][3]= {{100,150,200},
                        {100,100,100},
                        {100,200,150}};
    int obrero1,obrero2,obrero3;
    
    cout<<"La cantidad maxima de productos es: "<<recursion(maquinas,3,0,0,obrero1,obrero2,obrero3)<<endl;
    cout<<"Obrero 1: "<<obrero1<<endl;
    cout<<"Obrero 2: "<<obrero2<<endl;
    cout<<"Obrero 3: "<<obrero3<<endl;
    
    
    
    return 0;
}

