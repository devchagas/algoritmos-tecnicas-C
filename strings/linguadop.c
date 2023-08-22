#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(){
	char str[1000];
	int i = 0,c;
	
	while ((c = getchar()) != '\0'){
		if (c == ' ') str[i++] = ' ';
		else str[i++] = getchar();
	}
	printf("%s\n", str);
}
