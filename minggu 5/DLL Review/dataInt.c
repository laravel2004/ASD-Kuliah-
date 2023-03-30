#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
    int data;
    node *next, *prev;
};

node *head = NULL, *p;

void menu();
void alokasi();
void insertTerurut();
void cariData();
void deleteAwal();
void deleteAkhir();
void deleteTertentu();
void print();

int main(){
    menu();
}

void menu(){
    int pilihan;
    do {
        int pilihan;
        printf("\nPILIH MENU : \n");
        printf("1.penambahan secara terurut\n2.pencarian data\n3.penghapusan data\n4.keluar\n");
        printf("PILIH SALAH SATU : ");
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                insertTerurut();
                break;
            case 2:
                cariData();
                break;
            case 3:
                deleteTertentu();
                break;
            case 4:
                exit(0);
                break;
            default:
                system("cls");
                puts("Inputan salah");
                menu();
                break;
        }
        print();
//        system("cls");
    } while(pilihan != 4);
}

void alokasi() {
    p = (node *) malloc(sizeof(node));
    if (p == NULL) {
        printf("out of memory");
        exit(0);
    }
    printf("masukan nomor\t: ");
    scanf("%d", &p->data);
    p->next = NULL;
    p->prev = NULL;
}

node* freeNode(node *pointer){
    free(pointer);
    return NULL;
}

void insertTerurut(){
    node *scan;
    alokasi();
    if(head == NULL) {
        head = p;
    } else if(head->data >= p->data){
        p->next = head;
        head->prev = p;
        head = p;
    } else {
        scan = head;
        while(scan->data < p->data) {
            if(scan->next == NULL){
                scan->next = p;
                p->prev = scan;
                return;
            }
            scan = scan->next;
        }
        p->next = scan;
        p->prev = scan->prev;
        scan->prev->next = p;
        scan->prev = p;
    }
}

void cariData(){
    node *scan;
    int key, count=0;
    scan = head;
    printf("masukan data yang ingin dicari : ");
    scanf("%d", &key);
    if(head == NULL){
        printf("SLL masih kosong!\n");
    } else {
        while(scan != NULL) {
            if(scan->data == key){
                count++;
            }
            scan = scan->next;
        }
        if(count == 0){
            printf("Data %d tidak ada dalam SLL\n", key);
        } else {
            printf("Data %d ada %d buah\n", key, count);
        }
    }
}

void deleteAwal(){
    node *hapus;
    if(head == NULL){
        printf("DLL kosong, tidak bisa menghapus!\n");
    } else if(head->next == NULL){
        head = freeNode(head);
    } else {
        hapus = head;
        head = head->next;
        head->prev = NULL;
        free(hapus);
    }
}

void deleteAkhir(){
    node *hapus;
    if(head == NULL){
        printf("DLL kosong, tidak bisa menghapus!\n");
    } else if(head->next == NULL){
        head = freeNode(head);
    } else {
        hapus = head;
        while(hapus->next != NULL) {
            hapus = hapus->next;
        }
        hapus->prev->next = NULL;
        free(hapus);
    }
}

void deleteTertentu(){
    int key;
    node *hapus = head;
    printf("masukan angka yang ingin dihapus : ");
    scanf("%d", &key);
    if(head == NULL){
        printf("DLL kosong, tidak bisa menghapus!\n");
        return;
    } else if(head->data == key) {
        deleteAwal();
        return;
    } else {
        while(hapus->data != key) {
            if(hapus->next == NULL){
                printf("nomor tidak ditemukan!\n");
                return;
            }
            hapus = hapus->next;
        }
        if(hapus->next == NULL){
            deleteAkhir();
            return;
        }
        hapus->next->prev = hapus->prev;
        hapus->prev->next = hapus->next;
        free(hapus);
    }
}


void print(){
    node *baca = head;
    printf("DLL = [");
    while(baca != NULL){
        printf("%d",baca->data);
        baca = baca->next;
        if(baca != NULL){
            printf(", ");
        }
    }
    printf("]\n");
}