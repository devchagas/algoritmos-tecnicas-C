#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 20
#define INDEX_SIZE 3

typedef struct index index;

struct index {
   int kindex; //valor de chave
   int pos;    //posição na tabela principal
};

void cria_indice(index I[], int t, int D[], int n) {
   for (int j = 0; j < t; j++) {
      int pos = (j+1) * n / (t+1); 
      I[j].kindex = D[pos];
      I[j].pos = pos;
   }
}

int busca_seq_ind(int D[], int n, int k, index I[], int t) {
   int j;
   for (j = 0; j < t && I[j].kindex <= k; j++)
      ;

   int lowLim = (j == 0) ? 0 : I[j-1].pos;
   int hiLim = (j == t) ? n - 1 : I[j].pos - 1;
   
   for (int j = lowLim; j <= hiLim; j++)
	if (D[j] == k)
         return j; //chave encontrada

   return -1; //chave não encontrada
}

int main(int argc, char *argv[]) {
   int x[TABLE_SIZE] = {10, 15, 16, 18, 20, 23, 25, 27, 29, 30, 42, 49, 50, 55, 60, 65, 70, 72, 80, 99};
   index ind[INDEX_SIZE];
   
   cria_indice(ind, INDEX_SIZE, x, TABLE_SIZE);
   
   printf("INDICE\n");
   for (int i = 0; i < INDEX_SIZE; i++)
      printf("I[%d].kindex = %d, pos = %d\n", i, ind[i].kindex, ind[i].pos);
   
   int res = busca_seq_ind(x, TABLE_SIZE, 3, ind, INDEX_SIZE);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
      
   res = busca_seq_ind(x, TABLE_SIZE, 20, ind, INDEX_SIZE);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
      
   res = busca_seq_ind(x, TABLE_SIZE, 23, ind, INDEX_SIZE);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
   
   res = busca_seq_ind(x, TABLE_SIZE, 65, ind, INDEX_SIZE);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
   
   res = busca_seq_ind(x, TABLE_SIZE, 99, ind, INDEX_SIZE);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
   
   res = busca_seq_ind(x, TABLE_SIZE, 100, ind, INDEX_SIZE);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
      
   getchar();
   return 0;
}