#include <stdio.h>
#include <string.h>

void rekursi(char[], int);

int main() {
  char kalimat[32];
  int panjang;
  printf("masukan kalimat :");
  fflush(stdin);
  gets(kalimat);
  panjang = strlen(kalimat);
  rekursi(kalimat, panjang);
}

void rekursi(char nama[], int panjang) {
  if(panjang >= 0) {
    printf("%c", nama[panjang]);
    panjang--;
    rekursi(nama, panjang);
  }
}