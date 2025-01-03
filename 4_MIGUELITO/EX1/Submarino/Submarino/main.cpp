/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 1 de setiembre de 2024, 22:23
 */

#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"

using namespace std;

void Muestramovimientos(char *seq,int n) 
{       Pila stack; 
        construir(stack);
	for (int i = 0; i <= n; i++) 
	{       apilar(stack,i+1);
		if (i == n || seq[i] == 'S') 
                    while (!esPilaVacia(stack)) 
                            cout << desapilar(stack) << " ";

	} 
        cout << endl;
} 
int main() 
{ 
    char ordenes[]={'B','B','S'};
    int n=sizeof(ordenes)/sizeof(ordenes[0]);
    Muestramovimientos(ordenes,n); 
    char ordenes1[]={'S','S','B','S'};
    n=sizeof(ordenes1)/sizeof(ordenes1[0]);
    Muestramovimientos(ordenes1,n); 

    char ordenes2[]={'S','S','S','B','S'};
    n=sizeof(ordenes2)/sizeof(ordenes2[0]);
    Muestramovimientos(ordenes2,n); 

    return 0; 
} 