#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} LinkedQueue;

// function declarations
void initQueue(LinkedQueue *q);
int isEmpty(LinkedQueue *q);
void Enqueue(LinkedQueue *q, int value);
int Dequeue(LinkedQueue *q);
void display(LinkedQueue *q);

void initQueue(LinkedQueue *q)
{
    q->front = q->rear = NULL;
}

int isEmpty(LinkedQueue *q)
{
    return q->front == NULL;
}

void Enqueue(LinkedQueue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // first element
    if (isEmpty(q))
    {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int Dequeue(LinkedQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1000;
    }

    Node *temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    // if queue becomes empty
    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    return val;
}

void display(LinkedQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    Node *temp = q->front;

    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    LinkedQueue q;
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