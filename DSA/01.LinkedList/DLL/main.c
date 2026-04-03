#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Insertion -- At starting , Middle , at Last
// Deletion -- At starting , Middle , at Last
// Searching
// Traversing

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
    newNode->prev = NULL;
    return newNode;
}

// Insert --
//    head -> 10

//<-Node ->  <- 10 ->

// <-Node ->

struct Node *insertAtStart(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    return newNode;
}

// <- 10 -> <-15 ->
// <-15 ->
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
    newNode->prev = temp;

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

    for (int i = 0; i <= position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    struct Node *newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev = newNode;
    temp->prev->next = newNode;

    return newNode;
}

//         3     6 ->  <- 5 ->    <- 8             4            2

//         0     1           2            3             4
//                  <- 5 ->

// head-> NULL<-3 ->   <- 6 ->  <- 5 ->    <- 8
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
    head->prev = NULL;

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
    // struct Node *prev = NULL;

    while (temp->next != NULL)
    {
        // prev = temp;
        temp = temp->next;
    }

    temp->prev->next = NULL;
    temp->prev = NULL;
    printf("Deleted: %d\n", temp->data);
    free(temp);

    return head;
}

//    3     6 ->  <- 5 ->    <- 8             4  ->  NULL     <- 2 -> NULL

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

    for (int i = 0; i <= position && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = NULL;
    temp->prev = NULL;
    printf("Deleted: %d\n", temp->data);
    free(temp);

    return head;
}

// 4 5 6.    7 ->     <- 80 ->   <- 45

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