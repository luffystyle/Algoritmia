/* 
 * File:   main.cpp
 * Author: Miguel Angel Torres Villanueva
 * Codigo : 20175525
 * Created on October 18, 2024, 5:36 PM
 */

#include <iostream>

using namespace std;

int calcularFrecMaxima(int *frecuencias, int &duracion, int &area) {
    
}




int main(int argc, char** argv) {

    
    int frecuencias[] = {1, 2, 1, 4, 5, 6, 4, 5, 2, 2, 1};
    int duracion = 0;
    double area;
    
    cout << "Frecuencia maximo es " << calcularFrecMaxima(frecuencias, 7, duracion, area) << endl;
    cout << "Duracion: " << duracion << endl;
    cout << "Area: " << area << endl;
    
    return 0;
}
