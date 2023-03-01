#include <stdio.h>

typedef struct mahasiswa {
    char nama[30];
    char grade;
    int nilaiTugas, nilaiUAS, nilaiUTS;
    float nilaiAkhir;
} Mahasiswa;

int input(Mahasiswa*, int*);
void tampil(Mahasiswa*, int*);
int main() {
    int n;
    printf("Berapa jumlah mahasiswa :");
    scanf("%d", &n);
    Mahasiswa pens[n];
    printf("\nMasukan data mahasiswa\n");
    input(pens, &n);
    tampil(pens, &n);

}

int input(Mahasiswa *pens, int *n) {
    for(int i = 0; i < *n; i++) {
        printf("\nMahasiswa ke - %d\n", i + 1);
        printf("Nama\t\t :");
        fflush(stdin);
        gets(pens[i].nama);
        printf("Nilai tugas\t :");
        scanf("%d", &pens[i].nilaiTugas);
        printf("Nilai UTS\t :");
        scanf("%d", &pens[i].nilaiUTS);
        printf("Nilai UAS\t :");
        scanf("%d", &pens[i].nilaiUAS);
        pens[i].nilaiAkhir = pens[i].nilaiTugas * 0.2 + pens[i].nilaiUTS * 0.4 + pens[i].nilaiUAS * 0.4;
        if(pens[i].nilaiAkhir >= 80) {
            pens[i].grade = 'A';
        }
        else if(pens[i].nilaiAkhir >= 70) {
            pens[i].grade = 'B';
        }
        else if(pens[i].nilaiAkhir >= 60) {
            pens[i].grade = 'C';
        }
        else if(pens[i].nilaiAkhir >= 50) {
            pens[i].grade = 'D';
        }
        else if(pens[i].nilaiAkhir < 50) {
            pens[i].grade = 'E';
        }
    }
}

void tampil(Mahasiswa *pens, int *n) {
    float nilai = 0;
    int max = 0;
    printf("\n\t\t\tDAFTAR NILAI\n");
    printf("\t\tMATA KULIAH KONSEP PEMROGRAMAN\n\n");
    printf("===========================================================\n");
    printf("No\t Mahasiswa\t Tugas\t UTS\t UAS\t AKHIR\t Grade\n");
    printf("===========================================================\n");
    int i;
    for(i = 0; i < *n; i++) {
        printf("%d\t %s\t\t %d\t %d\t %d\t %.2f\t %c\n", i + 1, pens[i].nama, pens[i].nilaiTugas, pens[i].nilaiUTS, pens[i].nilaiUAS, pens[i].nilaiAkhir, pens[i].grade);
        if(nilai < pens[i].nilaiAkhir) {
            nilai = pens[i].nilaiAkhir;
            max = i;
        }
    }
    printf("\n\nTotal Mahasiswa : %d\n\n", i);
    printf("Nilai Tertinggi\n");
    printf("Nama : %s\nNilai : %.2f\n", pens[max].nama, pens[max].nilaiAkhir);
}