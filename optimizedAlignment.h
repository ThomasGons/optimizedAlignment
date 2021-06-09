#ifndef _OPTIMIZED_ALIGNMENT_H_
#define _OPTIMIZED_ALIGNMENT_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define SIZE 25

static int move_set[4][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};

int** alignment(int** matrix);
bool indexErr(int i, int j, int* move);

#endif 