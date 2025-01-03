#include <iostream>
using namespace std;

void triangulo (int a, int b) {
    //caso base: tomando en cuenta "Nota: a siempre debe ser menor o igual que b"

	if (a>b){
    	return;
	}	
	//caso recursivo
	else{
		for (int i=0; i<a; i++)
			cout << " * ";
		cout<<endl;				//a=3, 3<=5  * * *
		triangulo (a+1,b); 		//a=4, 4<=5  * * * *
								//a=5, 5<=5  * * * * *
								//a=6, 6>5 (CASO BASE!!!) => return
		
		for (int i=0; i<a; i++)
			cout << " * ";
		cout<<endl;	
	}
}

int main() {
	int a=3, b=10;
    triangulo(a,b);
    return 0;
}
