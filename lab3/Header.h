#pragma once
#pragma once
#include <stdio.h>
#include <random>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
void generate(int** mass,int f);
int main();
void otoz(int s, int s1, int** mass, int f);
void styag(int s, int s1, int** mass1, int f);
void rs(int s, int s1, int** mass2, int f, int** mass3);
void pere(int** massOB1, int** massOB2, int f,int u);
void obe(int** massPE1, int** massPE2, int f, int u);
void kolez(int** massKO1, int** massKO2, int f, int u);
void cpy(int** mass1, int** mass2, int f);
void dekart(int** mass1, int** mass2, int f, int u);