#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i;
	int *vet;
	
	scanf(" %d", &n);
	vet = (int *) malloc (n * sizeof(int));
	if (vet == NULL) printf("Erro na Alocação!");
	
	for (i = 0; i < n; i++){
		scanf(" %d", &vet[i]);
	}
	
	vet = realloc(vet, sizeof(int) * (2*n));
	
	for (i = 0; i < n; i++){
		vet[n + i] = 2 * vet[i];
	}
	
	for (i = 0; i < (2*n); i++){
		printf("%d ", vet[i]);
	}
	
	free(vet);
}
