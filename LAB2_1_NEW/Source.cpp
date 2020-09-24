#define _CRT_SECURE_NO_WARNINGS
#include <random>
#include <stdlib.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include <malloc.h>


int main(void)
{

	clock_t start, end;
	int i = 0, j = 0, r = 0;
	int elem_c, n;
	printf("Enter lenght: ");
	scanf("%d", &n);
	int** a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}
	int** b = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		b[i] = (int*)malloc(n * sizeof(int));
	}
	int** c = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		c[i] = (int*)malloc(n * sizeof(int));
	}
		srand(time(NULL));
		while (i < n)
		{
			while (j < n)
			{
				a[i][j] = rand() % 100 + 1;
				j++;
			}
			i++;
		}
		srand(time(NULL));
		i = 0; j = 0;
		while (i < n)
		{
			while (j < n)
			{
				b[i][j] = rand() % 100 + 1;
				j++;
			}
			i++;
		}
		start = clock();
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				elem_c = 0;
				for (r = 0; r < n; r++)
				{
					elem_c = elem_c + a[i][r] * b[r][j];
					c[i][j] = elem_c;
				}
			}
		}
		end = clock();
		printf("Time of sort = %lf sec.", (double)(end - start) / CLK_TCK);
		free(a);
		free(b);
		free(c);
		system("pause");
		return(0);
}

