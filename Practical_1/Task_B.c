// Task-B: Naive Pairwise Comparison Approach
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

    float minTemp = temp[0];
    float maxPress = press[0];

    clock_t start = clock();

    
    for (int i = 0; i < n; i++) {
        int isMin = 1;
        for (int j = 0; j < n; j++) {
            if (temp[i] > temp[j]) {
                isMin = 0;
                break;
            }
        }
        if (isMin) {
            minTemp = temp[i];
            break;
        }
    }

    
    for (int i = 0; i < n; i++) {
        int isMax = 1;
        for (int j = 0; j < n; j++) {
            if (press[i] < press[j]) {
                isMax = 0;
                break;
            }
        }
        if (isMax) {
            maxPress = press[i];
            break;
        }
    }

    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Minimum Temperature: %.2f\n", minTemp);
    printf("Maximum Pressure: %.2f\n", maxPress);
    printf("Time taken: %.6f sec\n", time);

    
}
