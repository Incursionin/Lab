#include "Header.h"
void obe(int** massPE1, int** massPE2, int f, int u) {
	int i, j;
	for (i = 0; i < f; i++) {
		for (j = 0; j < f; j++) {

			printf("%d ", massPE1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < u; i++) {
		for (j = 0; j < u; j++) {

			printf("%d ", massPE2[i][j]);
		}
		printf("\n");
	}
	if (f > u) {
		for (i = 0; i < u; i++) {
			for (j = 0; j < u; j++) {
				if (massPE1[i][j] != 1 && massPE2[i][j] == 1) {
					massPE1[i][j] = 1;
				}
			}
			printf("\n");
		}

		for (int i = 0; i < f; i++) {
			for (int j = 0; j < f; j++) {
				printf("%d ", massPE1[i][j]);
			}
			printf("\n");
		}
	}
	if (u > f) {
		for (i = 0; i < f; i++) {
			for (j = 0; j < f; j++) {
				if (massPE1[i][j] == 1 && massPE2[i][j] != 1) {
					massPE2[i][j] = 1;
				}
			}
			printf("\n");
		}

		for (int i = 0; i < u; i++) {
			for (int j = 0; j < u; j++) {
				printf("%d ", massPE2[i][j]);
			}
			printf("\n");
		}
	}
}