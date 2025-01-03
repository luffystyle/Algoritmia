#include <iostream>

#define MAXF 5
#define MAXC 4

using namespace std;

int busca(char tablero[MAXF][MAXC],char palabra[3],int sizePalabra,int movimientos[8][2],int posIniI,int posIniJ, char resultado[MAXF][MAXC]){
	int posI, posJ, j, posIAux, posJAux, haySolucion=0;
	if (tablero[posIniI][posIniJ]!=palabra[0]){
		return 0;
	}
	
	/*Ahora si voy a buscar la palabra*/
	for (int i=0; i<8; i++){
		 posI = posIniI + movimientos[i][0];
		 posJ = posIniJ + movimientos[i][1];
		 
		 /*Voy a buscar cada letra de la palabra en la direccion*/
		 /*Ojo, las letras de la palabra inician en 1*/
		for (j=1; j<sizePalabra; j++){
		 	/*Primero validare que estoy en una posicion valida*/
		 	if (posI<0 || posI>=MAXF || posJ<0 || posJ>=MAXC){
				break;		 		
			}
			if (palabra[j]!=tablero[posI][posJ]){
				break;
			}
			posI = posI + movimientos[i][0];
		 	posJ = posJ + movimientos[i][1];
		}
		if (j==sizePalabra){
			resultado[posIniI][posIniJ] = tablero[posIniI][posIniJ];
			posIAux = posIniI + movimientos[i][0];
		 	posJAux = posIniJ + movimientos[i][1];
			for (int k=1; k<sizePalabra; k++){
				resultado[posIAux][posJAux] = tablero[posIAux][posJAux];
				posIAux = posIAux + movimientos[i][0];
		 		posJAux = posJAux + movimientos[i][1];
			}
			haySolucion = 1;
		}
	}
	return haySolucion;
}


int main(){
	char tablero[MAXF][MAXC] = {{'L','O','G','O'},
								{'J','Z','O','A'},
								{'K','H','L','R'},
								{'L','O','A','B'},
								{'G','R','Z','A'}};
	char resultado[MAXF][MAXC] = {{' ',' ',' ',' '},
								{' ',' ',' ',' '},
								{' ',' ',' ',' '},
								{' ',' ',' ',' '},
								{' ',' ',' ',' '}};
	char palabra[3] = {'G','O','L'};
	int movimientos[8][2] = {{-1,-1},
							 {-1,0},
							 {-1,1},
							 {0,-1},
							 {0,1},
							 {1,-1},
							 {1,0},
							 {1,1}};	
	int sizePalabra = 3;
	
	/*Vamos a recorrer todo el tablero por todas las posiciones*/
	for (int i=0; i<MAXF; i++){
		for (int j=0; j<MAXC; j++){
			if (busca(tablero,palabra,sizePalabra,movimientos,i,j,resultado)){
				cout << "La palabra esta en la posicion: " << i << "," << j << endl;
			}	
		}
	}
	
	for (int i=0; i<MAXF; i++){
		for (int j=0; j<MAXC; j++){
			cout << resultado[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
