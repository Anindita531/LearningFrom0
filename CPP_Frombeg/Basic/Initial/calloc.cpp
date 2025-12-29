#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr = (int*) calloc(n, sizeof(int)); // memory initialized to 0

    if(arr == NULL) return 1;

    for(int i = 0; i < n; i++) printf("%d ", arr[i]); // prints 0
    printf("\n");

    free(arr);
    return 0;
}

