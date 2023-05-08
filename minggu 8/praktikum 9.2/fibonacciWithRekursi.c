#include <stdio.h>

int fibonacci(int);
void printFibonacci(int);

int main() {
    int n;
    printf("Masukkan jumlah bilangan dalam deret Fibonacci: ");
    scanf("%d", &n);
    printFibonacci(n);
    return 0;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void printFibonacci(int n) {
    int i;
    printf("Deret Fibonacci: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}

