#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int no;
    char nama[20];
    float nilai;
}Data;

typedef struct simpul Node;
struct simpul {
    Data siswa;
    Node *next;
};

Node *head;
Node *p;

void tampil();
void alokasi();
void insertAwal();

int main() {
    int x;
    do
    {
        alokasi();
        insertAwal();
        printf("Tambah data ? [1/0] : ");
        scanf("%d", &x);
    } while (x != 0);
    tampil();
}

void alokasi(){
    p = (Node *)malloc(sizeof(Node));
    printf("Masukan no siswa : ");
    scanf("%d", &p->siswa.no);
    printf("Masukan nama siswa : ");
    fflush(stdin);
    gets(p->siswa.nama);
    printf("Berapa nilai siswa : ");
    scanf("%f", &p->siswa.nilai);
    p->next = NULL;
}

void tampil() {
    Node *baca;
    baca = head;
    printf("No\t Nama\t Nilai\n");
    while(baca != NULL) {
        printf("%d\t", baca->siswa.no);
        printf("%s\t", baca->siswa.nama);
        printf("%.2f\t", baca->siswa.nilai);
        printf("\n");
        baca = baca->next;
    }
}

void insertAwal() {
    if(head != NULL) {
        p->next = head;
    }
    head = p;
}