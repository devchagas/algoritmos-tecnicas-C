#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct registro registro;

struct registro {
	int chave;
	//além de outros campos de informação do registro
};

void insertionsort (registro* v, int n )
{
  int i,j;
  registro temp;
  for (i = 1; i < n; i++)
  {
    temp = v[i];
    j = i - 1;
    while ( ( j >= 0 ) && ( temp.chave < v[j].chave ) )
    {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = temp;
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
	
	insertionsort(v, 10);
	
	printf("\n\nVetor ordenado\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", v[i].chave);
	
	return 0;
}