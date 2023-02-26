package Code;

class binarySearch {
    int binarySearchFunction(int arr[], int low, int high, int x) {
        if (high >= low) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x)
                return binarySearchFunction(arr, low, mid - 1, x);
            return binarySearchFunction(arr, mid + 1, high, x);
        }
        return -1;
    }

    public static void main(String args[]) {
        binarySearch ob = new binarySearch();
        int sizes[] = {100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600, 51200};
        int n = sizes.length;

        int[] a = new int[2097152];
        int i, j, k;

        for (i = 0; i < n; i++) {
            for (j = 0; j < sizes[i]; j++)
                a[j] = j;
            
            long start = System.nanoTime();
            for (k = 0; k < 10000; k++) {
                ob.binarySearchFunction(a,0, j-1, j);
            }
            long end = System.nanoTime();
            long time = end - start;
            System.out.println("Time for size " + j + " is: " + time + "ns");
        }
    }
}

