#include "Header.h"
void randomGen(int f, int** mass) {
    for (int i = 0; i < f; i++) {
        mass[i] = (int*)malloc(sizeof(int) * f);
    }
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < f; j++) {
            int c = (rand() % 10 - 2);
            mass[i][j] = c;
            if (i == j) {
                mass[i][j] = 0;
            }

        }
    }
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < f; j++) {
            printf("|%d|\t ", mass[i][j]);
        }
        printf("\n");
    }
}