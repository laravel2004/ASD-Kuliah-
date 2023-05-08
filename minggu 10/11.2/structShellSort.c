#include <stdio.h>
#include <stdlib.h>

typedef struct Siswa
{
  int no;
  char nama[50];
  int nilai;
} Siswa;


void inisialisasiData(Siswa *, int);
void shellSort(Siswa [], int);
void tampil(Siswa [], int);

int main() {
  int n;
  printf("Masukkan jumlah data siswa: ");
  scanf("%d", &n);

  Siswa Data[n];
  inisialisasiData(Data, n);
  shellSort(Data, n);
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

void shellSort(Siswa arr[], int n) {
    int i, j, gap;
    Siswa temp;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j-gap].no > temp.no; j -= gap) {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

void tampil(Siswa Data[], int n) {
  for(int i = 0; i < n; i++) {
    printf("Nomor: %d\n", Data[i].no);
    printf("Nama : %s\n", Data[i].nama);
    printf("Nilai: %d\n", Data[i].nilai);
    printf("\n");
  }
}
