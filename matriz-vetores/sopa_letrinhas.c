#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

int busca_sequencial(char vet[], int n, char c) {
   int i;
   
   for (i = 0; i < n; i++)
      if (vet[i] == c)
         return i;

   return -1;
}

char * char_String(char c){
		
		char *string;
		
		string = (char *) malloc (2 * sizeof(char));
		if (string == NULL){
			printf("Nao e possivel alocar");
		}
		
		*(string) = c;
		*(string+1)= '\0';
		return(string);
}

bool verificar(char chave[], char vet[]){
	
	int k, i;
	
	for (i=0; i < strlen(chave); i++){
		k = busca_sequencial(vet, strlen(vet), chave[i]);
		if (k == -1)
		  return false;
		else
	    	vet[k]= '.';
	
	}
	return true;
	
}


int main (){
	int q, k, i;
	char *vet, palavra[MAX];

	scanf (" %d", &q);

	vet = (char *) malloc((q+1) * sizeof(char));


	for (i=0; i < q; i++){
		scanf(" %c", &vet[i]);
	}
	vet[q+1] = '\0';
	
	scanf(" %[^\n]%*c", palavra);

	k = verificar(palavra,vet);

	if (k)
		printf("S");
	else (printf("N"));
	
	free(vet);
}
