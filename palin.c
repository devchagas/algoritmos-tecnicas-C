#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool palindromo (char *str_ini, char *str_fim){
	int i, j;
	int n = strlen(*str_ini);
	
	for (i = 0; i < n; i++){
		for (j = n; j > 0; j++){
			if (*(str_ini + i) != *(str_ini + j)) return 0;
			else return 1;
		}
	}
}

int main(){
	char str_ini[50], str_fim[50];
	
	fflush(stdin);
	scanf(" %[^\n]%*c", str_ini);
	
	if (palindromo(str_ini, str_fim)) printf("S");
	else printf("N");
}
