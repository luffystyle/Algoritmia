#include <iostream>

using namespace std;

void imprimir(int i, int size){
	if (i<size){
		cout << "*";
		imprimir(i+1,size);
	}
}

void triangulo(int a, int b){
	if (a<=b){
		imprimir(0,a);
		cout << endl;
		triangulo(a+1,b);
		imprimir(0,a);
		cout << endl;
	}
}

int main(){
	triangulo(3,5);
	return 0;
}
