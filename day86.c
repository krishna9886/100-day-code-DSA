#include <stdio.h>

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    long long low = 0, high = n, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long sq = mid * mid;

        if (sq == n) {
            ans = mid;
            break;              // perfect square
        } else if (sq < n) {
            ans = mid;          // mid is a candidate
            low = mid + 1;      // try bigger
        } else {
            high = mid - 1;     // try smaller
        }
    }

    printf("%lld\n", ans);
    return 0;
}
