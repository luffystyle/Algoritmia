
#include <iostream>
#define MAX 10

using namespace std;

/*Base multiple*/
int lista[MAX];
int x=0,y=0;

int empaca(int i,int n,int peso,int p[])
{	if(i==n||peso<0)
		return 0;
	if(p[i]==peso)
	{
		lista[y]=p[i];
		int k;
		cout << "Resultado:";
		for(k=0;k<=y;k++)
                    cout << lista[k]<<" ";
		x++;
		cout << endl;
	}
	lista[y++]=p[i];
	if(empaca(i+1,n,peso-p[i],p))
		return 1;
	else{
		y--;  //back aqui retrocede
		return(empaca(i+1,n,peso,p));
	
	}
}

int main()
{
	int paq[]={1,8,7,2,3,6,5,4};
	int n=8;
	int peso=9;
	empaca(0,n,peso,paq);
	if(x)
		cout << "Hay solucion"<<endl;
	else	
		cout << "No hay solucion"<<endl;

	return 0;
}



