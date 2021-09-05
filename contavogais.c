#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int contavogais(char *str, int cont){
	char pont = *str;
	
	if (pont == '\0') return cont;
	
	if (pont == 'a' || pont == 'A') cont++;
	else if (pont == 'e' || pont == 'E') cont++;
	else if (pont == 'i' || pont == 'I') cont++;
	else if (pont == 'o' || pont == 'O') cont++;
	else if (pont == 'u' || pont == 'U') cont++;
	
	return contavogais(str + 1, cont);
}

int main(){
	int cont = 0;
	char str[50];
	
	fflush(stdin);
	scanf(" %[^\n]%*c", str);
	printf("%d", contavogais(str, cont));
}
