#include <iostream>
using namespace std;

int BuscaNumero(int arreglo[], int longitud_arreglo,int numero_buscar){
	//Definimos nuestro caso base
	if (longitud_arreglo==0)//es decir NO encontramos el número
		return -1;
	if (arreglo[longitud_arreglo-1]==numero_buscar)//Si el numero a buscar está en la última posición, devuelvo la posición
		return longitud_arreglo-1;
	else//Sino, envío el resto del arreglo a la llamada recursiva
		return BuscaNumero(arreglo, longitud_arreglo-1,numero_buscar);
}


int EncuentraMayor(int arreglo[], int longitud_arreglo){
	//En Recursión siempre hay que reducir algo del problema
	//y definir nuestro CASO BASE 
	
	int opcion1, opcion2;//para evaluar qué elemento es el mayor
	
	//Tanteamos el caso base
	if (longitud_arreglo==1){//sólo nos queda 1 elemento
	
		//cout<<"Longitud = "<<longitud_arreglo<<endl;
		//cout<<"Return "<<arreglo[longitud_arreglo-1]<<endl;
		
		return arreglo[longitud_arreglo-1];//asumimos que ese último elemento es el mayor
	}
	opcion1=arreglo[longitud_arreglo-1];//tomamos el último elemento para compararlo con el mayor de los elementos restantes.
	opcion2=EncuentraMayor(arreglo, longitud_arreglo-1);//busco el mayor en el resto del arreglo
	
	//cout<<endl<<"Longitud = "<<longitud_arreglo<< ". LLama a EncuentraMayor("<<longitud_arreglo-1<<")";
	//cout<<"opcion1= "<<opcion1<<"   opcion2="<<opcion2<<endl;
	
	if (opcion1<opcion2){//comparo el último elemento (opcion1) con el mayor del resto del arreglo (opcion2)
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
	cout << "El mayor número del arreglo es: " << EncuentraMayor(arreglo, longitud_arreglo) << endl;
	cout << "El numero en el arreglo: "<<BuscaNumero(arreglo, longitud_arreglo,20)<<endl;
	return 0;
}
