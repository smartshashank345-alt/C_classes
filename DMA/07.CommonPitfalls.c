/*
 * ====================================================================
 *  Common pitfalls and how to avoid them - Dynamic Memory Allocation
 * ====================================================================
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // ----- 1. Always check for NULL after allocation -----
    int *ptr1 = (int *)malloc(1000000000 * sizeof(int)); // deliberately huge
    if (ptr1 == NULL)
    {
        printf("1. malloc failed (as expected for huge size). Good we checked.\n");
    }
    else
    {
        free(ptr1);
    }

    // ----- 2. Use correct size: multiply by sizeof(type) -----
    // Wrong: int *arr = (int*) malloc(10);   // only 10 bytes, not 10 ints!
    // Correct:
    int *arr = (int *)malloc(10 * sizeof(int));
    if (arr == NULL)
        return 1;
    printf("2. Correctly allocated 10 ints (40 bytes on most systems).\n");
    free(arr);

    // ----- 3. Never free stack memory -----
    int stack_var = 5;
    // free(&stack_var);   // WRONG – undefined behaviour

    // ----- 4. Avoid double free -----
    int *p = (int *)malloc(sizeof(int));
    free(p);
    // free(p);   // WRONG – double free
    // Instead, set to NULL after first free, then free(NULL) is safe
    p = NULL;
    free(p); // OK – does nothing

    // ----- 5. realloc: use temporary pointer -----
    int *data = (int *)malloc(5 * sizeof(int));
    if (data == NULL)
        return 1;
    // Wrong: data = realloc(data, 10 * sizeof(int));  // if fails, original pointer lost
    // Correct:
    int *temp = (int *)realloc(data, 10 * sizeof(int));
    if (temp != NULL)
    {
        data = temp;
    }
    else
    {
        // handle error – data still points to original 5 elements
        printf("5. realloc failed, but original data intact.\n");
        free(data);
        return 1;
    }
    free(data);

    // ----- 6. Free memory in all code paths -----
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL)
        return 1;
    // Suppose some error condition occurs
    int error = 1;
    if (error)
    {
        free(ptr); // must free before returning
        printf("6. Error path – freed memory.\n");
        return 1;
    }
    // normal path
    free(ptr);

    // ----- 7. After free, pointer is dangling – set to NULL -----
    int *q = (int *)malloc(sizeof(int));
    *q = 100;
    free(q);
    q = NULL; // now it's safe
    // later, you can check if (q != NULL) before using

    printf("\nAll best practices demonstrated.\n");
    return 0;
}