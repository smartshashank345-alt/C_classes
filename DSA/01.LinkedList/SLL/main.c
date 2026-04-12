#include <stdio.h>
#include <stdlib.h>

/*
========================================
Linked List - Complete Implementation
========================================

Operations Covered:
1. Insert (Start, End, Position)
2. Delete (Start, End, Position)
3. Traversal
4. Search
5. Reverse

Indexing: 0-based
*/

// Node Definition
struct Node
{
    int data;
    struct Node *next;
};

// Create Node
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

// Insert at Start
struct Node *insertAtStart(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return newNode;
}

// Insert at End
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

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

    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
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
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    struct Node *temp = head;
    head = head->next;

    printf("Deleted: %d\n", temp->data);
    free(temp);

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

    prev->next = NULL;
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

    while (temp != NULL)
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

    while (temp != NULL)
    {
        if (temp->data == value)
            return index;

        temp = temp->next;
        index++;
    }

    return -1;
}
// Main Function (Driver)
int main()
{
    struct Node *head = NULL;

    // Insert Operations
    head = insertAtStart(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtPosition(head, 15, 1);

    printf("After Insertions:\n");
    traversal(head);

    // Search
    int pos = search(head, 20);
    if (pos != -1)
        printf("Value found at position: %d\n", pos);
    else
        printf("Value not found\n");

    // Delete Operations
    head = deleteAtBegin(head);
    head = deleteFromEnd(head);
    head = deleteFromPosition(head, 1);

    printf("After Deletions:\n");
    traversal(head);
    return 0;
}