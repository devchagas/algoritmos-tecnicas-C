#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char str[50], cifra[50];
	int rot, i, asc, n;
	
	scanf(" %d", &rot);
	fflush(stdin);
	scanf(" %[^\n]%*c", str);
	
	n = strlen(str);
	
	for (i = 0; i < n; i++){
		if (str[i] == ' '){
			cifra[i] = str[i];
		}
		else{
		asc = str[i];
		cifra[i] = asc + rot;
		}
	}
	printf("%s", cifra);
}
