#include"optimizedAlignment.h"

int main()
{
    srand(time(NULL));
    int** matrix = malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++)
    {
        matrix[i] = malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 2;
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    alignment(matrix);
}

int** alignment(int** matrix)
{
    int allAlignement[SIZE][2]; // contains all the alignments of each symbol according to their length
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            allAlignement[i][j] = 0;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int length = 0, store[2] = {i, j};
                while(indexErr(i, j, move_set[k]) != false && matrix[i][j] == matrix[i + move_set[k][0]][j + move_set[k][1]])
                {
                    i += move_set[k][0];
                    j += move_set[k][1];
                    length++;
                }
                allAlignement[length][matrix[store[0]][store[1]]] += 1;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", allAlignement[i][j]);
        }
        printf("\n");
    }
}

bool indexErr(int i, int j, int* move)
{
    if (0 < i + move[0] || i + move[0] > SIZE 
    || 0 < j + move[1] || j + move[1] > SIZE)
    {
        return false;
    }
}