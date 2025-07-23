// TASK A:Apply Linear Search Approach
#include <stdio.h>
#include <time.h>

int main() {
    int n;

    printf("Enter the number of readings: ");
    scanf("%d", &n);

    float temp[n], press[n];

    printf("Enter %d temperature values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &temp[i]);
    }

    printf("Enter %d pressure values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &press[i]);
    }

    clock_t start = clock();

    float minTemp = temp[0];
    float maxPress = press[0];

    for (int i = 1; i < n; i++) {
        if (temp[i] < minTemp) {
            minTemp = temp[i];
        }
        if (press[i] > maxPress) {
            maxPress = press[i];
        }
    }

    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Minimum Temperature: %.2f\n", minTemp);
    printf("Maximum Pressure: %.2f\n", maxPress);
    printf("Time taken: %.6f sec\n", time);

    
}
