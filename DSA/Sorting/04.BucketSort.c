#include <stdio.h>

// Insertion Sort for sorting individual buckets
void insertionSort(float arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Bucket Sort for numbers between 0 and 1
void bucketSort(float arr[], int n)
{

    float buckets[n][n]; // Create n buckets
    int count[n];        // Count elements in each bucket

    // Initialize counts to 0
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
    }

    // Put elements into buckets
    for (int i = 0; i < n; i++)
    {
        int index = arr[i] * n; // Find bucket index
        buckets[index][count[index]] = arr[i];
        count[index]++;
    }

    // Sort each bucket
    for (int i = 0; i < n; i++)
    {
        if (count[i] > 0)
        {
            insertionSort(buckets[i], count[i]);
        }
    }

    // Combine buckets back into original array
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            arr[k++] = buckets[i][j];
        }
    }
}

// Print array
void printArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main()
{
    float arr[] = {0.42, 0.32, 0.67, 0.89, 0.12, 0.55, 0.73, 0.91, 0.28, 0.64};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("After Sorting:\n");
    printArray(arr, n);

    return 0;
}
