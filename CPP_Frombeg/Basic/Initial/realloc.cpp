#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;
    int *arr = (int*) malloc(n * sizeof(int));
    for(int i=0;i<n;i++) arr[i] = i+1;  
	 for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    n = 5; // new size
    arr = (int*) realloc(arr, n * sizeof(int)); // resize memory
    arr[3] = 4; arr[4] = 5;
    printf("\n %d",&arr);
     printf("\n ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}

