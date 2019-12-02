#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
      for (i = 0; i < TABSIZE; ++i)
            tabela[i] = 0; // preenche tabela com 0
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
                  printf("%d\n",(i-M+1) );//sucesso, imprime a posicao inicial d padrao encontrado no texto
                  r = 1; //altera o valor de r pois retornado -1 indica que o padrao nao foi encontrado no texto
                }
      }
      return r; // fracasso
}

void main() {
  FILE *arq = fopen("entrada.txt", "r");
  char* texto = (char*) malloc(1000*sizeof(char));
  le_arquivo (arq, texto);
  char padrao[] = "teste";
  int r = shiftand(padrao, texto); //chama a funcao shiftand passando o padrao e o texto e retorna r
  if (r == -1) // se o valor retornado for -1 nao possui o padrao no texto
    printf("Nao possui no padrao\n");
}
