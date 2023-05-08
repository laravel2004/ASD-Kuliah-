#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 100000

void generate(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void bubble_sort(int arr[], int n, int mode) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mode == 1) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            else {
                if (arr[j] < arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

int main() {
    int arr[MAX_ELEMENTS], n, mode;
    clock_t start, end;
    double cpu_time_used;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);
    if (n > MAX_ELEMENTS) {
        printf("Jumlah elemen terlalu besar!\n");
        return 0;
    }
    generate(arr, n);
    printf("1. Urutkan secara ascending\n");
    printf("2. Urutkan secara descending\n");
    printf("Pilih mode pengurutan: ");
    scanf("%d", &mode);
    start = clock();
    bubble_sort(arr, n, mode);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Waktu komputasi: %f detik\n\n\n", cpu_time_used);
    printf("Hasil pengurutan:\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    printf("\n");
    return 0;
}
