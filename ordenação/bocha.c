#include <stdio.h>
#include <stdlib.h>

void bubblesort(int vet[], int n){
	int i, j, aux;
	
	for (i = 0; i < 2; i++)
		for (j = 1; j < n - i; j++){
			if (vet[j] < vet[j-1]){
				aux = vet[j];
				vet[j] = vet[j - 1];
				vet[j - 1] = aux;
			}
		}
	
	printf("%d", vet[n-2]);
}

int main(){
	int *vet;
	int n, i;
	
	scanf(" %d", &n);
	
	vet = (int *) malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++){
		scanf(" %d", &vet[i]);
	}
	
	bubblesort(vet, n);
	
	free(vet);
	
}
