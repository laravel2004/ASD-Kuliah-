#include <stdio.h>
#include <stdlib.h>

void tampil();
void insertAkhir();
void alokasi();
void deleteTertentu();
void deleteAwal();

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *p;
Node *head;

int main() {
  char x = 1;
  while(x == 1) {
    alokasi();
    insertAkhir();
    printf("Lagi [1 / 0] : ");
    scanf("%d", &x);
  }
  deleteTertentu();
}

void tampil() {
  Node *baca;
  baca = head;
  while(baca != NULL) {
      printf("%d\n", baca->data);
      baca = baca->next;
  }
}
void deleteTertentu() {
  Node * hapus;
  hapus = head;
  int x;
  printf("nilai yang mau didelete : ");
  scanf("%d", &x);
  if(hapus->data == x) {
    deleteAwal();
  }
  else {
    Node *ph;
    while(hapus->data != x) {
    if(hapus->next == NULL) {
      printf("Tidak ada");
    }
    ph = hapus;
    hapus = hapus->next;
   }
   ph->next = hapus->next;
   free(hapus);
   hapus = NULL;
   printf("Menghapus data dari posisi awal\n");
   tampil();
  }
}

void deleteAwal() {
  Node * hapus;
  hapus = head;
  if(hapus->next == NULL) {
    head = NULL;
    printf("Menghapus data dari posisi awal\n");
    printf("Kosong");
  }
  else {
    head = hapus->next;
    free(hapus);
    hapus = NULL;
    printf("Menghapus data dari posisi awal\n");
    tampil();
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
  p = (Node*)malloc(sizeof(Node));
  printf("Masukan data yang dimasukkan :");
  scanf("%d", &p->data);
  p->next = NULL;
}