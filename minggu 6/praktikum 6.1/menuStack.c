#include <stdio.h>
#include <stdlib.h>
#define MAX 5


typedef char ItemType;
typedef struct {
  ItemType data[MAX];
  int count;
}stack;

void inisialisasi(stack *);
int kosong(stack*);
int penuh(stack *);
void push(ItemType, stack*);
ItemType pop(stack*);
void menu();
void tampil(stack *);

stack tumpukan;

int main() {
  inisialisasi(&tumpukan);
  do
  {
    menu();
  } while (1);
  
}

void menu() {
  int jawab;
  ItemType data;
  printf("\nMENU STACK using ARRAY : \n");
  printf("1. Mengisi stack (push)\n2. Mengambil isi Stack (POP)\n3. Menampilkan isi stack -> LIFO\n4. Keluar\n");
  printf("Masukan pilihan anda : ");
  scanf("%d",&jawab);
  system("cls");
  switch(jawab) {
    case 1 :
      printf("Masukan data anda : ");
      fflush(stdin);
      scanf("%c", &data);
      push(data, &tumpukan);
      break;
    case 2 :
      pop(&tumpukan);
      break;
    case 3 :
      tampil(&tumpukan);
      break;
    case 4 :
      exit(0);
      break;
    default :
      puts("Inputan salah"); 
  }

}

void tampil(stack *s) {
  if(kosong(s)) {
    printf("STACK UNDERFLOW\n");
  }
  else {
    printf("Nilai stack saat ini !\n");
    for(int i = s->count - 1; i >= 0; i--) {
      printf("%c\t", s->data[i]);
    }
  }
}

void inisialisasi(stack *s) {
  s->count = 0;
}

int kosong(stack *s) {
  return (s->count == 0) ? 1 : 0;
}

int penuh(stack *s) {
  return (s->count == MAX) ? 1 : 0;
}

void push(ItemType x, stack *s) {
  if(penuh(s) == 1) {
    printf("STACK OVERFLOW\n");
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