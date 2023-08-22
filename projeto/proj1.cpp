#include <stdio.h>
#include <stdlib.h>

void histograma(FILE *fp){
	FILE *fp3;
	int quebra_linha = 0, aux, vet[256] = {0}; //0 até 255
	char ch;
	
	int i;
	
	fp3 = fopen("histograma.txt", "w+");
	if (fp3 == NULL){
		printf("Não foi possível abrir o arquivo!");
		getchar();
		return;
	}
	while (quebra_linha < 3){
		ch = fgetc(fp);
		if (ch == '\n') quebra_linha++;
	}
	
	while(!feof(fp)){
		fscanf(fp, "%d", &aux);
		vet[aux]++;
		
		ch = fgetc(fp);
		if (ch == EOF){
			printf("EOF\n");
		}
	}
	fputs("HISTOGRAMA\n", fp3);
	for (i = 0; i < 256; i++){
		fprintf(fp3, "Tom %d : %d\n", i, vet[i]);
	}
	fclose(fp3);
}

void negativo(FILE *fp){
	FILE *fp2;
	int quebra_linha = 0, v;
	char ch;
	
	fp2 = fopen("negativo.pgm", "w");
	if (fp2 == NULL){
		printf("Não foi possível abrir o arquivo!");
		getchar();
		return;
	}
	while (quebra_linha < 3){
		ch = fgetc(fp);
		if (ch == '\n') quebra_linha++;
		fputc(ch, fp2);
	}
	
	while(!feof(fp)){
		fscanf(fp, "%d", &v);
		fprintf(fp2, "%d ", 255 - v);
		
		ch = fgetc(fp);
		if (ch == EOF){
			printf("EOF\n");
			return;
		}
	}
	fclose(fp2);
}

void limiar(FILE *fp){
	int limiar, quebra_linha = 0, aux;
	FILE *fp1;
	char ch;
	
	printf("Digite o limiar: ");
	scanf(" %d", &limiar);
	
	fp1 = fopen("limiar.pgm", "w");
	if (fp1 == NULL){
		printf("Não foi possível abrir o arquivo!");
		getchar();
		return;
	}
	while (quebra_linha < 3){
		ch = fgetc(fp);
		if (ch == '\n') quebra_linha++;
		fputc(ch, fp1);
	}
	
	while(!feof(fp)){
		fscanf(fp, "%d", &aux);
		if (aux > limiar){
			fprintf(fp1, "%d ", 255);
		}
		else fprintf(fp1, "%d ", 0);
		
		ch = fgetc(fp);
		if (ch == EOF){
			printf("EOF\n");
			return;
		}
	}
	fclose(fp1);
}

int main(){
	FILE *fp;
	int quebra_linha = 0;
	char ch;
	
	fp = fopen("exemplo.pgm", "r");
	if (fp == NULL){
		printf("Não foi possível abrir o arquivo!");
		getchar();
		return 0;
	}
	limiar(fp);
	rewind(fp);
	fflush(fp);
	negativo(fp);
	rewind(fp);
	fflush(fp);
	histograma(fp);
	fclose(fp);
}
