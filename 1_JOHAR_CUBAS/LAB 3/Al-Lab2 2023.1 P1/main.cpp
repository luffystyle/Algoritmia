/* 
 * Nombre:   Johar Ricarte Cubas Castro
 * Codigo:   20195806
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
void merge(int A[], int inicial, int medio, int final, int B[]) {
	int longitud1 = (medio + 1) - inicial;
	int longitud2 = final - medio;
	int P[longitud1 + 1];
	int Q[longitud2 + 1];
	int Muno[longitud1 + 1];
	int Ndos[longitud2 + 1];

	P[longitud1] = 999999;
	Q[longitud2] = 999999;
	Muno[longitud1] = 999999;
	Ndos[longitud2] = 999999;

	for (int i = inicial; i <= medio; i++) {
		P[i - inicial] = A[i];
		Muno[i - inicial] = B[i];
	}
	for (int i = medio + 1; i <= final; i++) {
		Q[i - (medio + 1)] = A[i];
		Ndos[i - (medio + 1)] = B[i];
	}
	int p = 0;
	int q = 0;
	int muno = 0;
	int mdos = 0;
	for (int i = inicial; i <= final; i++) {
		if (P[p] < Q[q]) {
			A[i] = P[p++];
			B[i] = Muno[muno++];
		} else {
			A[i] = Q[q++];
			B[i] = Ndos[mdos++];
		}
	}
}

void mergesort(int A[], int inicial, int final, int B[]) {
	if (inicial == final)
		return;
	int medio = (inicial + final) / 2;
	mergesort(A, inicial, medio, B);
	mergesort(A, medio + 1, final, B);
	merge(A, inicial, medio, final, B);
}

int main(int argc, char** argv) {
    int cant=30;
    int arr1[cant]={-1,-2,-3,-4,-5,-6,-7,-8,1,-9,2,-10,-11,1,2,-12,-13,-14,-15,-16,-17,1,-18,-19,-20,1,2,-21,-22,-23};
    int arr2[cant]={10,5,8,9,8,1,10,5,2,8,2,3,4,2,1,4,8,1,1,2,4,3,5,3,8,3,3,8,5,3};
    mergesort(arr1,0,cant-1,arr2);
    for(int i=0;i<30;i++) cout<<arr1[i]<<" ";
    
    return 0;
}

