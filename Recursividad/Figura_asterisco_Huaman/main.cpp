
#include <iostream>

using namespace std;

void patron(int n, int i) {
    
    // Nuestra condición de parada, hasta por ESTE MOMENTO, es cuando el número n se reduce
    // hasta su máxima expresión
    if( n == 0 ) return;
    int j;
    
    // En esta linea de patron(n/2, i), es cuando NOS SUMERGIMOS en los pequeños universos hasta llegar al más pequeño
    // con esta llamada me voy a reducirla a mi n a su máxima expresión
    patron(n/2, i); // lo divimos entre 2 xq empezamos de un 8, entonces
    // vamos estar dibujando 1, 4, 8, que son los asteriscos horizontales
    
    //Empezamos con este for porque primero, se imprime LOS ESPACIOS DE BLANCOS hasta que los asteriscos
    for(j = 0; j<i; j++) cout << "   "; // en el universo más pequeño, no se imprime porque el i = 0
    // esto empieza a apartir de cuando i = 1;
    for(j = 0; j<n; j++) cout << " * ";//en el universo más pequeño, n = 1, xq la secuencia de los univesos con n
    // son en universos 8 ---> 4 ----> 2-----> 1 -----> 0(aqui hacemo el return)
    cout<< endl;
    
    
    
    patron(n/2, n/2 + i);// si fuese en el universo más pequeño, como n=1, esto me returna porque al ingresar seria 0 el n
    // se regresa al mundo donde n = 2, donde 
    // como regresa 
}


int main(int argc, char** argv) {

    int n = 8, i = 0;
    patron(n, i);

    return 0;
}

