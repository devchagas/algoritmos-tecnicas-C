#include <stdlib.h>
#include <stdio.h>

int maximo (int ant, int maximo){
	if (maximo > ant)
		return maximo;
	else return ant;
}

int main (){
	
	int mat[50][50], saida[25][25];
	int flag = 0, n, i, j, y, x, valor;

	
	for (i = 0; i < 50; i++){
		for (j = 0; j < 50; j++){
			mat[i][j] = 0;
		}
	}
	
	for (i = 0; i < 25; i++){
		for (j = 0; j < 25; j++){
			saida[i][j]=0;
		}
	}
	
	scanf (" %d", &n);
	for( i = 0; i < n; i++){
    	for (j = 0; j < n; j++){	
            scanf(" %d", &mat[i][j]);	
        }
	}
	
	
	
	for ( y = 0; y < n/2; y++) { 
    	for ( x = 0; x < n/2; x++) { 
        	for ( i = 0; i < 2; i++) { 
           		 for ( j = 0; j < 2; j++) {
				
                    valor = mat[(y * 2) + i][(x * 2) + j];            
					flag = maximo(flag, valor);
					saida[y][x] = flag;	
                }
            }
			flag = 0;      
        }
    }
    

	for( i = 0; i < n/2; i++){
    	for (j = 0; j < n/2; j++){
			if((j+1) == n/2)
				printf("%d", saida[i][j]);	
			else printf("%d ", saida[i][j]);	
        }
        printf("\n");
	}

}
