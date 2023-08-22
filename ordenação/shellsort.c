#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct registro registro;

struct registro {
	int chave;
	//além de outros campos de informação do registro
};

void shellsort (registro* v, int n)
{ 
  int i, j; 
  int h = 1;
  registro temp;
  
  do
	  h = h * 3 + 1;
  while (h < n);
  do
  { 
    h /= 3; 
    for( i = h ; i < n ; i++ )
    {
      temp = v[i];
	  j = i;
      while (v[j - h].chave > temp.chave)
      {
        v[j] = v[j - h];
	    j -= h;
        if (j < h) break;
      }
      v[j] = temp;
    }
  } while (h != 1);
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
	
	shellsort(v, 10);
	
	printf("\n\nVetor ordenado\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", v[i].chave);
	
	return 0;
}