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

// Function to delete node at any position
struct Node *deleteAtPosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("\nList is empty!\n");
        return head;
    }

    struct Node *temp = head;

    // Case 1: delete first node
    if (position == 1)
    {
        printf("\nDeleted node: %d\n", head->data);
        head = head->next;
        free(temp);
        return head;
    }

    // Traverse to the node before the one to be deleted
    struct Node *prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL)
    {
        printf("\nInvalid position!\n");
        return head;
    }

    // Unlink and delete node
    prev->next = temp->next;
    printf("\nDeleted node: %d\n", temp->data);
    free(temp);

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
    int n, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createLinkedList(n);

    printf("\nOriginal ");
    displayList(head);

    printf("\nEnter position to delete: ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);

    printf("\nAfter deletion ");
    displayList(head);

    return 0;
}
