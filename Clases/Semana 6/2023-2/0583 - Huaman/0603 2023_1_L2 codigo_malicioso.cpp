#include <iostream>
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


int main (){
	int ID[10][10]={{-1, -2, -3, -4, -5, -6},
                     {-7, -8, 1, -9, 2, -10},
                     {-11, 1, 2, -12, -13, -14},
                     {-15, -16, -17, 1, -18, -19},
                     {-20, 1, 2, -21, -22, -23}};

	int Instrucciones[10][10]= {{10, 5, 8, 9, 8, 1},
                      {10, 5, 2, 8, 2, 3},
                      {4, 2, 1, 4, 8, 1},
                      {1, 2, 4, 3, 5, 3},
                      {8, 3, 3, 8, 5, 3}};
	int N=5,M=6;
	int cantidad_instrucciones,registro;
	int arregloID[50],arregloInstrucciones[50];
	

	   
	//Pasamos las matrices a arreglos para poder hace MergeSort
	PasarMatrizArreglo(ID, arregloID, N, M);
	PasarMatrizArreglo(Instrucciones, arregloInstrucciones, N, M);
		
	//Invocamos MergeSort para 2 arreglos
	MergeSort(arregloID,arregloInstrucciones,0,30-1);
	
	//Volvemos los arreglos a las matrices
	PasarArregloMatriz(arregloID, ID, N, M);
	PasarArregloMatriz(arregloInstrucciones, Instrucciones, N, M);
	
	//Solicitamos el número de registro del virus
	cout << "Registro de virus a encontrar: " << endl;
	cin >> registro;
	cantidad_instrucciones=Encontrar(ID,Instrucciones,registro,0,N-1,0,M-1);//Funcion para desarrollar
	cout << "Cantidad instrucciones: " << cantidad_instrucciones << endl;
	if(cantidad_instrucciones>=10){
	    cout << "El archivo tiene un posible codigo malicioso del virus con registro " << registro << endl;
	}
	else 
		cout << "El archivo no tiene un posible codigo malicioso del virus con registro " << registro << endl;
	return 0;
}
