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
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at Start – fixed: link new node to old head, return new head
struct Node *insertAtStart(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head; // <-- was missing
    return newNode;       // new head
}

// Insert at End – fixed: return head (unchanged unless list was empty)
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
        return newNode;
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head; // <-- was returning newNode incorrectly
}

// Insert at Position – fixed: return head (not the new node)
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
    // Edge case: if head is NULL and position > 0, loop will detect temp == NULL
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
    return head; // <-- was returning newNode
}

// Delete at Beginning – correct (already works)
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

// Delete from End – correct (already works)
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

// Delete from Position – correct (already works)
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

int main()
{
    struct Node *head = NULL;

    head = insertAtStart(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtPosition(head, 15, 1); // 10 -> 15 -> 20 -> 30

    printf("After Insertions:\n");
    traversal(head);

    int pos = search(head, 20);
    if (pos != -1)
        printf("Value found at position: %d\n", pos);
    else
        printf("Value not found\n");

    head = deleteAtBegin(head);         // deletes 10
    head = deleteFromEnd(head);         // deletes 30
    head = deleteFromPosition(head, 1); // deletes 20 (list becomes 15 only)

    printf("After Deletions:\n");
    traversal(head);

    return 0;
}