#include <iostream>
#include <cmath>
#define MAXCOL 5
#define MAXFIL 4

using namespace std;

int m[8][2];// de manera horaria
/* -1 0
   -1 1
    0 1
	1 1
	1 0
	1 -1
	0 -1
	-1 -1*/

void movimientos() {
	m[0][0] = -1; m[0][1] =  0; 
	m[1][0] = -1; m[1][1] =  1;
	m[2][0] =  0; m[2][1] =  1;
	m[3][0] =  1; m[3][1] =  1;
	m[4][0] =  1; m[4][1] =  0;
	m[5][0] =  1; m[5][1] = -1;
	m[6][0] =  0; m[6][1] = -1;
	m[7][0] = -1; m[7][1] = -1;
}

int busca(char pupi[][MAXCOL], char palabra[], char resultados[][MAXCOL], int row, int col, int npalabra) {
	
	int nrow, ncol, j=1;
	
	if(pupi[row][col] != palabra[0]) return 0;
	
	for(int i = 0; i<8; i++) {
		nrow = row + m[i][0];
		ncol = col + m[i][1];
		
		if(nrow<0 || nrow>=MAXFIL || ncol>=MAXCOL || ncol<0) 
			continue;
		else {
			for(j = 1; j<npalabra; j++) {
				if(palabra[j] != pupi[nrow][ncol]) {
					j = 0;
					break;
				}
				nrow = nrow + m[i][0];
				ncol = ncol + m[i][1];
			}
		}
		if( j == npalabra) {
						
			return 1;
		}
	}
	return 0;
}


void pupiletras(char pupi[][MAXCOL], char palabra[], char resultados[][MAXCOL], int npalabra) {
	
	for(int i = 0; i<MAXFIL; i++) {
		for(int j = 0; j<MAXCOL; j++){
			if( busca(pupi, palabra, resultados, i, j, npalabra)) {
				cout<<"La palabra empieza en : "<<i<<" "<<" "<<j<<endl;	
			}			
		}
	}		
}

void imprimir( char resultados[][MAXCOL]) {
	for( int i = 0; i<MAXFIL; i++) {
		cout<<endl;
		for(int j = 0; j<MAXCOL; j++)
			cout<< resultados[i][j]<< " ";
	}
}


int main() {
	
	int npalabra = 3;
	char palabra[] = {'G', 'O', 'L'};
	char pupi[][MAXCOL] = {
			{'A', 'G', 'E', 'L', 'M'},
			{'C', 'O', 'O', 'B', 'A'},
			{'D', 'L', 'M', 'L', 'I'},
			{'I', 'J', 'G', 'O', 'P'}
		};
	
	char resultados[][MAXCOL] = {
			{' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' '},
		};
	
	movimientos();
	pupiletras(pupi, palabra, resultados, npalabra);
	imprimir(resultados);
	
	return 0;
}






