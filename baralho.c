#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
	char chave;
}registro;

void partition(int Esq, int Dir, int *i, int *j, registro *v){
	registro x, w;
	*i = Esq; *j = Dir;
	
	x = v[(*i + *j) / 2];
	
	do{
		while(x.chave < v[*i].chave)
				(*i)++;
		while(x.chave > v[*j].chave)
				(*j)--;
		if (*i <= *j){
			w = v[*i];
			v[*i] = v[*j];
			v[*j] = w;
			(*i)++;
			(*j)--;
		}
	} while (*i <= *j);
}

void sort(int Esq, int Dir, registro *v){
	int i,j;
	partition(Esq, Dir, &i, &j, v);
	if (Esq < j)
		sort(Esq, j, v);
	if (i < Dir)
		sort(i, Dir, v);
}

void quicksort(registro *v, int n){
	sort(0, n-1, v);
}

int main(){
	registro * v;
	int n, i;
	
	scanf(" %d", &n);
	
	v = (registro *) malloc(n * sizeof(registro));
	
	for (i = 0; i < n; i++){
		scanf(" %c", &v[i].chave);
	}
	
	quicksort(v, n);
	
	for (i = 0;i < n; i++){
		printf("%c ", v[i].chave);
	}
	
	return 0;
	
	free(v);
}
