#include <stdio.h>
#include <stdlib.h>

int * nextPrime (int n){
	int *num, i, aux = 1, res = 0;
	
	num = (int *) malloc (sizeof(int));
	
	if (num == NULL){
		printf("Erro na Alocação!");
	}
	*num = n + 1;
	
	while (aux){
	for (i = 2; i < n; i++){
		if ((*num) % i == 0){
			res++;
			break;
		}
	}
	if (res == 0) return (num);
	res = 0;
	(*num)++;
	}
	return (num);
}

int main(){
	int n, *prime;
	
	//printf("Digite o valor de N: ");
	scanf(" %d", &n);
	prime = nextPrime(n);
	printf("%d", *prime);
	free(prime);
}
