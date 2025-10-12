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
    head->next = head;
    head->prev = head;
    temp = head;

    for (int i = 2; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode = createNode(value);

        newNode->prev = temp;
        newNode->next = head;
        temp->next = newNode;
        head->prev = newNode;
        temp = newNode;
    }

    printf("\nDoubly Circular Linked List created successfully!\n");
}

// Function to display the list
void displayList()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("\nDoubly Circular Linked List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to insert node at the end
void insertAtEnd(int value)
{
    struct Node *newNode, *last;

    newNode = createNode(value);

    if (head == NULL)
    {
        // If list is empty
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        printf("\nNode inserted as the first node successfully!\n");
        return;
    }

    last = head->prev; // get the last node

    // Link new node
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;

    printf("\nNode inserted at end successfully!\n");
}

// Main function
int main()
{
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    displayList();

    printf("\nEnter value to insert at end: ");
    scanf("%d", &value);
    insertAtEnd(value);

    displayList();

    return 0;
}
