// Stack -- Linear data -- LIFO -- Last In First Out

// Stack data structure / Call Stack  vs Stack Memory --
// Stack DS and Stack Memory are totally different things.

// add - push
// delete - pop
// top - peek
// isEmpty -- Arrays and Linked List
// Full - Arrays
// size
// Stack implementation -- Arrays based and Linked List

//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #define MAX 5;

typedef struct
{
    int arr[5];
    int top;
} stack;

void initStack(stack *s)
{
    s->top = -1;
}

bool isEmpty(stack *s)
{
    return s->top == -1;
}

bool isFull(stack *s)
{
    return s->top == 4;
}

void push(stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow. Can't push value : %d\n", value);
        return;
    }
    s->top++;
    s->arr[s->top] = value;
    printf("Pushed Value : %d\n", value);
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Empty Stack. Can't pop value");
        return;
    }
    int value = s->arr[s->top];
    s->top--;
    return value;
}

int peek(stack *s)
{
    if (isEmpty(s))
    {
        printf("Empty Stack. Can't pop value");
        return;
    }
    return s->arr[s->top];
}

int size(stack *s)
{
    return s->top + 1;
}