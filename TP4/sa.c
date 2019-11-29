#include "sa.h"

int** tab_mascara(char* p, int tam){
  int **ascii = (int**) calloc(127, sizeof(int*));

  for(int i = 0; i < tam; i++){

    if(ascii[p[i]] == 0){

      ascii[p[i]] = (int*) calloc(tam, sizeof(int));
    }
    ascii[p[i]][i] = 1;
  }
  return ascii;
}

void shift_or(int *r, int *rl, int tam){
  //SHIFTA O VETOR R' PRA DIREITA
    for(int i = tam-1; i > 0; i--){
      r[i] = rl[i-1];
    }
    //ADICIONA 1 NA PRIMEIRA POSIÇÃO DO VETOR R
    r[0] = 1;
}

void sa_or(int* r, int* rl, int tam, int** ascii){
  char c;

  FILE *arq = fopen("entrada.txt", "r");
  if(arq == NULL){
    printf("Falha ao ler arquivo.\n");
    exit(1);
  }

  for(int i = 0; (c = fgetc(arq)) != EOF; i++){

    int *aux = (int*) malloc(tam * sizeof(int));

    shift_or(r, rl, tam);

    //FAZ O AND DO VETOR R COM A MASCARA DO PROXIMO CARACTER
    for(int j = 0; j < tam; j++){

      //PREENCHE COM 0 TODAS AS POSICOES DA MASCARA DE CARACTERES ENCONTRADOS NO TEXTO MAS QUE NAO FAZEM PARTE DO PADRAO
      for(int k = 0; k < tam; k++){

        if(ascii[c] == NULL){
          aux[k] = 0;
        }
        else{
          aux[k] = ascii[c][j];
        }
      }
      //FAZ O AND DE R COM A MASCARA DO PROXIMO CARACTERE
      if(r[j] && aux[j]){
        rl[j] = 1;
      }
      else{
        rl[j] = 0;
      }
    }
    //CASO A ULTIMA POSIÇÃO DE R' SEJA 1, ENTÃO OCORRE O CASAMENTO
    if(rl[tam-1] == 1){
      printf("Casamento na posição %d\n", i-(tam-1));
    }

    free(aux);

  }

  fclose(arq);
}

void bmh(int m, int n, char* txt, char* p){

  int i, k, j;
  int *pulo = (int*) malloc(sizeof(int)*127);
  
  for(int j = 0; j < 127; j++){

    pulo[j] = m;
  }
  for(int j = 0; j <= m-2; j++){
    
    pulo[p[j]] = m - j - 1;
  }

  i = m-1;
  while(i <= n){
    
    k = i;
    j = m-1;
    while((txt[k] == p[j]) && j > -1){
      k--;
      j--;
    }

    if(j < 0){
      printf("Casamento na posiçao %d\n", k+1);
    }

    i += pulo[txt[i]];
  }
}