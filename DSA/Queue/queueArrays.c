#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct
{
    int data[MAX];
    int front, rear;
} ArrayQueue;

// function declarations
void initQueue(ArrayQueue *aq);
void Enqueue(ArrayQueue *aq, int value);
int Dequeue(ArrayQueue *aq);
int isEmpty(ArrayQueue *aq);
int isFull(ArrayQueue *aq);
void display(ArrayQueue *aq);

void initQueue(ArrayQueue *aq)
{
    aq->front = aq->rear = -1;
}

int isEmpty(ArrayQueue *aq)
{
    return aq->front == -1;
}

int isFull(ArrayQueue *aq)
{
    return (aq->rear + 1) % MAX == aq->front;
}

void Enqueue(ArrayQueue *aq, int value)
{
    if (isFull(aq))
    {
        printf("Queue Overflow\n");
        return;
    }

    // first element
    if (isEmpty(aq))
    {
        aq->front = 0;
    }

    // move rear circularly
    aq->rear = (aq->rear + 1) % MAX;
    aq->data[aq->rear] = value;
}

int Dequeue(ArrayQueue *aq)
{
    if (isEmpty(aq))
    {
        printf("Queue Underflow\n");
        return -1000;
    }

    int val = aq->data[aq->front];

    // single element case
    if (aq->front == aq->rear)
    {
        aq->front = aq->rear = -1;
    }
    else
    {
        aq->front = (aq->front + 1) % MAX;
    }

    return val;
}

void display(ArrayQueue *aq)
{
    if (isEmpty(aq))
    {
        printf("Queue is empty\n");
        return;
    }

    int i = aq->front;

    printf("Queue: ");
    while (1)
    {
        printf("%d ", aq->data[i]);

        if (i == aq->rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    ArrayQueue q;
    initQueue(&q);

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);

    display(&q);

    printf("Deleted: %d\n", Dequeue(&q));
    printf("Deleted: %d\n", Dequeue(&q));

    display(&q);

    Enqueue(&q, 50);
    Enqueue(&q, 60);

    display(&q);

    return 0;
}