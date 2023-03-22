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
DNode *after;
DNode *bef;


void menu();
void tampil();
void alokasi();
void insertAwal();
void insertAkhir();
void insertAfter();
void insertBefore();

int main() {
  menu();
}

void menu() {
  int pilihan;
  char jawab;
  while(pilihan != 5) {
    printf("\nMenu Insert\n1. Insert Awal\n2. Insert Akhir\n3. Insert After\n4. Insert Before\n5. Keluar\n\nMasukan Pilihan Anda :");
    scanf("%d", &pilihan);
    alokasi();
    switch(pilihan) {
      case 1:
        insertAwal();
        break;
      case 2 :
        insertAkhir();
        break;
      case 3 :
        insertAfter();
        break;
      case 4 :
        insertBefore();
        break;
    }
    system("cls");
    tampil();
  }
}

void tampil() {
  DNode *baca;
  baca = head;
  if(baca == NULL) {
    printf("Tidak ada DLL");
  }
  else {
    while(baca != NULL) {
      printf("%d\t", baca->data);
      baca = baca->next;
    }
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

void insertAfter() {
  int key;
  printf("Sisip after berapa? ");
  scanf("%d", &key);
  after = head;
  if(head == NULL) {
    printf("DLL Masih kosong");
  }
  else {
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
    if(after->next != NULL) {
      after->next->prev = p;
    }
    after->next = p;
  }
}

void insertBefore() {
  int key;
  printf("Sisip before berapa? ");
  scanf("%d", &key);
  bef = head;
  if(bef == NULL) {
    printf("DLL tidak bisa");
  }
  else if(bef->prev == NULL) {
    insertAwal();
  }
  else {
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
}