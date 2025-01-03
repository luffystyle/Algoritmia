#include <iostream>

using namespace std;

int palindroma(char arreglo[5],int posI,int posJ){
	if (arreglo[posI]!=arreglo[posJ]){
		return 0;
	}
	if (posJ<=posI){
		return 1;
	}
	return palindroma(arreglo,posI+1,posJ-1);
}


int main(){
	char arreglo[5]={'L','R','V','E','L'};
	int size = 5;
	int posI = 0;
	int posJ = size-1;
	cout << "Es palindroma? : " << palindroma(arreglo,posI,posJ);
	return 0;
}
