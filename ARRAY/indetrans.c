#include <stdio.h>

/*****************************TRAVERSAL*************************/

void Traverse(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
}

/*****************************INSERTION*************************/

void insertion(int a[], int *n, int e, int p)
{
    if (p < 0 || p > *n)
    {
        printf("Invalid position for insertion.\n");
        return;
    }

    for (int i = *n; i > p; i--)
    {
        a[i] = a[i - 1];
    }
    a[p] = e;
    (*n)++;
}

/*******************************DELETION************************/

int deletion(int A[], int *n, int i)
{
    if (i < 0 || i >= *n)
    {
        printf("Invalid position for deletion.\n");
        return -1;
    }

    int x = A[i];
    for (int j = i + 1; j < *n; j++)
    {
        A[j - 1] = A[j];
    }
    (*n)--;
    return x;
}

int main()
{
    int a[50], n, e, p;
    printf("Enter the number of Elements: ");
    scanf("%d", &n);
    printf("\nEnter Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Original Array: ");
    Traverse(a, n);

    printf("\nEnter the Position for Insertion: ");
    scanf("%d", &p);
    printf("Enter the Element to Insert: ");
    scanf("%d", &e);

    insertion(a, &n, e, p);

    printf("The New Array after Insertion: ");
    Traverse(a, n);

    printf("\nEnter the Position to Delete: ");
    scanf("%d", &p);

    int x = deletion(a, &n, p);

    if (x != -1)
    {
        printf("The New Array after Deletion: ");
        Traverse(a, n);
        printf("\nDeleted element was: %d\n", x);
    }

    return 0;
}
