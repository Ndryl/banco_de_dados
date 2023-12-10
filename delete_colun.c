#include "updateTableList.h"

void remove_coluna(char *nome) {
    FILE *file = fopen(nome, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome);
        return;
    }

    printf("Insira o número da coluna que você deseja excluir: ");
    int column_number;
    if (scanf("%d", &column_number) != 1 || column_number <= 0) {
        printf("Entrada inválida para o número da coluna.\n");
        fclose(file);
        return;
    }

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        printf("Erro ao criar o arquivo temporário\n");
        fclose(file);
        return;
    }

    char linha[1000];
    while (fgets(linha, sizeof(linha), file) != NULL) {
        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') {
            linha[len - 1] = '\0'; // Remove o caractere de nova linha, se houver
        }

        char *token = strtok(linha, "|");
        int coluna_atual = 1;
        int primeiro_token = 1;

        while (token != NULL) {
            if (coluna_atual != column_number) {
                if (!primeiro_token) {
                    fprintf(temp_file, "|");
                }
                fprintf(temp_file, "%s", token);
                primeiro_token = 0;
            }
            token = strtok(NULL, "|");
            coluna_atual++;
        }
        fprintf(temp_file, "\n");
    }

    fclose(file);
    fclose(temp_file);

    // Remove o arquivo original e renomeia o temporário para o nome original
    if (remove(nome) != 0) {
        printf("Erro ao remover o arquivo original\n");
        return;
    }
    if (rename("temp.txt", nome) != 0) {
        printf("Erro ao renomear o arquivo temporário\n");
        return;
    }
}
