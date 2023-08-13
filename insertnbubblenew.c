#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void insertionSort(int *array, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i;
        while (j > 0 && array[j - 1] > key)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }
}

void bubblesort(int *a, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

int main()
{
    int n;
    clock_t start, end;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n], a[n]; // create an array with the given number of elements

    printf("Enter elements for Insertion Sort:\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
    printf("Array before Sorting: Insertion Sort ");
    display(arr, n);
    start = clock();
    insertionSort(arr, n);
    end = clock();
    printf("Time taken for Insertion sort: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Array after Sorting: Insertion Sort ");
    display(arr, n);

    printf("Bubble sort: Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }
    display(a, n);
    start = clock();
    bubblesort(a, n);
    end = clock();
    printf("Time taken for Bubble sort: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Array after Sorting: Bubble sort ");
    display(a, n);
    return 0;
}