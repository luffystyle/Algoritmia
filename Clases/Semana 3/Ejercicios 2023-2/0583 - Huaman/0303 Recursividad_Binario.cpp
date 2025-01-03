#include <iostream>
using namespace std;
 
void imprimirBinario(int num){
	//caso base: cuando el cociente es igual a 0
	if (num==0){
		cout<<"0";
		return;
	}
	if (num==1){
		cout<<"1";
		return;
	}
	imprimirBinario(num/2);
	cout<< num%2;
}

int main(){
	int num;
	cout << "Ingrese el numero en base 10 = ";
	cin >> num;
	cout<<num<< " en base 2 = ";
	imprimirBinario(num);
	
	cout << endl;
	return 0;
}
