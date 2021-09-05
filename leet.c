#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void leetConverte(char *str){
	char leet[] = {'4','8','c','d','3','f','9','#','1','j','k','/','m','n','0','?','q','r','5','7','u','v','w','x','y','2','\0'};
	char alf[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
	int i;
	int n = strlen(*str);
	for (i = 0; i < n; i++){
		if (*(str + i) == leet[i]){
			*(str + i) = alf[i];
		}
	}
}

int main(){
	char str[50];
	
	fflush(stdin);
	scanf(" %[^\n]%*c", str);
	leetConverte(str);
	printf("%s", str);
}
