#include <stdlib.h>
#include <stdio.h>
#define MAX 100

int submarino(int n, char tabuleiro[MAX][MAX]){
	int cont=0, aux = 0, i, j;
	
	for (i = 0;i < n; i++){
		for (j = 0; j < n; j++){
			
			if (tabuleiro[i][j] == '+'){
				aux = aux + 1;
			} else if (aux == 2){
					cont = cont + 1;
					aux=0;
			} else (aux =0);
		}
		if (aux == 2){
			cont = cont + 1;
		}
		aux=0;
	}
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j ++){
			
			if (tabuleiro[j][i] == '+'){
				aux = aux + 1;
			} else if (aux == 2){
					cont = cont + 1;
					aux = 0;
			} else (aux = 0);
		}
		if (aux == 2){
			cont = cont + 1;
		}
		aux = 0;
	}	

	return cont;
}

int main (){
	
	int n = 100;
	char tabuleiro[n][n];
	int i, j;

	scanf (" %d", &n);
	
	for( i = 0; i < n; i++){
    	for (j = 0; j < n; j++){	
            scanf(" %c", &tabuleiro[i][j]);	
        }
	}
			
	printf("%d", submarino(n, tabuleiro));
}
