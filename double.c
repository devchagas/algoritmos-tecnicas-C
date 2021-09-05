#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct item item;

struct item {
    int info;
    item *next;
};

typedef struct list list;

struct list {
   item *first;   
   item *last;    

    item *current;    
};

list * create_list() {
    list *novo = malloc(sizeof(list));
    assert(novo);
    novo->first = NULL;
    novo->last = NULL;
    novo->current = NULL;

    return novo;
}

bool empty(list *l) {
    return l->first == NULL;
}

void destroy(list **q) {
	item *temp;
    if (!empty(*q)) {
        item *aux = (*q)->first;

        while(aux) {
            temp = aux;
            aux = aux->next;
            free(temp);
        }

    }
	free(*q);
	
	*q = NULL;
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

void print(list *l) {
    if (empty(l)) {
        printf("A lista esta' vazia");
        return;
    }
    
    item *aux = l->first;

    do {
        printf("%d ", aux->info);
        aux = aux->next;
    }
    while(aux);

    printf("\n");
}

void insertAtLast(list *l, item *node) {
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

bool last(list *q, item **it) {
    if (empty(q))
        return false;

    q->current = q->last;
    *it = q->current;
    return true;
}

int main(){
	list * lista = create_list();
	
	int i, n;
	
	scanf(" %d", &n);
	while (n != 0){
		insertAtLast(lista, create_node(n));
		scanf(" %d", &n);
	}
	print(lista);
}
