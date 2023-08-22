#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 20

int busca_seq(int D[], int n, int k) {
   for (int i = 0; i < n; i++)
      if (D[i] == k)
         return i; //chave encontrada

   return -1; //chave não encontrada
}

int main(int argc, char *argv[]) {
   int x[TABLE_SIZE] = {23, 25, 27, 10, 15, 16, 50, 55, 60, 18, 20, 80, 99, 29, 30, 42, 49, 65, 70, 72};
   
   int res = busca_seq(x, TABLE_SIZE, 3);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
      
   res = busca_seq(x, TABLE_SIZE, 20);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
      
   res = busca_seq(x, TABLE_SIZE, 23);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
   
   res = busca_seq(x, TABLE_SIZE, 65);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
   
   res = busca_seq(x, TABLE_SIZE, 99);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
   
   res = busca_seq(x, TABLE_SIZE, 100);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
      
   getchar();
   return 0;
}