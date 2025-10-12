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

// Function to reverse the linked list
struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL)
    {
        next = current->next; // store next node
        current->next = prev; // reverse the link
        prev = current;       // move prev one step ahead
        current = next;       // move current one step ahead
    }

    head = prev; // new head of the reversed list
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

    head = reverseList(head);

    printf("\nReversed ");
    displayList(head);

    return 0;
}
