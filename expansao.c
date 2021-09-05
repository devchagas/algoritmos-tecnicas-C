#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i, aux = 0, j;
	int *vet, *s;
	
	scanf(" %d", &n);
	
	vet = (int *) malloc(n * sizeof(int));
	for (i = 0; i < n; i++){
		scanf(" %d", &vet[i]);
	}
	
	s = (int *) malloc(sizeof(int));
	
	for (i = 0; i < n; i++){
		aux = aux + vet[i];
		s = realloc(s, aux * sizeof(int));
		while (j < aux){
			s[j] = vet[i];
			j++;
		}
		j = aux;
	}
	
	for (i = 0; i < aux; i++){
		printf("%d ", s[i]);
	}
	
	free(vet);
	free(s);
}
