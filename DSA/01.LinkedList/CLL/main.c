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

// Delete at Beginning
struct Node *deleteAtBegin(struct Node *head)
{
    // EMpty Linked List
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    // single Node
    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    struct Node *temp = head;
    struct Node *delNode = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;

    free(delNode);

    return head;
}

// Delete from End
struct Node *deleteFromEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        printf("Deleted: %d\n", head->data);
        free(head);
        return NULL;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    printf("Deleted: %d\n", temp->data);
    free(temp);

    return head;
}

// Delete from Position
struct Node *deleteFromPosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (position < 0)
    {
        printf("Invalid position\n");
        return head;
    }

    if (position == 0)
        return deleteAtBegin(head);

    struct Node *temp = head;
    struct Node *prev = NULL;

    for (int i = 0; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    prev->next = temp->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);

    return head;
}

// Traversal
void traversal(struct Node *head)
{
    struct Node *temp = head;

    while (temp != head)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Search (returns index)
int search(struct Node *head, int value)
{
    struct Node *temp = head;
    int index = 0;

    while (temp != head)
    {
        if (temp->data == value)
            return index;

        temp = temp->next;
        index++;
    }

    return -1;
}