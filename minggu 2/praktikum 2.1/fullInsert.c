#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *head;
Node *p;

void tampil();
void alokasi();
void insertAwal();
void insertAkhir();
void insertAfter();
void insertBefore();

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

void tampil() {
    Node *baca;
    baca = head;
    printf("Nilai Yang kamu miliki sekarang : \n");
    while(baca != NULL) {
        printf("%d\t", baca->data);
        baca = baca-> next;
    }
    printf("\n");
}

void alokasi() {
    p = (Node *)malloc(sizeof(Node));
    printf("Masukan nilai yang dimaksukkan : ");
    scanf("%d", &p->data);
    p->next = NULL;
}

void insertAwal() {
    if(head != NULL) {
        p->next = head;
    }
    head = p;
    p = NULL;
}

void insertAkhir() {
    Node *tail;
    if(head == NULL) {
        head = p;
    }
    else {
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
    if(head == NULL) {
        puts("pilihan anda salah");
    }
    else{
        printf("Masukan angka yang ingin disisipi : ");
        scanf("%d", &x);
        alokasi();
        after = head;
        while(after->data != x) {
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
}

void insertBefore() {
    Node *bef;
    Node *pbef;
    int x;
    if(head == NULL) {
        puts("pilihan anda salah");
    }
    else {
        printf("Masukan angka yang ingin disisipi : ");
        scanf("%d", &x);
        alokasi();
        bef = head;
        while(bef->data != x) {
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