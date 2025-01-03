


#include <iostream>
#include <iomanip>
#define MAX_COLUMNA 6
#define MAX_FILA 5

using namespace std;



void Merge(int arregloID[], int arregloInstrucciones[], int posicion_inicio, int posicion_medio, int posicion_final) {
    int longitud1, longitud2, i, p, q;

    //dimensiones de los arreglos auxiliares 1 y 2
    longitud1 = (posicion_medio+1) - posicion_inicio;
    longitud2 = posicion_final - posicion_medio;

	//arreglos auxiliares
    int ID_1[longitud1+1], ID_2[longitud2+1];
    int Instrucciones_1[longitud1+1], Instrucciones_2[longitud2+1];

    //copiamos de los arreglos principales a los subarreglos auxiliares
	//Subarreglos1
    for (i = posicion_inicio; i <= posicion_medio; i++) {
        ID_1[i - posicion_inicio] = arregloID[i];
        Instrucciones_1[i - posicion_inicio] = arregloInstrucciones[i];
    }
    ID_1[longitud1] = 999999;
	//Subarreglos2
    for (i = posicion_medio + 1; i <= posicion_final; i++) {
        ID_2[i - (posicion_medio + 1)] = arregloID[i];
        Instrucciones_2[i - (posicion_medio + 1)] = arregloInstrucciones[i];
    }
    ID_2[longitud2] = 999999;
	
    //Mezcla
	p=q=0;
    for (i = posicion_inicio; i <= posicion_final; i++) {
        if (ID_1[p] < ID_2[q]) {
            arregloID[i] = ID_1[p];
            arregloInstrucciones[i] = Instrucciones_1[p];
            p++;
        }
        else {
            arregloID[i] = ID_2[q];
            arregloInstrucciones[i] = Instrucciones_2[q];
            q++;
        }
    }
}


void MergeSort(int arregloID[],int arregloInstrucciones[],int posicion_inicio,int posicion_final){
    if(posicion_inicio==posicion_final)//CASO BASE
		return;
		
    int posicion_medio=(posicion_inicio+posicion_final)/2;
    
    MergeSort(arregloID,arregloInstrucciones,posicion_inicio,posicion_medio);
    MergeSort(arregloID,arregloInstrucciones,posicion_medio+1,posicion_final);
    
    Merge(arregloID,arregloInstrucciones,posicion_inicio,posicion_medio,posicion_final);
}



void pasarMatrizAarregloUnidimensional(int matriz[][MAX_COLUMNA], int arreglo[]) {
    
    int contador = 0;
    for(int i = 0; i<MAX_FILA; i++) {
        for(int j = 0; j<MAX_COLUMNA; j++) {
            arreglo[contador] = matriz[i][j];
            contador++;
        }
    }
}


void imprimirArreglo(int arreglo[]){
    for(int i = 0; i<MAX_COLUMNA*MAX_FILA; i++) cout << arreglo[i] << " ";
    cout << endl;
}

void imprimirMatriz(int matriz[][MAX_COLUMNA]) {
    for(int i = 0; i<MAX_FILA; i++) {
        for( int j = 0; j<MAX_COLUMNA; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}


void pasarArregloAmatriz(int arreglo[], int matriz[][MAX_COLUMNA]) {
    int contador = 0;
    for(int i = 0; i<MAX_FILA; i++) {
        for(int j = 0; j<MAX_COLUMNA; j++) {
            matriz[i][j] = arreglo[contador];
            contador++;
        }
    }
}



int main(int argc, char** argv) {


    int matriz_Registro[][MAX_COLUMNA] = { {-1, -2, -3, -4, -5, -6}, 
                                 {-7, -8, 1, -9, 2, -10}, 
                                 {-11, 1, 2, -12, -13, -14}, 
                                 {-15, -16, -17, 1, -18, -19}, 
                                 {-20, 1, 2, -21, -22, -23}   };
    
    
    int matriz_Lineas_Instruccion[][MAX_COLUMNA] = { {10, 5, 8, 9, 8, 1},
                                           {10, 5, 2, 8, 2, 3}, 
                                           {4, 2, 1, 4, 8, 1}, 
                                           {1, 2, 4, 3, 5, 3}, 
                                           {8, 3, 3, 8, 5, 3} };

    // primero es quee tenemos que ordenar las matrices
    int arreglo_Registro[MAX_COLUMNA*MAX_FILA], arreglo_Lineas_Instruccion[MAX_COLUMNA*MAX_FILA];
    
    // Aqui pasamos de una Matriz de NxM a un Arreglo Unidimensional 
    pasarMatrizAarregloUnidimensional(matriz_Registro, arreglo_Registro);
    pasarMatrizAarregloUnidimensional(matriz_Lineas_Instruccion, arreglo_Lineas_Instruccion);

//    imprimirArreglo(arreglo_Registro);
//    imprimirArreglo(arreglo_Lineas_Instruccion);
    
    // este MergeSort a parte de ordenar dos arreglos, tbm ordena el otro arreglo de forma descendente
    // es decir si se repite 1 varias veces, las lineas de intrucción tbm lo orden en 3 3 2 2 1, así de esa manera
    MergeSort(arreglo_Registro, arreglo_Lineas_Instruccion, 0, MAX_COLUMNA*MAX_FILA-1);
//  Aqui hacemos lo contrario, pasamos de un Arreglo Unidimensional a una Matriz de NxM
    pasarArregloAmatriz(arreglo_Registro, matriz_Registro);
    pasarArregloAmatriz(arreglo_Lineas_Instruccion, matriz_Lineas_Instruccion);
    
    imprimirMatriz(matriz_Registro);
    cout << endl << endl;
    imprimirMatriz(matriz_Lineas_Instruccion);
    
    
    
    
    
    return 0;
}

