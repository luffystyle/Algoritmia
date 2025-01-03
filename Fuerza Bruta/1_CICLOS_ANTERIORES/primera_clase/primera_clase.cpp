#include <iostream>
#include <cmath>

using namespace std;

void cargabin( int num, int n, int cromo[]) {//esto es la carga, aqui lo pasamos de lo que era array de
											 //de numero en base 10, lo pasamos a binario
	
	int i, res;
	//limpiador el cromo, que todos sean 0
	for( int i = 0; i<n; i++) cromo[i] = 0;
	i = 0;
	while(num>0) {
		res = num%2;// ejemplo, 11%2 = 1
		num = num/2; 
		cromo[i] = res;//aqui
		i++;// 00001
	}
}

int main() {
	int peso = 15, n = 5 /* cantidad de objetos*/, mpeso = 0, mcomb = 0, parcial;
	int paq[] = {1, 2, 4, 12, 1};
	int cromo[n]; // no inicializamos, pero si le damos la longitud del array
	int opcion = (int)pow(2, n); // el pow nos devuelve un double, por eso lo casteamos
	// opcion es la cantidad combinaciones
	for(int i = 0; i < opcion; i++) {
		cargabin(i, n, cromo);
		parcial = 0;
		for(int j = 0; j<n; j++) {
			parcial = cromo[j]*paq[j] + parcial;
		}
		
		if(parcial<=peso and mpeso<parcial) {
			mpeso = parcial;
			mcomb = i;
		}
	}
	
	cout<< mpeso << " " << mcomb;
	
	return 0;
}
