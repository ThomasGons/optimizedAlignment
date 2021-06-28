#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 19
#define SYMBOLS 2

static int moveSet[4][2] = {{1, -1}, {1, 0}, {1, 1}, {0, 1}};


void globalAlign(int** matrix);
int indexErr(int i, int j, int* move);
