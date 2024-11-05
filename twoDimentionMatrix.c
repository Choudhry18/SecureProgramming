#include <stdio.h>
#include <stdlib.h>

int main(){
    int row, col;

    printf("what is the number of row and column? \n");
    scanf("%d %d", &row, &col);


    int * matrix1, * matrix2, * result; 
    matrix1 = malloc(row * col * sizeof(int));
    matrix2 = (int *) malloc(row * col * sizeof(int));
    result = (int *) malloc(row * col * sizeof(int));

    printf("what is the input for matrix1? \n");
    for(int i = 0; i < row; i++)
        for (int j=0; j< col; j++)
            scanf("%d", &matrix1[i * col + j]);

    printf("what is the input for matrix2? \n");
    for(int i = 0; i < row; i++)
        for (int j=0; j< col; j++)
            scanf("%d", matrix2 + i * col + j);

    for(int i = 0; i < row; i++)
        for (int j=0; j< col; j++)
            result[i * col + j] = matrix1[i * col + j] + matrix2[i * col + j];

    printf("the result would be: \n");
    for(int i = 0; i < row; i++){
        for (int j=0; j< col; j++)
            printf("%d ", result[i * col + j]);
        printf("\n");

    }

    free(matrix1);
    free(matrix2);
    free(result);
        


}