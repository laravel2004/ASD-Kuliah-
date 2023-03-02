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
void insertBefore();
void insertAkhir();
void insertAwal();
void insertAfter();

int main() {
    int x;
    int y;
    while(x != 5) {
        printf("\nPILIH MENU : \n");
        printf("1.insert awal\n2.insert akhir\n3.insert after\n4.insert before\n5.keluar\n");
        printf("PILIH SALAH SATU : ");
        scanf("%d", &x);
        switch(x){
            case 1:
                do
                {
                    alokasi();
                    printf("Tambah Data ? [1/0] :");
                    scanf("%d", &y);
                    insertAwal();
                } while (y == 1);
                system("cls");
                tampil();
                break;
                
            case 2:
                do
                {
                    alokasi();
                    printf("Tambah Data ? [1/0] :");
                    scanf("%d", &y);
                    insertAkhir();
                } while (y == 1);
                system("cls");
                tampil();
                break;
            case 3:
                insertAfter();
                system("cls");
                tampil();
                break;
            case 4:
                insertBefore();
                system("cls");
                tampil();
                break;
            default:
                system("cls");
                puts("Inputan salah");
                break;
        }
    }
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

void insertBefore() {
    Node *bef;
    Node *pbef;
    int x;
    printf("Masukan angka yang ingin disisipi : ");
    scanf("%d", &x);
    alokasi();
    if(head->siswa.no == x) {
        p->next = head;
        head = p;
    }
    else {
        bef = head;
        while(bef->siswa.no != x) {
            if(bef->next == NULL) {
                puts("Inputan kamu salah bree!");
            }
            else {
                pbef = bef;
                bef = bef->next;
            }
        }
        p->next = bef;
        pbef->next = p;
    }
}