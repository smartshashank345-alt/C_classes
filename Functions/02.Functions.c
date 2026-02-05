#include <stdio.h>
// without return without parameters -- f1
int salary = 30000;
// global
void f1()
{
    printf("Function f1 : without return without parameters");
    // printf(salary);
}

// without return with parameters
// void f2(int num)
// {
//     int result = 0;

//     result += num * 2; // result = result + num*2
//     // if (result > 100)
//     // {
//     //     int blockLevel = 36;
//     //     printf("Hello");
//     //     // printf(salary);
//     // }
//     // printf(blockLevel);
//     printf("\n Function f2:without return with parameters");
//     printf("\n Result is : %d", result);
//     // return result;
// }

int Add()
{
    int a, b;
    a = 100;
    b = 300;
    int result = 0;
    result = a + b;
    // printf("\n %d ", result);
    return result;
    // printf("Hello World");
}

// int Final(int a, int b)
// {
//     int result = 0;
//     result = a + b;
//     printf("\n %d ", result);
//     return result;
// }
int main()
{

    // f1();
    // f2(45);
    // int finalResult = 0;
    // finalResult = Add();
    // printf("\n Final Result : %d", finalResult + 100);
    // int finalAnswer = 0;
    // int x, y;
    // x = 100;
    // y = 200;
    // finalAnswer = Final(x, y);
    // printf("\n Final Answer : %d", finalAnswer);
    printf("%d", Add());

    // printf(result);
    return 0;
}

// with return without parameters

// with return with parameters