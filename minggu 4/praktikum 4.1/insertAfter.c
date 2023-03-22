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
DNode *after;
DNode *tail;

void tampil();
void alokasi();
void insertAfter();
void insertAkhir();

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
  insertAfter();
  tampil();
}

void tampil() {
  DNode *baca;
  baca = head;
  printf("Isi Dari DLL :\n");
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

void insertAfter() {
  int key;
  alokasi();
  printf("Sisip after berapa? ");
  scanf("%d", &key);
  after = head;
  while(after->data != key) {
    if(after->next == NULL) {
      printf("Key tidak ada");
      exit(0);
    }
    else {
      after = after->next;
    }
  }
  p->next = after->next;
  p->prev = after;
  after->next->prev = p;
  after->next = p;
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