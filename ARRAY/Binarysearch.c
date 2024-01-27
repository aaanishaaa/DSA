#include <stdio.h>

int binarysearch(int a[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Corrected the calculation of mid

        if (a[mid] == key) {
            printf("The element %d is found at index %d\n", key, mid);
            return mid;
        } else if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("The element %d is not found\n", key);
    return -1;  // Element not found
}

int main() {
    int a[100], i, n, key;
    printf("Enter the number of elements of array: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &key);

    binarysearch(a, n, key);

    return 0;
}
