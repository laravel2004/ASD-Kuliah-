#include <stdio.h>
void rekursi(int);
int temp = 0;

int main() {
  int nilai;
  printf("masukan nilai : ");
  scanf("%d", &nilai);
  rekursi(nilai);
}

void rekursi(int value) {
  if(temp <= value) {
    printf("%d ", temp);
    temp++;
    rekursi(value);
  }
}