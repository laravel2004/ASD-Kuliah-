#include <stdio.h>

void shellSort(int arr[], int n) {
    int i, j, temp, gap, C = 0, S = 0, M = 0;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap) {
                C++;
                arr[j] = arr[j-gap];
                M++;
            }
            arr[j] = temp;
            S++;
            M++;
        }
        printf("Iteration %d: ", gap);
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
    shellSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
