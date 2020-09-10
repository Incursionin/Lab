#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
int main(void) {
    srand(time(NULL));
    int i, j,sum=0,n,f;
    int massive[5][5];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            massive[i][j] = rand() % 100;
            printf("\n[%d][%d]%d\n\t",i,j,massive[i][j]);
        }
    }
    i = 0;
    for (j = 0; j < 5; ++j) {
        sum += massive[i][j];
        if (j == 4) {
            j = -1;
            i++;
            printf("\n%d\n", sum);
            sum = 0;
        }
        if (i == 5) {
            break;
        }
    }
    system("pause");
}
