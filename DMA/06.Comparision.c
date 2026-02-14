/*
 * ====================================================================
 * Comparison – malloc and calloc
 * ====================================================================
 *
 *
 *
 * | Feature      | malloc                     | calloc                     |
 * |--------------|----------------------------|----------------------------|
 * | Parameters   | (size)                     | (num, size)                |
 * | Initial value| garbage                    | zero                       |
 * | Speed        | faster (no clearing)       | slower (writes zeros)      |
 * | Use when     | you fill memory immediately| you need zero‑initialized  |
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    int *m, *c;

    // 1. malloc – garbage values
    m = (int *)malloc(n * sizeof(int));
    if (m == NULL)
        return 1;

    printf("malloc (garbage): ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", m[i]); // unpredictable
    }
    printf("\n");

    // 2. calloc – all zeros
    c = (int *)calloc(n, sizeof(int));
    if (c == NULL)
    {
        free(m);
        return 1;
    }

    printf("calloc (all zeros): ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", c[i]); // prints 0 0 0 0 0
    }
    printf("\n");

    // Free both
    free(m);
    free(c);
    m = c = NULL;

    return 0;
}