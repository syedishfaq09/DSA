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

// Function to delete node from end
struct Node *deleteAtEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("\nList is already empty!\n");
        return head;
    }

    // If there is only one node
    if (head->next == NULL)
    {
        printf("\nDeleted node: %d\n", head->data);
        free(head);
        head = NULL;
        return head;
    }

    // Traverse to the second last node
    struct Node *temp = head, *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    printf("\nDeleted node: %d\n", temp->data);
    prev->next = NULL; // remove link to last node
    free(temp);        // free memory of last node

    return head;
}

// Function to display linked list
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
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createLinkedList(n);

    printf("\nOriginal ");
    displayList(head);

    head = deleteAtEnd(head);

    printf("\nAfter deletion at end ");
    displayList(head);

    return 0;
}
