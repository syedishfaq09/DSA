#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue
void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued.\n", value);
}

// Dequeue
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow! Nothing to dequeue.\n");
        return;
    }
    struct Node *temp = front;
    printf("%d dequeued.\n", front->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

// Peek
void peek()
{
    if (front == NULL)
        printf("Queue is empty.\n");
    else
        printf("Front element: %d\n", front->data);
}

// Display
void display()
{
    if (front == NULL)
        printf("Queue is empty.\n");
    else
    {
        struct Node *temp = front;
        printf("Queue: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    peek();
    return 0;
}
