/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>

using namespace std;

int busquedaBinaria2(int *arr,int ini, int fin, int elemento){
    if(ini > fin) return -1;
    
    int med= (ini+fin)/2;
    
    if(arr[med]==elemento){
        return med;
    }else{
        if(arr[med]<elemento){
            return busquedaBinaria2(arr,med+1,fin,elemento);
        }else{
            return busquedaBinaria2(arr,ini,med-1,elemento);
        }
    }
    
    
    
}




int busquedaBinaria(int *arr,int ini,int fin,int numBuscado){
    if(ini>fin)return -1;
    int medio = (ini + fin)/2;
    if(arr[medio] == numBuscado) return medio;
    else
        if(arr[medio]<numBuscado)
            return busquedaBinaria(arr,medio+1,fin,numBuscado);
        else
            return busquedaBinaria(arr,ini,medio-1,numBuscado);
    
    
}

void merge(int *arr,int ini,int med,int fin){
    int p1=med-ini+1;
    int p2=fin-med;
    int aux1[p1+1];
    int aux2[p2+1];
    
    for(int i=ini;i<=med;i++)
        aux1[i-ini]=arr[i];
    for(int i=med+1;i<=fin;i++)
        aux2[i-med-1]=arr[i];
    aux1[p1]=999999;
    aux2[p2]=999999;        
    int p=0,q=0;
    for(int i=ini;i<=fin;i++){
        if(aux1[p]<aux2[q]){
            arr[i]=aux1[p];
            p++;
        }
        else{
            arr[i]=aux2[q];
            q++;
        }
    }    
}


void mergesort(int *arr,int ini,int fin){
    if(ini==fin) return;
    
    int med=(ini+fin)/2;
    mergesort(arr,ini,med);
    mergesort(arr,med+1,fin);
    merge(arr,ini,med,fin);
}

void buscaSolo2(int *arr,int ini,int fin){
    if(ini > fin) return;
    if(ini==fin){
        cout<<arr[ini]<<endl;
    }
    int med = (ini+fin)/2;
    
    if(med%2==0){
        if(arr[med]==arr[med+1]){
            buscaSolo2(arr,med+2,fin);
        }else{
            buscaSolo2(arr,ini,med);
        }
    }else{
        if(arr[med-1]==arr[med]){
            buscaSolo2(arr,med+1,fin);
        }else{
            buscaSolo2(arr,ini,med-1);
        }
        
    }
    
}







void buscasolo(int *arreglo,int ini,int fin){
    if(ini>fin){
        cout<<"No se encontro una pareja sola"<<endl;
        return;
    }
    if(ini == fin){
        cout<<arreglo[ini]<<endl;
        return;  
    }
    int med= (ini+fin)/2;
    
    if(med%2==0){
        if(arreglo[med]==arreglo[med+1]){
            buscasolo(arreglo,med+2,fin);
        }else{
            buscasolo(arreglo,ini,med);
        }
    }else{
        if(arreglo[med]== arreglo[med-1]){
            buscasolo(arreglo,med+1,fin);
        }else{
            buscasolo(arreglo,ini,med-1);
        }
    } 
}

int buscaCeros(int *arr,int ini,int fin, int cont){
    if(ini>fin) return cont;
    int med= (ini+fin)/2;
    //si encuentras un 0 al medio entonces avansas xq sabes que todo lo anterior es 0 
    if(arr[med] == 0){
        return buscaCeros(arr,med+1,fin,med+1);
    }else{
        return buscaCeros(arr,ini,med-1,cont);
    }   
}
 
int buscaUnos(int *arr4,int ini,int fin, int cont){
    if(ini>fin) return cont;
    int med=(ini+fin)/2;
    if(arr4[med]==1){
        return buscaUnos(arr4,ini,med-1,cont+fin-med+1);
    }else
        return buscaUnos(arr4,med+1,fin,cont);
}

int buscarMaximo(int *arr,int ini,int fin){
    if(ini>=fin) return arr[ini];
    int med=(ini+fin)/2;
    
    if(arr[med]>arr[med+1]){
        return buscarMaximo(arr,ini,med);
    }else{
        return buscarMaximo(arr,med+1,fin);
    }
}

int max(int a,int b){
    if(a>b) return a;
    return b;
}
int maxcentro(int *arr,int ini,int med,int fin){
    int izq=1,der=1;
    
    if(arr[med]>arr[med+1]) 
        return 1;
    
    for(int i=med;i>ini;i--)
        if(arr[i]>arr[i-1])
            izq++;
        else
            break;

    for(int i=med+1;i<fin;i++)
        if(arr[i+1]>arr[i])
            der++;
        else
            break;  
    
    return der+izq;
}


int cuentaincremento(int *arr,int ini,int fin){
    
    if(ini==fin) return 1;
    int med=(ini+fin)/2;
    int izq = cuentaincremento(arr,ini,med);
    int der = cuentaincremento(arr,med+1,fin);
    int cen = maxcentro(arr,ini,med,fin);
    
    return max(max(izq,der),cen);
    
}

int numeroDecrecimiento(int *arr,int ini,int fin){
    if(ini>=fin) return arr[ini];
    int med=(ini+fin)/2;
    //tiene que moverse a la derecha el med
    if(arr[med-1]<arr[med]){
        return numeroDecrecimiento(arr,med+1,fin);
    }else{
        return numeroDecrecimiento(arr,ini,med-1);
    }
    
    
}

int sumarNumerosContinuos(int *arr,int ini,int med,int fin){
    int suma=0;
    int sumaIzq =-99999;
    int sumaDer =-99999;
    
    for(int i=med;i>=ini;i--){
        suma += arr[i];
        if(suma>sumaIzq){
            sumaIzq=suma;
        }
    }
        
    
    int suma2=0;
    for(int i=med+1;i<=fin;i++){
        suma2 += arr[i];
        if(suma2 > sumaDer){
            sumaDer = suma2;
        }
    }
    return sumaIzq + sumaDer;
}


int encontrarNumerosDeSumaMaxima(int *arr,int ini,int fin){
    if(ini==fin){
        return arr[ini];
    }
    
    int med=(ini+fin)/2;
    int izq = cuentaincremento(arr,ini,med);
    int der = cuentaincremento(arr,med+1,fin);
    int cen = sumarNumerosContinuos(arr,ini,med,fin);
    
    return max(max(izq,der),cen);
}

int encontrarNumMin(int *arr,int ini,int fin){
    if(ini>=fin) return arr[ini];
    int med= (ini+fin)/2;
    
    if(arr[med]<arr[fin]){
        return encontrarNumMin(arr,ini,med);
    }else{
        return encontrarNumMin(arr,med+1,fin);
    }
    
    
}

int main(int argc, char** argv) {
    
    int arreglo[]={4,6,8,9,10,14,16,19};
    int n=8;
    int arr2[]={9,13,8,18,12,5};
    int n2=6;
    cout<<"La posicion en la que se encuentra es: "<<busquedaBinaria2(arreglo,0,n-1,19)+1<<endl;
    mergesort(arr2,0,n2-1);
    cout<<"Utilizacion del merge sort:"<<endl;
    for(int i=0;i<n2;i++)
        cout << arr2[i] << " "; 

    int arreglo3[]={3,3,5,5,6,6,7,7,9};
    int n3=9;
    cout<<endl<<"Buscar Pareja sola "<<endl;
    buscasolo(arreglo3,0,n3-1);
    cout<<"Buscar Cuantos 0 hay en el arreglo"<<endl;
    int arr4[]={0,0,1,1,1,1,1,1};
    int n4=8;
    cout<<buscaCeros(arr4,0,n4-1,0)<<endl;
//    cout<<"Cuantoa 1 hay en el arreglo:"<<endl;
//    cout<<buscaUnos(arr4,0,n4-1,0);
//    
    cout<<endl<<"Buscar maximo numero :"<<endl;
    int arr5[]={12,24,15,12,11,10};
    int n5=6;
    cout<<buscarMaximo(arr5,0,n5-1);
//    
//    cout<<endl<<"Cuenta incrementos"<<endl;
//    int arr6[]={10,20,25,10,2,20,23,28};
//    int n6=8;
//    cout<<cuentaincremento(arr6,0,n6-1);
//    cout<<endl<<"Encontrar el numero donde empieza el decrecimiento:"<<endl;
//    
//    int arr7[]={8,10,20,80,100,200,400,500,3,2,1};
//    int n7=11;
//    cout<<numeroDecrecimiento(arr7,0,n7-1)<<endl;
//    
//    int arr8[]={-2, -5, 6, -2, -3, 1, 5, -6};
//    int n8=8;
//    cout<<"Encontrar la suma maxima:"<<endl;
//    cout<<encontrarNumerosDeSumaMaxima(arr8,0,n8-1)<<endl;
//    
//    int arr9[]={5, 6, 1, 2, 3, 4};
//    int n9=6;
//    cout<<"Encontrar el numero minimo:"<<endl;
//    cout<<encontrarNumMin(arr9,0,n9-1)<<endl;
//    
    
    return 0;
}

