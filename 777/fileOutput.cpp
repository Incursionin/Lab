#include "Header.h"
void fileOutput(int count, int* result, int apex, FILE* file) {
    int i;
    fprintf(file, "Результат : \n");
    for (i = 0; i < count; i++)
    {

        if (result[i] < 10000) {
            fprintf(file, "Минимальное расстояние между вершинами %d и %d = %d\n\n", apex, \
                i, result[i]);
        }
        else {
            fprintf(file, "Расстояний из  %d не существует \n", apex, \
                i);
        }

    }

}