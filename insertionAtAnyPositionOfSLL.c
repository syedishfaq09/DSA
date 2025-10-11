#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory not allocated!\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list
struct Node *createLinkedList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data;

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode = createNode(data);

        if (head == NULL)
            head = newNode; // first node
        else
            temp->next = newNode; // link previous node to new node

        temp = newNode; // move temp to last node
    }
    return head;
}

// Function to insert a node at any position
struct Node *insertAtPosition(struct Node *head, int data, int position)
{
    struct Node *newNode = createNode(data);

    // Case 1: insert at beginning
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    struct Node *temp = head;
    // Traverse to node before desired position
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL)
    {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }

    // Insert in middle or end
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Function to display the linked list
void displayList(struct Node *head)
{
    struct Node *temp = head;
    printf("\nLinked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;
    int n, data, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createLinkedList(n);

    printf("\nOriginal ");
    displayList(head);

    printf("\nEnter data to insert: ");
    scanf("%d", &data);

    printf("Enter position to insert at: ");
    scanf("%d", &position);

    head = insertAtPosition(head, data, position);

    printf("\nAfter insertion ");
    displayList(head);

    return 0;
}
