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
    head->next = head; // first node points to itself
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

// Function to insert node at the end
void insertAtEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = createNode(value);

    if (head == NULL)
    {
        // if list is empty
        head = newNode;
        newNode->next = head;
        return;
    }

    temp = head;
    // move to last node
    while (temp->next != head)
    {
        temp = temp->next;
    }

    // link new node
    temp->next = newNode;
    newNode->next = head;

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
