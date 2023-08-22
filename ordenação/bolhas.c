#include <stdio.h>
#include <stdlib.h>

void bubblesort(int v[], int n){
	int i, j, aux, k = 0;
	
	for (i = 0; i < n - 1; i++)
		for (j = 1; j < n - 1; j++)
			if (v[j] < v[j - 1]){
				aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
				k++;
			}
			
	if (k % 2 == 0) printf("Marcelo");
	else printf("Carlos");
}

int main(){
	int n, i;
	int *vet;
	
	scanf(" %d", &n);
	
	vet = (int *) malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++){
		scanf(" %d", &vet[i]);
	}
	
	bubblesort(vet, n);
	
	free(vet);
}
