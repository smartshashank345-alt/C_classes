/*
 * ====================================================================
 * Using calloc() to allocate zero‑initialized memory
 * ====================================================================
 *
 * calloc(size_t num, size_t size):
 *   - Allocates memory for an array of 'num' elements,
 *     each of 'size' bytes (total = num * size).
 *   - Returns a void* pointer, or NULL on failure.
 *   - ALL bytes are set to ZERO.
 *
 * Syntax:
 *   type *ptr = (type*) calloc(num_elements, sizeof(type));
 *
 * Use calloc when you need the memory to start with zeros
 * (e.g., arrays, strings, structures). It's safer because you
 * won't accidentally read uninitialized garbage.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *arr;

    printf("How many integers do you need? ");
    scanf("%d", &n);

    // Allocate memory for n integers and set all to zero
    arr = (int *)calloc(n, sizeof(int));

    if (arr == NULL)
    {
        printf("calloc failed! Not enough memory.\n");
        return 1;
    }

    // Memory is already zeroed
    printf("\nAfter calloc (all zeros):\n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]); // prints 0 for all
    }

    // Now we can fill it with our own data
    for (int i = 0; i < n; i++)
    {
        arr[i] = (i + 1) * 5;
    }

    printf("\nAfter filling with data:\n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}