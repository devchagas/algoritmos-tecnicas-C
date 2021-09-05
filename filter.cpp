#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void filter(char *str, char c, char *frase){
	
	
	if (*str == '\0') return;
	
	if (isupper(c)) c += 32;
	
	if (*str == c || *str == toupper(c)) {
		filter(str+1, c, frase);
	//	*str = *(str+1);
	//	filter(str,c);
	}
		if (*str != c){
		*frase = *str;
	}
	filter(str+1,c, frase+1);
	
}

int main(){
	char str[50], c, frase[50];
	
	scanf(" %c", &c);
	fflush(stdin);
	scanf(" %[^\n]%*c", str);
	fflush(stdin);
	
	filter(str, c, frase);
	printf("%s", frase);
}
