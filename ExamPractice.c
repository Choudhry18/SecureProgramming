#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PreventBufferOverflow(){
    int MAX_LENGTH = 10;
    char input[MAX_LENGTH];

    // Prompt the user to enter a line of text
    printf("Enter a line of text (up to %d characters): ", MAX_LENGTH - 1);

    // Use fgets to read input, ensuring it doesn't exceed MAX_LENGTH - 1 (reserve space for null terminator)
    if (fgets(input, MAX_LENGTH, stdin) != NULL) {
        // Remove the trailing newline character if present
        size_t length = strlen(input);
        if (length > 0 && input[length - 1] == '\n') {
            input[length - 1] = '\0';
        }

        // Display the user input
        printf("You entered: %s\n", input);
    } else {
        printf("Error reading input.\n");
    }
}
double add (double x, double y){
    return x+y;
}

double subtract (double x, double y){
    return x-y;
}

double division (double x, double y){
    return x/y;
}

double multiplication (double x, double y){
    return x*y;
}
void functionPointer(){
    double a ,b;
    printf("Give the numbers: ");
    scanf("%lf %lf", &a, &b);
    int select;
    printf("What is the operation? \n");
    scanf("%d", &select);
    double (*operation) (double, double);
    switch (select)
    {
    case 1:
        operation = add;
        break;
    case 2:
        operation = subtract;
        break;
    case 3:
        operation = multiplication;
        break;
    case 4: 
        operation = division;
        break;
    default:
        printf("Error");
    }
    double out = (*operation) (a,b);
    printf("This is the answer %llf" , out);
}

void twodimensional(){
    int row, col;
    printf("what is the number of row and column? \n");

}

/* void DynamicArray(){
    int size = 10;
    int* arr = malloc(10 * sizeof(size));
    int* pointer = arr;
    while(1){
        scanf("%d", &pointer);
        arr += 1;

    }
} */


int main() {
    functionPointer();
    return 0;
}