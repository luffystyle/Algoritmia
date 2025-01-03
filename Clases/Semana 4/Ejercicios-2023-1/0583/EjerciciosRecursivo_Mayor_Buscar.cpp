#include <iostream>
using namespace std;

int EncuentraMayor(int arreglo[], int longitud_arreglo) {
    int opcion1, opcion2;
    
	// Caso base: Si el arreglo tiene un solo elemento, ese es el m�ximo
    if (longitud_arreglo == 1) {
    
	//	cout<<endl<<"Longitud = " << longitud_arreglo <<endl;
    //	cout<< "Return " <<arreglo[longitud_arreglo-1]<<endl;
    
	    return arreglo[longitud_arreglo-1];
    }
    // Caso recursivo: comparar el �ltimo elemento con el m�ximo del resto del arreglo
    opcion1=arreglo[longitud_arreglo-1];//asumo que el mayor est� en mi �ltima posici�n
    opcion2=EncuentraMayor(arreglo,longitud_arreglo-1);//busco el mayor en lo que me resta del arreglo
    
    //cout<<endl<<"Longitud = " << longitud_arreglo << ". LLama a BuscaMayor("<< longitud_arreglo-1<<"), ";
	//cout<< "Return: " <<opcion2<<endl;
    //cout << "opcion1 = "<<opcion1<< " vs. opcion2 = "<<opcion2<<endl;
    
	if (opcion1<opcion2){
    	return opcion2;
	}
    
    else{
    	return opcion1;
	}
	    
}


int BuscaNumero(int arreglo[], int longitud_arreglo, int numero) {
        
	// Caso base: Si el arreglo tiene un solo elemento, ese es el m�ximo
    if (longitud_arreglo == 0) {
	    return -1; //No se encontr� el n�mero
    }
    
    if(arreglo[longitud_arreglo-1]==numero){
    	return longitud_arreglo-1;
	}
	else{
		return BuscaNumero(arreglo, longitud_arreglo-1, numero);
	}
}

int main() {
    int arr[] = {24, 20, 25, 23, 10};
    int longitud_arr = 5;
    cout << endl<< "El m�ximo n�mero del arreglo es: " << EncuentraMayor(arr, longitud_arr) << endl;
    cout << endl<< "El n�mero en el arreglo: " << BuscaNumero(arr, longitud_arr,25) << endl;
    return 0;
}
