#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countwords(char *str, int cont){
	char pont = *str;
	
	if (pont == '\0'){
		cont++;
		return cont;
	}
	
	if (pont == ' ') cont++;
	return countwords(str + 1, cont);
}

int main(){
	char str[50];
	int cont = 0;
	
	fflush(stdin);
	scanf(" %[^\n]%*c", str);
	printf("%d", countwords(str, cont));
}
