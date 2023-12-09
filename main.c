#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct coluna_nome {
  char nome_coluna[50];
  void *vetor_coluna;
};
typedef struct coluna_nome coluna_nome;

struct linha_id {
  int id;
  coluna_nome *vetor_coluna; // Agora é um vetor de coluna_nome
};
typedef struct linha_id linha_id;

int main(void) {
  int coluna;
  int linha;
  char referencia[50];
  linha_id *vetor_primario;

  printf("Digite o número de linhas da tabela: ");
  scanf("%d", &linha);

  vetor_primario = malloc(linha * sizeof(linha_id));
  for (int i = 0; i < linha; i++) {
    vetor_primario[i].id = i;
    // Aloca um vetor de coluna_nome para cada linha
    vetor_primario[i].vetor_coluna = malloc(sizeof(coluna_nome) * coluna);
  }

  printf("Digite o número de colunas da tabela: ");
  scanf("%d", &coluna);

  for (int i = 0; i < coluna; i++) {
    printf("Digite o nome da coluna %d: ", i + 1);
    scanf("%s", referencia);
    for (int j = 0; j < linha; j++) {
      strcpy(vetor_primario[j].vetor_coluna[i].nome_coluna, referencia);
    }
  }

  for (int i = 0; i < coluna; i++) {
    printf("Digite o tipo de dados da coluna %d (1 = inteiro, 2 = float, 3 = char, 4 = string): ", i + 1);
    int escolha;
    scanf("%d", &escolha);
    for (int j = 0; j < linha; j++) {
      switch(escolha) {
        case 1:
          vetor_primario[j].vetor_coluna[i].vetor_coluna = malloc(sizeof(int) * coluna);
          break;
        case 2:
          vetor_primario[j].vetor_coluna[i].vetor_coluna = malloc(sizeof(float) * coluna);
          break;
        case 3:
          vetor_primario[j].vetor_coluna[i].vetor_coluna = malloc(sizeof(char) * coluna);
          break;
        case 4:
          vetor_primario[j].vetor_coluna[i].vetor_coluna = malloc(sizeof(char) * 50 * coluna);
          break;
        default:
          printf("Escolha inválida!\n");
          break;
      }
    }
  }

  // Aqui você pode prosseguir com o restante do seu código
  // ...

  return 0;
}
