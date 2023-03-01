#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *p;
Node *head;

void alokasi();
void insertAwal();
void tampil();
int main() {
    int x;
    do
    {
        alokasi();
        insertAwal();
        printf("Tambah Data ? [1/0] :");
        scanf("%d", &x);
    } while (x == 1);
    
    tampil();
}

void alokasi() {
    p = (Node*) malloc(sizeof(Node));
    printf("Nilai yang mau dimasukkan :");
    scanf("%d", &p->data);
    p->next=NULL;
}

void insertAwal() {
    if(head != NULL) {
        p->next = head;
    }
    head = p;
    p = NULL;
}

void tampil() {
    Node *baca;
    baca = head;
    while(baca != NULL) {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}