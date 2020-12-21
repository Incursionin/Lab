#include "Header.h"
void outputFord(int count, int* result, int apex)
{
    int i;
    printf("Результат : \n");
    for (i = 0; i < count; i++)
    {

        if (result[i] < 10000) {
            printf("Минимальное расстояние между вершинами %d и %d = %d\n\n", apex, \
                i, result[i]);
        }
        else {
            printf("Расстояний из вершины %d не существует\n", apex, \
                i);
        }
    }

}