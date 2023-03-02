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
void insertAfter();
void insertAkhir();

int main() {
    int x;
    do
    {
        alokasi();
        printf("Tambah data ? [1/0] : ");
        scanf("%d", &x);
        insertAkhir();
    } while (x == 1);
    insertAfter();
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

void insertAkhir() {
    if(head == NULL) {
        head = p;
    }
    else {
        Node *tail;
        tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = p;
    }   
}

void insertAfter() {
    Node *after;
    int x;
    printf("Masukan angka yang ingin disisipi : ");
    scanf("%d", &x);
    alokasi();
    after = head;
    while(after->siswa.no != x) {
        if(after->next == NULL) {
            puts("Inputanmu salah bree!");
        }
        else {
            after = after->next;
        }
    }
    p->next = after->next;
    after->next = p;
}