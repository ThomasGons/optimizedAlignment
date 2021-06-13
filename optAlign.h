#ifndef _OPT_ALIGN_H_
#define _OPT_ALIGN_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define SIZE 3
#define SYMBOLS 3 // add one for the first column of allAlignment

static int move_set[4][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};


void alignment(int** matrix, FILE* f);
bool indexErr(int i, int j, int* move);

#endif 