#include <stdio.h>
#include <stdlib.h>

int aux = 1;

typedef struct{
	float ni;
	float di;
} Fracao;

Fracao * fracoesPositivas(int k, Fracao *f){
	Fracao *fracoes;
	int i;
	
	fracoes = (Fracao *) malloc(sizeof(Fracao));
	
	for (i = 0; i < k; i++){
		if ((f[i]->ni / f[i]->di) > 0){
			fracoes[i]->ni = f[i]->ni;
			fracoes[i]->di = f[i]->di;
			aux++;
			fracoes = realloc(fracoes, aux * sizeof(Fracao));
		}
	}
	
	return (fracoes);	
	
}

int main(){
	int k, i;
	Fracao *f, *p;
	
	scanf(" %d", &k);
	f = (Fracao *) malloc(k * sizeof(Fracao));
	
	for (i = 0; i < k; i++){
		scanf(" %d", &f[i]->ni);
		scanf(" %d", &f[i]->di);
	}
	
	p = fracoesPositivas(k, f);
	for (i = 0; i < aux; i++){
		printf("%d/%d=%.2f", p[i]->ni, p[i]->di, (p[i]->ni / p[i]->di));
	}
}
