#include <stdio.h>
#include <stdlib.h>

void tampil();
void deleteAfter();
void alokasi();
void insertAkhir();
void deleteAwal();

typedef struct {
  int no;
  float nilai;
  char nama[20];
} Siswa;

typedef struct simpul Node;
struct simpul {
    Siswa data;
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
    deleteAfter();
  }
 
}

void tampil() {
    Node *baca;
    baca = head;
    printf("No\t Nama\t Nilai\n");
    while(baca != NULL) {
        printf("%d\t", baca->data.no);
        printf("%s\t", baca->data.nama);
        printf("%.2f\t", baca->data.nilai);
        printf("\n");
        baca = baca->next;
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

void deleteAfter() {
  Node * hapus;
  Node *phapus;
  hapus = head;
  int x;
  printf("nilai yang mau didelete : ");
  scanf("%d", &x);
  if(hapus->data.no == x) {
    if(hapus->next == NULL) {
      printf("Tidak Bisa");
    }
    else {
      phapus = hapus->next->next;
      hapus->next = phapus;
      free(hapus);
      hapus = NULL;
      tampil();
    }
  }
  else {
    while(hapus->data.no != x) {
      if(hapus->next == NULL) {
        printf("Tidak ada");
      }
      phapus = hapus;
      hapus = hapus->next;
   }
   hapus->next = phapus->next;
   free(phapus);
   phapus = NULL;
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
  printf("Masukan data yang dimasukkan :\n");
  printf("No : ");
  scanf("%d", &p->data.no);
  printf("Nama : ");
  fflush(stdin);
  gets(p->data.nama);
  printf("Nilai : ");
  scanf("%f", &p->data.nilai);
  p->next = NULL;
}