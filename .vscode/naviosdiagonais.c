#include <stdio.h>

int main() {
    int tabuleiro[10][10];

    // Inicializar o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal (linha 2, colunas 1 a 3)
    for (int j = 1; j < 4; j++) {
        tabuleiro[2][j] = 3;
    }

    // Navio vertical (coluna 5, linhas 4 a 6)
    for (int i = 4; i < 7; i++) {
        tabuleiro[i][5] = 3;
    }

    // Navio diagonal principal (0,0) até (2,2)
    for (int k = 0; k < 3; k++) {
        tabuleiro[k][k] = 3;
    }

    // Navio diagonal secundária (0,9) até (2,7)
    for (int k = 0; k < 3; k++) {
        tabuleiro[k][9 - k] = 3;
    }

    // Exibir tabuleiro
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}