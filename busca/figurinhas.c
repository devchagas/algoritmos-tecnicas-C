#include <stdio.h>
#include <stdlib.h>

void insertionsort(int vet[], int n){
	int i, j, aux;
	
	for (i = n - 3; i < n; i++){
		aux = vet[i];
		j = i - 1;
		while((j >= 0) && (aux < vet[j])){
			vet[j+1] = vet[j];
			j--;
		}
		vet[j+1] = aux;
	} 
}

int main(){
	int *vet;
	int n, i;
	
	scanf(" %d", &n);
	
	vet = (int *) malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++){
		scanf(" %d", &vet[i]);
	}
	
	insertionsort(vet, n);
	
	for (i = 0; i < n; i++){
		printf("%d ", vet[i]);
	}
	
	free(vet);
}
