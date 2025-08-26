#include <stdio.h>
#include <stdlib.h> // para usar abs()

int main() {
    int tabuleiro[10][10];

    // 1. Inicializar tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Colocar navios (3)
    for (int j = 2; j < 5; j++) { // navio horizontal
        tabuleiro[2][j] = 3;
    }
    for (int i = 5; i < 8; i++) { // navio vertical
        tabuleiro[i][6] = 3;
    }

    // 3. Criar e aplicar habilidades (5x5)

    // Cone (origem no [1][1])
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i && i < 3) { // formato de cone
                int x = 1 + i;
                int y = 1 + j;
                if (tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Cruz (origem no [5][5])
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) { // formato de cruz
                int x = 5 + (i - 2);
                int y = 5 + (j - 2);
                if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                    if (tabuleiro[x][y] == 0) {
                        tabuleiro[x][y] = 5;
                    }
                }
            }
        }
    }

    // Octaedro (origem no [7][7])
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) { // formato de losango
                int x = 7 + (i - 2);
                int y = 7 + (j - 2);
                if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                    if (tabuleiro[x][y] == 0) {
                        tabuleiro[x][y] = 5;
                    }
                }
            }
        }
    }

    // 4. Exibir tabuleiro
    printf("=== Tabuleiro com Habilidades ===\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}