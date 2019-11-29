#include "sa.h"

void main(){

  char p[6] = "teste";
  char *txt = (char*) malloc(sizeof(char)*5000);
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

  bmh(tam_p, strlen(txt), txt, p);
  printf("%s\n", txt);
}