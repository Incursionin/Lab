#include "Header.h"
void kolez(int ** massKO1, int** massKO2, int f, int u) {
	int i, j;
	for (i = 0; i < f; i++) {
		for (j = 0; j < f; j++) {

			printf("%d ", massKO1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < u; i++) {
		for (j = 0; j < u; j++) {

			printf("%d ", massKO2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	if (f > u) {
		for (i = 0; i < u; i++) {
			for (j = 0; j < u; j++) {
				if (massKO1[i][j] != 1 && massKO2[i][j] == 1 || massKO2[i][j] != 1 && massKO1[i][j] == 1) {
					massKO1[i][j] = 1;
				}
				else massKO1[i][j] = 0;
			}
		}

		for (i = 0; i < f; i++) {
			for (j = 0; j < f; j++) {
				printf("%d ", massKO1[i][j]);
			}
			printf("\n");
		}
	}
	if (u > f) {
		for (i = 0; i < f; i++) {
			for (j = 0; j < f; j++) {
				if (massKO1[i][j] != 1 && massKO2[i][j] == 1 || massKO2[i][j] != 1 && massKO1[i][j] == 1) {
					massKO2[i][j] = 1;
				}
				else massKO2[i][j] = 0;
			}
		}

		for (i = 0; i < u; i++) {
			for (j = 0; j < u; j++) {
				printf("%d ", massKO2[i][j]);
			}
			printf("\n");
		}
	}
}