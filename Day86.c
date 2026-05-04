#include <stdio.h>

long long integerSqrt(long long n) {
    if (n < 2) return n;
    long long low = 1, high = n, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid <= n / mid) { // Avoiding overflow (mid * mid <= n)
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    return ans;
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) printf("%lld\n", integerSqrt(n));
    return 0;
}

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;
    if (n == 0 || n == 1) { printf("%lld\n", n); return 0; }
    
    long long low = 0, high = n, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid <= n / mid) { // Optimization to prevent overflow
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}