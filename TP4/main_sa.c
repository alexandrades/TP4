#include "sa.h"

void main(){

  char p[6] = "teste";

  int tam_p = strlen(p);
  //CRIA TABELA DE MASCARAS PARA TODOS OS CARECTERES DA TABELA ASCII
  int** ascii =(int**) tab_mascara(p, tam_p);

  //CRIA VETORES PARA R E R'
  int *r = (int*) calloc(tam_p, sizeof(int));
  int *rl = (int*) calloc(tam_p, sizeof(int));

  sa_or(r, rl, tam_p, ascii);

}