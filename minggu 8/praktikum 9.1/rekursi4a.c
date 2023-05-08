#include <stdio.h>

void iterasi(int);

int main() {
  int nilai;
  printf("masukan nilai : ");
  scanf("%d", &nilai);
  iterasi(nilai);
}

void iterasi(int value) {
  int temp = 1;
  while(value >= 1) {
    temp = temp * value;
    value--;
  }
  printf("%d", temp);
}