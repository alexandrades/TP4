#include "sa.h"

void main(){

  char *p = (char*) malloc(sizeof(char) * 100);
  printf("Insira o padrao a ser procurado no texto(tamanho max = 100):\n");
  scanf("%s", p);

  char *txt = (char*) malloc(sizeof(char)*5001);
  char c;
  int tam_p = strlen(p);

  FILE *arq = fopen("entrada.txt", "r");
  if(arq == NULL){
  	printf("Erro ao abrir arquivo\n");
 	exit(1);
  }

  for(int i = 0; (c = fgetc(arq)) != EOF; i++){
  	txt[i] = c;
  }

  bmhs(tam_p, strlen(txt), txt, p);
  
}
