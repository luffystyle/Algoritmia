/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
void cargarBin(int cromo[], int num, int n){
    for(int i=0;i<n;i++) cromo[i]=0;
    int i=0;
    while(num>0){
        cromo[i]= num%2;
        num /=2;
        i++;
    }
    
}
void intercambiar(int arr[],int i,int j){
    int aux = arr[i];
    arr[i]=arr[j];
    arr[j]=aux;
}
void interDouble(double arr[],int i,int j){
    double aux = arr[i];
    arr[i]=arr[j];
    arr[j]=aux;    
}
void ordenarArr(int proy[],int costo[],int gananc[],double predece[],int cant){
    for(int i=0;i<cant-1;i++){
        for(int j=1+i;j<cant;j++){
            if(gananc[i]<gananc[j]){
                intercambiar(gananc,i,j);
                intercambiar(proy,i,j);
                intercambiar(costo,i,j);
                interDouble(predece,i,j);
            }
        }
    }
    
    
    
}




int main(int argc, char** argv) {
////    int n=8,proy[]={1,2,3,4,5,6,7,8};
////    int costo[]={80,20,100,100,50,10,50,50};
////    int gananc[]={150,80,300,150,80,50,120,150};
////    double predece[]={0,0,1.2,0,0,2,6,6};
////    int p=250;
////    int cromo[n];
////    int opcion = (int)pow(2,n);
////    int sumGanancia,predecesores=3,sumPresupuesto;
////    double sumPredece;
////    int ganMax=-99999,mcomb;
////    for(int i=0;i<opcion;i++){
////        cargarBin(cromo,i,n);
////        sumGanancia =0;
////        sumPresupuesto =0;
////        sumPredece=0;
////        
////        for(int j=0;j<n;j++){
////            sumGanancia += cromo[j]*gananc[j];
////            sumPresupuesto += cromo[j]*costo[j];
////            sumPredece += cromo[j]*predece[j]*1.0;
////        }
////        
////        if(sumGanancia > ganMax and sumPresupuesto<=p and sumPredece<=3){
////            ganMax = sumGanancia;
////            mcomb = i;
////        }
////    }
////    cout<<mcomb<<endl;
////    cargarBin(cromo,mcomb,8);
////    for(int i=0;i<8;i++){
////        if(cromo[i]==1){
////            cout<<proy[i]<<endl;
////        }
////    }
////    cout<<"Proyectos ordenados de manera descendente en funcion a la ganancia:"<<endl;
////    ordenarArr(proy,costo,gananc,predece,8);
////    int cromo2[8]={};
////    cargarBin(cromo2,mcomb,8);
////    for(int i=0;i<8;i++){
////       // if(cromo[i]==1){
////            cout<<proy[i]<<endl;
////        //}
////    }
    
    //PREGUNTA 2:
    
    int matriz[][4]={{101,2,10,2},
                    {102,3,12,2},
                    {103,1,13,2},
                    {104,3,15,1},
                    {105,1,10,2},
                    {106,4,16,1},
                    {107,2,8,2},
                    {108,3,14,1},
                    {109,2,18,2},
                    {110,1,18,2},
                    {111,4,14,2}};
    int cromo[12];
    int opcion=(int)pow(2,12) ;
    int hora[24],cruce,mcomb;
    for(int i=0;i<opcion;i++){
        cargarBin(cromo,i,12);
        for(int x=0;x<24;x++) hora[x]=0;
        int prio1=0,prio2=0,prio3=0,prio4=0;
        cruce =0;
        for(int j=0;j<12;j++){
            if(cromo[j]==1){
                if(matriz[j][1]==1) prio1++;
                if(matriz[j][1]==2) prio2++;
                if(matriz[j][1]==3) prio3++;
                if(matriz[j][1]==4) prio4++;
                for(int h=matriz[j][2];h<matriz[j][2]+matriz[j][3];h++){
                        
                    if(hora[h]!=1){
                        hora[h]=1;
                    }else{
                        cruce=1; 
                        break;
                    } 
                }
                
                if(cruce==1) break;
            }
            
        }
        
        if(prio1==2 and prio2==2 and prio3 ==1 and prio4==1 and cruce!=1){
            mcomb=i;
            cout<<i<<endl;
            for(int l=0;l<12;l++){
                    if(cromo[l]==1){
                            cout<<matriz[l][0]<<"  "<<matriz[l][1]<<endl;
                    }
            }
            break;

        }
        
        
    }
    int n=8,proy[]={1,2,3,4,5,6,7,8};
   int costo[]={80,20,100,100,50,10,50,50};
    int gananc[]={150,80,300,150,80,50,120,150};
    double predece[]={0,0,1.2,0,0,2,6,6};
    ordenarArr(proy,costo,gananc,predece,8);
    for(int i=0;i<8;i++){
        cout<<proy[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<8;i++){
        cout<<costo[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<8;i++){
        cout<<gananc[i]<<" ";
    }
    cout<<endl;
    
    
    
    return 0;
}

