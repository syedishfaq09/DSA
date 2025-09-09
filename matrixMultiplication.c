#include <stdio.h>
int main()
{
    int r1, c1, r2, c2;

    printf("Enter number of Rows of first matrix. ");
    scanf("%d", &r1);

    printf("Enter number of columns of first matrix. ");
    scanf("%d", &c1);

    printf("Enter number of Rows of second matrix. ");
    scanf("%d", &r2);

    printf("Enter number of columns of second matrix.");
    scanf("%d", &c2);

    if (c1 != r2)
    {
        printf("\nMatrix multiplication is not possible.\n");
        printf("Reason: column of first matrix is not equal to row of second matrix.");
        return 1;
    }

    int mat01[r1][c1];

    int mat02[r2][c2];

    // First matrix:


    printf("\n");

    
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("Enter element mat01[%d][%d]. ", i, j);
            scanf("%d", &mat01[i][j]);
        }
    }

    printf("\nFirst matrix: \n");

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d ", mat01[i][j]);
        }
        printf("\n");
    }

    // 2nd matrix

    printf("\n");

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("Enter element mat02[%d][%d]. ", i, j);
            scanf("%d", &mat02[i][j]);
        }
    }

    printf("\nSecond matrix: \n");

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", mat02[i][j]);
        }
        printf("\n");
    }

    int res[r1][c2];

    int cr = c1;

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < cr; k++)
            {
                res[i][j] = res[i][j] + mat01[i][k] * mat02[k][j];
            }
        }
    }
    printf("\nMultiplication of matrix is: \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}