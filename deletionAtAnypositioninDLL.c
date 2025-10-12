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

// Function to delete at any position
struct Node *deleteAtPosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("\nList is empty. Nothing to delete.\n");
        return head;
    }

    struct Node *temp = head;

    // Deleting the first node
    if (position == 1)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        printf("\nDeleted node: %d\n", temp->data);
        free(temp);
        return head;
    }

    // Traverse to the node to be deleted
    for (int i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("\nInvalid position!\n");
        return head;
    }

    // Update links
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("\nDeleted node: %d\n", temp->data);
    free(temp);

    return head;
}

// Main function
int main()
{
    struct Node *head = NULL;
    int n, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createDoublyLinkedList(n);

    displayList(head);

    printf("\nEnter position to delete (1 = beginning): ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);

    displayList(head);

    return 0;
}
