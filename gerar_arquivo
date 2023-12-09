#include "tableToFile.h"

void tableToFile(char* nome, int qtd_colunas, char (*nome_colunas)[qtd_colunas], char (*
tipo_colunas)[qtd_colunas]){
  strcat(nome, ".txt");
  FILE *arquivo;
  arquivo = fopen(nome, "w");
  if(arquivo == NULL){
    printf("Erro ao gerar o arquivo.\n");
    return;
  }
  for(int i = 0; i < qtd_colunas; i++){
    fprintf(arquivo, "%s ", tipo_colunas[i]);
  }
  fprintf("\n");
  for(int i = 0; i < qtd_coluna; i++){
    fprintf(arquivo, "%s ", nome_colunas[i]);
  }
  fprintf("\n");

  fclose(arquivo);

}
