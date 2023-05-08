#include <stdio.h>

int fpb(int, int);

int main() {
    int bilangan1, bilangan2;
    printf("Masukkan bilangan pertama: ");
    scanf("%d", &bilangan1);
    printf("Masukkan bilangan kedua: ");
    scanf("%d", &bilangan2);
    printf("FPB dari %d dan %d adalah %d", bilangan1, bilangan2, fpb(bilangan1, bilangan2));
    return 0;
}

int fpb(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return fpb(b, a % b);
    }
}

