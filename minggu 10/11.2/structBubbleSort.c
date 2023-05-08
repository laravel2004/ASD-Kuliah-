#include <stdio.h>
#include <stdlib.h>

typedef struct Siswa
{
  int no;
  char nama[50];
  int nilai;
} Siswa;


void inisialisasiData(Siswa *, int);
void bubbleSort(Siswa [], int);
void tampil(Siswa [], int);

int main() {
  int n;
  printf("Masukkan jumlah data siswa: ");
  scanf("%d", &n);

  Siswa Data[n];
  inisialisasiData(Data, n);
  bubbleSort(Data, n);
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

void bubbleSort(Siswa arr[], int n) {
    int i, j;
    Siswa temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].no > arr[j+1].no) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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
