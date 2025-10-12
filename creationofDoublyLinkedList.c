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
            head = newNode; // first node
            temp = newNode;
        }
        else
        {
            temp->next = newNode; // link new node to current last node
            newNode->prev = temp; // link back to previous node
            temp = newNode;       // move temp to last node
        }
    }
    return head;
}

// Function to display the list in forward direction
void displayForward(struct Node *head)
{
    struct Node *temp = head;
    printf("\nList in forward direction: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display the list in backward direction
void displayBackward(struct Node *head)
{
    struct Node *temp = head;

    // Move to the last node
    while (temp != NULL && temp->next != NULL)
        temp = temp->next;

    printf("List in backward direction: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createDoublyLinkedList(n);

    displayForward(head);
    displayBackward(head);

    return 0;
}
