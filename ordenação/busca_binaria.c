#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 20

int busca_binaria(int D[], int n, int k) {
   int inf = 0, sup = n-1;

   while(inf <= sup) {
      int meio = (inf + sup) / 2;
	   
      if (k < D[meio])
         sup = meio - 1;
	  else if (k > D[meio])
	     inf = meio + 1;
      else return meio; /* encontrou */
   }

   return -1;
}

int busca_binaria_rec(int D[], int k, int inf, int sup) {  
   if (inf <= sup) {
      int meio = (inf + sup) / 2;
	   
      if (k < D[meio])
          return busca_binaria_rec(D, k, inf, meio - 1);
	  else if (k > D[meio])
		  return busca_binaria_rec(D, k, meio + 1, sup);
      else return meio; /* encontrou */
   }

   return -1;
}

int busca_binaria2(int D[], int n, int k) {
	return busca_binaria_rec(D, k, 0, n - 1);
}

int main(int argc, char *argv[]) {
   int x[TABLE_SIZE] = {10, 15, 16, 18, 20, 23, 25, 27, 29, 30, 42, 49, 50, 55, 60, 65, 70, 72, 80, 99};
   
   int res = busca_binaria2(x, TABLE_SIZE, 3);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
      
   res = busca_binaria2(x, TABLE_SIZE, 20);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
      
   res = busca_binaria2(x, TABLE_SIZE, 23);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
   
   res = busca_binaria2(x, TABLE_SIZE, 65);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
   
   res = busca_binaria2(x, TABLE_SIZE, 99);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
   
   res = busca_binaria2(x, TABLE_SIZE, 100);
   if (res == -1)
      printf("Nao encontrado!\n");
   else
      printf("Encontrado na posicao %d = %d\n", res, x[res]);
      
   getchar();
   return 0;
}