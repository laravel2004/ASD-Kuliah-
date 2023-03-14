#include <stdio.h>
#include <stdlib.h>

void tampil();
void deleteAkhir();
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
    deleteAkhir();
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