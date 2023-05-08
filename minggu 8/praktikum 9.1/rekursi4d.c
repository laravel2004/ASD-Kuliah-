#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void iterasi(int);
void rekursi(int);
int rekursiTail(int, int);
void menu();

int hasil, n;

int main() {
  do {
    menu();
  } while(1);
}

void menu() {
  int jawaban;
  printf("Pilih menu\n1. Iterasi\n2. Rekursi\n3. Rekursi tail\n4. Keluar\n\nMasukan pilihan anda :");
  scanf("%d", &jawaban);
  printf("Masukan data :");
  scanf("%d", &n);
  system("cls");
  switch(jawaban) {
    case 1 :
      iterasi(n);
      break;
    case 2 :
      rekursi(n);
      break;
    case 3 :
      hasil = rekursiTail(n, 1);
      printf("%d\n", hasil);
      break;
    case 4 :
      exit(0);
      break;
  }
}

void iterasi(int value) {
  int temp = 1;
  while(value >= 1) {
    temp = temp * value;
    value--;
  }
  printf("%d\n", temp);
}

void rekursi(int value) {
  static int temp = 1;
  if(value >= 1) {
    temp = temp * value;
    value--;
    rekursi(value);
  }
  else {
    printf("%d\n", temp);
  }
}

int rekursiTail(int n, int value) {
  if(n == 0) {
    return value;
  }
  else {
    return rekursiTail(n - 1, n * value);
  }
}