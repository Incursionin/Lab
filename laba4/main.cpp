#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <queue>
using namespace std;
void DFS(int vert, int* vis, int** mass, int f) {
	printf("%d", vert + 1);
	vis[vert] = 1;
	for (int i = 0; i < f; i++) {
		if (mass[vert][i] && vis[i] != 1) {
			DFS(i, vis, mass, f);
		}
	}
}
void norecurses(int vertex, int** mass, int* vis, int f) {
	stack<int>DFSstack;
	DFSstack.push (vertex);
	vis[vertex] = 1;
	while (!DFSstack.empty()) {
		vertex = DFSstack.top();
		printf("%d", vertex + 1);
		DFSstack.pop();
		for (int i = f - 1; i >= 0; i--) {
			if (mass[vertex][i] == 1 && vis[i]!= 1) {
				vis[i] = 1;
				DFSstack.push(i);
			}
		}
	}

}

void BFS(int vertex, int** mass, int* vis, int f) {
	queue<int>BFS;
	BFS.push(vertex);
	vis[vertex] = 1;
	while (!BFS.empty()) {
		vertex = BFS.front();
		BFS.pop();
	}
	for (int i = 0; i < f; i++) {
		if (mass[vertex][i] == 1 && vis[i] == 0) {
			BFS.push(i);
			vis[i] = 1;
			printf("%d", i+1);
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
			if (c <= 50) {
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
	
	/*for (int vert = 0; vert < f; vert++) {
		if (vis[vert] == 0) {
			printf("\n");
			DFS(vert, vis, mass, f);
		}
	}*/
	printf("\n");
	for (int vert = 0; vert < f; vert++) {
		if (vis[vert] == 0) {
			printf("\n");
			norecurses(vert, mass, vis, f);
		}
	}

}