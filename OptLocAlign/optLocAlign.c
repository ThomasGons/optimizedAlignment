#include"optLocAlign.h"

int main()
{
    int i, j, x, y, symbol = 0; 
    int** matrix = malloc(SIZE * sizeof(int*));    
    for (i = 0; i < SIZE; i++)
    {
        matrix[i] = malloc(SIZE * sizeof(int));
        for (j = 0; j < SIZE; j++)
        {
            matrix[i][j] = '.';
        }
    }
    do{
        do{
            printf("Where do you want to place a %d\n", symbol % SYMBOLS);
            scanf("%d", &x);
            scanf("%d", &y);
        }while (indexErr(x, y, {0, 0}) == 0 && matrix[x][y] != '.');
    }while (localAlign(matrix, x, y) != 0);
    for (i = 0; i < SIZE; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return EXIT_SUCCESS;
}

int localAlign(int** matrix, int x, int y)
{
    int store[2] = {x, y}, length = 0;
    // there are four directions for an alignment in each cell
    for (int k = 0; k < 4; k++)
    {
        for (int r = -1; r < 1; r += 2)
        {
            while (indexErr(x, y, r, moveSet[k]) == 0 && matrix[x][y] == matrix[x + moveSet[k][0] * r][y + moveSet[k][1] * r])
            {
                x += moveSet[k][0];
                y += moveSet[k][1];
                if (length++ == SIZE)
                    return 0;
            }
            // we increase the Align's number for the given symbol and the correct length of the globalAlign
            x = store[0], y = store[1];
        }
    }
    return 1;
}

int indexErr(int i, int j, int r, int *move)
{
    return (0 > i + move[0] * r || i + move[0] * r > SIZE - 1 || 0 > j + move[1] * r || j + move[1] * r > SIZE - 1)? 1: 0;
}