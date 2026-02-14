#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = (int *)malloc(3 * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory not allocated\n");
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        arr[i] = i + 1;
    }

    // Increase size to 5 elements
    arr = (int *)realloc(arr, 5 * sizeof(int));

    if (arr == NULL)
    {
        printf("Reallocation failed\n");
        return 1;
    }

    arr[3] = 4;
    arr[4] = 5;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
