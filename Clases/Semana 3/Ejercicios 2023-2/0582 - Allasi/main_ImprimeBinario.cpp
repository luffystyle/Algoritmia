#include <iostream>

using namespace std;

void imprimeBinario(int num){
	int digito;
	if (num>0){
		digito = num%2;
		num = num/2;
		imprimeBinario(num);
				cout << digito;		
	}
}

int main(){	
	imprimeBinario(8);
	return 0;
}
