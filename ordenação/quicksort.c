#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct registro registro;

struct registro {
	int chave;
	//além de outros campos de informação do registro
};

void partition(int Esq, int Dir,
              int *i, int *j, registro *v)
{ 
  registro x, w;
  *i = Esq; *j = Dir;
	 
  //pivô
  x = v[(*i + *j)/2]; 

  do
  { 
    while (x.chave > v[*i].chave)
	     (*i)++;
    while (x.chave < v[*j].chave)
        (*j)--;
    if (*i <= *j)
    { 
      w = v[*i];
      v[*i] = v[*j];
      v[*j] = w;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}


void sort(int Esq, int Dir, registro *v)
{ 
  int i,j;
  partition(Esq, Dir, &i, &j, v);
  if (Esq < j)
	 sort(Esq, j, v);
  if (i < Dir)
     sort(i, Dir, v);
}
void quicksort(registro *v, int n)
{ 
  sort(0, n-1, v); 
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
	
	quicksort(v, 10);
	
	printf("\n\nVetor ordenado\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", v[i].chave);
	
	return 0;
}