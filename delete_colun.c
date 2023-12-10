#include "updateTableList.h"


void remove_coluna(char* nome) {
  printf("Insira a coluna que você quer excluir: ");
  int column_number;
  scanf(" %d", &column_number);
  FILE *arquivo;
  char nome_arquivo[] = "../tables/tableList.txt";
  arquivo = fopen(nome_arquivo, "r");
  char nome_arquivoTemp[] = "../tables/arquivoTemp.txt";
   FILE *arquivoTemp = fopen(nome_arquivoTemp, "w");

  if(arquivo == NULL){
      printf("Erro ao abrir o arquivo tableList.txt\n");
      return;
  }
  if (arquivoTemp == NULL) {
      perror("Erro ao criar o arquivo temporário\n");
      fclose(arquivo);
      return;
  }

  char linha[1000];

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    char *linha_copia = strdup(linha); // Faz uma cópia da linha para manipulação

    // Tokeniza a linha usando '|' como delimitador
    char *token = strtok(linha_copia, "|");
    int coluna_atual = 1;
    while (token != NULL) {
      if (coluna_atual != column_number) {
      // Escreve no arquivo temporário apenas se não for a coluna especificada
        fprintf(arquivoTemp, "%s|", token);
      }
      token = strtok(NULL, "|");
      coluna_atual++;
    }
    fprintf(arquivoTemp, "\n");

    free(linha_copia); // Libera a memória alocada para a cópia da linha
    }

  fclose(arquivo);
  fclose(arquivoTemp);

  remove(nome_arquivo);

  if (rename(nome_arquivoTemp, nome_arquivo) != 0) {
    perror("Erro ao renomear o arquivo temporário");
  }
}
