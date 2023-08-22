#include <stdio.h>
#include <stdlib.h>

int * elementos_PA(int n, int r, int a1){
	int *vet, i;
	
	vet = (int *) malloc(n * sizeof(int));
	if (vet == NULL) printf("Erro na Alocação!");
	
	vet[0] = a1;
	for (i = 1; i < n; i++){
		vet[i] = vet[i - 1] + r;
	}
	return (vet);
}

int main(){
	int n, r, a1, i;
	int *vet;
	
	scanf(" %d", &n);
	scanf(" %d", &r);
	scanf(" %d", &a1);
	vet = elementos_PA(n, r, a1);
	for (i = 0; i < n; i++){
		printf("%d ", vet[i]);
	}
	free(vet);
}
