#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void leetConverter(char *str){
	
	if (str* == '\0') printf("%s", *str);
	
	if (*str == ' ') leetConverter(*str + 1);

		if (*str == 4) *str = 'A';
		if (*str == 8) *str = 'B';
		if (*str == 'c') *str = 'C';
		if (*str == 'd') *str = 'D';
		if (*str == 3) *str = 'E';
		if (*str == 'f') *str = 'F';
		if (*str == 9) *str = 'G';
		if (*str == #) *str = 'H';
		if (*str == 1) *str = 'I';
		if (*str == 'j') *str = 'J';
		if (*str == 'k' *str = 'K';
		if (*str == /) *str = 'L';
		if (*str == 'm') *str = 'M';
		if (*str == 'n') *str = 'N';
		if (*str == 0) *str = 'O';
		if (*str == ?) *str = 'P';
		if (*str == 'q') *str = 'Q';
		if (*str == 'r') *str = 'R';
		if (*str == 5) *str = 'S';
		if (*str == 7) *str = 'T';
		if (*str == 'u') *str = 'U';
		if (*str == 'v') *str = 'V';
		if (*str == 'w') *str = 'W';
		if (*str == 'x') *str = 'X';
		if (*str == 'y') *str = 'Y';
		if (*str == 2) *str = 'Z';
		
		leetConverte(*str + 1);
}


int main(){
	char str[50];
	
	fflush(stdin);
	scanf(" %[^\n]%*c", str);
	leetConverte(str);
}
