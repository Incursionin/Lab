#pragma once
#define _CRT_SECURE_NO_WARNINGS  
#define INF 10000000;
#include <conio.h>
#include <time.h>
#include <random>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
void outputFord(int count, int* result, int apex);
void fileOutput(int count, int* result, int apex, FILE* file);
void Ford_Ballman(int CountApex, int** SourceMatrix, int Start, FILE* fin, int status);
void Title();
void Menu();
void output(int** mass, int f);
void randomGen(int f, int** mass);