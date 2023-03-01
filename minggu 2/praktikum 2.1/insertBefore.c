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
void insertBefore();
void insertAkhir();

int main() {
    int x;
    do
    {
        alokasi();
        printf("Tambah Data ? [1/0] :");
        scanf("%d", &x);
        insertAkhir();
    } while (x == 1);
    insertBefore();
    tampil();
}

void tampil() {
    Node *baca;
    baca = head;
    while(baca != NULL) {
        printf("%d", baca->data);
        baca = baca->next;
    }
}

void alokasi() {
    p = (Node *)malloc(sizeof(Node));
    printf("Masukan data yang dimasukkan : ");
    scanf("%d", &p->data);
    p->next = NULL;
}

void insertAkhir() {
    Node *tail;
    if(head == NULL) {
        head = p;
    }
    else {
        tail = head;
        while(tail->next  != NULL) {
            tail = tail->next;
        }
        tail->next = p;
    }
}

void insertBefore() {
    Node *bef;
    Node *pbef;
    int x;
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