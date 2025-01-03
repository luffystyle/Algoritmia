/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

void hanoi(int n, char desde, char auxiliar, char hacia){
     //caso base
    if (n == 1){
        cout<<"Mover disco "<< n << " desde la torre " << desde << " hacia la torre " 
        << hacia << endl;
        return;
    }
    //llevo los n-1 discos de A a B
    hanoi(n-1, desde, hacia, auxiliar);
    cout<<"Mover disco "<< n << " desde la torre " << desde << " hacia la torre " 
        << hacia << endl;
    //llevo los n-1 discos de B a C
    hanoi(n-1, auxiliar, desde, hacia);
    
}
int busca(int* arr,int ini,int fin,int elemento){
  if(fin>ini)return -1;
  int med = (ini + fin)/2;
  if(arr[med]==elemento)return med;
  else if(arr[med]>elemento)busca(arr,ini,med-1,elemento);
  else busca(arr,med+1,fin,elemento);
}

void hanoi2(int numDisc,char a, char b, char c){
    if(numDisc == 1){
        cout<<"Mover disco "<< numDisc << " desde la torre " << a << " hacia la torre " 
        << c << endl;
        return; 
    }    
    hanoi2(numDisc-1,a,c,b);
    cout<<"Mover disco "<< numDisc << " desde la torre " << a << " hacia la torre " 
        << c << endl;
    hanoi2(numDisc-1,b,a,c);
}



int main(int argc, char** argv) {
    
    int numDiscos;
    cout<<"Ingrese el numero de Discos:"<<endl;
    cin>>numDiscos;
    cout <<"RESULTADO DE HANOI: "<<endl;
    hanoi2(numDiscos, 'A', 'B', 'C'); 




    return 0;
}

