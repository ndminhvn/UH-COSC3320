#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int m;
    printf("Enter the value of m: ");
    scanf("%d", &m);

    int **A=(int **)malloc(3*m*sizeof(int*));      // Allocate memory for a sequence of 3m arrays
    clock_t time;                                  // Timer to find execution time

    // Allocate memory for 3m arrays of size 1MB each
    time = clock();                                // Timer starts
    for(int i = 0; i < 3*m; i++)
        A[i] = (int *)malloc(1000000);
    time = clock() - time; // Timer ends
    double time_required = ((double)time)/CLOCKS_PER_SEC; // in seconds
    printf("Time required for the allocation memory of the %d arrays of size 1MB each: %f Sec \n", 3*m, time_required);

    // Deallocate the even-numbered arrays
    time = clock(); // Timer starts
    for(int i = 0; i < 3*m; i = i + 2)
        free(A[i]);
    time = clock() - time; // Timer ends
    time_required = ((double)time)/CLOCKS_PER_SEC; // in seconds
    printf("Time required for the deallocation of the even-numbered arrays: %f Sec \n", time_required);

    // Then allocate memory for m arrays of size 1.25MB each
    time = clock(); // Timer starts
    for(int i = 0; i < m; i++)
        A[i] = (int *)malloc(1250000);
    time = clock() - time; // Timer ends
    time_required = ((double)time)/CLOCKS_PER_SEC; // in seconds
    printf("Time required for the allocation memory of the %d arrays of size 1.25MB each: %f Sec \n", m, time_required);
    
    return 0;
}
