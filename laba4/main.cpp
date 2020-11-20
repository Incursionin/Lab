#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <queue>
using namespace std;

void BFS(int vertex, int** mass, int* vis, int f) {
	queue<int>BFS;
	BFS.push(vertex);
	vis[vertex] = 1;
	while (!BFS.empty()) {
		vertex = BFS.front();
		printf("%d", vertex + 1);
		BFS.pop();
		for (int i = 0; i < f; i++) {
			if (mass[vertex][i] == 1 && vis[i] == 0) {
				BFS.push(i);
				vis[i] = 1;
			}
		}
	}
}

int main() {
	srand(time(NULL));
	int f;
	printf("Enter lenght: ");
	scanf("%d", &f);
	int* vis = (int*)malloc(sizeof(int) * f);
	int* vert = (int*)malloc(sizeof(int) * f);
	int** mass = (int**)malloc(sizeof(int) * f);
	for (int i = 0; i < f; i++) {
		vis[i] = 0;
	}
	printf("\n");
	printf("\n");
	for (int i = 0; i < f; i++) {
		vert[i] = i + 1;
		printf("%d ", vert[i]);
	}
	printf("\n");
	printf("\n");
	for (int i = 0; i < f; i++) {
		mass[i] = (int*)malloc(sizeof(int) * f);
	}
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < f; j++) {
			int c = rand() % 101;
			if (c <= 30) {
				mass[i][j] = 1;
			}
			else mass[i][j] = 0;
			if (i == j) {
				mass[i][j] = 0;
			}

		}
	}
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < f; j++) {
			if (mass[i][j] != mass[j][i])
				mass[i][j] = mass[j][i];

		}
	}
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < f; j++) {
			printf("%d ", mass[i][j]);
		}
		printf("\n");
	}
	

	for (int vert = 0; vert < f; vert++) {
		if (vis[vert] == 0) {
			printf("\n");
			BFS(vert, mass, vis, f);
		}
	}

}