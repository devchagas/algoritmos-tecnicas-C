#include <stdio.h>
#include <stdlib.h>

int ** somar_matrizes(int n, int **a, int **b){
	int **mat, i, j;
	
	mat = malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		mat[i] = (int *) malloc(n * sizeof(int));
		
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			mat[i][j] = a[i][j] + b[i][j];
		}
	}
	
	return (mat);
}

int main(){
	int n, i;
	int **a, **b, **mat;
	scanf(" %d", &n);
	
	a = malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) 
		a[i] = malloc(n * sizeof(int));
	
	b = malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) 
		b[i] = malloc(n * sizeof(int));
		
	int j;
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			scanf(" %d", &a[i][j]);
		}
	}
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			scanf(" %d", &b[i][j]);
		}
	}
	
	mat = somar_matrizes(n, a, b);
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	
	free(a);
	free(b);
	free(mat);
}
