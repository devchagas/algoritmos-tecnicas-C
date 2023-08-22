#include <stdio.h>
#include <stdlib.h>

char * charToString(char c){
	char *str;
	
	str = (char *) malloc(2 * sizeof(char));
	
	if (str == NULL) printf("Erro na Alocação!");
	
	
	*str = c;
	str[1] = '\0';
	return (str);
}

int main(){
	char c, *str;
	
	scanf(" %c", &c);
	str = charToString(c);
	printf("%s", str);
	free(str);
}
