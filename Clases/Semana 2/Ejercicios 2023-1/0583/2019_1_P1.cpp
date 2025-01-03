#include <iostream>
#include <math.h>


using namespace std;

void cargaBinaria(int numero,int cromosoma[],int longitud_cromosoma){
	int i, aux;
	for (i=0; i<longitud_cromosoma; i++){
		cromosoma[i] = 0;
	}
	i = 0;
	while (numero>0){
		aux = numero%2;
		numero = numero/2;
		cromosoma[i] = aux;
		i++;
	}
}

int main(){
	int i,j; 
	
	//variable para la cantidad de productos que puede traer en la mochila
	int cantidad_productos;//Limitante: cantidad de productos
	cout<<"Ingrese cantidad máxima de productos que puede traer (M)";
	cin >> cantidad_productos;
	
	int peso_maximo; //es la limitante de la mochila: el peso de la mochila
	//Solicitamos el peso maximo a considerar (nuestra limitante)
	cout << "Peso máximo de la mochila, según aerolínea: ";
	cin >> peso_maximo;
	

	int productos[cantidad_productos][2]; // peso de las cajas

	//Solicitamos el ingreso de los datos
	for (i=0;i<cantidad_productos;i++){
		cout << "Artículo N° " << i+1 << ": ";
		cout << "Peso (p): ";
		cin >> productos[i][0];//productos[][0] es para el peso del producto
		cout << "Ganancia (g): ";
		cin >> productos[i][1];//productos[][1] es para la ganacia del producto
		cout << endl;
	}
	
	int cromosoma[cantidad_productos]; //arreglo de nuestro cromosoma
	int peso_mochila, //es el peso que iremos calculando para cada combinacion
	ganancia_mochila, //es la ganancia que iremos calculando para cada combinacion
	combinaciones; //cantidad de combinaciones
	combinaciones = pow(2,cantidad_productos);//definimos la cantidad de combinaciones
		
	int mejor_peso_mochila=0, mejor_combinacion=0, mayor_ganancia=0;
	
	//iniciamos nuestros for de FUERZA BRUTA
	for (i=1; i<combinaciones; i++){ //recorremos cada combinacion
	//Para cada combinación vamos a converirla en binario, es decir vamos a obtener el cromosoma
	//Por ejemplo: Combinación 4, el cromosoma sería {0 0 1 0 0 0} 
		cargaBinaria(i,cromosoma,cantidad_productos); //convertimos la combinacion a binario
		
		//Para cada combinación (ya en binario) vamos a calcular el peso y la ganancia
		peso_mochila = 0; //inicializo en 0 el peso de la combinacion
		ganancia_mochila = 0; //inicializo en 0 la ganancia de la combinacion
		
		//Voy a calcular el peso y la ganancia de la combinacion
		for (j=0; j<cantidad_productos; j++){
			if (cromosoma[j]==1){//cada vez que encuentre un producto seleccionado, acumulo el peso y la ganancia
				peso_mochila = peso_mochila + productos[j][0];//acumulo el peso
				ganancia_mochila = ganancia_mochila + productos[j][1];//acumulo la ganancia
			}
		}
		//hasta aquí tenemos calculado el peso y la ganancia de la combinación
		//ahora, analizaremos si el peso y la ganancia de la combinación me sirve
		//es decir, si cumple con los limitantes
		
		if (peso_mochila<=peso_maximo && mayor_ganancia <= ganancia_mochila){//Cuando el peso de la mochila es menor igual a mi limitante  Y encontramos un nuevo mejor peso
			mayor_ganancia=ganancia_mochila;
			mejor_combinacion=i;
		}
	}
	
	//hasta este punto, hemos conseguido la mejor combinación, es decir, la que tiene peso<=peso_maximo Y tiene la mayor ganancia de todas combinaciones
	
	cargaBinaria(mejor_combinacion,cromosoma,cantidad_productos);//pasamos la mejor combinación a cromosoma
	cout << "Solucion: " << ": "; //Muestro la solucion
	for (j=0; j<N; j++){
		if (cromosoma[j]==1){
			cout << j+1 << " "; //Se muestra la solución
			//ganancia_mochila = ganancia_mochila + productos[j][1];//acumulo la ganancia
		}
	}
	cout<<"Ganancia: "<<mayor_ganancia;
	cout << endl;
	return 0;
}
