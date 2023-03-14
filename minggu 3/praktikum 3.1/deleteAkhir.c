#include <stdio.h>
#include <stdlib.h>

void tampil();
void deleteAkhir();
void alokasi();
void insertAkhir();

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
  while(head != NULL) {
    deleteAkhir();
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
void deleteAkhir() {
  Node * hapus;
  hapus = head;
  if(hapus->next == NULL) {
    head = NULL;
    printf("Menghapus data dari posisi awal\n");
    printf("Kosong");
  }
  else {
    Node *ph;
   while(hapus->next != NULL) {
    ph = hapus;
    hapus = hapus->next;
   }
   free(hapus);
   ph->next = NULL;
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