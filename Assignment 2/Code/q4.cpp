#include <iostream> 
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>
#include <ctime>
 
using namespace std; 
 
int main() { 
 	//n-values to be used 
 	int n[6] = { 16, 64, 256, 1024, 4096, 16384 }; 
 	int next = 0;

    size_t m;
    cout << "Enter value of m: ";  	 	
    cin >> m;       // m = 1,000,000,000 and m = 10,000,000,000
	
 	while (next < 6) { 
 	 	int a, b, x;  	 		 	
        int** M = new int*[n[next]];  //initialize Matrix M

        for (int i = 0; i < n[next]; i++) { 
 	 	 	M[i] = new int[i]; 
 	 	} 

 	 	// Initialize the Matrix to 0 
 	 	for (int i = 0; i < n[next]; i++) { 
 	 	 	for (int j = 0; j < n[next]; j++) { 
 	 	 	 	M[i][j] = 0; 
 	 	 	} 
 	 	}
        
        clock_t timer;
        
        timer = clock(); 
 	 	//perform the calculation by adding random numbers from 1-100 
 	 	for (int i = 0; i < m; ++i) { 
 	 	 	x = rand() % 100 + 1;  	 	 	
            b = rand() % n[next];
            a = rand() % n[next];  	 	 	
            M[a][b] += x; 
 	 	} 
        timer = clock() - timer; 
        printf("Clock time for size n = %d: %.2f seconds", n[next], ((float)timer) / CLOCKS_PER_SEC); 
 	 	cout << endl;  	 	
        next++; 
 	}
 	return 0; 
}
