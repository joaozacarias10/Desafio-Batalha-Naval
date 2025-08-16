batalha-naval/
├── batalha_naval.c
└── README.md
#include <stdio.h>
#include <stdlib.h>

// =====================================================
// NÍVEL NOVATO
// =====================================================
void nivelNovato() {
    int navioVertical[3][2] = { {0,0}, {1,0}, {2,0} };  // (x,y)
    int navioHorizontal[3][2] = { {4,1}, {4,2}, {4,3} };

    printf("=== Nivel Novato ===\n");
    printf("Navio Vertical:\n");
    for (int i = 0; i < 3; i++) {
        printf("(%d,%d)\n", navioVertical[i][0], navioVertical[i][1]);
    }

    printf("\nNavio Horizontal:\n");
    for (int i = 0; i < 3; i++) {
        printf("(%d,%d)\n", navioHorizontal[i][0], navioHorizontal[i][1]);
    }
    printf("\n");
}

// =====================================================
// NÍVEL AVENTUREIRO
// =====================================================
void nivelAventureiro() {
    int tabuleiro[10][10] = {0};

    // Dois navios horizontais/verticais
    for (int i = 0; i < 4; i++) tabuleiro[2][i] = 3; // horizontal
    for (int i = 0; i < 4; i++) tabuleiro[i][5] = 3; // vertical

    // Dois navios diagonais
    for (int i = 0; i < 3; i++) tabuleiro[i][i] = 3; // diagonal principal
    for (int i = 0; i < 3; i++) tabuleiro[i][9-i] = 3; // diagonal secundária

    printf("=== Nivel Aventureiro ===\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// =====================================================
// NÍVEL MESTRE
// =====================================================
void habilidadeCone(int n) {
    int matriz[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = 0;

    int meio = n/2;
    for (int i = 0; i <= meio; i++) {
        for (int j = meio - i; j <= meio + i; j++) {
            matriz[i][j] = 1;
        }
    }

    printf("Habilidade: Cone\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("\n");
}

void habilidadeCruz(int n) {
    int matriz[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = 0;

    int meio = n/2;
    for (int i = 0; i < n; i++) matriz[meio][i] = 1;
    for (int i = 0; i < n; i++) matriz[i][meio] = 1;

    printf("Habilidade: Cruz\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("\n");
}

void habilidadeOctaedro(int n) {
    int matriz[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = 0;

    int meio = n/2;
    for (int i = 0; i < n; i++) {
        int distancia = abs(meio - i);
        for (int j = distancia; j < n - distancia; j++) {
            matriz[i][j] = 1;
        }
    }

    printf("Habilidade: Octaedro\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", matriz[i][j]);
        printf("\n");
    }
    printf("\n");
}

// =====================================================
// MAIN
// =====================================================
int main() {
    nivelNovato();
    nivelAventureiro();

    printf("=== Nivel Mestre ===\n");
    habilidadeCone(5);
    habilidadeCruz(5);
    habilidadeOctaedro(5);

    return 0;
}
