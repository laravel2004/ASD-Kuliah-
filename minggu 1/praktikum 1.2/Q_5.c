#include <stdio.h>

typedef struct {
    char nama[30];
    int umur;
} Student;

int isYounger(Student, Student);

int main() {
    Student stud1, stud2;
    printf("MASUKAN NAMA STUDENT 1 :");
    fflush(stdin);
    gets(stud1.nama);
    printf("MASUKAN UMUR STUDENT 1 :");
    scanf("%d", &stud1.umur);
    printf("\n");
    printf("MASUKAN NAMA STUDENT 2 :");
    fflush(stdin);
    gets(stud2.nama);
    printf("MASUKAN UMUR STUDENT 2 :");
    scanf("%d", &stud2.umur);
    if(isYounger(stud1, stud2) == 1) {
        printf("%s Lebih Tua Daripada %s", stud1.nama, stud2.nama);
    }
    else if(isYounger(stud1, stud2) == 0) {
        printf("%s Lebih Muda Daripada %s", stud1.nama, stud2.nama);
    }
    else {
        printf("Umur mereka sama");
    }
}

int isYounger(Student stud1, Student stud2) {
    if(stud1.umur >= stud2.umur) {
        return 1;
    }
    else if(stud1.umur == stud2.umur) {
        return 2;
    }
    else {
        return 0;
    }
}