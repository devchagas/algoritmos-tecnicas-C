#include <stdio.h>
#include <stdlib.h>

int main(){
	int nA, nB, i, j, cont, k;
	int *A, *B, *res;
	
	scanf(" %d", &nA);
	scanf(" %d", &nB);
	
	A = (int *) malloc (nA * sizeof(int));
	B = (int *) malloc (nB * sizeof(int));
	
	for (i = 0; i < nA; i++){
		scanf(" %d", &A[i]);
	}
	for (i = 0; i < nB; i++){
		scanf(" %d", &B[i]);
	}

	if (nA > nB){
		k = nA;
		res = (int *) malloc (nA * sizeof(int));
		for (i = 0; i < nA; i++){
			res[i] = A[i];
		}
		
		for (i = 0; i < nB; i++){
			for (j = 0; j < nA; j++){
				if (B[i] == A[j])
				 break;
			}
			res = realloc(res, (nA+1) * sizeof(int));
			nA++;
			res[k] = B[i];
			k++;
		}
	}
	
	if (nB > nA){
		k = nB;
		res = (int *) malloc (nB * sizeof(int));
		for (i = 0; i < nB; i++){
			res[i] = B[i];
		}
		
		for (i = 0; i < nA; i++){
			for (j = 0; j < nB; j++){
				if (A[i] == B[j])
				 break;
			}
			res = realloc(res, (Nb+1) * sizeof(int));
			nB++;
			res[k] = B[i];
			k++;
		}
	}
	
}
