#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str[1000], frase[1000];
	int i, n, j = 0;
	
	scanf(" %[^\n]%*c", str);
	n = strlen(str);
	
	for (i = 1; i < n; i+2){
		if (str[i+1] == ' ') i++;
		frase[j] = str[i];
		j++;
	}
	
	printf("%s", frase);
}
