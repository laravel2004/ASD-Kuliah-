#include <stdio.h>
#include <string.h>

typedef struct date {
    int day;
    int month;
    int year;
} Date;

typedef struct kantor {
    char nama[30];
    char jenisKelamin[15];
    Date tanggalLahir;
    int gaji;
} Pegawai;

void input(Pegawai*, int*);
void output(Pegawai*, int*);
int main() {
    int jumlahPegawai;
    printf("Berapa jumlah pegawai  : ");
    scanf("%d", &jumlahPegawai);
    Pegawai sipil[jumlahPegawai];
    input(sipil, &jumlahPegawai);
    output(sipil, &jumlahPegawai);
}

void input(Pegawai *sipil, int *n) {
    char kelamin;
    for(int i = 0; i < *n; i++) {
        printf("Data Pegawai ke - %d\n", i + 1);
        printf("Nama\t\t\t : ");
        fflush(stdin);
        gets(sipil[i].nama);
        printf("Tgl lahir (dd-mm-yyyy)\t : ");
        scanf("%d-%d-%d", &sipil[i].tanggalLahir.day, &sipil[i].tanggalLahir.month, &sipil[i].tanggalLahir.year);
        printf("Jenis kelamin [L / P]\t : ");
        fflush(stdin);
        scanf("%c", &kelamin);
        printf("Gaji/bulan\t\t : ");
        scanf("%d", &sipil[i].gaji);
        if(kelamin == 'l'  || kelamin == 'L') {
            strcpy(sipil[i].jenisKelamin, "Laki - laki");
        }
        else if(kelamin == 'p' || kelamin == 'P') {
            strcpy(sipil[i].jenisKelamin, "Perempuan");
        }
    }
}
void output(Pegawai *sipil, int *n) {
    printf("\n\nData pegawai yang telah diinputkan\n\n");
    for(int i = 0; i < *n; i++) {
        printf("No id\t\t\t : %d\n", i + 1);
        printf("Nama\t\t\t : %s\n", sipil[i].nama);
        printf("Tgl Lahir\t\t : %d-%d-%d\n", sipil[i].tanggalLahir.day, sipil[i].tanggalLahir.month, sipil[i].tanggalLahir.year);
        printf("Jenis Kelamin\t\t : %s\n", sipil[i].jenisKelamin);
        printf("Gaji/Bln\t\t : %d\n", sipil[i].gaji);

    }
}