#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define MAX 30


typedef struct lista lista;

struct lista{
	int total[MAX];
	int ultimo;
	int atual;
};

lista * create_lista(){
 	lista *novo = malloc(sizeof(lista));
 	assert(novo);
 	novo->atual = -1;
 	novo->ultimo = -1;
 	
 	return novo;
}

int tamanho(lista *lista) {
    if (lista != NULL)
        return lista->ultimo + 1;

    return 0;
}

bool vazia(lista *lista){
	return tamanho(lista) == 0;
}

bool cheia(lista *lista) {
    return tamanho(lista) == MAX;
}

bool inserirInicio(int *item, lista *lista) {
	 if (cheia(lista))
       return false;

    lista->ultimo++;
    lista->atual = lista->ultimo;
    while (lista->atual - 1 >= 0) {
        lista->total[lista->atual] = lista->total[lista->atual - 1];
        lista->atual--;
    }

    lista->total[lista->atual] = *item;

    return true;
}

void printar(lista *lista, int N){
	if (N == 0){
		printf("[NULL]");
		return;
	}
	
	printf("[%d] -> ", lista->total[lista->atual]);
	lista->atual++;
	N--;
	return printar(lista, N);
}

int main(){
	lista *lista = NULL;
	int N, i, x;
	
	lista = create_lista();
	
	scanf(" %d", &N);
	
	for (i = 0; i < N; i++){
		scanf(" %d", &x);
		inserirInicio(&x, lista);
	}
	
	printar(lista, N);
}


