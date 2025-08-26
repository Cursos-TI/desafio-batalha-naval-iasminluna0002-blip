#include <stdio.h>

#define TAMANHO 10   // Tamanho fixo do tabuleiro 10x10
#define TAM_NAVIO 3  // Tamanho dos navios
#define NAVIO 3      // Valor que representa o navio no tabuleiro

int main() {
    int tabuleiro[TAMANHO][TAMANHO]; // Matriz para o tabuleiro
    int i, j;

    // Inicializa todo o tabuleiro com 0 (água)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais dos navios
    int linhaH = 2, colunaH = 4; // Navio horizontal
    int linhaV = 5, colunaV = 6; // Navio vertical

    // Posiciona navio horizontal (3 casas)
    for (j = 0; j < TAM_NAVIO; j++) {
        tabuleiro[linhaH][colunaH + j] = NAVIO;
    }

    // Posiciona navio vertical (3 casas)
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // Exibe o tabuleiro
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n");
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
