/*
 * ====================================================================
 *  Using malloc() to allocate uninitialized memory
 * ====================================================================
 *
 * malloc(size_t size):
 *   - Allocates 'size' bytes of memory from the heap.
 *   - Returns a void* pointer to the first byte, or NULL on failure.
 *   - The memory is NOT initialized – it contains garbage values.
 *
 * Syntax:
 *   type *ptr = (type*) malloc(number_of_elements * sizeof(type));
 *
 * Always check for NULL after calling malloc.
 * Always free the memory when you are done.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *arr;

    printf("How many integers do you need? ");
    scanf("%d", &n);

    // Allocate memory for n integers
    arr = (int *)malloc(n * sizeof(int));

    // Check if allocation succeeded
    if (arr == NULL)
    {
        printf("malloc failed! Not enough memory.\n");
        return 1;
    }

    // The allocated memory contains unpredictable values (garbage)
    printf("\nAfter malloc (garbage values):\n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]); // may print random numbers
    }

    // Initialize the memory with some data
    for (int i = 0; i < n; i++)
    {
        arr[i] = i * 10;
    }

    printf("\nAfter initialization:\n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Free the memory
    free(arr);
    arr = NULL; // good practice

    return 0;
}