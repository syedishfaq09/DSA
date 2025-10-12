#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create a doubly circular linked list
void createList(int n)
{
    struct Node *newNode, *temp;
    int value;

    if (n <= 0)
    {
        printf("Number of nodes must be positive.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &value);
    head = createNode(value);
    head->next = head; // circular link
    head->prev = head;
    temp = head;

    for (int i = 2; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode = createNode(value);

        newNode->prev = temp; // new node previous = current last node
        newNode->next = head; // new node next = head (circular link)
        temp->next = newNode; // last node next = new node
        head->prev = newNode; // head previous = new node (circular link)
        temp = newNode;       // move temp to new node
    }

    printf("\nDoubly Circular Linked List created successfully!\n");
}

// Function to display list in forward direction
void displayForward()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("\nList in forward direction: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to display list in backward direction
void displayBackward()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head->prev; // start from last node
    printf("\nList in backward direction: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("\n");
}

// Main function
int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    displayForward();
    displayBackward();

    return 0;
}
