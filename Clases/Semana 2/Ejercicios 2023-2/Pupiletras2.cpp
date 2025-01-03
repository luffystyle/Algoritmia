
#include <iostream>
#define MAXCOL 5
#define MAXFIL 5

int m[8][2];

using namespace std;


void cargamovimientos(){
	m[0][0]=-1; m[0][1]=0;
	m[1][0]=-1; m[1][1]=1;
	m[2][0]=0; m[2][1]=1;
	m[3][0]=1; m[3][1]=1;
	m[4][0]=1; m[4][1]=0;
	m[5][0]=1; m[5][1]=-1;
	m[6][0]=0; m[6][1]=-1;
	m[7][0]=-1; m[7][1]=-1;
}
int busca(char letras[][MAXCOL],char patron[],
	char resultado[][MAXCOL],int row,int col,int n){
		
	int i,j,k,l,s,nrow,ncol,flag=0;	
		
	if(patron[0]!=letras[row][col]) return 0;
	
	for(i=0;i<8;i++){
		
		nrow = row + m[i][0];
		ncol = col + m[i][1];
		
		if(nrow<0 ||nrow>=MAXFIL || ncol<0 ||ncol>=MAXCOL)
			continue;		
		else{
			for(j=1;j<n;j++){
				if(patron[j]!=letras[nrow][ncol])
					break;
				nrow = nrow + m[i][0];
				ncol = ncol + m[i][1];
			}
			if(j==n){
				for(k=0,l=0,s=0;s<n;k+=m[i][0],l+=m[i][1],s++)
					resultado[row+k][col+l] = patron[s];
				flag=1;				
			}
		}

	}
	if(flag==1) return 1;
	return 0;
}



void pupiletras(char letras[][MAXCOL],char patron[],
	char resultado[][MAXCOL],int n){
		
	for(int i=0;i<MAXFIL;i++)
		for(int j=0;j<MAXCOL;j++){
			if(busca(letras,patron,resultado,i,j,n)){
				cout <<"La palabra esta en:"<<i<<" "<<j<<endl;
				
			}			
			
		}		
	
	
}
void imprime(char resultado[][MAXCOL]){
	for(int i=0;i<MAXFIL;i++){
		for(int j=0;j<MAXCOL;j++)
			cout << resultado[i][j] <<" ";
		cout << endl;
	}
		
	
	
}



int main(){
	int n=4;
	char letras[][MAXCOL]={
	{'B','A','L','I','C'},
	{'N','B','I','C','A'},
	{'T','I','I','A','L'},
	{'P','C','P','C','M'},
	{'R','O','B','O','A'}
	};
	
	char resultado[][MAXCOL]={
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '}
	};
	
	char patron[]={'B','I','C','A'};
	cargamovimientos();
	pupiletras(letras,patron,resultado,n);
	imprime(resultado);
	return 0;
}
