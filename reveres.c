// Reverse Array

#include <stdio.h>
int main()
{

    int x;
    printf("Enter the number of elements:");
    scanf("%d", &x);

    int arr[x];
    for (int i = 0; i < x; i++)
    {
        printf("Enter element number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("You entered: ");
    for (int i = 0; i < x; i++)
        printf("%d ", arr[i]);

    printf("\nArray elements in reverse order: ");

    for (int i = x - 1; i >= 0; i--)
    {

        printf("%d ", arr[i]);
    }
}