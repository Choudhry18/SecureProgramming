#include <stdio.h>

void swap(int *a, int *b) {
    // Complete the function to swap values using pointers
    *(a+1) = *a;
    *a =  *b;
    *b = *(a+1);
}

void reverse(int *arr, int size) {
    for(int i=0;i< (size/2); i++){
        int temp = *(arr+i);
        *(arr+i) = *((arr+(size-1))-i);
        *((arr+size)-i) = temp;
    }
}

int main() {
    int x = 5, y = 10;
    printf("Before Swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);   // what will happen if you swap two integers
    printf("After Swap: x = %d, y = %d\n", x, y);
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    reverse(arr, size);

    printf("\nReversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}