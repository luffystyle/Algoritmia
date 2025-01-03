#include <iostream>
#include <cstring>

using namespace std;
#define MAXCOL 15
#define MAXFIL 15
int buscar(char word[], int t, char tablero[][MAXCOL], char *rest, int row, int col, int n) ;

void PopulateGameBoard(int t, char tablero[][MAXCOL]) {
    char letter;
    cout << "Bienvenido al juego de sopa de letras" <<endl;
    for (int i=0; i<t; i++){
            for (int j=0; j<t; j++){
                    letter = 'A' + (rand() % ('Z' - 'A' + 1) );
                    tablero [i][j] = letter;
            }
    }
}


void ShowGameBoard( int t, char tablero[][MAXCOL]) {
    for( int i = 0; i < t; i++) {
        for( int j = 0; j < t; j++) {
            cout<< tablero[i][j] << " ";
        }
        cout << endl;
    }
}

int m[4][2];

void cargarMovimientos() {
    m[0][0] = -1; m[0][1] =  0;
    m[1][0] =  0; m[1][1] =  1;
    m[2][0] =  1; m[2][1] =  0;
    m[3][0] =  0; m[3][1] = -1;
}


//void determinarMovimiento(char rest[], int movFila, int movCol,  int row, int col) {
//    
//    if(movFila == -1 and movCol == 0) rest[3] == 'U';
//    else if(movFila == 0 and movCol == 1) rest[3] == 'R';
//    else if(movFila == 1 and movCol == 0) rest[3] == 'D';
//    else if(movFila == 0 and movCol == -1) rest[3] == 'L';  
//}


int buscar(char word[], int t, char tablero[][MAXCOL], char *rest, int row, int col, int n) {
    
    int nrow, ncol, j, i ;
    
    if(word[0] != tablero[row][col] ) return 0;
    
    
    for(  i = 0; i < 4; i++) {
        nrow = row + m[i][0];// el row como son filas observa si sube o baja
        ncol = col + m[i][1];// en cambio el col, si se mueve a la derecha o izquierda.
        if(nrow<0 or ncol<0 or nrow>=MAXFIL or ncol>=MAXCOL) {
            continue;
        } else{
            for(  j = 1; i<n; j++) {
                if(word[j] != tablero[nrow][ncol])break;
                nrow += m[i][0];
                ncol += m[i][1];
            }
            if( j == n) {
                rest[1] = row + 'A' - 'a';
                rest[2] = col + 'A' - 'a';
                
                if(m[i][0] == -1 and m[i][1] == 0) rest[3] == 'U';
                else if(m[i][0] == 0 and m[i][1] == 1) rest[3] == 'R';
                else if(m[i][0] == 1 and m[i][1] == 0) rest[3] == 'D';
                else if(m[i][0] == 0 and m[i][1] == -1) rest[3] == 'L';
                //determinarMovimiento(rest, m[i][0], m[i][0], row, col, n);
                
                return true;
            }
        }
        
    }
    return 0;
}



void SearchWord( char word[], int t, char  tablero[][MAXCOL], char *res, int n) {
    
    cargarMovimientos(); // aqui he llenado mi arreglo de movimientos
    
    for(int i = 0; i < t; i++) {
        for(int j = 0; j < t; j++) {
            if( buscar(word, t, tablero, res, i, j, n)  ) {
                cout << "Esta en " << i<< ", "<<j <<endl;
                for(int k = 0; k < 3; k++ ) cout<<res[k]<< " ";
                cout <<endl;
            } 
        }
    }
    
}




int main(int argc, char** argv) {

    
    int t, n, cantPalabras;
    cout << "Ingrese el tamaño de la cuadricula" << endl;
    cin>>t;
    
    char palabra[100], res[3];
    char tablero[MAXFIL][MAXCOL];
    PopulateGameBoard(t,tablero);
    ShowGameBoard(t, tablero);
    cout << "Ingrese la cantidad de palabras a buscar" <<endl;
    cin >> cantPalabras;
    for( int i = 0; i<cantPalabras; i++) {
        cout << "Palabra " << i + 1 << ":" << endl;
        cin >> palabra>>n;
        SearchWord( palabra, t, tablero, res, n);
        
    }
    

    
    
    return 0;
}

