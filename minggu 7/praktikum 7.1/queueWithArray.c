#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef char itemType;
typedef struct {
  itemType item[MAX];
  int count;
  int front;
  int rear;
} Queue;

void inisialisasi(Queue*);
int penuh(Queue*);
int kosong(Queue*);
void enqueue(Queue*, itemType);
itemType dequeue(Queue*);
void menu();
void fifo(Queue*);
Queue antrian;

int main() {
  inisialisasi(&antrian);
  do
  {
    menu();
  } while (1);
  
}

void menu() {
  int jawab;
  itemType x;
  printf("MENU QUEUE using ARRAY");
  printf("\n1. Mengisi queue <enqueue>\n2. Mengambil isi queue <dequeue>\n3. Menampilkan isi  -> FIFO\n4. Keluar\n\nMasukan Pilihan Anda : ");
  scanf("%d", &jawab);
  switch(jawab) {
    case 1: 
      printf("Masukan data anda : ");
      fflush(stdin);
      scanf("%c", &x);
      enqueue(&antrian, x);
      break;
    case 2 :
      printf("Item yang telah diambil %c\n", dequeue(&antrian));
      break;
    case 3 :
      fifo(&antrian);
      break;
    case 4 :
      exit(0);
      break;
  }

}


void inisialisasi(Queue *q) {
  q->count = 0;
  q->front = 0;
  q->rear = 0;
}

int penuh(Queue *q) {
  return (q->count == MAX) ? 1 : 0 ;
}

int kosong(Queue *q) {
  return (q->count == 0) ? 1 : 0 ;
}

void enqueue(Queue *q, itemType x) {
  if(penuh(q)) {
    printf("Queue penuh tidak dapat disimpan\n");
  }
  else {
    q->item[q->rear] = x;
    q->rear = (q->rear + 1) % MAX;
    q->count++;
  }
}

itemType dequeue(Queue *q) {
  itemType temp;
  if(kosong(q)) {
    printf("Queue masih kosong harap isi terlebih dahulu\n");
  }
  else {
    temp = q->item[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return temp;
  }
}

void fifo(Queue *q) {
  if(kosong(q)) {
    puts("Queue masih kosong\n");
  }
  else {
    int temp = q->front;
    puts("Isi queue saat ini adalah : ");
    for(int i = 0; i < q->count; i++) {
      printf("%c\n", q->item[temp]);
      temp = (temp + 1) % MAX;
    }
  }
}