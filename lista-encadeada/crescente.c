#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct item item;

struct item {
    int info;
    item *next;
};

typedef struct lista lista;

struct lista {
   item *first; 
   item *last;    

   item *current;    
};

lista * create_lista() {
    lista *novo = malloc(sizeof(lista));
    assert(novo);
    novo->first = NULL;
    novo->last = NULL;
    novo->current = NULL;

    return novo;
}

item * create_node(int info) {
    //Aloca a memória para um novo item
    item * novo = malloc(sizeof(item));
    assert(novo);

    //Define suas informações
    novo->info = info;
    novo->next = NULL;

    //Retorna o endereço do novo item
    return novo;
}

void insertAtLast(lista *l, item *node) {
    item *aux;
    if (empty(l))
        l->first = node;
    else {
        last(l, &aux);
        aux->next = node;
    }
    
    l->current = node;
    l->last = node;
}

int main(){
	lista *lista = create_lista();
	
	int n, flag = 1;
	
	scanf(" %d", &n);
	while (n != 0){
		insertAtLast(lista, createnode(n));
		scanf(" %d", &n);
	}
	
	item *aux = lista->first;
	item *temp = lista->first->next;
	
	while (flag){
		if (aux == NULL || temp == NULL) printf("S");
		if (aux > temp) printf("N");
		else{
			aux = aux->next;
			temp = temp->next;
		}
	}
	
}
