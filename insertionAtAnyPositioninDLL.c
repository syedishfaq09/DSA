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

// Function to insert at any position
struct Node *insertAtPosition(struct Node *head, int data, int position)
{
    struct Node *newNode = createNode(data);

    if (position <= 1 || head == NULL)
    { // Insert at beginning
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        printf("\nNode %d inserted at position %d (beginning).\n", data, position);
        return head;
    }

    struct Node *temp = head;
    int i;

    // Traverse to the node before the desired position
    for (i = 1; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    // Insert in between or at end
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("\nNode %d inserted at position %d.\n", data, position);
    return head;
}

// Main function
int main()
{
    struct Node *head = NULL;
    int n, data, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createDoublyLinkedList(n);

    displayList(head);

    printf("\nEnter data to insert: ");
    scanf("%d", &data);

    printf("Enter position to insert (1 = beginning): ");
    scanf("%d", &position);

    head = insertAtPosition(head, data, position);

    displayList(head);

    return 0;
}
