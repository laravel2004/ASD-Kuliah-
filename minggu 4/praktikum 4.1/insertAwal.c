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

void tampil();
void alokasi();
void insertAwal();

int main() {
  char jawab;
  printf("DDL Insert Awal\n");
  do
  {
    alokasi();
    insertAwal();
    printf("Mau lagi (y/t) ? ");
    fflush(stdin);
    scanf("%c", &jawab);
  } while ((jawab == 'y') || (jawab == 'Y'));
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

void insertAwal() {
  if(head != NULL) {
    p->next = head;
    head->prev = p;
  }
  head = p;
}