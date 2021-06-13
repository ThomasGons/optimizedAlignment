#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define SIZE 3
#define SYMBOLS 3 // add one for the first column of allAlignment

static int move_set[4][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};


void alignment(int** matrix, FILE* f);
int indexErr(int i, int j, int* move);
int allZeros(const int *t, size_t size);