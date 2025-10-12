#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Function to create doubly circular linked list
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

// Function to delete node from end
void deleteAtEnd()
{
    struct Node *last;

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
        printf("\nLast node deleted. List is now empty.\n");
        return;
    }

    last = head->prev; // get last node
    struct Node *secondLast = last->prev;

    secondLast->next = head;
    head->prev = secondLast;

    free(last);

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
