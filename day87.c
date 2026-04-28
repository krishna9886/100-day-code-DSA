#include <stdio.h>

// Iterative binary search on a sorted array
// Returns index if found, -1 otherwise
int binary_search_iterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;           // found
        } else if (arr[mid] < key) {
            low = mid + 1;        // search right half
        } else {
            high = mid - 1;       // search left half
        }
    }

    return -1; // not found
}

int main() {
    int n;
    int arr[100];   // adjust size as per constraints

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Simple sorting (e.g., bubble sort) to match example
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Output: sorted array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    /*
    // If the actual problem gives you a key k to search,
    // you can uncomment this part and use binary_search_iterative:

    int k;
    scanf("%d", &k);
    int idx = binary_search_iterative(arr, n, k);
    if (idx != -1) {
        printf("Found at index %d\n", idx);
    } else {
        printf("Not Found\n");
    }
    */

    return 0;
}
