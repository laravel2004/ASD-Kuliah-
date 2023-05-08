#include <stdio.h>

void fibonacci(int);

int main() {
    int n;
    printf("Masukkan jumlah bilangan dalam deret Fibonacci: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}

void fibonacci(int n) {
    int i, a = 0, b = 1, c;
    printf("Deret Fibonacci: %d %d ", a, b);
    for (i = 2; i < n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

