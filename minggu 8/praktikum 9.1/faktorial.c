#include <stdio.h>

// Fungsi faktorial dalam bentuk rekursi
int faktorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * faktorial(n - 1);
}

// Fungsi untuk menghitung permutasi
int permutasi(int n, int r) {
    return faktorial(n) / faktorial(n - r);
}

// Fungsi untuk menghitung kombinasi
int kombinasi(int n, int r) {
    return faktorial(n) / (faktorial(r) * faktorial(n - r));
}

int main() {
    int n, r;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);
    printf("Masukkan nilai r: ");
    scanf("%d", &r);

    if (n < r) {
        printf("n harus lebih besar dari atau sama dengan r");
        return 0;
    }

    printf("Permutasi dari %d dan %d adalah %d\n", n, r, permutasi(n, r));
    printf("Kombinasi dari %d dan %d adalah %d\n", n, r, kombinasi(n, r));

    return 0;
}
