#include "Header.h"
void generate(int** mass, int f) {
	int i, r, c;
	for (i = 0; i < f; i++) {
		for (int j = 0; j < f; j++) {
			r = rand() % 2;
			c = rand() % 2;
			if (r == 1) {
				mass[i][j] = 1;
			}
			else
				mass[i][j] = 0;
			if (i == j) {
				mass[i][j] = 0;
			}

		}
	}
	for (i = 0; i < f; i++) {
		for (int j = 0; j < f; j++) {
			if (mass[i][j] != mass[j][i]) {
				mass[i][j] = mass[j][i];
			}
		}
	}

}