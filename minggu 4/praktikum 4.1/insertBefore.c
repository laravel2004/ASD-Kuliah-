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
DNode *bef;
DNode *tail;

void tampil();
void alokasi();
void insertBefore();
void insertAkhir();

int main() {
  char jawab;
  printf("DDL Insert Before\n");
  do
  {
    alokasi();
    insertAkhir();
    printf("Mau lagi (y/t) ? ");
    fflush(stdin);
    scanf("%c", &jawab);
  } while ((jawab == 'y') || (jawab == 'Y'));
  tampil();
  insertBefore();
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

void insertBefore() {
  int key;
  alokasi();
  printf("Sisip before berapa? ");
  scanf("%d", &key);
  bef = head;
  while(bef->data != key) {
    if(bef->next == NULL) {
      printf("Key tidak ada");
      exit(0);
    }
    else {
      bef = bef->next;
    }
  }
  p->next = bef;
  p->prev = bef->prev;
  bef->prev->next = p;
  bef->prev = p;
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