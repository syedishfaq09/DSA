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

// Function to delete node at any position
void deleteAtPosition(int position)
{
    struct Node *temp, *prev;
    int i;

    if (head == NULL)
    {
        printf("\nList is already empty.\n");
        return;
    }

    // Case 1: delete first node
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

        // More than one node
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next; // move to last node
        }
        struct Node *toDelete = head;
        head = head->next; // move head
        temp->next = head; // last node points to new head
        free(toDelete);
        printf("\nNode deleted from position 1 successfully!\n");
        return;
    }

    // Case 2: delete from middle or end
    temp = head;
    prev = NULL;
    for (i = 1; i < position && temp->next != head; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    // If position greater than number of nodes
    if (temp == head)
    {
        printf("\nInvalid position! No deletion performed.\n");
        return;
    }

    prev->next = temp->next;
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
