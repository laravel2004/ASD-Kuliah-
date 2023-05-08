#include <stdio.h>

int rekursi(int, int);

int main() {
  int n, hasil;
  printf("masukan data : ");
  scanf("%d", &n);
  hasil = rekursi(n, 1);
  printf("%d", hasil);
}

int rekursi(int n, int hasil) {
  if(n == 0) {
    return hasil;
  }
  else {
    return rekursi(n - 1, n * hasil);
  }
}