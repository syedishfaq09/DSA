#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node
{
    int data;
    struct Node *prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create a doubly linked list
struct Node *createDoublyLinkedList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data;

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode = createNode(data);

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    return head;
}

// Function to display the list
void displayList(struct Node *head)
{
    struct Node *temp = head;
    printf("\nDoubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete at the end
struct Node *deleteAtEnd(struct Node *head)
{
    if (head == NULL)
    { // List is empty
        printf("\nList is empty. Nothing to delete.\n");
        return head;
    }

    struct Node *temp = head;

    // If only one node exists
    if (head->next == NULL)
    {
        printf("\nDeleted node: %d\n", head->data);
        free(head);
        return NULL;
    }

    // Traverse to the last node
    while (temp->next != NULL)
        temp = temp->next;

    // Update second last node
    temp->prev->next = NULL;

    printf("\nDeleted node: %d\n", temp->data);
    free(temp); // Free memory of last node

    return head;
}

// Main function
int main()
{
    struct Node *head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createDoublyLinkedList(n);

    displayList(head);

    head = deleteAtEnd(head);

    displayList(head);

    return 0;
}
