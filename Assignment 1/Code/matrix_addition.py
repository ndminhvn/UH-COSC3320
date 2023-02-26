import numpy as np
import time

# Values for the size of the matrices
N = [128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536]

# for n in N:
#     print("Current matrix size:", n)
    
#     A = np.random.randint(10, size=(n,n))
#     B = np.random.randint(10, size=(n,n))
    
#     # VERSION 1
#     # Generate an empty matrix for the result
#     C = np.empty((n,n))

#     start_time = time.time()
#     for i in range(n):
#         for j in range(n):
#             C[i,j] = A[i,j] + B[i,j]
#     end_time = time.time()
    
#     print(f"Version 1 - Total Time: {end_time - start_time}s\n")
    
for n in N:
    print("Current matrix size: ", n)
    
    A = np.random.randint(10, size=(n,n))
    B = np.random.randint(10, size=(n,n))
    
    # VERSION 2
    # Generate an empty matrix for the result
    C = np.empty((n,n))

    start_time = time.time()
    for j in range(n):
        for i in range(n):
            C[i,j] = A[i,j] + B[i,j]
    end_time = time.time()
    
    print(f"Version 2 - Total Time: {end_time - start_time}s\n")
