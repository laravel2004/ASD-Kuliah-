#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int no;
  float nilai;
  char nama[20];
}Siswa;

typedef struct simpul Node;
struct simpul {
    Siswa data;
    Node *next;
};

Node *head;
Node *p;

void tampil();
void alokasi();
void insertAwal();
void insertAkhir();
void insertAfter();
void insertBefore();
void deleteAwal();
void deleteAkhir();
void deleteTertentu();
void switchDelete(int);
void switchInsert(int);

int main() {
    int menuInsert, menuUtama, menuDelete;
    while(menuUtama != 3) {
        printf("\nPILIH MENU : \n");
        printf("1. Insert\n2. Delete\n 3. exit\n");
        printf("Pilih Salah satu : ");
        scanf("%d", &menuUtama);
        if(menuUtama == 1) {
          printf("1.insert awal\n2.insert akhir\n3.insert after\n4.insert before\n");
          printf("PILIH SALAH SATU : ");
          scanf("%d", &menuInsert);
          switchInsert(menuInsert);
        }
        else if(menuUtama == 2){
          if(head != NULL) {
            printf("1. Delete Awal\n2. Delete Akhir\n 3.DeleteTertentu\n");
            scanf("%d", &menuDelete);
            switchDelete(menuDelete);
          }
          else {
            system("cls");
            printf("SSL KOSONG ");
          }
        }
    }
}

void switchInsert(int x) {
  int y;
  switch(x){
    case 1:
      do
      {
        alokasi();
        printf("Tambah Data ? [1/0] :");
        scanf("%d", &y);
        insertAwal();
      } while (y == 1);
      break;    
    case 2:
      do
      {
        alokasi();
        printf("Tambah Data ? [1/0] :");
        scanf("%d", &y);
        insertAkhir();
      } while (y == 1);
      break;
    case 3:
      insertAfter();
      break;
    case 4:
      insertBefore();
      break;
  }
  system("cls");
  tampil();
}

void switchDelete(int x) {
  switch(x) {
    case 1:
      deleteAwal();
      break;
    case 2 :
      deleteAkhir();
      break;
    case 3 :
      deleteTertentu();
      break;
  }
  tampil();
}


void deleteAwal() {
  Node * hapus;
  hapus = head;
  if(hapus->next == NULL) {
    head = NULL;
    printf("Menghapus data dari posisi awal\n");
  }
  else {
    head = hapus->next;
    free(hapus);
    hapus = NULL;
    system("cls");
    printf("Menghapus data dari posisi awal\n");
  }
}

void deleteAkhir() {
  Node * hapus;
  hapus = head;
  if(hapus->next == NULL) {
    head = NULL;
    system("cls");
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
   hapus = NULL;
   ph->next = NULL;
   system("cls");
   printf("Menghapus data dari posisi awal\n");
  }
}

void deleteTertentu() {
  Node * hapus;
  hapus = head;
  int x;
  printf("nilai yang mau didelete : ");
  scanf("%d", &x);
  if(hapus->data.no == x) {
    deleteAwal();
  }
  else {
    Node *ph;
    while(hapus->data.no != x) {
    if(hapus->next == NULL) {
      system("cls");
      printf("Tidak ada");
    }
    ph = hapus;
    hapus = hapus->next;
   }
   ph->next = hapus->next;
   free(hapus);
   hapus = NULL;
   system("cls");
   printf("Menghapus data dari posisi awal\n");
  }
}

void tampil() {
    Node *baca;
    baca = head;
    if(baca == NULL) {
      printf("SSL KOSONG\n");
    }
    else {
      printf("Nilai Yang kamu miliki sekarang : \n");
      while(baca != NULL) {
          printf("%d\t", baca->data.no);
          printf("%s\t", baca->data.nama);
          printf("%.2f\t", baca->data.nilai);
          printf("\n");
          baca = baca-> next;
      }
      printf("\n");
    }
}

void alokasi() {
    p = (Node *)malloc(sizeof(Node));
    printf("Masukan nilai yang dimaksukkan : \n");
    printf("No : ");
    scanf("%d", &p->data.no);
    printf("Nama : ");
    fflush(stdin);
    gets(p->data.nama);
    printf("Nilai : ");
    scanf("%f", &p->data.nilai);
    p->next = NULL;
}

void insertAwal() {
    if(head != NULL) {
        p->next = head;
    }
    head = p;
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

void insertAfter() {
    Node *after;
    int x;
    if(head == NULL) {
        puts("pilihan anda salah");
    }
    else{
        printf("Masukan angka yang ingin disisipi : ");
        scanf("%d", &x);
        alokasi();
        after = head;
        while(after->data.no != x) {
            if(after->next == NULL) {
                puts("Inputanmu salah bree!");
            }
            else {
                after = after->next;
            }
        }
        p->next = after->next;
        after->next = p;
    }
}

void insertBefore() {
    Node *bef;
    Node *pbef;
    int x;
    if(head == NULL) {
        puts("pilihan anda salah");
    }
    else {
        printf("Masukan angka yang ingin disisipi : ");
        scanf("%d", &x);
        alokasi();
        if(head->data.no == x) {
            p->next = head;
            head = p;
        }
        else {
            bef = head;
            while(bef->data.no != x) {
                if(bef->next == NULL) {
                    puts("Inputan kamu salah bree!");
                }
                else {
                    pbef = bef;
                    bef = bef->next;
                }
            }
            p->next = bef;
            pbef->next = p;
        }
    }
}