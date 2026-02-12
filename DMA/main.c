// Po0gram phases -- Compile Phase & Runtime Phase

// DMA -- Runtime

// malloc() , calloc(), realloc(), free()

// malloc --

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n;
    int *arr;
    printf("Enter the number of elements:");
    scanf("%d", &n);

    // arr = (int *)malloc(n * sizeof(int));
    arr = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
    free(arr);
}
// calloc --

// Radix , Selection  , Insertion , BUbble , Count Sort
//  Merge , Quick

// Linear and Binary