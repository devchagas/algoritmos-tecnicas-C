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
void contador(lista *lista){
	lista->ultimo++;
	lista->atual = lista->ultimo;
	scanf(" %d", &lista->total[lista->atual]);
	if (lista->total[lista->atual] == 0){
		lista->ultimo--;
		lista->atual = 0;
		return;
	}
	return contador(lista);
}

int main(){
	lista *lista = NULL;
	
	lista = create_lista();
	contador(lista);
	printf("%d", tamanho(lista));
}
