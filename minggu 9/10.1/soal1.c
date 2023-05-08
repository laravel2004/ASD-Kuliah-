#include <stdio.h>

void selectionSort(int arr[], int n, int *comp, int *swap) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++) {
            (*comp)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            (*swap)++;
        }
    }
}

int main() {
    int arr1[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    int arr2[] = {1, 2, 3, 4, 5, 9, 7, 6, 8, 10};
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr4[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;

    int comp1 = 0, swap1 = 0;
    selectionSort(arr1, n, &comp1, &swap1);
    printf("Array 1: Jumlah perbandingan = %d, jumlah penukaran = %d\n", comp1, swap1);

    int comp2 = 0, swap2 = 0;
    selectionSort(arr2, n, &comp2, &swap2);
    printf("Array 2: Jumlah perbandingan = %d, jumlah penukaran = %d\n", comp2, swap2);

    int comp3 = 0, swap3 = 0;
    selectionSort(arr3, n, &comp3, &swap3);
    printf("Array 3: Jumlah perbandingan = %d, jumlah penukaran = %d\n", comp3, swap3);

    int comp4 = 0, swap4 = 0;
    selectionSort(arr4, n, &comp4, &swap4);
    printf("Array 4: Jumlah perbandingan = %d, jumlah penukaran = %d\n", comp4, swap4);

    return 0;
}
