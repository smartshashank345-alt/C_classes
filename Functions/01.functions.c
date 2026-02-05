// Doctor --
#include <stdio.h>
void Hello();
void Hello()
{
    printf("This is my Hello Function \n");
}

int Number()
{
    int a, b;
    a = 10;
    b = 20;
    // printf("hello in Number");
    return a + b;
}
int main()
{
    int x;
    Hello();
    x = Number();
    printf("%d", x);
    printf("Hello, World!\n");
    return 0;
}
