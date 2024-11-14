#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col;

    printf("what is the number of row and column? \n");
    scanf("%d %d", &row, &col);


    int * matrix1, * result;
    matrix1 = malloc(row * col * sizeof(int));
    result = malloc(row * col * sizeof(int));

    printf("what is the input for matrix1? \n");
    for(int i = 0; i < row; i++)
        for (int j=0; j< col; j++)
            scanf("%d", &matrix1[i * col + j]);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            result[j * row + i] = matrix1[i * col + j];
        }
    }
    printf("Input Matrix:\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", matrix1[i * col + j]);
        }
        printf("\n");
    }

    printf("Result Matrix:\n");
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            printf("%d ", result[i * row + j]);
        }
        printf("\n");
    }

    free(matrix1);
    free(result);

    return 0;
}