#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct registro registro;

struct registro {
	int chave;
	//além de outros campos de informação do registro
};

void bubblesort (registro* v, int n )
{
  int i, j;
  registro temp;
  for( i = 0 ; i < n-1 ; i++ )
    for( j = 1 ; j < n-i ; j++ )
      if ( v[j].chave < v[j-1].chave ) 
      {
        temp = v[j];
        v[j] = v[j-1];
        v[j-1] = temp;
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
	
	bubblesort(v, 10);
	
	printf("\n\nVetor ordenado\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", v[i].chave);
	
	return 0;
}