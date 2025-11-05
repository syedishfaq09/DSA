#include <stdio.h>
#define MAX 5 // maximum size of stack

int stack[MAX];
int top = -1;

// Function to check if stack is full
int isFull()
{
    return top == MAX - 1;
}

// Function to check if stack is empty
int isEmpty()
{
    return top == -1;
}

// Push operation
void push(int value)
{
    if (isFull())
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

// Pop operation
void pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow! Nothing to pop.\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Peek operation
void peek()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

// Display the stack
void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    peek();
    display();
    pop();
    display();
    return 0;
}
