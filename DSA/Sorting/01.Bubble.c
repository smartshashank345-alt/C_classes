#include <stdio.h>

/*
=======================================================================================
    Bubble Sort -- Two versions of the code are present. You are free to use any of these but
    for exams try to use the first one.
=======================================================================================
    Idea:
    - Compare two neighboring elements.
    - If they are in the wrong order, swap them.
    - Repeat this process again and again.

    - After each full pass, the largest unsorted element moves to the end.

    --- Why it is called Bubble Sort

    --- Large elements slowly move to the end just like bubbles rising to the top.

    Time Complexity:
        Best Case  : O(n)
        Worst Case : O(n^2)

    Space Complexity:
        O(1)  (in place sorting)

    Stable Sort:
        Yes  (equal elements keep their relative order)
*/

void bubbleSort(int arr[], int n)
{
    int i, j;
    int temp;
    int swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0; // flag to detect if any swap happens

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap using temporary variable
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        // If no swaps happened, array is already sorted
        if (swapped == 0)
        {
            break;
        }
    }
}

void printArray(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = {1, 5, 9, 2, 0};
    int n = 5;
    // int n = sizeof(arr) / sizeof(arr[0]); // preferred for exams

    printf("Original Array:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}

/*
#include <stdio.h>

int main()
{
    int arr[] = {1, 5, 9, 2, 0};
    int n = 5;
    int i, j;
    int temp = 0;
    int swap = 0;
    //  0 -1 -- 0
    //  1- 2 -- 1
    //  2- 3 -- 2
    //  3- 4 -- 3

    for (i = 0; i < n - 1; i++)
    {
        // printf("Iteration Number %d : ",i);
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // swap = 1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}


*/
// x = 10  y = 5

/*
temp = x (10)
 x = y (5)
 y = temp (10)


 x = x+y = 15
 y = x-y = 15 - 5= 10
 x = x-y = 15 - 10 = 5
*/
// x = 5 y = 10

/*

arr = 3     4       1       6       2

//     3    1      4        2        6

//     1    3      2        4        6

//     1     2      3      4         6

//    1      2      3         4      6

*/

/*

arr = 1 2 3 4 5 6

// Swap = 1

//


*/

// O(n) -- Best Case -- already sorted array
// O(n^2) - Time Compplexity

// O(1) - Space Complexity

// Stable Sort -- relevant order of elements does not change
//  1 4 2 2 5 9
//  1 2 2 4 5 9

// In place sorting -- no extra space
