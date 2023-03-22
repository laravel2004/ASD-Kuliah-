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
DNode *tail;
DNode *after;
DNode *bef;
DNode *erase;


void menuInsert();
void tampil();
void alokasi();
void insertAwal();
void insertAkhir();
void insertAfter();
void insertBefore();
void menuDelete();
void deleteAwal();
void deleteAkhir();
void deleteTertentu();

int main() {
  int pilihan;
  while(pilihan != 3) {
    printf("\nPilihan Menu\n1. Insert\n2. Delete\n3. Keluar\n\nMasukan pilihan anda : "); 
    scanf("%d", &pilihan);
    system("cls");
    switch(pilihan) {
      case 1 : 
        menuInsert();
        break;
      case 2 :
        menuDelete();
        break;
    }
  }
  
}

void menuDelete() {
  int pilihan;
  printf("\nMenu Delete\n1. Delete Awal\n2. Delete Akhir\n3. Delete Tertentu\n\nMasukan Pilihan Anda : ");
  scanf("%d", &pilihan);
  switch(pilihan) {
    case 1 :
      deleteAwal();
      break;
    case 2 :
      deleteAkhir();
      break;
    case 3 :
      deleteTertentu();
      break;
  }
  system("cls");
  tampil();
}

void menuInsert() {
  int pilihan;
  printf("\nMenu Insert\n1. Insert Awal\n2. Insert Akhir\n3. Insert After\n4. Insert Before\n\nMasukan Pilihan Anda :");
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
    while(after->data.no != key) {
      if(after->next == NULL) {
        printf("Key tidak ada");
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
    while(bef->data.no != key) {
      if(bef->next == NULL) {
        printf("Key tidak ada");
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

void deleteAwal() {
  if(head == NULL) {
    puts("DLL Kosong");
  }
  else if(head->next == NULL) {
    free(head);
    head = NULL;
    tampil();
  } else {
    erase = head;
    head = erase->next;
    erase->next->prev = NULL;
    free(erase);
    erase = NULL;
  }
}

void deleteAkhir(){
  if(head == NULL) {
        puts("DLL Kosong");
    } else {
        if(head->next == NULL) {
            deleteAwal;
        } else {
            erase = head;

            while(erase->next != NULL) {
                erase = erase->next;
            }
            erase->prev->next = NULL;
            free(erase);
            erase = NULL;
        }
    }
}

void deleteTertentu() {
  int key;
    printf("Input key: "); scanf("%d", &key);

    if(head == NULL) {
        puts("DLL Kosong");
    } else {
        if(head->data.no == key) {
            deleteAwal();
        } else {
            erase = head;
            while(erase->data.no != key) {
                if(erase->next == NULL) {
                    puts("Key tidak ada");
                } else {
                    erase = erase->next;
                }
            }

            if(erase->next == NULL) {
                deleteAkhir();
            } else {
                erase->prev->next = erase->next;
                erase->next->prev = erase->prev;
                free(erase);
                erase = NULL;
            }
        }
    }
}

