#include <stdio.h>
void rekursi(int);

int main() {
  int nilai;
  printf("masukan nilai :");
  scanf("%d", &nilai);
  rekursi(nilai);
}

void rekursi(int value) {
  if(value >= 0) {
    printf("%d ", value);
    value -= 1;
    rekursi(value);
  }
}