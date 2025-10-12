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

// Function to delete node at any position
void deleteAtPosition(int position)
{
    struct Node *temp;
    int i;

    if (head == NULL)
    {
        printf("\nList is empty. No deletion possible.\n");
        return;
    }

    // Deletion at beginning
    if (position == 1)
    {
        // If only one node
        if (head->next == head)
        {
            free(head);
            head = NULL;
            printf("\nNode deleted from position 1. List is now empty.\n");
            return;
        }

        struct Node *last = head->prev;
        temp = head;
        head = head->next;
        last->next = head;
        head->prev = last;
        free(temp);
        printf("\nNode deleted from position 1 successfully!\n");
        return;
    }

    // Deletion at middle or end
    temp = head;
    for (i = 1; i < position && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        printf("\nInvalid position! No deletion performed.\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
    printf("\nNode deleted from position %d successfully!\n", position);
}

// Main function
int main()
{
    int n, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    displayList();

    printf("\nEnter position to delete (1 = beginning): ");
    scanf("%d", &pos);

    deleteAtPosition(pos);

    displayList();

    return 0;
}
