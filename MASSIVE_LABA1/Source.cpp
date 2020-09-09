#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
int main(void) {
    srand(time(NULL));
    int i, temp, temp2, j, min=0,max ;
    int* a;
    int n;
    printf("Enter massive length: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d\n", a[i]);
    }
    max = a[0];
    min = a[0];
    for (i = 0; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
        if (min > a[i]) {
            min = a[i];
        }
    }
    

    printf(" \nmax = %d ", max);
    printf("\nmin = %d", min);
    printf("\nsub = %d\n", max - min);
    system("pause");
}
