#include <stdio.h>
void exchange(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void selection(int A[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        exchange(&A[i], &A[min]);
    }
}
int main()
{
    int A[] = {1, 4, 1, 2, 6};
    selection(A, 4);
    printf("\n The Sorted array is\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}