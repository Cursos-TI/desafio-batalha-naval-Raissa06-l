#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
   char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10] = {0};

    // Preencher o tabuleiro com base nas condições
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            //  CONE no canto superior esquerdo (valor 2)
            if (i >= 0 && i <= 2) { // linhas 0 a 2
                if (j >= 2 - i && j <= 2 + i) {
                    tabuleiro[i][j] = 2;
                }
            }

            //  CRUZ no centro (valor 1)
            if ((i >= 2 && i <= 6 && j == 4) || (j >= 2 && j <= 6 && i == 4)) {
                tabuleiro[i][j] = 1;
            }

            //  OCTAEDRO no canto inferior direito (valor 3)
            // centrado em [7][7], com tamanho de losango 2
            if ((i >= 5 && i <= 9) && (j >= 5 && j <= 9)) {
                if ((i + j >= 12 && i + j <= 16) &&
                    (i - j <= 2 && j - i <= 2)) {
                    tabuleiro[i][j] = 3;
                }
            }
        }
    }

    // Imprimindo o cabeçalho
    printf("TABULEIRO\n  ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", linha[i]);
    }
    printf("\n");

    // Imprimindo o tabuleiro
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
