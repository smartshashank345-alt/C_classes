#include <stdio.h>
#include <limits.h>

struct item
{
    int value, priority;
};

struct item pr[100000];
int size = -1;

// Function to insert element in priority queue
void enqueue(int value, int priority)
{
    pr[++size] = (struct item){value, priority};
}

// Function to get index of element with highest priority
int peek()
{
    int highestPriority = INT_MIN, ind = -1;
    for (int i = 0; i <= size; i++)
    {
        if (pr[i].priority > highestPriority ||
            (pr[i].priority == highestPriority && pr[i].value > pr[ind].value))
        {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}

// Function to remove the element with highest priority
void dequeue()
{
    int ind = peek();
    for (int i = ind; i < size; i++)
    {
        pr[i] = pr[i + 1];
    }
    size--;
}

int main()
{
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);

    printf("%d\n", pr[peek()].value);
    dequeue();

    printf("%d\n", pr[peek()].value);
    dequeue();

    printf("%d\n", pr[peek()].value);
    return 0;
}