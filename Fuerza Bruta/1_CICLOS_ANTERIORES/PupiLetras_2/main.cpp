#include <iostream>
#define MAXCOL 5
#define MAXFIL 5

using namespace std;

int m[8][2];// de manera horaria


void movimientos() {
	m[0][0] = -1; m[0][1] =  0; //  -1   0
	m[1][0] = -1; m[1][1] =  1; //  -1   1
	m[2][0] =  0; m[2][1] =  1; //   0   1
	m[3][0] =  1; m[3][1] =  1; //   1   1
	m[4][0] =  1; m[4][1] =  0; //   1   0
	m[5][0] =  1; m[5][1] = -1; //   1  -1
	m[6][0] =  0; m[6][1] = -1; //   0  -1
	m[7][0] = -1; m[7][1] = -1; //  -1  -1
}
\

int busca(char pupi[][MAXCOL], char  palabra[], char resultados[][MAXCOL],
        int row, int col, int npalabra) {
    
    int i, j, k, l, s, nrow, ncol, flag = 0;
    
    //verificamos si la letra que estamos recorriendo, pertenece a la palabra
    //por ejemplo, BICA, tenemos que encontrar B primeramente. En caso, de que no sea
    // retornamos y seguimos buscando
    if (palabra[0] != pupi[row][col]) return 0;
    
    //usamos los movimientos
    for(i = 0; i<8; i++) {
        // con le decimos que los movimientos que haga no sean negativo, porque 
        // si son negativos, no serían validos. 
        nrow = row + m[i][0];//
        ncol = col + m[i][1];
        
        if( nrow < 0 or nrow >= MAXFIL or ncol < 0 or ncol >= MAXCOL) continue;
        else {
            for( j = 1; j < npalabra; j++){//Recorriendo ICA de BICA, sin la B
                if( palabra[j] != pupi[nrow][ncol]) break;
                nrow += m[i][0];//en el row hace el mismo movimiento qeu debe seguir
                ncol += m[i][1];//en el colu seguis haciendo el mismo movimiento
            }
            if(j == npalabra){
                for( k = 0, l = 0, s = 0; s<npalabra; k += m[i][0], l += m[i][1], s++)
                    resultados[row+k][col+l] = palabra[s];
                flag = 1;
            }
        }
    }
    if( flag == 1) return 1;
    return 0;
}

void imprimir( char resultados[][MAXCOL]) {
    for(int i = 0; i<MAXFIL; i++) {
        for( int j =0; j<MAXFIL; j++) {
            cout<< resultados[i][j]<< " ";
        }
        cout<<endl;
    }
}


void pupiletras(char pupi[][MAXCOL], char palabra[], char resultados[][MAXCOL], int npalabra) {
    //Con el for estoy recorriendo LA MATRIZ PUPILETRAS(pupi[][MAXCOLU]), No los movimientos
    for(int i = 0; i<MAXFIL; i++) {
        for(int j = 0; j<MAXCOL; j++){
                if( busca(pupi, palabra, resultados, i, j, npalabra)) {
                        cout<<"La palabra empieza en : "<<i<<" "<<" "<<j<<endl;	
                }			
        }
    }		
}


int main() {
	
	int npalabra = 4;
	char palabra[] = {'B', 'I', 'C', 'A'};
	char pupi[][MAXCOL] = {
			{'B', 'A', 'L', 'I', 'C'},
			{'N', 'B', 'I', 'C', 'A'},
			{'T', 'I', 'I', 'A', 'L'},
			{'P', 'C', 'P', 'C', 'M'},
                        {'R', 'O', 'B', 'O', 'A'}
            };
	
	char resultados[][MAXCOL] = {
			{'0', '0', '0', '0', '0'},
			{'0', '0', '0', '0', '0'},
			{'0', '0', '0', '0', '0'},
			{'0', '0', '0', '0', '0'},
                        {'0', '0', '0', '0', '0'}
            };
	
	movimientos();
	pupiletras(pupi, palabra, resultados, npalabra);
	imprimir(resultados);
	
	return 0;
}

