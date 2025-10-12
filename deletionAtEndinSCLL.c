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

// Function to delete node from end
void deleteAtEnd()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("\nList is already empty.\n");
        return;
    }

    // If only one node
    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("\nLast node deleted, list is now empty.\n");
        return;
    }

    temp = head;
    // Traverse to the last node
    while (temp->next != head)
    {
        prev = temp;       // keep track of previous node
        temp = temp->next; // move ahead
    }

    prev->next = head; // second last node points to head
    free(temp);        // delete last node

    printf("\nNode deleted from end successfully!\n");
}

// Main function
int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    displayList();

    deleteAtEnd();

    displayList();

    return 0;
}
