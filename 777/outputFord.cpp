#include "Header.h"
void outputFord(int count, int* result, int apex)
{
    int i;
    printf("��������� : \n");
    for (i = 0; i < count; i++)
    {

        if (result[i] < 10000) {
            printf("����������� ���������� ����� ��������� %d � %d = %d\n\n", apex, \
                i, result[i]);
        }
        else {
            printf("���������� �� ������� %d �� ����������\n", apex, \
                i);
        }
    }

}