#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stack>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int s, s1, f, u;
	printf("Enter lenghts:");
	scanf("%d %d", &f, &u);
	int** mass = (int**)malloc(sizeof(int) * f);
	int** mass1 = (int**)malloc(sizeof(int) * f);
	int** massPE1 = (int**)malloc(sizeof(int) * f);
	int** massOB1 = (int**)malloc(sizeof(int) * f);
	int** massKO1 = (int**)malloc(sizeof(int) * f);
	for (int i = 0; i < f; i++) {
		mass[i] = (int*)malloc(sizeof(int) * f);
		mass1[i] = (int*)malloc(sizeof(int) * f);
		massPE1[i] = (int*)malloc(sizeof(int) * f);
		massOB1[i] = (int*)malloc(sizeof(int) * f);
		massKO1[i] = (int*)malloc(sizeof(int) * f);
	}
	int** massre = (int**)malloc(sizeof(int) * u);
	int** massPE2 = (int**)malloc(sizeof(int) * u);
	int** massOB2 = (int**)malloc(sizeof(int) * u);
	int** massKO2 = (int**)malloc(sizeof(int) * u);
	for (int i = 0; i < u; i++) {
		massre[i] = (int*)malloc(sizeof(int) * u);
		massPE2[i] = (int*)malloc(sizeof(int) * u);
		massOB2[i] = (int*)malloc(sizeof(int) * u);
		massKO2[i] = (int*)malloc(sizeof(int) * u);
	}
	int** mass2 = (int**)malloc(sizeof(int) * f + 1);
	for (int i = 0; i < f + 1; i++) {
		mass2[i] = (int*)malloc(sizeof(int) * f + 1);
	}
	int** mass3 = (int**)malloc(sizeof(int) * f);
	for (int i = 0; i < f; i++) {
		mass3[i] = (int*)malloc(sizeof(int) * f);
	}
	int i = 0;
	int j = 0, k = 0, m = 0;
	printf("Matrix 1:\n");
	generate(mass, f);
	generate(massPE2, u);
	for (i = 0; i < f; i++) {
		for (j = 0; j < f; j++) {
			mass1[i][j] = mass[i][j];
			massOB1[i][j] = mass1[i][j];
			massPE1[i][j] = mass1[i][j];
			massKO1[i][j] = mass1[i][j];
		}
	}

	printf("\n");
	for (i = 0; i < f; i++) {
		for (j = 0; j < f; j++) {
			printf("%d ", mass[i][j]);
		}
		printf("\n");
	}
	printf("Matrix 2 :\n");
	for (i = 0; i < u; i++) {
		for (j = 0; j < u; j++) {
			printf("%d ", massPE2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("Otozhdestvlenie a and b : \n");
	scanf_s("%d %d", &s, &s1);
	cpy(mass3, mass, f);
	otoz(s, s1, mass3, f);
	printf("\n");
	printf("Styagivanie a and b: \n");
	printf("\n");
	cpy(mass3, mass, f);
	styag(s, s1, mass3, f);
	printf("Rasheplenie a and b: \n");
	cpy(mass3, mass, f);
	rs(s, s1, mass2, f, mass3);
	printf("\n");
	printf("Perecechenie matriz\n");
	cpy(massOB2, massPE2, u);
	pere(massOB1, massOB2, f,u);
	printf("Obiedinenie matriz\n");
	cpy(massKO2, massPE2, u);
	obe(massPE1, massPE2, f,u);
	printf("\n");
	printf("Kolez summa matriz\n");
	kolez(massKO1, massKO2, f,u);
	printf("\n");
	dekart(massKO1, massKO2, f, u);
}
