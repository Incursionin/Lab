void cpy(int** mass1, int** mass2, int f) {
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < f; j++) {
			mass1[i][j] = mass2[i][j];
		}
	}
}