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
	int *vet, *exame, cont;
	int n, i, j = 0;
	
	scanf(" %d", &n);
	
	vet = (int *) malloc(n * sizeof(int));
	exame = (int *) malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++){
		scanf(" %d", &vet[i]);
	}
	
	for (i = 0; i < n; i++){
		if (vet[i] < 50){
			cont++;
			exame[j] = vet[i];
			j++;
		}
	}
	
	exame = realloc(exame, cont * sizeof(int));
	
	selectionSort(exame, cont);
	
	for (i = 0; i < cont; i++){
		printf("%d ", exame[i]);
	}
	
	free(vet);
	free(exame);
}
