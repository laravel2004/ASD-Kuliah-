#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int no;
  float nilai;
  char nama[20];
}Siswa;

typedef struct simpul DNode;
struct simpul {
    DNode *prev;
    Siswa data;
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
      printf("%d\t", baca->data.no);
      printf("%s\t", baca->data.nama);
      printf("%.2f\t", baca->data.nilai);
      printf("\n");
      baca = baca->next;
  }
}

void alokasi() {
  p = (DNode*)malloc(sizeof(DNode));
  printf("Data yang mau disimpan?\n ");
  printf("No : ");
  scanf("%d", &p->data.no);
  printf("Nama : ");
  fflush(stdin);
  gets(p->data.nama);
  printf("Nilai : ");
  scanf("%f", &p->data.nilai);
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