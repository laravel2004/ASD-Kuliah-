#include <stdio.h>
#include <stdlib.h>

typedef struct Siswa
{
  int no;
  char nama[50];
  int nilai;
} Siswa;


void inisialisasiData(Siswa *, int);
void shellSort(Siswa [], int, int);
void tampil(Siswa [], int);
void swapElement(Siswa*, Siswa*);

int main() {
  int n, jwb;
  printf("Masukkan jumlah data siswa: ");
  scanf("%d", &n);

  Siswa Data[n];
  inisialisasiData(Data, n);
  printf("1. Ascending\n2. Descending\n");
  scanf("%d", &jwb);
  shellSort(Data, n, jwb);
  tampil(Data, n);

  return 0;
}


void inisialisasiData(Siswa Data[], int n) {
  for(int i = 0; i < n; i++) {
    printf("Data siswa ke %d:\n", i+1);
    printf("Masukkan nomor: ");
    scanf("%d", &Data[i].no);
    printf("Masukkan nama: ");
    fflush(stdin);
    gets(Data[i].nama);
    printf("Masukkan nilai: ");
    scanf("%d", &Data[i].nilai);
  }
}

void shellSort(Siswa a[], int max, int jwb) {
    int range = max, didSwap;
    while (range > 1) {
        range = range / 2;
        didSwap = 1;
        while (didSwap) {
            didSwap = 0;
            for (int i = 0; i < (max - range); ++i) {
                if (a[i].no > a[i + range].no) {
                    swapElement(&a[i], &a[i + range]);
                    didSwap = 1;
                }
            }
        }
    }
}

void swapElement(Siswa *x, Siswa *y) {
    Siswa temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void tampil(Siswa Data[], int n) {
  for(int i = 0; i < n; i++) {
    printf("Nomor: %d\n", Data[i].no);
    printf("Nama : %s\n", Data[i].nama);
    printf("Nilai: %d\n", Data[i].nilai);
    printf("\n");
  }
}
