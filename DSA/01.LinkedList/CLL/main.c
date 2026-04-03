#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node *insertAtStart(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;

    return newNode;
}
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    return newNode;
}

// Insert at Position (0-based)
struct Node *insertAtPosition(struct Node *head, int data, int position)
{
    if (position < 0)
    {
        printf("Invalid position\n");
        return head;
    }

    if (position == 0)
        return insertAtStart(head, data);

    struct Node *temp = head;

    for (int i = 0; i < position - 1 && temp != head; i++)
        temp = temp->next;

    if (temp == head)
    {
        printf("Position out of range\n");
        return head;
    }

    struct Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;

    return newNode;
}
