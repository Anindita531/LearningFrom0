#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main() {
	
	clock_t start=clock();
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
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nExecution time: first " << time_taken << " seconds\n";
    clock_t start1=clock();
    int marks[5] = {90, 85, 78, 92, 88};

    cout << "Marks of student 3: " << marks[2] << endl; // 78

    // Loop through all marks
    for(int i = 0; i < 5; i++) {
        cout << "Student " << i+1 << ": " << marks[i] << endl;
    }
    clock_t end1 = clock();
      double time_taken2 = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "\nExecution time: 2nd " << time_taken2 << " seconds\n";
    
}
