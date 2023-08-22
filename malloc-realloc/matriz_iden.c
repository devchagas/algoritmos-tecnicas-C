#include <stdio.h>
#include <stdlib.h>

int * matriz_identidade(int n){
	int i, j;
	int *mat;
	
	mat = malloc (n * n * sizeof(int));
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (i == j) mat[(i*n) + j] = 1;
			else mat[(i*n) + j] = 0;
		}
	}
	return (mat);
	
}

int main(){
	int n, i, j;
	int *mat;
	
	scanf(" %d", &n);
	mat = matriz_identidade(n);
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%d ", mat[(i*n) + j]);
		}
		printf("\n");
	}
	free(mat);
}
