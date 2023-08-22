#include <stdio.h>
#include <stdlib.h>

int main(){
	int vet[8];
	int i, j, cont = 0;
	
	for (i = 0; i < 8; i++){
		scanf(" %d", &vet[i]);
	}
	
	for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++){
			if (vet[i] == vet[j])
				cont++;
		}
		if (cont > 4){
			printf("N");
			return 1;
		}
		else cont = 0;
	}
	
	printf("S");
}
