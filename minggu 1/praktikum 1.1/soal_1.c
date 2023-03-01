#include <stdio.h>

#define MAX_MAHASISWA 100

struct Mahasiswa {
    char nama[50];
    float nilai_tugas;
    float nilai_uts;
    float nilai_uas;
    float nilai_akhir;
    char grade;
};

void input(struct Mahasiswa mahasiswa[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Masukkan data mahasiswa ke-%d:\n", i+1);
        printf("Nama: ");
        fflush(stdin);
        gets(mahasiswa[i].nama);
        printf("Nilai tugas: ");
        scanf("%f", &mahasiswa[i].nilai_tugas);
        printf("Nilai UTS: ");
        scanf("%f", &mahasiswa[i].nilai_uts);
        printf("Nilai UAS: ");
        scanf("%f", &mahasiswa[i].nilai_uas);
        printf("\n");
    }
}

void tampil(struct Mahasiswa mahasiswa[], int n) {
    printf("====================================================================\n");
    printf("| No |            Nama          | Tugas | UTS  | UAS | Akhir | Grade |\n");
    printf("====================================================================\n");
    for (int i = 0; i < n; i++) {
        float nilai_akhir = 0.2 * mahasiswa[i].nilai_tugas + 0.4 * mahasiswa[i].nilai_uts + 0.4 * mahasiswa[i].nilai_uas;
        mahasiswa[i].nilai_akhir = nilai_akhir;
        if (nilai_akhir >= 80) {
            mahasiswa[i].grade = 'A';
        } else if (nilai_akhir >= 70) {
            mahasiswa[i].grade = 'B';
        } else if (nilai_akhir >= 60) {
            mahasiswa[i].grade = 'C';
        } else if (nilai_akhir >= 50) {
            mahasiswa[i].grade = 'D';
        } else {
            mahasiswa[i].grade = 'E';
        }
        printf("|%3d | %-24s |  %3.1f | %3.1f | %3.1f | %4.1f |   %c   |\n",
            i+1, mahasiswa[i].nama,
            mahasiswa[i].nilai_tugas, mahasiswa[i].nilai_uts, mahasiswa[i].nilai_uas,
            mahasiswa[i].nilai_akhir, mahasiswa[i].grade);
    }
    printf("====================================================================\n");
}

int main() {
    int n;
    struct Mahasiswa mahasiswa[MAX_MAHASISWA];

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    input(mahasiswa, n);
    tampil(mahasiswa, n);

    return 0;
}