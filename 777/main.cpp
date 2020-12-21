#include "Header.h"
void main(){
    srand(time(NULL));
    setlocale(LC_ALL, "russian");
    int f, start, input = 0;
    int** mass;
    FILE* fout;
    Title();
	system("cls");
    Menu();
    while (input < 4) {
       scanf("\n%d", &input);
       if (input == 1) {
            system("cls");
            printf("\nВведите размер графа : ");
            scanf_s("%d", &f);
            mass = (int**)malloc(sizeof(int) * f);
            randomGen(f, mass);
            _getch();
            system("cls");
            Menu();
       }
       else if (input == 2) {
           if (mass == 0) {
               system("cls");
               printf("Граф не найден!\n");
               printf("\nВведите размер графа : ");
               scanf_s("%d", &f);
               mass = (int**)malloc(sizeof(int) * f);
               randomGen(f, mass);
           }
           system("cls");
           output(mass, f);
           printf("Введите стратовую веришу : ");
           scanf("%d", &start);
           if (start > f - 1) {
               printf("Введена неправильная вершина!");
               _getch();
               system("cls");
               Menu();
           }
           else {
               Ford_Ballman(f, mass, start, 0, 1);
               _getch();
               system("cls");
               Menu();
           }
       }
       if (input == 3) {    
           char name[] = "data.txt";
           if ((fout = fopen(name, "w+"))  == NULL) {
               printf("Файл не найден!");
               _getch();
           }
           else {
               system("cls");
               printf("Файл сохранен\n");
               fout = fopen("C:\\new\\data.txt", "w");
               for (int i = 0; i < f; i++) {
                   for (int j = 0; j < f; j++) {
                       fprintf(fout, "|%d|\t ", mass[i][j]);
                       if (j == f - 1)
                           fprintf(fout, "\n");
                   }
               }
               Ford_Ballman(f, mass, start, fout, 2);
               printf("\n");
               Menu();
           }

           

       }
        

    }
    system("cls");
	
	system("pause");









}