#include "Header.h"
void fileOutput(int count, int* result, int apex, FILE* file) {
    int i;
    fprintf(file, "��������� : \n");
    for (i = 0; i < count; i++)
    {

        if (result[i] < 10000) {
            fprintf(file, "����������� ���������� ����� ��������� %d � %d = %d\n\n", apex, \
                i, result[i]);
        }
        else {
            fprintf(file, "���������� ��  %d �� ���������� \n", apex, \
                i);
        }

    }

}