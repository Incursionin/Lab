#include "Header.h"
void Ford_Ballman(int CountApex, int** SourceMatrix, int Start, FILE* fin, int status)
{

    int* MinPath; // ������ ����������� �����
    int i, j, k;
    MinPath = (int*)malloc(CountApex * sizeof(int));
    for (i = 0; i < CountApex; i++)
    {
        MinPath[i] = INF; //��� ���������� ������ ������������
    }

    MinPath[Start] = 0;
    for (k = 0; k < CountApex; k++)
    {
        for (i = 0; i < CountApex; ++i)
        {
            for (j = 0; j < CountApex; ++j)
            {
                if (SourceMatrix[i][j] != 0) //���� ������� �� ��������
                    if (MinPath[j] > MinPath[i] + SourceMatrix[i][j]) {
                        MinPath[j] = MinPath[i] + SourceMatrix[i][j];
                    }
            }
        }
    }
    for (i = 0; i < CountApex; ++i) {

        for (j = 0; j < CountApex; ++j)
        {
            if (SourceMatrix[i][j] != 0)
                if (MinPath[j] > MinPath[i] + SourceMatrix[i][j]) {
                    printf("������! ������ ������������� ����\n");
                    return;
                }
        }
    }
    if (status == 1)
        outputFord(CountApex, MinPath, Start);
    if (status == 2)
        fileOutput(CountApex, MinPath, Start, fin);
}