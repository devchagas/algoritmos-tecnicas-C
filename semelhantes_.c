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

bool next(list *q, item **it) {
    if (empty(q))
        return false;

    if (q->current == q->last)
        return false;

    q->current = q->current->next;
    *it = q->current;
    return true;
}

int size(list *l) {
    int count = 0;
    item *aux = l->first;
    
    while(aux) {
        count++;
        aux = aux->next;
    }

    return count;
}

bool first(list *q, item **it) {
    if (empty(q))
        return false;

	q->current = q->first;
    *it = q->current;
    return true;
}

bool last(list *q, item **it) {
    if (empty(q))
        return false;

    q->current = q->last;
    *it = q->current;
    return true;
}

void print(list *l) {
    if (empty(l)) {
        printf("A lista esta' vazia");
        return;
    }
    
    item *aux = l->first;

    do {
        printf("[%d] -> ", aux->info);
        aux = aux->next;
    }
    while(aux);
    printf("[NULL]");
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

item * search(list *l, int key) {
    if (empty(l))
        return NULL;

    item *aux = l->first;

    while(aux && aux->info != key)
        aux = aux->next;

    return aux;
}

bool removeItemByKey(list *l, int key) {
	item *temp = search(l, key);
	
    if (temp == NULL)
        return false;

    if (temp == l->first) {
    	l->first = temp->next;
    	l->current = temp->next;
    	
    	if (l->current == NULL) 
    		l->last = NULL;
	}
	else { 
		l->current = l->first;
		while(l->current->next != temp)
			l->current = l->current->next;
		
		l->current->next = temp->next;
		
		if (temp == l->last) 
			l->last = l->current;
	}
	
	free(temp);
	return true;
    
}

bool comparar(list * lista1, list * lista2){
	lista2->current = search(lista2, lista1->current->info);
	if (lista1->current->info != lista2->current->info)
	 return false;
	else
		if (lista1->current->next == NULL)
			return true;
	lista1->current	 = lista1->current->next;
	return comparar(lista1, lista2);
}

int main(){
	int n;
	list * lista1 = create_list();
	list * lista2 = create_list();

	scanf(" %d", &n);
	while (n != 0){
		insertAtLast(lista1, create_node(n));
		scanf(" %d", &n);
	}
	
	scanf(" %d", &n);
	while (n != 0){
		insertAtLast(lista2, create_node(n));
		scanf(" %d", &n);
	}
	lista1->current = lista1->first;
	lista2->current = lista2->first;
	if (comparar(lista1, lista2))
		printf("S");
	else{
		lista1->current = lista1->first;
		lista2->current = lista2->first;
		if (comparar(lista2, lista1))
			printf("S");
		else printf("N");
	}
}
