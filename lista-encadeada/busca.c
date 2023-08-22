#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define MAX 1000

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

void buscar(lista *lista, int B, int N){
	if (vazia(lista))
	 return;
	
	if (lista->total[lista->atual] == B){
		printf("S");
		return;
	}

	else{
		if (N == 0){
			printf("N");
			return;
		}
		lista->atual++;
		N--;
		return buscar(lista, B, N);
	}
}

int main(){
	lista *lista = NULL;
	
	lista = create_lista();
	
	int N, B, i, x;
	
	scanf(" %d", &N);
	scanf(" %d", &B);
	
	for (i = 0; i < N; i++){
		scanf(" %d", &x);
		inserirInicio(&x, lista);
	}
	
	buscar(lista, B, N);
}
