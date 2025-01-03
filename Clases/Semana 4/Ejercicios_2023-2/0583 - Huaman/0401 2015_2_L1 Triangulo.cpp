#include <iostream>
using namespace std;

void triangulo (int a, int b){
	//CASO BASE
	if (a>b){
		return;		
	}
	else{
		for (int i=0; i<a; i++)
			cout<<" * ";
		cout<<endl;
		triangulo (a+1,b);
		for (int i=0; i<a; i++)
			cout<<" * ";
		cout<<endl;
	}
}
int main(){
	int a=3,b=5;
	triangulo (a,b);
	return 0;
}
