#include <stdio.h>
#include <stdlib.h>

int main(){
	int vet[5], i, j;
	int d = 0, c = 0;
	
	for (i = 0; i < 5; i++){
		scanf(" %d", &vet[i]);
	}
	
	for (i = 0, j = 1; j < 5; i++, j++){
		if (vet[i] < vet[j])
			c = 1;
		if (vet[i] > vet[j])
			d = 1;
	}
	
	if (c && !d) printf("C");
	else if (!c && d) printf("D");
	else if (c && d) printf("N"); 
}
