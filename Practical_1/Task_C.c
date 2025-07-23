//Task-C:
//1.Generate sorted data for temperature (range: 20 to 50)
//2.Find the first Occurrence of temperature >=30.

// Apply Linear search
// Apply Binary Search
#include <stdio.h>
#include <time.h>

void fillTemperature(int temp[], int n) {
    int value = 20;
    for (int i = 0; i < n; i++) {
        temp[i] = value;
        value++;
    }
}

int linearSearch(int temp[], int n) {
    for (int i = 0; i < n; i++) {
        if (temp[i] >= 30)
            return i;
    }
    return -1;
}

int binarySearch(int temp[], int n) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (temp[mid] >= 30) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n = 31, temp[n];
    fillTemperature(temp, n);

    clock_t start, end;
    double time;

    start = clock();
    int index1 = linearSearch(temp, n);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Linear Search:\n");
    printf("First temperature >= 30 at index: %d\n", index1);
    printf("Time taken: %f seconds\n\n", time);

    start = clock();
    int index2 = binarySearch(temp, n);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Binary Search:\n");
    printf("First temperature >= 30 at index: %d\n", index2);
    printf("Time taken: %f seconds\n", time);

    
}
