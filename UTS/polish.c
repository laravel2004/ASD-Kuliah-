#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef char ItemType;
typedef struct {
  ItemType data[100];
  int count; 
} stack;

stack tumpukan;

void inisialisasi(stack *);
int penuh(stack *);
int kosong(stack *);
void push(ItemType, stack *);
ItemType pop(stack *);


int main() {
  char nilai;
  inisialisasi(&tumpukan);
  nilai = getchar();
  push(nilai, &tumpukan);
  printf("%c", pop(&tumpukan));

}

void inisialisasi(stack *s) {
  s->count = 0;
}

int penuh(stack *s) {
  return(s->count == MAX) ? 1 : 0; 
}

int kosong(stack *s) {
  return(s->count == 0) ? 1 : 0;
}

void push(ItemType x, stack *s) {
  if(penuh(s)) {
    printf("Stackoverflow");
  }
  else {
    s->data[s->count] = x;
    s->count++;
  }
}

ItemType pop(stack *s) {
  ItemType temp;
  if(kosong(s)) {
    printf("stackunderflow");
  }
  else {
    --s->count;
    temp = s->data[s->count];
    return temp;
  }
}