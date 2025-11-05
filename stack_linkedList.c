#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack node
struct Node
{
    int data;
    struct Node *next;
};

// Top pointer (head of linked list)
struct Node *top = NULL;

// Push operation
void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack.\n", value);
}

// Pop operation
void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }
    struct Node *temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;
    free(temp);
}

// Peek operation
void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

// Display stack
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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
