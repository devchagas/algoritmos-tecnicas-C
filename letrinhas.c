#include <stdio.h>
#include <stdlib.h>

int main(){
	int q, i, j;
	char *p, *vet;
	
	scanf(" %d", &q);
	
	vet = (char *) malloc (q * sizeof(char));
	
	for (i = 0; i < q; i++){
		scanf("%c", &vet[i]);
	}
	
	scanf(" %[^\n]%*c", p);
	
	printf("%d", q);
	puts(p);
}
