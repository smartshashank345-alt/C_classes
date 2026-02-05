// // Functions - call by value or reference -- THis happens when your function starts its execution

// // return -- 1. local variable uski copy
// //           2. It represents the eding program -- When it ends its execution

// #include <stdio.h>

// void Add(int x)
// {
//     printf("%d", x + 10);
//     // return x;
// }
// int main()
// {

//     // printf("Helo World");
//     int x = 5;
//     Add(x);
//     printf("\n%d", x);
//     return 0;
// }

// #include <stdio.h>
// void swap(int x, int y)
// {
//     // x = 5 , y = 10
//     int temp = x;
//     x = y;
//     y = temp;
//     printf("x: %d - y : %d \n", x, y);
// }

// void swap2(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
//     // printf(*x, *y);
// }
// int main()
// {
//     int a = 5, b = 10;
//     // swap(a,b);
//     printf("a:%d - b is %d :", a, b);
//     swap2(&a, &b);
//     printf("a:%d - b is %d :", a, b);

//     return 0;
// }

#include <stdio.h>
// Call stack

//
void F1()
{
    printf(" \n I am in F1 \n ");
}
void F3()
{
    printf("\n I am in F3 \n");
}
void F2()
{
    F3();
    printf("\n I am in F2 \n ");
}

int main()
{
    // Sequential Manner -- top to bottom
    F2();
    printf("Hello World \n");
    F1();
}

// Calls -- Call Stack
