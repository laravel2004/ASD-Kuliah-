#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    int i, j, temp;
    int comparison = 0, shift = 0, insertion = 0;
    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
            comparison++;
            shift++;
        }
        arr[j+1]=temp;
        insertion++;
    }
    printf("Jumlah perbandingan: %d\n", comparison);
    printf("Jumlah pergeseran: %d\n", shift);
    printf("Jumlah penyisipan: %d\n", insertion);
}

int main()
{
    int arr1[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    int arr2[] = {1, 2, 3, 4, 5, 9, 7, 6, 8, 10};
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr4[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;
    
    printf("Array 1:\n");
    insertion_sort(arr1, n);
    printf("Hasil pengurutan: ");
    for(int i=0;i<n;i++)
        printf("%d ", arr1[i]);
    printf("\n\n");

    printf("Array 2:\n");
    insertion_sort(arr2, n);
    printf("Hasil pengurutan: ");
    for(int i=0;i<n;i++)
        printf("%d ", arr2[i]);
    printf("\n\n");

    printf("Array 3:\n");
    insertion_sort(arr3, n);
    printf("Hasil pengurutan: ");
    for(int i=0;i<n;i++)
        printf("%d ", arr3[i]);
    printf("\n\n");

    printf("Array 4:\n");
    insertion_sort(arr4, n);
    printf("Hasil pengurutan: ");
    for(int i=0;i<n;i++)
        printf("%d ", arr4[i]);
    printf("\n\n");

    return 0;
}
