#include <stdio.h>
#include <stdlib.h>

void countSort(int arr[], int n)
{
    if (n <= 1)
        return;

    // Find maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    // Create counting array (auto-initialized to 0)
    int *count = calloc(max + 1, sizeof(int));
    int *output = malloc(n * sizeof(int));

    // Store frequencies
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Convert to cumulative count
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build sorted array (stable)
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    // Copy back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(count);
    free(output);
}

int main()
{
    int arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    countSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
