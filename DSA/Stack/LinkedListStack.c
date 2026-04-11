#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Stack structure – only needs a pointer to the top node
typedef struct
{
    Node *top;
    int count;
} Stack;

void initStack(Stack *s)
{
    s->top = NULL;
    s->count = 0;
}

// Check if stack is empty
bool isEmpty(Stack *s)
{
    return s->top == NULL;
}

// Push a value onto the stack
void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Cannot push %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = s->top; // new node points to old top
    s->top = newNode;       // top becomes new node
    s->count++;
    printf("Pushed %d\n", value);
}

// Pop the top element and return its value
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow! Cannot pop from empty stack\n");
        return -999; // sentinel error value
    }
    Node *temp = s->top;
    int poppedValue = temp->data;
    s->top = s->top->next; // move top down
    free(temp);            // free the old top node
    s->count--;
    return poppedValue;
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty, nothing to peek\n");
        return -999;
    }
    return s->top->data;
}

int size(Stack *s)
{
    return s->count;
}

void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    Node *current = s->top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeStack(Stack *s)
{
    while (!isEmpty(s))
    {
        pop(s);
    }
    printf("Stack memory fully freed\n");
}
int main()
{
    Stack s;
    initStack(&s);

    printf("----- Linked List Stack\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);
    printf("Top element: %d\n", peek(&s));
    printf("Stack size: %d\n", size(&s));

    printf("Popped: %d\n", pop(&s));
    display(&s);
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d \n", pop(&s));
    display(&s);

    freeStack(&s);
    return 0;
}