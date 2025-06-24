#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX_LINHAS 100
#define MAX_COLUNAS 20

FILE* abrirArquivo(char nomeArquivo[]);
void lerDadosEContarLinhas(int dados[MAX_LINHAS][MAX_COLUNAS], int* numeroDeLinhas);
void resolverOperacoes(int resultados[MAX_LINHAS][MAX_COLUNAS], int *numeroDeLinhas);

int main(void) {

    int dados[MAX_LINHAS][MAX_COLUNAS];     // Matriz de dados
    int resultados[MAX_LINHAS][MAX_COLUNAS];

    int numeroDeLinhas;                     // Variável de controle de número de linhas

    lerDadosEContarLinhas(dados, &numeroDeLinhas);
    resolverOperacoes(resultados, &numeroDeLinhas);

    printf("Dados lidos com sucesso!\n");
    return 0;
}

void lerDadosEContarLinhas(int dados[MAX_LINHAS][MAX_COLUNAS], int *numeroDeLinhas) {

    FILE *arq = abrirArquivo("DADOS.txt");
    if (arq == NULL) return;

    // Recebe o número de linhas da matriz
    int numeroDeColunas;
    fscanf(arq, "%d", &numeroDeColunas);

    // Lê o caractere '\n' após o número de linhas
    getc(arq);

    int linha = 0;
    while (!feof(arq)) {
        for (int coluna = 0; coluna < numeroDeColunas; coluna++) {
            fscanf(arq, "%d", &dados[linha][coluna]);
            getc(arq);
        }
        linha++;
    }

    // Registra o número real de linhas lidos
    *numeroDeLinhas = linha - 1;
    fclose(arq);
}

void resolverOperacoes(int resultados[MAX_LINHAS][MAX_COLUNAS], int *numeroDeLinhas) {

    FILE *arq = abrirArquivo("EXP.txt");
    if (arq == NULL) return;
}

void operar(char operacao, int num1, int num2) {
    switch (operacao) {
        case '+':
            somar(num1, num2);
            break;
        case '-':
            subtrair(num1, num2);

        break;
        case '.':
            multiplicar(num1, num2);
        break;
        case '+':
            operarAnd(num1, num2);
        break;
        case '+':
            dividir(num1, num2);
        break;
    }
}

FILE* abrirArquivo(char nomeArquivo[]) {

    FILE* arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return NULL;
    }
    return arquivo;
}