#include <iostream>
using namespace std;

int busqueda_binaria(int A[],int k, int inicial, int final){
	if (inicial>final)//si no encuentra a "K"
		return -1;
	
	int medio=(inicial+final)/2; //calculamos nuestra posición medio
	
	if (A[medio]==k)//si hemos encontrado el elemento "K"
		return medio;
	else
		if (A[medio]>k)//descarto el subarreglo de la derecha y analizo el subarreglo de la izquierda
			return busqueda_binaria(A,k,inicial,medio-1);
		else//descarto el subarreglo de la izquierda y analizo el subarreglo de la derecha
			return busqueda_binaria(A,k,medio+1,final);
}

int main(){
	int A[]={1,5,7,9,12,15,17,20};
	int n=8;
	int k=17;
	
	int posicion=busqueda_binaria(A,k,0,n-1);
	if (posicion==-1)
		cout<<"El elemento no se encuentra."<<endl;
	else 
		cout<<"El elemento se encuentra en la posición: "<<posicion+1<<endl;
	
	return 0;
}
