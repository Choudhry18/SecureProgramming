#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char *str = malloc(20 * sizeof(char));  // Allocate memory for a string of 20 characters
;
    strcpy(str, "Hello, world!;");  // Copy a string into the allocated memory
    printf("%s\n", str);

    free(str);  // Free allocated memory
}

