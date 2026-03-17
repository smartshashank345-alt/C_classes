// 170 45 75 90 802 24 2 66 -- Array

// 170 90
// 802 2
// 24
// 45 75
// 66
// 802 2 24 45 66 170 75 90

// 2 24 45 66 75 90 170 802 11 11

// 11 11
// 187 % 10 == 7

#include <stdio.h>
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
void radixSort(int arr[], int n)
{

    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);
    return 0;
}

// 802 -- 802 % 10 -- 2
// 802 % 100 -- 02