#include "sa.h"


/*
le arquivo de entrada e salva o conteudo em texto
*/

void le_arquivo(FILE* arq, char* texto){

  int n = 0;

  while((texto[n] = fgetc(arq)) != EOF){
      n++;
  }

  fclose(arq);
}
/*
funcao cria a tabela com valores baseados no padrao e procura o padrao no texto
caso o padrao seja encontrado faz se o calculo e printa a posicao inicial da palavra no texto
*/
int shiftand (const char *p, const char *t) {

  int r = -1;

  const int TABSIZE = 256; //tamanho maximo da tabela de acordo com a tabela ascii
  const unsigned long ONELEFT = 0x80000000; //valor usado para construir os valores da mascara
  int i = 0, j = 0, M = strlen(p), N = strlen(t);
  unsigned long tabela[TABSIZE];

  for (i = 0; i < TABSIZE; ++i){
    tabela[i] = 0; // preenche tabela com 0
  }

  unsigned long mascara = ONELEFT;

  for (j = 0; j < M; ++j) {
    tabela[p[j]] |= mascara; // posições onde ocorrem caracteres do padrao recebem mascara
    mascara >>= 1; // mascara recebe shift de 1
  }

  unsigned long R = 0; //r recebe 0, r auxilia na localizacao de ocorrencia de padrao no texto 
  mascara = ONELEFT >> (M - 1);

  for (i = 0 ; i < N; ++i) {
    R = ((R >> 1) | 0x80000000) & tabela[t[i]];
    if (R & mascara){
      printf("Casamento na posicao: %d\n",(i-M+1) );//sucesso, imprime a posicao inicial d padrao encontrado no texto
      r = 1; //altera o valor de r pois retornado -1 indica que o padrao nao foi encontrado no texto
    }
  }
  return r; // fracasso
}

void bmh(int m, int n, char* txt, char* p){

  int i, k, j; 
  int *pulo = (int*) malloc(sizeof(int)*256); //ALOCA UM VETOR PARA GUARDAR OS VALORES DOS PULOS PARA CADA CARACTER DA TABELA ASCII
  //PREENCHE TODAS AS POSIÇOES DO VETOR COM O TAMANHO DO PADRAO A SER PROCURADO
  for(int j = 0; j < 256; j++){

    pulo[j] = m;
  }
  //PREENCHE TODAS AS POSIÇOES DO VETOR QUE POSSUEM OCORRENCIA NO PADRAO, ATUALIZANDO O VALOR DO PULO
  for(int j = 0; j <= m-2; j++){
    
    pulo[p[j]] = m - j - 1;
  }

  i = m-1;

  //WHILE É EXECUTADO ENQUANTO O FIM DO ARQUIVO NÃO FOR ALCANÇADO
  while(i <= n){
    
    k = i;
    j = m-1;
    //K E J É DECREMENTADO ENQUANTO OS CARACTERES DO PADRÃO SE CASA COM O DO TEXTO E J > -1(ENQUANTO J > -1, EXISTE CARACTER DO PADRÃO PARA SER COMPARADO)
    while((txt[k] == p[j]) && j > -1){
      k--;
      j--;
    }
    //SE J = -1, EXISTE CASAMENTO NA POSIÇÃO K+1
    if(j < 0){
      printf("Casamento na posicao: %d\n", k+1);
    }
    //REALIZA O PULO DO PADRÃO EM RELAÇÃO AO TEXTO
    i += pulo[txt[i]];
  }
  free(pulo);
}

void bmhs(int m, int n, char* txt, char* p){

  int i, k, j; 
  int *pulo = (int*) malloc(sizeof(int)*256); //ALOCA UM VETOR PARA GUARDAR OS VALORES DOS PULOS PARA CADA CARACTER DA TABELA ASCII
  //PREENCHE TODAS AS POSIÇOES DO VETOR COM O TAMANHO DO PADRAO A SER PROCURADO
  for(int j = 0; j < 256; j++){

    pulo[j] = m;
  }
  //PREENCHE TODAS AS POSIÇOES DO VETOR QUE POSSUEM OCORRENCIA NO PADRAO, ATUALIZANDO O VALOR DO PULO
  for(int j = 0; j <= m-1; j++){
    
    pulo[p[j]] = m - j;
  }

  i = m-1;

  //WHILE É EXECUTADO ENQUANTO O FIM DO ARQUIVO NÃO FOR ALCANÇADO
  while(i <= n){
    
    k = i;
    j = m-1;
    //K E J É DECREMENTADO ENQUANTO OS CARACTERES DO PADRÃO SE CASA COM O DO TEXTO E J > -1(ENQUANTO J > -1, EXISTE CARACTER DO PADRÃO PARA SER COMPARADO)
    while((txt[k] == p[j]) && j > -1){
      k--;
      j--;
    }
    //SE J = -1, EXISTE CASAMENTO NA POSIÇÃO K+1
    if(j < 0){
      printf("Casamento na posicao: %d\n", k+1);
    }
    //REALIZA O PULO DO PADRÃO EM RELAÇÃO AO TEXTO
    i += pulo[txt[i+1]];
  }
  free(pulo);
}