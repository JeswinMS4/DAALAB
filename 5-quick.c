#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start_t;
clock_t end_t;
clock_t total_t;
void swap(int ar[], int pos1, int pos2)
{
    int temp;
    temp = ar[pos1];
    ar[pos1] = ar[pos2];
    ar[pos2] = temp;
}
int partition(int ar[], int low, int high, int pivot)
{
    int i = low;
    int j = low;
    while (i <= high)
    {
        if (ar[i] > pivot)
        {
            i++;
        }
        else
        {
            swap(ar, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}
void quicksort(int ar[], int low, int high)
{
    if (low < high)
    {
        int pivot = ar[high];
        int pos = partition(ar, low, high, pivot);
        quicksort(ar, low, pos - 1);
        quicksort(ar, pos + 1, high);
    }
}
void main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int ar[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);
    start_t = clock();
    quicksort(ar, 0, n - 1);
    end_t = clock();
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", ar[i]);
    }
    printf("Time taken to run Quick Sort %lf\n", (float)(end_t - start_t) / (float)CLOCKS_PER_SEC);
}