#include"optAlign.h"

int main()
{
    srand(time(NULL));
    int** matrix = malloc(SIZE * sizeof(int*));
    FILE* f = fopen("optAlign.csv", "w+");
    for (int i = 0; i < SIZE; i++)
    {
        matrix[i] = malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 2;
            fprintf(f, "%d, ", matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        fprintf(f, "\n");
        printf("\n");
    }
    alignment(matrix, f);
    for (int i = 0; i < SIZE; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void alignment(int** matrix, FILE* f)
{
    int allAlignment[SIZE][3]; // contains all the alignments of each symbol according to their length
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            allAlignment[i][j] = (j == 0)? i: 0;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int length = 0, store[2] = {i, j};
                while(indexErr(i, j, move_set[k]) == true && matrix[i][j] == matrix[i + move_set[k][0]][j + move_set[k][1]])
                {
                    i += move_set[k][0];
                    j += move_set[k][1];
                    length++;
                }
                if (length > 0)
                {
                    allAlignment[length][matrix[store[0]][store[1]] + 1] += 1;
                }
                i = store[0], j = store[1];
            }
        }
    }
    
    fprintf(f, "\n\nAlignment, 0, 1\n\n");
    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            
            (j == 0)? fprintf(f, "%d,  ", allAlignment[i][j] + 1) : fprintf(f, "%d, ", allAlignment[i][j]);
        }
        fputs("\n", f);
    }
    fclose(f);
} 

bool indexErr(int i, int j, int* move)
{
    if (0 > i + move[0] || i + move[0] > SIZE - 1 || 0 > j + move[1] || j + move[1] > SIZE - 1)
    {
        return false;
    }
    return true;
}