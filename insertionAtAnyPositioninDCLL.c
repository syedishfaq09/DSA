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

// Function to insert node at any position
void insertAtPosition(int value, int position)
{
    struct Node *newNode, *temp;
    int i;

    newNode = createNode(value);

    if (head == NULL)
    {
        // If list is empty, insert as first node
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        printf("\nList was empty. Node inserted as the first node.\n");
        return;
    }

    // Insert at beginning
    if (position == 1)
    {
        struct Node *last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
        head = newNode;
        printf("\nNode inserted at position 1 (beginning).\n");
        return;
    }

    // Insert at middle or end
    temp = head;
    for (i = 1; i < position - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    // Link the new node
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    printf("\nNode inserted at position %d successfully!\n", position);
}

// Main function
int main()
{
    int n, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    displayList();

    printf("\nEnter value to insert: ");
    scanf("%d", &value);
    printf("Enter position to insert (1 = beginning): ");
    scanf("%d", &pos);

    insertAtPosition(value, pos);

    displayList();

    return 0;
}
