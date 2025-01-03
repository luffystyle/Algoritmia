#include <iostream>
#include <iomanip>

using namespace std;

int contador_Ceros( int A[], int inicio, int fin, int contador) {
    
    if(inicio == fin) {
        // aqui NO SÉ POR QUÉ cuando hago contador++, no me suma, pero en fin, no hay que darle importancia
        if( A[inicio] == 0) return contador+1;
        else return contador;
    }
    int medio;
    medio = (inicio + fin)/2;
  
    // Aqui a diferencia de otros problemas, este problema es ELEGIR UN CAMINO U OTRO CAMINO; por ejemplo, podria
    // ser como en mergesort DONDE TIENES QUE COMPARAR DOS MERGESORT y no podemos una condición, sino que debajo
    // comparamos como por ejemplo
    // mergesort(A,posicion_inicial,posicion_medio); 
    // mergesort(A,posicion_medio+1,posicion_final); 
    // aqui por ejemplo no ponemos una condicion, porque JUNTAMOS DOS CAMINOS, en cambio en nuestro ejemplo de
    // contador ceros elegimos un camino u otro, no al mismo tiempo, entonces, elegimos un camino y 
    // otro camino lo DESCARTAMOS, pero contando sus 0's.   
    
    if(A[medio] == 0) {
        // lo que pasa es que estoy sumando cuando esté entrando a los mundos, NO HAGO NADA AL VOLVER DE LOS MUNDOS
        // es decir mientras estoy entrando a cada mundo ahí cuento y sumo, cuando devuelvo solo hago return, pero no sumo
        return contador_Ceros(A, inicio, medio-1, contador+(fin-medio+1) );
    } else{ 
        return contador_Ceros(A, medio+1, fin, contador);
    }     
}

int main(int argc, char** argv) {

    int n = 7;
    int arreglo[] = {1, 0, 0, 0, 0, 0, 0};
    // como sabemos que en nuestra derecha estána los 0's y en la izquierda nuestro 1's hacemos un algoritmo
    // en base a eso
    
    int contador = 0;
    int inicio = 0; //  del arreglo
    int fin = n-1; // del arreglo
    // colocamos el inicio, el fin del arreglo. Por último, el contador que me duelve la cantidad de 0's
    cout << "El número de 0's es: " << contador_Ceros(arreglo, inicio, fin, contador) << endl;

    return 0;
}
