/*
SELECTION SORT

Definition:
Selection sort is a comparison based sorting algorithm.
It repeatedly selects the smallest element from the unsorted
portion and places it at the correct position.

Working:
1. Divide array into two parts:
   - Sorted part (left side)
   - Unsorted part (right side)

2. For each position:
   - Find the minimum element in the unsorted part
   - Swap it with the current position

3. Repeat until array is sorted.

-----------------------------------------------------

TIME COMPLEXITY

Best Case:    O(n^2)
Average Case: O(n^2)
Worst Case:   O(n^2)

Reason:
Even if array is already sorted,
the algorithm still compares all remaining elements.

-----------------------------------------------------

SPACE COMPLEXITY:
O(1)
(In-place sorting, only one temporary variable used)

-----------------------------------------------------

Key Points:
- Simple to implement
- Not stable by default
- Good for small datasets
- Not efficient for large arrays
*/

#include <stdio.h>

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {

        int min_idx = i;

        // Find the minimum element
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            int temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;
        }
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {10, 1, 2, 9, 8, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, size);

    printf("Sorted array in Ascending Order:\n");
    printArray(arr, size);

    return 0;
}
