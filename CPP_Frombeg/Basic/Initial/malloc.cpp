#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr = (int*) malloc(n * sizeof(int)); // allocate memory

    if(arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize and print
    for(int i = 0; i < n; i++) arr[i] = i+1;
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr); // free memory
    return 0;
}

