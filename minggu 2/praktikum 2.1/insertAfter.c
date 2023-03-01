#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

void tampil();
void alokasi();
void insertAfter();
void insertAkhir();

Node *head;
Node *p;
int main() {
    int x;
    do
    {
        alokasi();
        printf("Tambah Data ? [1/0] :");
        scanf("%d", &x);
        insertAkhir();
    } while (x == 1);
    insertAfter();
    tampil();
}

void tampil (){
    Node *baca;
    baca = head;
    while(baca != NULL) {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
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

void alokasi() {
    p = (Node *)malloc(sizeof(Node));
    printf("Masukan Data yang Dimasukkan : ");
    scanf("%d", &p->data);
    p->next = NULL;
}

void insertAfter() {
    Node *after;
    int x;
    printf("Masukan angka yang ingin disisipi : ");
    scanf("%d", &x);
    alokasi();
    after = head;
    while(after->data == x) {
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