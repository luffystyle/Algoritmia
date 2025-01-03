
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 14 de septiembre de 2024, 08:09 AM
 */
//PREGUNTA 2 RECURSION
#include <iostream>

using namespace std;


//  Modificamos el arreglo segun estamos recorriendo
void robotReponedor(int x, int y, int n, int m, int MAX, int matriz[5][5]) {
   
    // n = 5, m = 5
    //CASO BASE
    if(x>n || y >n || x<0 || y<0){
        return;
    }
    //avanzamos a la derecha
    //if()
//    robotReponedor(x, y+1, n, m-1, MAX, matriz);
//    
//    // avanzo abajo
//    //if()
//    robotReponedor(x+1, y, n-1, m, MAX, matriz);
//    
//    //avanzo izquierda
//    //if()
//    robotReponedor(x, y-1, n, m-1, MAX, matriz);
//    
//    //avanzo arriba
//    //if()
//    robotReponedor(x-1, y+1, n, m-1, MAX, matriz);
//    
//    robotReponedor(x-1, y+1, n, m-1, MAX, matriz);
    
    for(int i = y; i<=m; i++) matriz[x][i]= MAX - matriz[x][i]; // derecha
    for(int i = x+1; i<=n; i++) matriz[i][m]= MAX - matriz[i][m]; // abajo
    for(int i = m-1; i>=y; i--) matriz[n][i]= MAX - matriz[n][i]; // izquierda
    for(int i = n-1; i>=x+1; i--) matriz[i][y]= MAX - matriz[i][y]; // arriba
    
    //mi unica recursion
    robotReponedor( x+1,  y+1,  n-1,  m-1,  MAX, matriz);
}





int main(int argc, char** argv) {

    int matriz[5][5] = { {4, 3, 6, 8, 7}, 
                        {6, 3, 8, 4, 10}, 
                        {2, 15, 1, 2, 13}, 
                        {5, 1, 10, 11, 2}, 
                        {10, 4, 7, 9, 4} };
    
    int n = 5, m =5;
    int MAX = 15;
    int x = 0, y = 0; // posicion final
    int movX =1, movY = 1;
    robotReponedor(x, y, n-1, m-1, MAX, matriz);
    
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

