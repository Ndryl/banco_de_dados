#include "updateTableList.h"



void add_table(char* nome){
    FILE *arquivo;
    arquivo = fopen("../tables/tableList.txt", "a");
    if(arquivo == NULL){
        printf("Erro ao abrir/criar o arquivo tableList.txt\n");
        return;
    }

    fprintf(arquivo, "%s\n", nome);

    fclose(arquivo);

}
// TODO: FUNÇÃO AINDA PRECISA SER IMPLEMENTADA
void remove_table(char *nome) {
    FILE *arquivo, *arquivo_temp;
    arquivo = fopen("../tables/tableList.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo tableList.txt\n");
        return;
    }

    arquivo_temp = fopen("../tables/tableList_temp.txt", "w");
    if (arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo temporário\n");
        fclose(arquivo);
        return;
    }

    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        if (strcmp(linha, nome) != 0) {
            fprintf(arquivo_temp, "%s\n", linha);
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    remove("../tables/tableList.txt");
    rename("../tables/tableList_temp.txt", "../tables/tableList.txt");
}
