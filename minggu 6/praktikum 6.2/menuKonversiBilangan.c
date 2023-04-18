#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef char ItemType;
typedef struct {
  ItemType data[MAX];
  int count;
} stack;

void inisialisasi(stack *);
int kosong(stack*);
int penuh(stack *);
void push(ItemType, stack*);
ItemType pop(stack*);
void biner(int, stack *);
void tampil(stack *);
void menu();
void oktal(int, stack *);
void heksa(int, stack *);


stack tumpukan;

int main() {
  do {
     inisialisasi(&tumpukan);
  menu();
  } while(1);
 
}

void menu() {
  int jawab, nilai;
  printf("\nKONVERSI BILANGAN DESIMAL\n");
  printf("Masukan bilangan desimal yang ingin dikonversikan : ");
  scanf("%d", &nilai);
  printf("MENU KONVERSI\n\n1. BINER\n2. OKTAL\n3. HEKSADESIMAL\n4. Keluar\n\nMasukan Pilihan Anda : ");
  scanf("%d", &jawab);
  switch(jawab) {
    case 1 :
      biner(nilai, &tumpukan);
      break;
    case 2 :
      oktal(nilai, &tumpukan);
      break;
    case 3 :
      heksa(nilai, &tumpukan);
      break;
    case 4 :
      exit(0);
      break;
  }
  tampil(&tumpukan);

}

void biner(int nilai, stack *s) {
  for(int i = 0; nilai > 0; i++) {
    
    push(nilai % 2, s);
    nilai = nilai / 2;
  }
}

void oktal(int nilai, stack *s) {
  for(int i = 0; nilai > 0; i++) {
    push(nilai % 8, s);
    nilai = nilai / 8;
  }
}

void heksa(int nilai, stack *s) {
  for(int i = 0; nilai > 0; i++) {
    push(nilai % 16, s);
    nilai = nilai / 16;
  }
}

int kosong(stack *s) {
  return s->count == 0 ? 1 : 0 ;
}

int penuh(stack *s) {
  return s->count == MAX ? 1 : 0 ;
}

void inisialisasi(stack *s) {
  s->count == 0;
}

void push(ItemType x, stack *s) {
  if(penuh(s)) {
    printf("Stack overflow");
  }
  else {
    s->data[s->count] = x;
    s->count++;
  }
}

ItemType pop(stack *s) {
  ItemType temp;
  if(kosong(s)) {
    printf("STACK UNDERFLOW");
  }
  else {
    --s->count;
    temp = s->data[s->count];
    return temp;
  }
}

void tampil(stack *s) {
  if(kosong(s)) {
    printf("STACK UNDERFLOW\n");
  }
  else {
    while(s->count != 0) {
      printf("%X", pop(s));
    }
  }
}



 
