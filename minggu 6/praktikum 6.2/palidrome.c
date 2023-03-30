#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void menu();
int pembanding(char[],stack *);

stack tumpukan;

int main() {
  do{
    menu();
  } while(1);
}

void menu() {
  char kata[MAX];
  int i = 0;
  char jawab;
  printf("\nMENGECEK PALIDROME\n");
  printf("Masukan kata yang mau dicek : ");
  fflush(stdin);
  gets(kata);
  for(int i = 0; i < strlen(kata); i++) {
    push(kata[i], &tumpukan);
  }
  if(pembanding(kata, &tumpukan)) {
    printf("%s adalah palidrome", kata);
  } else {
    printf("%s bukan palidrome", kata);
  }
  printf("\nMau coba lagi (y / t) ? ");
  scanf("%c", &jawab);
  if(jawab == 't') {
    exit(0);
  }
  
}

int pembanding(char x[],stack *s) {
  char temp;
  for(int i = 0; i < strlen(x); i++ ) {
    temp = pop(s);
      if(x[i] != temp) {
        return 0;
      }
  }
  return 1;
}


void inisialisasi(stack *s) {
  s->count = 0;
}

int kosong(stack *s) {
  return s->count == 0 ? 1 : 0;
}
int penuh(stack *s) {
  return s->count == MAX ? 1 : 0;
}

void push(ItemType x , stack *s) {
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
    printf("Stack underflow");
  }
  else {
    --s->count;
    temp = s->data[s->count];
    return temp;
  }
}

void tampil(stack *s) {
  if(kosong(s)) {
    printf("Data tidak ada");
  }
  else {
    while(s->count != 0) {
      printf("%c", pop(s));
    }
  }
}