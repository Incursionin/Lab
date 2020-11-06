#include "Header.h"
void dekart(int** mass1, int** mass2, int f, int u) {
	int c1 = -1;
	int c2 = -1;
	int i, j;
	int  l = u * f;
	int** temp = NULL;
	temp = (int**)malloc(l * sizeof(int*));
	for (i = 0; i < l; i++) {
		temp[i] = (int*)malloc(l * sizeof(int));
	}
	for (i = 0; i < l; i++) {
		for (j = 0; j < l; j++) {
			temp[i][j] = 0;
		}
	}
	printf("Dekartovo :\n");
	
		for (i = 0; i < f; i++) {
			c1++;
			for (int k = 0; k < u; k++) {
				for (j = 0; j < f; j++) {
					for (int m = 0; m < u; m++) {
						c2++;
						if (i == k) {
							temp[c1][c2] = mass1[i][j];
						}
						if (j == m) {
							temp[c1][c2] = mass2[k][m];
						}
						if (c1 == c2) {
							temp[c1][c2] = 0;
						}

					}
				}
			}
		}
	for (i = 0; i < l; i++) {
		for (j = 0; j < l; j++) {
			temp[j][i] = temp[i][j];
		}
	}
	for (i = 0; i < l; i++) {
		for (j = 0; j < l; j++) {
			printf("%d ", temp[i][j]);
		}
		printf("\n");
	}
}