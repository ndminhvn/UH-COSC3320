#include<iostream>
#include<ctime>
#include<stdlib.h>

using namespace std;

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low+ (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);
        return binarySearch(arr, mid + 1, high, x);
    }
    return -1;
}

int main(){
    int sizes[10] = {100, 200, 400, 800, 1600, 3200, 6400, 12800, 25600, 51200};
    int i, j, k;
    int *a;
    a = (int*)malloc(sizeof(int)*2097152);

    clock_t time;

    for(i = 0; i < 10; i++) {
        for(j = 0; j < sizes[i]; j++)
            a[j] = j;

        time = clock();
        for(k = 0; k < 10000; k++){
            binarySearch(a, 0, j-1, j);
        }
        time = clock() - time;
        cout << "Time for size " << j << " is: "<< (float)time/CLOCKS_PER_SEC * 1000 << "ms"<<endl;
    }

    return 0;
}