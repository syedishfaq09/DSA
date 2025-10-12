#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create circular linked list
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
    temp = head;

    for (int i = 2; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode = createNode(value);
        newNode->next = head;
        temp->next = newNode;
        temp = newNode;
    }

    printf("\nCircular Linked List created successfully!\n");
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
    printf("\nCircular Linked List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to delete node from beginning
void deleteAtBeginning()
{
    struct Node *temp, *toDelete;

    if (head == NULL)
    {
        printf("\nList is already empty.\n");
        return;
    }

    // If only one node exists
    if (head->next == head)
    {
        toDelete = head;
        head = NULL;
        free(toDelete);
        printf("\nLast node deleted, list is now empty.\n");
        return;
    }

    // More than one node
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next; // move to last node
    }

    toDelete = head;
    head = head->next; // move head to next node
    temp->next = head; // last node now points to new head
    free(toDelete);    // delete old head

    printf("\nNode deleted from beginning successfully!\n");
}

// Main function
int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    displayList();

    deleteAtBeginning();

    displayList();

    return 0;
}
