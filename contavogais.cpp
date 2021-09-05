#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int contavogais(char *str, int cont){
	char pont = *str;
	
	if (pont == '\0') return cont;
	
	if (pont == 'a' || pont == 'A') cont++;
	else if (pont == 'b' || pont == 'B') cont++;
	else if (pont == 'c' || pont == 'C') cont++;
	else if (pont == 'd' || pont == 'D') cont++;
	else if (pont == 'e' || pont == 'E') cont++;
	
	return contavogais(str + 1, cont);
}

int main(){
	int cont = 0;
	char str[50];
	
	fflush(stdin);
	scanf(" %[^\n]%*c", str);
	printf("%d", contavogais(str, cont));
}
