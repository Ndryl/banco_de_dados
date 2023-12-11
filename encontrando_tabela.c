#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

int main(void) {
    char nome_arquivo[30];
    printf("Digite o nome do arquivo que deseja abrir: ");
    scanf("%29s", nome_arquivo);

    FILE *file = fopen(nome_arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char valor_procurado[100];
    printf("Qual valor você deseja encontrar na tabela: ");
    scanf("%99s", valor_procurado);

    int column_number = -1; // Armazena o número da coluna que contém o valor procurado
    char ***tabela = NULL; // Armazenamento de tabela com linhas e colunas
    int linhas = 0, colunas = 0;

    char linha[1000];
    while (fgets(linha, sizeof(linha), file) != NULL) {
        colunas = 0;
        tabela = realloc(tabela, (linhas + 1) * sizeof(char **));
        tabela[linhas] = malloc(MAX_COLS * sizeof(char *));

        char *token = strtok(linha, "|");
        while (token != NULL && colunas < MAX_COLS) {
            tabela[linhas][colunas] = malloc((strlen(token) + 1) * sizeof(char));
            strcpy(tabela[linhas][colunas], token);

            if (strcasecmp(token, valor_procurado) == 0) {
                column_number = colunas;
            }

            token = strtok(NULL, "|");
            colunas++;
        }

        linhas++;
    }

    fclose(file);

    if (column_number == -1) {
        printf("O valor não foi encontrado na tabela.\n");

        // Liberar a memória alocada antes de sair
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                free(tabela[i][j]);
            }
            free(tabela[i]);
        }
        free(tabela);

        return 1;
    }

    // Armazenar os valores da coluna em um array e imprimir
    char *valores_coluna[MAX_ROWS]; // Array para armazenar os valores da coluna
    printf("Valores da coluna onde o valor foi encontrado:\n");
    for (int i = 0; i < linhas; i++) {
        valores_coluna[i] = tabela[i][column_number];
        printf("%s\n", valores_coluna[i]);
    }

    // Liberar a memória alocada antes de sair
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            free(tabela[i][j]);
        }
        free(tabela[i]);
    }
    free(tabela);

    return 0;
}
