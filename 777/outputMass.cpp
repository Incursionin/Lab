#include "Header.h"
void output(int** mass, int f) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < f; j++) {
            printf("|%d|\t ", mass[i][j]);
        }
        printf("\n");
    }
}