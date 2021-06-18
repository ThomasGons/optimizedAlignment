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
            fprintf(f, "%d, ", matrix[i][j]);       // add the matrix to the .csv file
        }
        fprintf(f, "\n\n");                         // with the line breaks
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
           // the first column represents the length of the alignment thus it is not initalized to zero
            allAlignment[i][j] = (j == 0)? i: 0;  
        }
    }
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            // there are four directions for an alignment in each cell
            for (int k = 0; k < 4; k++)
            {
                int length = 0, store[2] = {i, j};  // store allows us to store i and j values
                /* as long as we do not leave the matrix and the next cell's value is equal,
                we continue to increase the length of the alignment in the given direction */
                while(indexErr(i, j, move_set[k]) == 0 && matrix[i][j] == matrix[i + move_set[k][0]][j + move_set[k][1]])
                {
                    i += move_set[k][0];
                    j += move_set[k][1];
                    length++;
                }
                // we increase the alignment's number for the given symbol and the correct length of the alignment
                allAlignment[length][matrix[store[0]][store[1]] + 1] += 1;  
                i = store[0], j = store[1];
            }
        }
    }
    for (i = 0; i < SYMBOLS; i++)
    {
        // display Alignment, 0, 1, ..., number of symbols - 1 in the .csv file
        i? fprintf(f, "%d, ", i - 1): fprintf(f, "Alignment, ");    
    }
    fprintf(f, "\n");
    for (i = 1; i < SIZE; i++)
    {
        // we do not display the useless lines which contains no alignments
        if (allZeros(allAlignment[i], SYMBOLS - 1))
            break;
        for (j = 0; j < SYMBOLS; j++)
        {
            /* display the number of alignments according to the symbol and the length of the alignment
            respectively define in the first line and column */
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
        if (!t[size])   // we only consider the non line of zeros  
            return 1;
    return 0;
}