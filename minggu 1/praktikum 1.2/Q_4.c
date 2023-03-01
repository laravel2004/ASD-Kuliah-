#include <stdio.h>

typedef struct {
    int day, month, year;
} Date;

int sameDay(Date, Date);

int main() {
    Date day1, day2;
    printf("MASUKAN TANGGAL PERTAMA :");
    scanf("%d", &day1.day);
    printf("MASUKAN BULAN PERTAMA :");
    scanf("%d", &day1.month);
    printf("MASUKAN TAHUN PETAMA :");
    scanf("%d", &day1.year);

    printf("MASUKAN TANGGAL KEDUA :");
    scanf("%d", &day2.day);
    printf("MASUKAN BULAN KEDUA :");
    scanf("%d", &day2.month);
    printf("MASUKAN TAHUN KEDUA :");
    scanf("%d", &day2.year);

    if(sameDay(day1, day2) == 1) {
        printf("It is the same day\n");
    }

}


int sameDay (Date day1, Date day2) {
    if((day1.day == day2.day) && (day1.month == day2.month) && (day1.year && day2.year)) {
        return 1;
    }
}