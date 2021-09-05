#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strlenght (char *str, int cont){
	
	char pont = *str;
	
	if (pont == '\0') return cont;
	
	cont++;
	return strlenght(str+1, cont);
}

int main(){
	char str[50];
	int cont = 0;
	
	scanf(" %[^\n]%*c", str);
	cont = strlenght(str, cont);
	printf("%d", cont);
}
