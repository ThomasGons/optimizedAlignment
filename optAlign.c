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
            matrix[i][j] = rand() % SYMBOLS;
            fprintf(f, "%d, ", matrix[i][j]);
            //printf("%d ", matrix[i][j]);             uncomment to see the matrix in the shell
        }
        fprintf(f, "\n\n");
        //printf("\n");                                uncomment to see the matrix in the shell 
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
    int allAlignment[SIZE][SYMBOLS], i, j; // contains all the alignments of each symbol according to their length
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
                if (length > 0)
                    allAlignment[length][matrix[store[0]][store[1]] + 1] += 1;
                i = store[0], j = store[1];
            }
        }
    }
    for (i = 1; i < SIZE; i++)
    {
        if (allZeros(allAlignment[i], (size_t) SYMBOLS))
            break;
        for (j = 0; j < SYMBOLS; j++)
        {
            (j == 0)? fprintf(f, "%d,  ", allAlignment[i][j] + 1) : fprintf(f, "%d, ", allAlignment[i][j]);
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