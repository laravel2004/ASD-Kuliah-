#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *p;
Node *head;

void tampil();
void alokasi();
void insertAkhir();

int main() {
    int x;
    do
    {
        alokasi();
        insertAkhir();
        printf("Tambah Data ? [1/0] :");
        scanf("%d", &x);
    } while (x == 1);
    tampil();

}

void alokasi() {
    p = (Node*)malloc(sizeof(Node));
    printf("Masukan data yang dimasukkan :");
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
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = p;
    } 
}

void tampil() {
    Node *baca;
    baca = head;
    while(baca != NULL) {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}