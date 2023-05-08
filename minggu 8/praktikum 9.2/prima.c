#include <stdio.h>
#include <math.h>

int isPrime(int n, int i) {
    if (n <= 2) {
        if (n == 2) {
            return 1;
        } else {
            return 0;
        }
    } else if (i > sqrt(n)) {
        return 1;
    } else if (n % i == 0) {
        return 0;
    } else {
        return isPrime(n, i + 1);
    }
}

int main() {
    int n;
    printf("Masukkan bilangan yang ingin diperiksa: ");
    scanf("%d", &n);
    if (isPrime(n, 2)) {
        printf("%d adalah bilangan prima.\n", n);
    } else {
        printf("%d bukan bilangan prima.\n", n);
    }
    return 0;
}
