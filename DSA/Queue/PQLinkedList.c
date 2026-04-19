#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;

    int priority;

    struct node *next;
} Node;

Node *newNode(int d, int p)
{

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

// Return the value at head
int peek(Node *head)
{

    // Return the data of the node at the head of the list
    return head->data;
}

// Removes the element with the highest priority from the list
Node *pop(Node *head)
{

    // Store the current head node in a temporary variable
    Node *temp = head;

    // Move the head to the next node in the list
    head = head->next;

    // Free the memory of the removed head node
    free(temp);

    // Return the new head of the list
    return head;
}

// Function to push according to priority
Node *push(Node *head, int d, int p)
{
    Node *start = head;

    // Create new Node with the given data and priority
    Node *temp = newNode(d, p);

    // Special Case: Insert the new node before the head
    // if the list is empty or the head has lower priority
    if (head->priority > p)
    {

        // Insert the new node before the head
        temp->next = head;
        head = temp;
    }
    else
    {

        // Traverse the list to find the correct position
        // to insert the new node based on priority
        while (start->next != NULL &&
               start->next->priority < p)
        {
            start = start->next;
        }

        // Insert the new node at the found position
        temp->next = start->next;
        start->next = temp;
    }
    return head;
}

// Function to check if the list is empty
int isEmpty(Node *head)
{
    return (head == NULL);
}

// Driver code
int main()
{

    Node *pq = newNode(4, 1);
    pq = push(pq, 5, 2);
    pq = push(pq, 6, 3);
    pq = push(pq, 7, 0);

    while (!isEmpty(pq))
    {
        printf("%d ", peek(pq));
        pq = pop(pq);
    }

    return 0;
}