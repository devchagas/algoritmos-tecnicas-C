#include <stdio.h>
#include <stdlib.h>

void selectionSort(int v[], int n){
	int i, j, menor, aux;
	
	for (i = 0; i < n-1; i++){
		menor = i;
		for (j = i + 1; j < n; j++)
			if ( v[j] < v[menor]) 
       		 menor = j;
       		
       	aux = v[menor];
       	v[menor] = v[i];
       	v[i] = aux;
	}
}


int main(){
	int n, i;
	int *vet;
	
	scanf(" %d", &n);
	
	vet = (int *) malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++){
		scanf(" %d", &vet[i]);
	}
	
	selectionSort(vet, n);
	
	for (i = 0; i < n; i++){
		printf("%d ", vet[i]);
	}
	
	free(vet);
}
