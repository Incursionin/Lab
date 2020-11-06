#include "Header.h"
void pere(int **massOB1, int **massOB2, int f, int u) {
	int i, j;
	for ( i = 0; i < f; i++) {
		for (j = 0; j < f; j++) {

			printf("%d ", massOB1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < u; i++) {
		for (j = 0; j < u; j++) {

			printf("%d ", massOB2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	if (f > u) {
		for (i = 0; i < u; i++) {
			for (j = 0; j < u; j++) {
				if (massOB2[i][j] == 1 && massOB1[i][j] == 1 )
					massOB1[i][j] = 1;
				else massOB1[i][j] = 0;
			}
		}
		for (i = 0; i < u; i++) {
			for (j = 0; j < u; j++) {
				printf("%d ", massOB1[i][j]);
			}
			printf("\n");
		}
	}
	if (u > f) {
		for (i = 0; i < f; i++) {
			for (j = 0; j < f; j++) {
				if (massOB2[i][j] == 1 && massOB1[i][j] == 1)
					massOB2[i][j] = 1;
				else massOB2[i][j] = 0;
				if (f > u) {
					massOB2[i][j] = 0;
				}
			}
		}
		for (i = 0; i < f; i++) {
			for (j = 0; j < f; j++) {
				printf("%d ", massOB2[i][j]);
			}
			printf("\n");
		}
	}
	printf("\n");
}