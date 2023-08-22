#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void str_upper(char *str){
	
	if (*str == '\0') return;
	
	if(isalpha(*str)){
		*str -= 32;
	}
	
	return str_upper(str+1);
}

int main(){
	char str[50];
	
	fflush(stdin);
	scanf(" %[^\n]%*c", str);
	str_upper(str);
	puts(str);
}
