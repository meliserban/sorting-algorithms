#include <stdio.h>

void swap(int *a, int *b);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);

int main()
{
    int a[] = {10, 11, 67, 35, 78, 23, 13, 5, 45, 27, 9, 1, 0};
    int length = 13;

    quicksort(a, length);

    for (int i = 0; i < length; i++)
    printf("%d ", a[i]);
    printf("\n");
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int array[], int length)
{
    quicksort_recursion(array, 0, length - 1);
}

void quicksort_recursion(int array[], int low, int high)
{

    if (low < high)
    {
        int pivot_index = partition(array, low, high);
        quicksort_recursion(array, low, pivot_index - 1);
        quicksort_recursion(array, pivot_index + 1, high);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    return i;
}
