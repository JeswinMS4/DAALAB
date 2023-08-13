#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start_t;
clock_t end_t;
clock_t start_t2;
clock_t end_t2;
void linear(int a[], int n, int key)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        printf("Element not found\n");
    }
    else
        printf("Element found at %d\n", i);
}
void binary(int a[], int n, int key)
{
    int i, flag, mid, low, high, flg = 0;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            printf("Element found at %d\n", mid);
            flg = 1;
            break;
        }
        else if (key < a[mid])
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    if (flg = 0)
    {
        printf("Element not found\n");
    }
}
void main()
{
    int a[10];
    int n, i, k, l;
    printf("enter the length of the array ");
    scanf("%d", &n);
    printf("Enter the array");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d", &k);
    start_t = clock();
    linear(a, n, k);
    end_t = clock();
    printf("Time taken to run Linear Search %lf\n", (float)(end_t - start_t) / (float)CLOCKS_PER_SEC);
    start_t2 = clock();
    binary(a, n, k);
    end_t2 = clock();
    printf("Time taken to run Binary Search %lf\n", (float)(end_t2 - start_t2) / (float)CLOCKS_PER_SEC);
}