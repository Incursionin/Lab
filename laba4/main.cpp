#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <queue>
using namespace std;
typedef struct NODE {
	int v;
	NODE* Next;
};
typedef struct LIST {
	int M;
	struct NODE** HEAD;
};
NODE* CreateNODE(int v) {
	NODE* NewNODE = (NODE*)malloc(sizeof(NODE));
	NewNODE->v = v;
	NewNODE->Next = NULL;
	return NewNODE;
}
LIST* CreateLIST(int M) {

	LIST* list = (LIST*)malloc(sizeof(LIST));
	list->M = M;
	list->HEAD = (NODE**)malloc(sizeof(struct NODE*) * M);
	for (int i = 0; i < M; i++) {
		list->HEAD[i] = NULL;
	}
	return list;
}
void AddFirstElement(NODE** HEAD, NODE* NewNODE) {
	NewNODE->Next = *HEAD;
	*HEAD = NewNODE;
}
void after(NODE* AfterNODE, NODE* NewNODE) {
	NewNODE->Next = AfterNODE->Next;
	AfterNODE->Next = NewNODE;
}
void before(NODE** HEAD, NODE* BeforeNODE, NODE* NewNODE) {
	NODE* active = *HEAD;
	if (*HEAD == BeforeNODE) {
		AddFirstElement(HEAD, NewNODE);
		return;
	}
	while (active && active->Next != BeforeNODE)
		active = active->Next;
	if (active)
		after(active, NewNODE);
}
void DFSLIST(int v, LIST* list, int* visitedArray, int N) {
	printf("%d ", v + 1);

	visitedArray[v] = 1;
	NODE* active = list->HEAD[v];
	while (active) {
		if (visitedArray[active->v] == 0) {
			DFSLIST(active->v, list, visitedArray, N);
		}
		active = active->Next;
	}
}


void AddLastElement(NODE** HEAD, NODE* NewNODE) {
	NODE* active = *HEAD;
	if (*HEAD == NULL) {
		AddFirstElement(HEAD, NewNODE);
		return;
	}
	while (active->Next)
		active = active->Next;
	after(active, NewNODE);
}
void outputLIST(LIST* list) {
	NODE* active;
	for (int i = 0; i < list->M; i++) {
		printf("%d", i + 1);
		active = list->HEAD[i];
		while (active != NULL) {
			printf("->%d", active->v + 1);
			active = active->Next;
		}
		printf("\n");
	}
}
void transfer(int** Array, int N, LIST* list) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Array[i][j] == 1) {
				NODE* NewNODE = CreateNODE(j);
				AddLastElement(&list->HEAD[i], NewNODE);
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
	LIST* list = CreateLIST(f);
	transfer(mass, f, list);
	printf("\n");
	outputLIST(list);
	for (int i = 0; i < f; i++) {
		vis[i] = 0;
	}
	for (int i = 0; i < f; i++) {
		if (vis[i] == 0) {
			DFSLIST(i, list, vis, f);
		}
	}

}