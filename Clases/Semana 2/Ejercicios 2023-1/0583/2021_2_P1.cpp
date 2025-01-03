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
	
	//variable para la cantidad de secciones en el almacén
	int cantidad_secciones;
	cout<<"Cantidad de secciones: ";
	cin >> cantidad_secciones;
	
	//variable para el peso solicitado en el pedido
	int peso_solicitado;//Limitante: peso del pedido
	cout<<"Peso del pedido: ";
	cin >> peso_solicitado;

	int cantidad_productos=cantidad_secciones*2*2;
	//Llenado de datos, tarea para la casa
	int productos[cantidad_productos]={7,9,8,18,17,12,6,7,14,11,10,15,19,8,12,11}; // peso de las carnes
	int ganancias[cantidad_productos]={10,15,10,10, }; // peso de las carnes
	string ubicaciones[cantidad_productos]={"IA1", "IB1", "DA1", "DB1", "IA2", "IB2", "DA2", "DB2","IA3", "IB3", "DA3", "DB3","IA4", "IB4", "DA4", "DB4"}; 

	int cromosoma[cantidad_productos]; //arreglo de nuestro cromosoma
	int peso, //es el peso que iremos calculando para cada combinacion
	combinaciones; //cantidad de combinaciones
	combinaciones = pow(2,cantidad_productos);//definimos la cantidad de combinaciones
		
	
	int contador_soluciones=0, mejor_peso_mochila=0, mejor_combinacion=0, mayor_ganancia=0;
	
	
	//iniciamos nuestros for de FUERZA BRUTA
	for (i=1; i<combinaciones; i++){ //recorremos cada combinacion
	//Para cada combinación vamos a converirla en binario, es decir vamos a obtener el cromosoma
	//Por ejemplo: Combinación 4, el cromosoma sería {0 0 1 0 0 0} 
		cargaBinaria(i,cromosoma,cantidad_productos); //convertimos la combinacion a binario
		
		//Para cada combinación (ya en binario) vamos a calcular el peso y la ganancia
		peso = 0; //inicializo en 0 el peso de la combinacion
		
		//Voy a calcular el peso y la ganancia de la combinacion
		for (j=0; j<cantidad_productos; j++){
			if (cromosoma[j]==1){//cada vez que encuentre un producto seleccionado, acumulo el peso y la ganancia
				peso = peso + productos[j];//acumulo el peso
				ganancia= ganancia+ganancias[j];
			}
		}
		//hasta aquí tenemos calculado el peso y la ganancia de la combinación
		//ahora, analizaremos si el peso y la ganancia de la combinación me sirve
		//es decir, si cumple con los limitantes
		
		if (peso==peso_solicitado){//Cuando el peso de la combinación es igual al peso solicitado en el pedido
			//Mostrar la solución encontrada
			contador_soluciones++;
			
			cout << "Resultado N°" << contador_soluciones << ": "; //Muestro la solucion de los pesos
			for (j=0; j<cantidad_productos; j++){
				if (cromosoma[j]==1){
					cout << productos[j] << "k ";
				}
			}
			cout << endl;
			cout<<"Ubicaciones: "; //Muestro la solucion de las ubicaciones
			for (j=0; j<cantidad_productos; j++){
				if (cromosoma[j]==1){
					cout << ubicaciones[j] << " ";
				}
			}
			cout << endl;
					
			
		}
	}
	
	
	return 0;
}
