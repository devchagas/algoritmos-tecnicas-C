#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct registro registro;

struct registro {
	int chave;
	//além de outros campos de informação do registro
};

void merge(registro *v, int p, int q, int r) 
{
   int i, j, k;
   registro *w;
   w = (registro *) malloc( (r-p+1) * sizeof (registro));
   i = p;
   j = q+1;
   k = 0;

   while (i <= q && j <= r) {
      if (v[i].chave <= v[j].chave)  
	      w[k++] = v[i++];
      else
          w[k++] = v[j++];
   }
   while (i <= q)
      w[k++] = v[i++];
   while (j <= r)
      w[k++] = v[j++];
   for (i = p; i <= r; ++i) 
      v[i] = w[i-p];
   free(w);
}


void mergesort(registro* v,int ini, int fim) 
{
  int meio; 
  if  (ini < fim) {
    meio = ( ini + fim ) / 2;
    mergesort(v, ini, meio );
    mergesort(v, meio+1, fim);
    merge(v, ini, meio, fim );
  }
}

int main()
{
	registro v[10];
	
	srand(time(NULL)); 
    
    printf("Vetor gerado\n");
	for (int i = 0; i < 10; i++) {
		v[i].chave = rand() % 100;
		printf("%d ", v[i].chave);
	}
	
	mergesort(v, 0, 9);
	
	printf("\n\nVetor ordenado\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", v[i].chave);
	
	return 0;
}