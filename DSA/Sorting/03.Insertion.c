// Insertion sort in C
#include <stdio.h>

void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && key < array[j])
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }

    // priting sorted array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {19, 6, 10, 4, 43};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Sorted array in ascending order:\n");
    insertionSort(arr, size);
}