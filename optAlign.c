#include"optAlign.h"

int main()
{
    srand(time(NULL));
    int i, j, **matrix = malloc(SIZE * sizeof(int*));
    FILE* f = fopen("optAlign.csv", "w+");
    for (i = 0; i < SIZE; i++)
    {
        matrix[i] = malloc(SIZE * sizeof(int));
        for (j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % (SYMBOLS - 1);
            fprintf(f, "%d, ", matrix[i][j]);
            //printf("%d ", matrix[i][j]);             uncomment to see the matrix in the shell
        }
        fprintf(f, "\n\n");
        printf("\n");
    }
    alignment(matrix, f);
    for (i = 0; i < SIZE; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return EXIT_SUCCESS;
}

void alignment(int** matrix, FILE* f)
{
    int i, j, allAlignment[SIZE][SYMBOLS]; // contains all the alignments of each symbol according to their length
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SYMBOLS; j++)
        {
            allAlignment[i][j] = (j == 0)? i: 0;
        }
    }
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int length = 0, store[2] = {i, j};
                while(indexErr(i, j, move_set[k]) == 0 && matrix[i][j] == matrix[i + move_set[k][0]][j + move_set[k][1]])
                {
                    i += move_set[k][0];
                    j += move_set[k][1];
                    length++;
                }
                allAlignment[length][matrix[store[0]][store[1]] + 1] += 1;
                i = store[0], j = store[1];
            }
        }
    }
    for (i = 0; i < SYMBOLS; i++)
    {
        i? fprintf(f, "%d, ", i): fprintf(f, "Alignment, ");
    }
    fprintf(f, "\n");
    for (i = 1; i < SIZE; i++)
    {
        for (j = 0; j < SYMBOLS; j++)
        {
            j? fprintf(f, "%d, ", allAlignment[i][j]): fprintf(f, "%d,  ", allAlignment[i][j] + 1);
        }
        fputs("\n", f);
    }
    fclose(f);
} 

int indexErr(int i, int j, int* move)
{
    return (0 > i + move[0] || i + move[0] > SIZE - 1 || 0 > j + move[1] || j + move[1] > SIZE - 1)? 1: 0;
}

int allZeros(const int *t, size_t size)
{
    while (size--)
        if (t[size])
            return 0;
    return 1;
}