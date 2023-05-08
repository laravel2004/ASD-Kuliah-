#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp, C = 0, S = 0, M = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            C++;
            if (arr[j] > arr[j+1]) {
                S++;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                M += 3;
            }
        }
        printf("Iteration %d: ", i+1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
    printf("Comparison: %d\n", C);
    printf("Swapping: %d\n", S);
    printf("Movement: %d\n", M);
}

int main() {
    int arr[10] = {9, 3, 7, 5, 6, 4, 8, 2, 1, 0};
    int n = 10;
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
