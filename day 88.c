#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int canPlaceCows(int stalls[], int n, int k, int minDist) {
    int count = 1; // Place first cow at first stall
    int lastPos = stalls[0];
    
    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
            if (count == k) return 1;
        }
    }
    return 0;
}

int aggressiveCows(int stalls[], int n, int k) {
    qsort(stalls, n, sizeof(int), compare);
    
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int result = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canPlaceCows(stalls, n, k, mid)) {
            result = mid;
            low = mid + 1; // Try for larger minimum distance
        } else {
            high = mid - 1; // Try for smaller minimum distance
        }
    }
    
    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }
    
    printf("%d\n", aggressiveCows(stalls, n, k));
    return 0;
}
