#include <stdio.h>
#include <stdlib.h>

typedef struct simpul DNode;
struct simpul {
    DNode *prev;
    int data;
    DNode *next;
};

DNode *head;
DNode *p;
DNode *tail;
DNode *hapus;

void tampil();
void alokasi();
void insertAkhir();
void deleteAwal();

int main() {
  char jawab;
  printf("DDL Insert Akhir\n");
  do
  {
    alokasi();
    insertAkhir();
    printf("Mau lagi (y/t) ? ");
    fflush(stdin);
    scanf("%c", &jawab);
  } while ((jawab == 'y') || (jawab == 'Y'));
  tampil();
  deleteAwal();
  tampil();
}

void tampil() {
  DNode *baca;
  baca = head;
  while(baca != NULL) {
    printf("%d\n", baca->data);
    baca = baca->next;
  }
}

void alokasi() {
  p = (DNode*)malloc(sizeof(DNode));
  printf("Data yang mau disimpan? ");
  scanf("%d", &p->data);
  p->next = NULL;
  p->prev = NULL;
}

void insertAkhir() {
  if(head == NULL) {
    head = p;
  }
  else {
    tail = head;
    while(tail ->next != NULL) {
      tail = tail->next;
    }
    p->prev = tail;
    tail->next = p;
    tail = p;
  }
}

void deleteAwal() {
  printf("Setelah didelete Awal\n");
  hapus = head;
  head = hapus->next;
  hapus->next->prev = NULL;
  free(hapus);
  hapus = NULL;
}