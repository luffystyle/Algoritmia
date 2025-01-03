/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

void cargaBin(int *cromo,int num,int cant){
    for(int i=0;i<cant;i++) cromo[i]=0;
    int i=0;
    while(num>0){
        cromo[i]= num%2;
        num /=2;
        i++;
    }
    
}

void tipoArmasRequeridas(int *guerrero,int &tipo1,int &tipo2,int &tipo3){
    for(int i=0;i<4;i++){
        if(i==2) tipo1 = guerrero[i];
        if(i==3) tipo2 = guerrero[i];
    }
    tipo3=0;
}

int validarPrerequisitos(int *cromo,int cant,int pos, int armas[][5]){
    int req1=0,req2=0,req3=0,esValido=-1;
    for(int i=3;i<cant;i++){
        if(armas[pos][i]!=0 and i==3) req1 = armas[pos][i];
        if(armas[pos][i]!=0 and i==4) req2 = armas[pos][i];
    }
    int esValido1,esValido2 ;
    if(req1!=0 and req2!=0){
        for(int j=0;j<12;j++){
            if(armas[j][0]== req1){
                if(cromo[j]==1){
                    esValido = 1;
                }else{
                    esValido=-1;
                }
            }
        }
        if(esValido==-1) return -1;
        for(int j=0;j<12;j++){
            if(armas[j][0]== req2){
                if(cromo[j]==1){
                    esValido = 1;
                }else{
                    esValido= -1;
                }
            }
        }
        if(esValido==-1) return -1;
    }else if(req1!=0 and req2==0){
         for(int j=0;j<12;j++){
            if(armas[j][0]== req1){
                if(cromo[j]==1){
                    esValido = 1;
                }else{
                    esValido=-1;
                }
            }
        }
        
    }else if(req2!=0 and req1==0){
        for(int j=0;j<12;j++){
            if(armas[j][0]== req2){
                if(cromo[j]==1){
                    esValido = 1;
                }else{
                    esValido= -1;
                }
            }
        }
        
    }
    
    
    return esValido;
}

int main(int argc, char** argv) {
    
    int guerrero[3][4]={{1,120,2,0},
                        {2,160,1,3},
                        {3,80,3,0}};
    int letras[12] = {'Z','P','R','D','E','F','G','H','I','J','K','L'};
                    // 1   2   3   4   5   6   7   8   9   10 11   12
    int armas[12][5]={{1,60,3,0},
                    {2,80,1,1},
                    {3,38,2,0},
                    {4,25,2,3},
                    {5,49,2,0},
                    {6,57,1,0},
                    {7,68,3,0},
                    {8,35,2,1,5},
                    {9,62,2,3},
                    {10,42,2,0},
                    {11,36,1,1},
                    {12,54,3,0}};
    
    int cromo[12];
    int opciones= pow(2,12);
    for(int x=0;x<3;x++){
        int poder = guerrero[x][1];
        int tipo1,tipo2,tipo3;
        tipoArmasRequeridas(guerrero[x],tipo1,tipo2,tipo3);
        cout<<"Guerrero "<<x+1<<endl<<endl;
        cout<<"Poder: "<<poder<<endl<<endl;
        cout<<tipo1<<" "<<tipo2<<endl;
        for(int i=0;i<opciones;i++){
            cargaBin(cromo,i,12);
            int suma=0;
            int suma2=0;
            int suma3=0;
            for(int j=0;j<12;j++){
                if(cromo[j]==1){
                    if(armas[j][2]==tipo1 or armas[j][2]==tipo2){
                        int valida = validarPrerequisitos(cromo,5,j,armas);
                        if(valida!=-1){
                            suma += armas[j][1];
                        }else{
                            suma3 += armas[j][1];
                        }

                    } else{
                        suma2 += armas[j][1];
                    }
                }
            }    
            if(suma2==0 and suma3 ==0 and suma>=poder){
                cout<<"Armas en mochila para vencerlo: ";
                for(int i=0;i<12;i++){
                    if(cromo[i]==1){
                        cout<<i<<" ";
                    }
                }
                cout<<endl<<endl;
                
            }

        }
    }
    
    
    return 0;
}

