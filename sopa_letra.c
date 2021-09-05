#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int alterar(char letras[], int q, int pos){
	int i;
	
	q--;
	for (i = pos; i < q; i++){
		letras[i] = letras[i + 1];
	}
	
	return q;
	
}

int verificar(char p[], char letras[], int q){
	int i, j;
	char pont = *p;
	char aux = *letras;
	
	while (p != '\0'){
		if (p == aux){
			printf("n");
			q = alterar(letras, q, i);
		}
	}
		p++;
}


int main(){
	int q, i;
	char p[MAX];
	char *letras;
	
	scanf(" %d", &q);
	
	letras = (char *) malloc(q * sizeof(char));
	
	for (i = 0; i < q; i++){
		scanf(" %c", &letras[i]);
	}
	
	scanf(" %[^\n]%*c", p);
	
	verificar(p, letras, q);
	
}
