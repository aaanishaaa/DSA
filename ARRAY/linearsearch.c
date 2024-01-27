#include<stdio.h>

int linearsearch(int a[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(a[i] == key) {
            printf("The element %d is found at index %d\n", key, i);
            return 0;  // Added return statement to exit the function if the element is found
        }
    }
    // If the loop completes without finding the element
    printf("The %d is not found\n", key);
    return 0;
}

int main() {
    int a[10], i, n, key;
    printf("Enter the number of elements of array: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &key);

    linearsearch(a, n, key);

    return 0;
}
