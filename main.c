#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do enum para os tipos de variáveis
enum TipoVariavel {
    INTEIRO,
    CARACTER,
    REAL,
    STRING,
};

struct id_pessoa {
    int id;
    char tabela[50]; 
    enum TipoVariavel tipo; // Utilizando o enum para definir o tipo de variável
    void *pessoa;
};
typedef struct id_pessoa id_pessoa;

// ... (outras funções, se houver)

int main() {
    int coluna;
    char referencia[50];
    id_pessoa *vetor_principal;

    printf("Digite quantas colunas a tabela vai ter: ");
    scanf("%d", &coluna);
    vetor_principal = (id_pessoa *)malloc(coluna * sizeof(id_pessoa));
    vetor_principal[0].id = 0;

    for(int i = 0; i < coluna; i++) {
        printf("Digite o nome da coluna %d: ", i+1);
        scanf("%s", referencia);
        strcpy(vetor_principal[i].tabela, referencia);

        printf("Digite o tipo da coluna %d (inteiro = 0, caracter = 1, real = 2, string = 3): ", i+1);
        int tipo;
        scanf("%d", &tipo);

        // Definindo o tipo com base no enum de TipoVariavel
        switch (tipo) {
            case 0:
                vetor_principal[i].tipo = INTEIRO;
                vetor_principal[i].pessoa = malloc(sizeof(int));
                break;
            case 1:
                vetor_principal[i].tipo = CARACTER;
                vetor_principal[i].pessoa = malloc(sizeof(char));
                break;
            case 2:
                vetor_principal[i].tipo = REAL;
                vetor_principal[i].pessoa = malloc(sizeof(float));
                break;
          case 3:
                vetor_principal[i].tipo = STRING;
                vetor_principal[i].pessoa = malloc(sizeof(char)*50);
                break;
            default:
                printf("Tipo inválido!\n");
                // Você pode tratar isso como desejar, como pedir o tipo novamente ou sair do programa.
                break;
        }
    }

    // Resto do seu código aqui

    return 0;
}
