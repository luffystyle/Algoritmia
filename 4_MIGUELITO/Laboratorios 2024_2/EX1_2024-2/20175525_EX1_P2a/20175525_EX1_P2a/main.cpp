
/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo: 20175525
 * Created on 19 de octubre de 2024, 10:17 AM
 */

#include <iostream>

using namespace std;

int matriz[3][3] = {{1, 1, 1}, 
                  {1, 1, 0}, 
                  {1, 0, 1}};



void pintar(int xini, int yini, int xPixel, int yPixel, int valorNuevo) {
    
    
    if(xini  >3 || yini >3) return;
    matriz[xini][yini] = valorNuevo;
    //if(xini == xPixel && yini == yPixel) matriz[xPixel][yPixel] = valorNuevo;
        
    if(yini== 0){ //Movimiento derecho
        
        pintar(xini, yini +1, xPixel, yPixel, valorNuevo);
    }

    if(xini == 0) { // moviemento hacia abajo
        
        pintar(xini + 1, yini, xPixel, yPixel, valorNuevo);
    } 

    
}


int main(int argc, char** argv) {
    
    
    int posX = 1, posY = 1;
    int valor = matriz[posX][posY];
    int valorNuevo = 2;
    
    pintar(posX-1, posY-1, posX, posY,valorNuevo);
    
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            cout << matriz[i][j] << " " ;
        }
        cout << endl;
    }
    
    return 0;
}

