#include "Header.h"
void rs(int s, int s1,int** mass2,int f, int**mass3) {
	if (s > f) {
		printf("Invalid number");
	}
	else {
		for (int i = 0; i < f + 1; i++) {
			for (int j = 0; j < f + 1; j++) {
				mass2[i][j] = 0;
			}
		}
		for (int i = 0; i < f; i++) {
			for (int j = 0; j < f; j++) {
				mass2[i][j] = mass3[i][j];
			}
		}
		printf("\n");
		for (int i = 0; i < f + 1; i++) {
			for (int j = 0; j < f + 1; j++) {
				if (j < f / 2 && mass2[s][j] == 1) {
					mass2[f][j] = 1;
					mass2[s][j] = 0;
				}
				if (i < f / 2 && mass2[i][s] == 1) {
					mass2[i][f] = 1;
					mass2[i][s] = 0;
				}
				printf("%d ", mass2[i][j]);
			}
			printf("\n");
		}
	}
}