#include <stdio.h>
#include <stdlib.h>

void busca_sequencial(int PA[], int N, int R){
	int i, j, res;
	
	for (i = 0, j = 1; j < N; i++, j++){
		if (PA[i] + R != PA[j]){
			res = PA[i] + R;
			printf("%d", res);
		}
	}
	
}

int main(){
	int R, N, i;
	int *PA;
	
	PA = (int *) malloc (N * sizeof(int));
	
	scanf(" %d", &R);
	scanf(" %d", &N);
	
	for (i = 0; i < N; i++){
		scanf(" %d", &PA[i]);
	}
	busca_sequencial(PA, N, R);
}

