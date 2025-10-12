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

// Function to concatenate two linked lists
struct Node *concatenate(struct Node *head1, struct Node *head2)
{
    if (head1 == NULL) // if first list is empty
        return head2;

    if (head2 == NULL) // if second list is empty
        return head1;

    struct Node *temp = head1;

    // Traverse to the last node of first list
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Link last node of first list to head of second
    temp->next = head2;

    return head1; // head of the combined list
}

// Main function
int main()
{
    struct Node *head1 = NULL, *head2 = NULL, *mergedList = NULL;
    int n1, n2;

    printf("Enter number of nodes for first list: ");
    scanf("%d", &n1);
    head1 = createLinkedList(n1);

    printf("\nEnter number of nodes for second list: ");
    scanf("%d", &n2);
    head2 = createLinkedList(n2);

    printf("\nFirst ");
    displayList(head1);

    printf("\nSecond ");
    displayList(head2);

    mergedList = concatenate(head1, head2);

    printf("\nAfter concatenation ");
    displayList(mergedList);

    return 0;
}
