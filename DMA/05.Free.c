/*
 * ====================================================================
 * How to properly free memory and avoid dangling pointers
 * ====================================================================
 *
 * free(void *ptr):
 *   - Releases heap memory previously allocated by malloc/calloc/realloc.
 *   - After free, the pointer becomes a "dangling pointer" – it still
 *     holds the old address, but the memory is gone. Using it leads to
 *     undefined behavior (crash, corruption).
 *   - It is safe to call free(NULL); it does nothing.
 *
 * Best practice:
 *   After free(ptr), set ptr = NULL. Then any accidental use will
 *   cause a NULL dereference (crash) which is easier to debug than
 *   random behaviour.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    // Allocate memory
    ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL)
        return 1;

    *ptr = 123;
    printf("Before free: *ptr = %d\n", *ptr);

    // Free the memory
    free(ptr);
    // ptr is now dangling – don't dereference it!

    // Good practice: set to NULL
    ptr = NULL;

    // Now it's safe to check before using
    if (ptr != NULL)
    {
        // this block won't execute
        printf("This won't print.\n");
    }

    return 0;
}