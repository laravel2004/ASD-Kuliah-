#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
typedef char itemType;
struct simpul {
    itemType data;
    Node *next;
};

Node *head = NULL, *p;

void menu();
void inisialisasi();
void push();
void pop();
void tampil();

int main(int argc, char const *argv[])
{
  menu();
  return 0;
}

void menu() {
    int flag = 0, option;

    while(!flag) {
        puts("STACK USING SLL");
        printf("1. Mengisi Stack (PUSH)\n2. Mengambil Isi Stack (POP)\n3. Menampilkan Isi Stack (LIFO)\n4. Keluar\n");
        printf("Masukkan opsi: ");
        scanf("%d", &option);
        fflush(stdin);

        switch(option) {
            case 1:
                inisialisasi();
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                tampil();
                break;
            case 4:
                flag = 1;
                break;
            default:
                puts("Invalid");
                exit(0);
        }
    }
}

void inisialisasi() {
    p = (Node *) malloc(sizeof(Node));
    if(p != NULL) {
        printf("Data yang mau diinput: "); scanf("%c", &p->data); p->next = NULL;
    } else {
        printf("Gagal Init\n"); exit(0);
    }
}

void push()
{
    if(head != NULL) {
        p->next = head;
    }
    head = p;
}

void pop()
{
    Node *delete;
    printf("\nDelete awal\n");
    if(head == NULL) {
        printf("STACK kosong\n");
    } else {
        printf("Data diPOP = %c\n", head->data);
        if(head->next == NULL) {
            free(head);
            head = NULL;
            tampil();
        } else {
            delete = head;
            head = head->next;
            free(delete);
            delete = head;
            tampil();
        }
    }
}

void tampil()
{
    Node *baca; baca = head;
    while(baca != NULL)
    {
        printf("%c\n", baca->data);
        baca = baca->next;
    }
    printf("\n");

}