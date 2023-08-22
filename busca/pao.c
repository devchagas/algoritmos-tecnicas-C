#include <stdio.h>
#define MAX 10000

int verificar(int meio, int k, int paes[], int n) {
  int i, total = 0;
  
  for (i = 0; i < k; i++) { 
    total += paes[i] / meio;
  }
  return (total >= n);
}

int main(){
    int i, solucao = 0, esquerda = 0, direita = MAX + 1, meio;
	int n, k;
	int paes[MAX];
	
    scanf ("%d %d", &n, &k);
    
    for (i = 0; i < k; i++) {
      scanf ("%d", &paes[i]);
    }

    while (esquerda <= direita) {
      meio = (esquerda + direita) / 2; 
      if (verificar(meio, k, paes, n)) {
	esquerda = meio + 1;
	solucao = meio;
      } else 
	direita = meio - 1;

    }
    printf ("%d\n", solucao);

}
