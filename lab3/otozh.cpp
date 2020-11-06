#include "Header.h"
void otoz(int s, int s1, int** mass, int f) {
	int i, j;
	if (s > f || s1 > f) {
		printf("Invalid number\n");
	}
	else {
		for (i = 0; i < f; i++) {
			for (j = 0; j < f; j++) {
				if (mass[s][j] > mass[s1][j])
					mass[s1][j] = 1;
				if (mass[i][s1] > mass[s1][j])
					mass[i][s1] = 1;
			}
		}
		int l = 0, g = 0;
		for (i = 0; i < f; i++) {
			for (j = 0; j < f; j++) {
				if (mass[s][j] == 1)
					g = 1;
				if (mass[i][s] == 1)
					l = 1;
				mass[s][j] = 0;
				if (g == 1)
					mass[s1][j] = g;
				mass[i][s] = 0;
				if (l == 1)
					mass[i][s1] = l;
				g = 0;
				l = 0;
				mass[s1][s1] = 1;
			}
		}
		for (int i = 0; i < f; i++) {
			for (j = 0; j < f; j++) {
				if (i == s || j == s) {
					continue;
				}
				printf("%d ", mass[i][j]);
				if (j == f - 1)
					printf("\n");
			}
		}
	}
}