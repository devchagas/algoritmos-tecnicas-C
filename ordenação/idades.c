#include <stdio.h>
#include <stdlib.h>

void verificar(int vet[], int n){
	int i, j, cont = 0;
	
	for (i = 0, j = 1; j < n; i++, j++){
			if (vet[i] > vet[j])
				cont++;
		}
	
	printf("%d", cont);
	
}

int main(){
	int *vet;
	int n, i;
	
	scanf(" %d", &n);
	
	vet = (int *) malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++){
		scanf(" %d", &vet[i]);
	}
	
	verificar(vet, n);
	
	free(vet);
}
