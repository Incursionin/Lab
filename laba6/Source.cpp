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
	printf("\n");
}
void matrix_into_list(int** mass, int f, LIST* list) {
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < f; j++) {
			if (mass[i][j] == 1) {
				NODE* NewNODE = CreateNODE(j);
				AddLastElement(&list->HEAD[i], NewNODE);
			}
		}
	}
}
void Zero_Distance(int* Dist, int f) {
	for (int i = 0; i < f; i++) {
		Dist[i] = -1;
	}
}
void BFSD(int vertex, int f, int **mass, int* DIST) {

	queue<int>BFS;
	BFS.push(vertex);
	DIST[vertex] = 0;
	while (!BFS.empty()) {
		vertex = BFS.front();
		printf("%d", vertex + 1);
		BFS.pop();
		for (int i = 0; i < f; i++) {
			if ((mass[vertex][i] == 1) && (DIST[i] == -1)) {
				BFS.push(i);
				DIST[i] = DIST[vertex] + 1;
			}
		}
	}
}
void BFSD_list(LIST* list, int f, int vertex, int *DIST) {
	queue<int>BFS_LIST;
	BFS_LIST.push(vertex);
	DIST[vertex] = 0;
	while (!BFS_LIST.empty()) {
		vertex = BFS_LIST.front();
		BFS_LIST.pop();
		NODE* active = list->HEAD[vertex];
		while (active) {
			if (DIST[active->v] == -1) {
				BFS_LIST.push(active->v);
				DIST[active->v] = DIST[vertex] + 1;
			}
			active = active->Next;
		}
	}
}
void DS(int vertex, int** mass, int f, int *DIST) {
	stack<int>S;
	S.push(vertex);
	DIST[vertex] = 0;
	while(!S.empty()) {
		vertex = S.top();
		S.pop();
		int i = f - 1;
		while (i >= 0) {
			if (mass[vertex][i] && DIST[i] == -1) {
				S.push(i);
				DIST[i] = DIST[vertex] + 1;
			}
			i--;
		}
	}

}
void DS_lists(int vertex, LIST* list, int f, int *DIST)
{
	std::stack<int>S;
	S.push(vertex);
	DIST[vertex] = 0;
	while (!S.empty()) {
		vertex = S.top();
		S.pop();
		NODE* active = list->HEAD[vertex];
		int i = f - 1;
		while (active) {
			if (DIST[active->v] == -1) {
				S.push(active->v);
				DIST[active->v] = DIST[vertex] + 1;
			}
			active = active->Next;
		}
	}
}

int main() {
	srand(time(NULL));
	int start, start2;
	int f;
	int min = 10000;
	int* DIST = NULL;
	printf("Enter lenght: ");
	scanf("%d", &f);
	int* vis = (int*)malloc(sizeof(int) * f);
	int* vert = (int*)malloc(sizeof(int) * f);
	int** mass = (int**)malloc(sizeof(int) * f);
	DIST = (int*)malloc(f * sizeof(int));
	DIST = (int*)malloc(f * sizeof(int));
	for (int i = 0; i < f; i++){
		DIST[i] = -1;
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
	LIST* list = CreateLIST(f);
	matrix_into_list(mass, f, list);
	outputLIST(list);
	printf("Enter start vertex :");
	scanf("%d", &start);
	printf("\nVisited vertexes \n");
	double start_time = clock();
	BFSD(start-1, f, mass, DIST);
	double end_time = clock();
	printf("\nTime shirina = %f\n", (end_time - start_time) / CLOCKS_PER_SEC);
	printf("\nVertexes \n");
	for (int i = 1; i <= f; i++) {
		printf("|%d|", i);
	}
	printf("\nDistance\n");
	for (int i = 0; i < f; i++) {
		printf("|%d|", DIST[i]);
	}
	printf("\n");
	printf("Distance on lists\n");
	for (int i = 0; i < f; i++) {
		DIST[i] = -1;
	}
	BFSD_list(list,f,start-1, DIST);
	for (int j = 0; j < f; j++) {
		printf("|%d|", DIST[j]);

	}
	for (int i = 0; i < f; i++) {
		DIST[i] = -1;
	}
	printf("\nDepth distance \n");
	double start2_clock = clock();
	DS(start - 1, mass, f, DIST);
	double end2_clock = clock();
	printf("Time = %f\n", (end2_clock - start2_clock)/CLOCKS_PER_SEC);
	for (int j = 0; j < f; j++) {
		printf("|%d|", DIST[j]);

	}
	for (int i = 0; i < f; i++) {
		DIST[i] = -1;
	}
	printf("\nDepth distance lists\n");
	DS_lists(start - 1, list, f, DIST);
	for (int j = 0; j < f; j++) {
		printf("|%d|", DIST[j]);

	}



	


}