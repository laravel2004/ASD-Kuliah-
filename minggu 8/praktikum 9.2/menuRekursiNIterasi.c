#include <stdio.h>
#include <stdlib.h>

int fibonacci(int);
void printFibonacci(int);
void fibonacciIterasi(int);
void menu();

int nilai;

int main() {
  do {
    menu();
  } while(1);
}

void menu() {
  int jawab;
  printf("Pilih menu\n\n1. Iterasi\n2. Rekursi\n3. Keluar\n\nMasukan pilihan anda : ");
  scanf("%d", &jawab);
  printf("berapa banyak yang ingin dimasukkan : ");
  scanf("%d", &nilai);
  switch(jawab) {
    case 1 :
      fibonacciIterasi(nilai);
      break;
    case 2 :
      printFibonacci(nilai);
      break;
    case 3 :
      exit(0);
      break;
  }
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

void fibonacciIterasi(int n) {
    int i, a = 0, b = 1, c;
    printf("Deret Fibonacci: %d %d ", a, b);
    for (i = 2; i < n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

