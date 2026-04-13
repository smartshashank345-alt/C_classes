#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at beginning – returns new head
Node *insertAtStart(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
        return newNode;
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Insert at end – returns head (unchanged unless list was empty)
Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
        return newNode;
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert at given 0‑based position – returns head
Node *insertAtPosition(Node *head, int data, int pos)
{
    if (pos < 0)
    {
        printf("Invalid position\n");
        return head;
    }
    if (pos == 0)
        return insertAtStart(head, data);

    Node *temp = head;
    // Traverse to the node currently at 'pos' (if it exists)
    for (int i = 0; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    Node *newNode = createNode(data);
    // Insert before 'temp'
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;
    return head;
}

// Delete first node – returns new head (NULL if list becomes empty)
Node *deleteAtBegin(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL) // EDGE CASE: list had only one node
        head->prev = NULL;
    printf("Deleted: %d\n", temp->data);
    free(temp);
    return head;
}

// Delete last node – returns head
Node *deleteFromEnd(Node *head)
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
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    printf("Deleted: %d\n", temp->data);
    free(temp);
    return head;
}

// Delete node at given 0‑based position – returns head
Node *deleteFromPosition(Node *head, int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if (pos < 0)
    {
        printf("Invalid position\n");
        return head;
    }
    if (pos == 0)
        return deleteAtBegin(head);

    Node *temp = head;
    // Traverse to the node at 'pos'
    for (int i = 0; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    // Bridge the gap
    temp->prev->next = temp->next;
    if (temp->next != NULL) // EDGE CASE: deleting last node
        temp->next->prev = temp->prev;
    printf("Deleted: %d\n", temp->data);
    free(temp);
    return head;
}

// Traversal forward
void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search – returns index or -1
int search(Node *head, int value)
{
    Node *temp = head;
    int idx = 0;
    while (temp != NULL)
    {
        if (temp->data == value)
            return idx;
        temp = temp->next;
        idx++;
    }
    return -1;
}

// Free entire list
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// ---------- Test in main ----------
int main()
{
    Node *head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 30);
    head = insertAtPosition(head, 20, 1); // 10 -> 20 -> 30
    traverse(head);

    head = deleteAtBegin(head);         // removes 10
    head = deleteFromEnd(head);         // removes 30
    head = deleteFromPosition(head, 0); // removes 20
    traverse(head);                     // NULL

    head = insertAtStart(head, 5);
    head = insertAtEnd(head, 15);
    traverse(head); // 5 -> 15 -> NULL

    freeList(head);
    return 0;
}