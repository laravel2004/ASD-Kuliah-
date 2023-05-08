#include <stdio.h>

void rekursi(int);

int main() {
  int nilai;
  printf("masukan data : ");
  scanf("%d", &nilai);
  rekursi(nilai);
}

void rekursi(int value) {
  static int temp = 1;
  if(value >= 1) {
    temp = temp * value;
    value--;
    rekursi(value);
  }
  else {
    printf("%d", temp);
  }
}