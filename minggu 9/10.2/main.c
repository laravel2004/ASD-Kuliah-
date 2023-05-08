#include <stdio.h>
#include <string.h>

typedef struct Siswa
{
    int NO;
    char Nama[50];
    int Nilai;
} Siswa;

void isiData(Siswa *, int );
void tampilData(Siswa *, int );
void modeUrut();
void insertionSort(Siswa *, int);
void selectionSort(Siswa *, int);

void menuSort(int, Siswa Data[], int);

// Variabel Global
int mode;

int main()
{
    int n = 5;
    Siswa Data[n];
    int pilihSort = 0;

    isiData(Data, n);
    while(pilihSort != 3)
    {
        printf("\nMENU METODE SORTING\n");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Keluar\n");

        printf("Pilihan anda [1/2/3]: ");
        scanf("%d", &pilihSort);

        menuSort(pilihSort, Data, n);
    }

    return 0;
}

void menuSort(int pilihSort, Siswa Data[], int n)
{
    modeUrut();
    switch(pilihSort)
    {
    case 1:
        insertionSort(Data, n);
        tampilData(Data, n);
        break;
    case 2:
        selectionSort(Data, n);
        tampilData(Data, n);
        break;
    case 3:
        printf("Terima kasih.\n");
        break;
    default:
        printf("Pilihan tidak valid.\n");
        break;
    }
}

void isiData(Siswa *Data, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Data Siswa ke-%d:\n", i+1);
        fflush(stdin);
        printf("NO : ");
        scanf("%d", &Data[i].NO);
        fflush(stdin);
        printf("Nama : ");
        scanf("%s", Data[i].Nama);
        fflush(stdin);
        printf("Nilai : ");
        scanf("%d", &Data[i].Nilai);
        fflush(stdin);
        puts("");
    }
}

void tampilData(Siswa *Data, int n)
{
    int i;
    printf("%-5s %-20s %-5s\n", "NO", "NAMA", "NILAI");
    for(i = 0; i < n; i++)
    {
        printf("%-5d %-20s %-5d\n", Data[i].NO, Data[i].Nama, Data[i].Nilai);
    }
}

void modeUrut()
{
    printf("\nPengurutan yang dipilih:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan anda [1/2]: ");
    scanf("%d", &mode);
}

void insertionSort(Siswa *Data, int n)
{
    int i, j;
    Siswa temp;
    for(i = 1; i < n; i++)
    {
        temp = Data[i];
        j = i - 1;
        while(j >= 0 && ((mode == 1 && Data[j].NO > temp.NO) || (mode == 2 && Data[j].NO < temp.NO)))
        {
            Data[j+1] = Data[j];
            j--;
        }
        Data[j+1] = temp;
    }
}

void selectionSort(Siswa *Data, int n)
{
    int i, j, minIndex;
    Siswa temp;

    for(i = 0; i < n-1; i++)
    {
        minIndex = i;
        for(j = i+1; j < n; j++)
        {
            if((mode == 1 && Data[j].NO < Data[minIndex].NO) || (mode == 2 && Data[j].NO > Data[minIndex].NO))
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            temp = Data[i];
            Data[i] = Data[minIndex];
            Data[minIndex] = temp;
        }
    }
}
