#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char **vetor;
    char input[100];
    int num_referencia = 0;
    int num_coluna = 5;
    int etiqueta = 0;

    vetor = (char **)malloc(num_coluna * sizeof(char *));

    if (vetor == NULL) {
        printf("Algo deu errado\n");
        return 1;
    }

    printf("Digite os atributos da tabela a serem adicionados ou 'fim' para encerrar a atribuição:\n");
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove o caractere de nova linha, se houver

        if (strcmp(input, "fim") == 0) {
            vetor[num_referencia] = (char *)malloc((sizeof(char) * 10)); // Alocando espaço suficiente para armazenar o número
            sprintf(vetor[num_referencia], "%d", etiqueta);
            num_referencia++;
            etiqueta++;
            break; // Sai do loop se o usuário digitar 'fim'
        }

        vetor[num_referencia] = (char *)malloc((strlen(input) + 1) * sizeof(char));

        if (vetor[num_referencia] == NULL) {
            printf("Erro ao alocar memória.\n");
            return 1;
        }

        strcpy(vetor[num_referencia], input);
        num_referencia++;

        if (num_referencia >= num_coluna) {
            num_coluna += 5;
            vetor = (char **)realloc(vetor, num_coluna * sizeof(char *));

            if (vetor == NULL) {
                printf("Erro ao alocar memória.\n");
                return 1;
            }
        }
    }

    // Salvando a lista no arquivo
    FILE *arquivo;
    arquivo = fopen("lista_atributos.txt", "w"); // Abre o arquivo para escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escrevendo a lista no arquivo
    for (int i = 0; i < num_referencia; i++) {
        fprintf(arquivo, "Atributo %d: %s\n", i + 1, vetor[i]);
    }

    fclose(arquivo); // Fecha o arquivo

    printf("Lista de atributos salva com sucesso no arquivo 'lista_atributos.txt'.\n");

    // Liberando memória alocada
    for (int i = 0; i < num_referencia; i++) {
        free(vetor[i]);
    }
    free(vetor);

    return 0;
}
