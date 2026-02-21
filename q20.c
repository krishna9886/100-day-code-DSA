#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n]; 
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    // Outer loop picks the STARTING point of the subarray
    for (int i = 0; i < n; i++) {
        long long current_sum = 0;

        for (int j = i; j < n; j++) {
            current_sum += arr[j];

            // If the sum from index i to j is zero, we found one!
            if (current_sum == 0) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}