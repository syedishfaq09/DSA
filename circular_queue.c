#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value)
{
    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front))
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("%d enqueued.\n", value);
    }
}

// Dequeue
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("%d dequeued.\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

// Display
void display()
{
    if (front == -1)
        printf("Queue is empty.\n");
    else
    {
        printf("Queue: ");
        int i = front;
        while (1)
        {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
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
    enqueue(40);
    enqueue(50);
    display();
    return 0;
}
