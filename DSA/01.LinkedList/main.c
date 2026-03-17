// Linked List -- Arrays
// 10 34 25 35 55
// 0  1  2  3. 4.

// 34 ----> 45 -------> 20

// Insertion -- At begin , in middle (somehwre in between), end
// Deletion --  At begin , in middle (somehwre in between), end
//  Search
// TRaversal

#include <stdio.h>
#include <stdlib.h>

// int a,  int b
// struct MyStruct {
// int a ,
// int b}

struct Node
{
    int data;
    struct Node *next;
    // strcut is keyword , Node is type and next is name of the variable
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Failed");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Node1 -> Node2 -> Node3 -> NULL

//  NewNode->Node1->Data = 100 , Node2-> Data = 300 Node3-> 30
//  HeadPointer --> First NOde

struct Node *InsertAtStart(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return newNode;
}

// zero based // 1 based
struct Node *InsertAtPosition(struct Node *head, int data, int position)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    if (position < 0)
    {
        printf("Invalid Position");
        return head;
    }
    // Beginning
    if (position == 0)
    {
        InsertAtStart(head, data);
    }

    //
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Out of range");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return newNode;
}