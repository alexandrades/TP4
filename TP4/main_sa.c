#include "sa.h"

void main() {

	FILE *arq = fopen("entrada.txt", "r");

	char* texto = (char*) malloc(1000*sizeof(char));

	le_arquivo (arq, texto);

	char *p = (char*) malloc(sizeof(char) * 100);
  	printf("Insira o padrao a ser procurado no texto(tamanho max = 100):\n");
  	scanf("%s", p);

	int r = shiftand(p, texto); //chama a funcao shiftand passando o padrao e o texto e retorna r

	free(p);
	free(texto);

	if (r == -1){ // se o valor retornado for -1 nao possui o padrao no texto
  		printf("Nao possui no padrao\n");
	}

}