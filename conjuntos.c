#include <stdio.h>
#include <stdlib.h>

int k = 0;

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
		res = (int *) malloc (nA * sizeof(int));
		for (i = 0; i < nA; i++){
			res[i] = A[i];
		}
		
		for (i = 0; i < nB; i++){
			for (j = 0; j < nA; j++){
				if (B[i] != A[j]){
					res = realloc(res, (nA+1) * sizeof(int));
					nA++;
					k = nA;
					res[k] = B[i];
				}
			}
		}
		
		for (i = 0; i < nA; i++){
			printf("%d ", res);
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
			res = realloc(res, (nB+1) * sizeof(int));
			nB++;
			res[k] = B[i];
			k++;
		}
		
		for (i = 0; i < nB; i++){
			printf("%d ", res);
		}
	}
	
	
	
}
