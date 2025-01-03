#include <iostream>
using namespace std;

int BuscaNumero(int arreglo[], int longitud_arreglo,int numero_buscar){
	//Definimos nuestro caso base
	if (longitud_arreglo==0)//es decir NO encontramos el n�mero
		return -1;
	if (arreglo[longitud_arreglo-1]==numero_buscar)//Si el numero a buscar est� en la �ltima posici�n, devuelvo la posici�n
		return longitud_arreglo-1;
	else//Sino, env�o el resto del arreglo a la llamada recursiva
		return BuscaNumero(arreglo, longitud_arreglo-1,numero_buscar);
}


int EncuentraMayor(int arreglo[], int longitud_arreglo){
	//En Recursi�n siempre hay que reducir algo del problema
	//y definir nuestro CASO BASE 
	
	int opcion1, opcion2;//para evaluar qu� elemento es el mayor
	
	//Tanteamos el caso base
	if (longitud_arreglo==1){//s�lo nos queda 1 elemento
	
		//cout<<"Longitud = "<<longitud_arreglo<<endl;
		//cout<<"Return "<<arreglo[longitud_arreglo-1]<<endl;
		
		return arreglo[longitud_arreglo-1];//asumimos que ese �ltimo elemento es el mayor
	}
	opcion1=arreglo[longitud_arreglo-1];//tomamos el �ltimo elemento para compararlo con el mayor de los elementos restantes.
	opcion2=EncuentraMayor(arreglo, longitud_arreglo-1);//busco el mayor en el resto del arreglo
	
	//cout<<endl<<"Longitud = "<<longitud_arreglo<< ". LLama a EncuentraMayor("<<longitud_arreglo-1<<")";
	//cout<<"opcion1= "<<opcion1<<"   opcion2="<<opcion2<<endl;
	
	if (opcion1<opcion2){//comparo el �ltimo elemento (opcion1) con el mayor del resto del arreglo (opcion2)
		//cout<<"Return "<<opcion2<<endl;
		return opcion2;
	}
	else{
		//cout<<"Return "<<opcion1<<endl;
		return opcion1;
	}
}

int main(){
	int arreglo[]={24,20,25,23,10};
	int longitud_arreglo=5;
	cout << "El mayor n�mero del arreglo es: " << EncuentraMayor(arreglo, longitud_arreglo) << endl;
	cout << "El numero en el arreglo: "<<BuscaNumero(arreglo, longitud_arreglo,20)<<endl;
	return 0;
}
