/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <complex>

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

int cantPredecesores(int numero,int &pred1,int &pred2,int &pred3){
    int cantidad=0;
    int num=numero;
    pred1=pred2=pred3=0;
    while(num>0){
        num /=10;
        cantidad++;
    }
    if(cantidad==1){
        pred1=numero%10;
    }
    if(cantidad==2){
        pred1=numero/10;
        pred2=numero%10;
    }
    if(cantidad==3){
        pred1=numero/100;
        pred2=(numero%100)/10;
        pred3=(numero%100)%10;
    }
    return cantidad;
}


int main(int argc, char** argv) {
   int tablero[][3]={{32000,0,60000},
                      {8000,0,32000},
                      {40000,12,120000},
                      {40000,0,60000},
                      {20000,0,32000},
                      {4000,2,20000},
                      {16000,6,48000},
                      {16000,6,60000}};
    
    int cantControl=8,maxMonto=100000;
    int opcion = (int)pow(2,cantControl);
    int cromo[cantControl], sumaInversion,sumaBeneficios;
    int benMaximos=-99999,mcomb ,cantCont,contador=0,maxBenf;
    int pred1,pred2,pred3,cant;
    // a) sumInversion = maxMonto =1000000
    for(int i=0;i<opcion;i++){
        cargaBin(cromo,i,cantControl);
        sumaInversion=0;
        //es decir que quiro que el beneficio sea el maximo posible
        sumaBeneficios=0;
        //inicializamos los predecesores siempre seran 3 como maximo como dicen en el riquisito, tenemos que comprobar
        pred1=pred2=pred3=0;
        for(int j=0;j<cantControl;j++){
            if(cromo[j]==1){
                //luego de verificar que el cromosoma sea un elemento seleecionado con un 1
                //verificamos si no tiene algun requisito para que el control sea seleecionado
                
                if(tablero[j][1]==0){
                    sumaInversion += tablero[j][0];
                    sumaBeneficios += tablero[j][2];
                }else{
                    //si tuviera por ejemplo requisito necitas para seleccionar el contro 3, requisito el control 1 y 2 entonces entra aca
                    //para buscar si sus predecesores controles han sido seleccionados
                    //formamos una variable cant que nos de la cantidad de controles debe ser seleccionados
                    cant=cantPredecesores(tablero[j][1],pred1,pred2,pred3);
                    if(cant==1){
                        if(cromo[pred1-1]==1){
                            sumaInversion += tablero[j][0];
                            sumaBeneficios += tablero[j][2];
                        }
                        //le pongo esta restrciion porque si no esta seleccionado el control requisito me va a seguir buscando mas controlos hasta llegar 
                        //la suma de inversion a 100k lo cual es ineficiente
                        //porque si le quito estas restriccion me sale controles demás y mal sumados
                        if(cromo[pred1-1]!=1){
                            sumaInversion =99999999;
                        }
                    }
                    if(cant==2){
                        if(cromo[pred1-1]==1 and cromo[pred2-1]==1){
                            sumaInversion += tablero[j][0];
                            sumaBeneficios += tablero[j][2];
                        }
                        if(cromo[pred1-1]!=1) sumaInversion = 99999999;
                        if(cromo[pred2-1]!=1) sumaInversion = 99999999;
                        
                    }    
                    
                    if(cant==3){
                        if(cromo[pred1-1]==1 and cromo[pred2-1]==1 and cromo[pred3-1]==1){
                            sumaInversion += tablero[j][0];
                            sumaBeneficios += tablero[j][2];
                        }
                    }
                    
                }
                   
            }
              
        }   
         if( sumaInversion == maxMonto){
            
            contador++;
            cout<<"La solucion N. "<<contador<<endl;
            cout<<"Controles: "<<endl;
            for(int j=0;j<cantControl;j++){
                if(cromo[j]==1){
                    cout<<j+1<<" ";
                }
            }
            cout<<" BENEFICIO OBTENIDO: "<<sumaBeneficios<<endl;
            cout<<endl<<endl;
        }
        
        // ESTO ES PARA LA PARTE B
            
        if( sumaBeneficios > benMaximos and sumaInversion == maxMonto){
            //para la parte b) el beneeficio maximo
            benMaximos=sumaBeneficios;
            mcomb=i;
            maxBenf= sumaBeneficios;
        }
    }
    
    //parte b)
    cout<<endl<<"LA MEJOR SOLUCION ES: "<<endl;
    for(int i=0;i<cantControl;i++){
        cargaBin(cromo,mcomb,cantControl);
        if(cromo[i]==1){
                    cout<<i+1<<" ";
        }
    }
    cout<<" EL BENEFICIO MAXIMO OBTENIDO: "<<maxBenf<<endl;
    
    
    
    
    
    return 0;
}

