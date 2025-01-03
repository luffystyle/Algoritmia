#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 16

void cargabin(int n, int numero, int cromo[16]) {
	
    int rest, i;
    for(i = 0; i<n; i++) cromo[i] = 0;//vuelvo a 0
    i = 0;//NUMERO 1
    while(numero>0) {
        rest = numero%2;        
        numero = numero/2;
        cromo[i] = rest; 
        i++;
    }
}

int main() {
	
    int peso , maxpeso = 23, n= N, cromo[N], resultado = 1, cant_espacios=0, numerito;
    int almacen[] = {7, 9, 8, 18, 17, 12, 6, 7, 14, 11, 10, 15, 19, 8, 12, 11};
    int combinaciones = (int)pow(2, N); //cantidad de cromosomas|
    for(int i = 1; i<combinaciones; i++) {
        peso=0;
        cargabin(n, i, cromo);
        numerito = 0;
        for(int j = 0; j<n; j++) peso = almacen[j]*cromo[j] + peso;
        if( peso == 23) {
            cout<<"Resultado "<<setw(2)<<resultado<<": ";
            for(int j = 0; j<n; j++) {
                if(cromo[j]==1) {
                    cout<<almacen[j]<<"k ";
                    //cant_espacios++;
                }   
            }
            //for(int k = 0; k<25-cant_espacios; k++) cout<<" ";
            cout<<"               Ubicaciones: ";
            for(int j = 0; j<n; j++) {
                if(cromo[j]/1==1) {
                    if(j%4==0 || j%4==1) cout<<"I";
                    else cout<<"D";
                    if(j%2!=0) cout<<"B";
                    else cout<<"A";
                    if(j/4 == 0) cout<<"1";
                    else if(j/4 == 1) cout<<"2";
                    else if(j/4 == 2) cout<<"3";
                    else cout<<"4";
                    cout<<" ";
                }
            }
            cout<<endl;
            resultado++;    
        }     
    }	
    return 0;
}

