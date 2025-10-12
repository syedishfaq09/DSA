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

// Function to insert at the end
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    { // If list is empty
        head = newNode;
        return head;
    }

    struct Node *temp = head;

    // Traverse to the last node
    while (temp->next != NULL)
        temp = temp->next;

    // Link the new node at the end
    temp->next = newNode;
    newNode->prev = temp;

    printf("\nNode %d inserted at end.\n", data);
    return head;
}

// Main function
int main()
{
    struct Node *head = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createDoublyLinkedList(n);

    displayList(head);

    printf("\nEnter data to insert at end: ");
    scanf("%d", &data);

    head = insertAtEnd(head, data);

    displayList(head);

    return 0;
}
