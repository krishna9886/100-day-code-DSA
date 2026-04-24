#include <stdio.h>

// Day 82 - Question 1: Upper Bound & Lower Bound Implementation
// Topic: Sorting & Searching - Binary Search - Bounds

// Lower Bound: first index where arr[mid] >= x
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Upper Bound: first index where arr[mid] > x
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int x;
    scanf("%d", &x);
    printf("%d %d\n", lowerBound(arr, n, x), upperBound(arr, n, x));
    return 0;
}
