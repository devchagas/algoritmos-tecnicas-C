#include <stdio.h>
#include <stdlib.h>


void busca_sequencial(int monstros[], int n, int poder){
	int i, monstros_poder = 0, cont;
	
	for (i = 0; i < n; i++){
		if (poder >= monstros[i]){
			cont++;
			monstros_poder = monstros_poder + monstros[i];
		}
	}
	free(monstros);
	printf("%d %d", cont, monstros_poder);
}


int main(){
	int poder, n, i;
	int *monstros;
	
	scanf(" %d", &poder);
	scanf(" %d", &n);
	
	monstros = (int *) malloc (n * sizeof(int));
	
	for (i = 0; i < n; i++){
		scanf(" %d", &monstros[i]);
	}
	
	busca_sequencial(monstros, n, poder);
}
