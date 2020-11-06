#include "Header.h"
void styag(int s, int s1, int** mass1, int f) {
	int g = 0, l = 0;
	if (s > f || s1 > f) {
		printf("Invalid number\n");
	}
	else {
		for (int i = 0; i < f; i++) {
			for (int j = 0; j < f; j++) {
				if (mass1[s][j] == 1)
					g = 1;
				if (mass1[i][s] == 1)
					l = 1;
				mass1[s][j] = 0;
				if (g == 1)
					mass1[s1][j] = g;
				mass1[i][s] = 0;
				if (l == 1)
					mass1[i][s1] = l;
				g = 0;
				l = 0;
				mass1[s1][s1] = 0;
			}
		}
		for (int i = 0; i < f; i++) {
			for (int j = 0; j < f; j++) {
				if (i == s || j == s) {
					continue;
				}
				printf("%d ", mass1[i][j]);
				if (j == f - 1)
					printf("\n");
			}
		}
	}
}