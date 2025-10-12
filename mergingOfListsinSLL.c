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

// Function to create a sorted linked list
struct Node *createLinkedList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data;

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d (in sorted order): ", i + 1);
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

// Function to merge two sorted linked lists
struct Node *mergeSortedLists(struct Node *head1, struct Node *head2)
{
    // If either list is empty
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    struct Node *mergedHead = NULL, *mergedTail = NULL;

    // Initialize mergedHead with the smaller first node
    if (head1->data <= head2->data)
    {
        mergedHead = mergedTail = head1;
        head1 = head1->next;
    }
    else
    {
        mergedHead = mergedTail = head2;
        head2 = head2->next;
    }

    // Traverse both lists
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            mergedTail->next = head1;
            head1 = head1->next;
        }
        else
        {
            mergedTail->next = head2;
            head2 = head2->next;
        }
        mergedTail = mergedTail->next; // move tail
    }

    // Attach the remaining nodes (if any)
    if (head1 != NULL)
        mergedTail->next = head1;
    else
        mergedTail->next = head2;

    return mergedHead;
}

// Main function
int main()
{
    struct Node *head1 = NULL, *head2 = NULL, *mergedList = NULL;
    int n1, n2;

    printf("Enter number of nodes for first (sorted) list: ");
    scanf("%d", &n1);
    head1 = createLinkedList(n1);

    printf("\nEnter number of nodes for second (sorted) list: ");
    scanf("%d", &n2);
    head2 = createLinkedList(n2);

    printf("\nFirst ");
    displayList(head1);

    printf("\nSecond ");
    displayList(head2);

    mergedList = mergeSortedLists(head1, head2);

    printf("\nAfter merging (sorted) ");
    displayList(mergedList);

    return 0;
}
