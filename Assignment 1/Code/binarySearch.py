import time

def binarySearch (arr, low, high, x):
    if high >= low:
        mid = low + (high - low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binarySearch(arr, low, mid-1, x)
        else:
            return binarySearch(arr, mid + 1, high, x)
    else:
        return -1
    
sizes = [100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600, 51200]
a = [1]*2097152

for i in range(0, 10):
    for j in range(0, sizes[i] + 1):
        a[j] = j
    
    start = time.time()
    for k in range(10000):
        binarySearch(a, 0, j-1, j)
    stop = time.time()
    print("Time for size " + str(j) + " is: " + str((stop - start) * 1000) + "ms")