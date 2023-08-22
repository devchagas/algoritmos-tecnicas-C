#include <stdlib.h>
#include <stdio.h>

typedef struct index {
   char kindex; 
   int pos;   
}index;

typedef struct func{
	char inicial;
	float salario;
	int posicao;
}func;

void primeiro_indice(index index[], int t, int vet[], int n) {
   int i, pos;
   
   for (i = 0; i < t; i++) {
      pos = (i+1) * n / (t+1); 
      index[i].kindex = vet[pos];
      index[i].pos = pos;
   }
}

void segundo_indice(index vet[], int tam_index){
	char valor;
	int pos, i;
	
	for (i=0; i< tam_index; i++){
		scanf(" %c", &valor);
		scanf(" %d", &pos);
		
		vet[i].kindex = valor;
		vet[i].pos = pos;
	}
}

void tabela (func *func, int tam){
	int i;
	
	for (i=0; i < tam; i++){
		scanf (" %d", &func[i].posicao);
		scanf (" %c", &func[i].inicial);
		scanf (" %f", &func[i].salario);
	}
}

int busca_seq_ind(int vet[], int n, int k, index index[], int t) {
   int i;
   for (i = 0; i < t && index[i].kindex <= k; i++)
      ;

   int lowLim = (i == 0) ? 0 : index[i-1].pos;
   int hiLim = (i == t) ? n - 1 : index[i].pos - 1;
   
   for (i = lowLim; i <= hiLim; i++)
	if (vet[i] == k)
         return i;

   return -1; 
}

void print(func *func, int tam_func, char k, index * indice, int tam_index){
	
	   int i;
	   
	   for (i = 0; i < tam_index && indice[i].kindex != k; i++);
	   	   	  	
    	int lowLim = (i == 0) ? 0 : indice[i].pos-1;
  		int hiLim = (i == tam_index-1) ? tam_func-1 : indice[i+1].pos-1 ;

 	 	for (i = lowLim; i < hiLim; i++){
 	 	 	
 	 	 	if(func[i].inicial != k)
 	 	 	i++;
 	 	 	
 			printf("%.2f\n", func[i].salario);
		}	
}

int main (){
	int tam_index, tam_func;
	char k;
	
	scanf(" %d", &tam_index);
	
	index indices[tam_index];
	
	segundo_indice(indices,tam_index);
	
	scanf(" %d", &tam_func);
	func func[tam_func];
	
	tabela(func,tam_func);
	
	scanf(" %c", &k);
	
	print(func, tam_func, k, indices, tam_index);
	
	
}
