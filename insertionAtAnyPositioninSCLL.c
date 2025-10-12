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

// Function to insert node at any position
void insertAtPosition(int value, int position)
{
    struct Node *newNode, *temp;
    int i;

    newNode = createNode(value);

    // Case 1: Empty list
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        printf("\nList was empty, inserted as the first node.\n");
        return;
    }

    // Case 2: Insert at beginning
    if (position == 1)
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        printf("\nNode inserted at position 1 (beginning).\n");
        return;
    }

    // Case 3: Insert at given position
    temp = head;
    for (i = 1; i < position - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    // If position is greater than number of nodes, insert at end
    if (temp->next == head && position > i + 1)
    {
        printf("\nPosition out of range. Inserting at end instead.\n");
    }

    newNode->next = temp->next;
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
