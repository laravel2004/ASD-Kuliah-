#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32


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
void tampil(stack *);
void konversi_cetak(char temp[]);
int drjt(char);

stack tumpukan;

int main() {
  int i= 0;
  char data[32];
  inisialisasi(&tumpukan);
  fflush(stdin);
  gets(data);
  konversi_cetak(data);
}

void konversi_cetak(char temp[])
{
    int i, pjg, valid = 1;
    char kar, smtr;
    pjg = strlen(temp) - 1;
    for (i = 0; i < pjg; i++)
    {
        kar = temp[i]; 
        switch (kar)
        {
        case '(':
            push(kar, &tumpukan);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            printf("%c", kar);
            break;
            
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            if ((kosong(&tumpukan)) ||
                ((drjt(kar) >
                  drjt(tumpukan.data[tumpukan.count]))))
                push(kar, &tumpukan);
            else
            {
                do
                {
                    smtr = pop(&tumpukan);
                    printf("%c", smtr);
                } while (drjt(kar) <
                         drjt(tumpukan.data[tumpukan.count]));
                push(kar, &tumpukan);
            }
            break;
        case ')':
            while (tumpukan.data[tumpukan.count] != '(')
            {
                smtr = pop(&tumpukan);
                printf("%c", smtr);
            }
            pop(&tumpukan);
          break;
        default: 
            valid = 0;
            puts("INVALID STATSMENT");
            break;
        } 
    }     

    if ((valid != 0) && (!kosong(&tumpukan)))
    {
        smtr = pop(&tumpukan);
        printf("%c", smtr);
    }
}

int drjt(char x) 
{
    if (x == '(')
        return 0;
    else if ((x == '+') || (x == '-'))
        return 1;
    else if ((x == '*') || (x == '/'))
        return 2;
    else if (x == '^')
        return 3;
    else
        return -1; 
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
  if(penuh(s)) {
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