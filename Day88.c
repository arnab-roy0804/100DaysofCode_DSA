#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if k cows can be placed with at least 'mid' distance
int canPlaceCows(int stalls[], int n, int k, int mid) {
    int count = 1; // Place first cow at first stall
    int last_pos = stalls[0];
    
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_pos >= mid) {
            count++;
            last_pos = stalls[i];
            if (count >= k) return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    
    int stalls[n];
    for (int i = 0; i < n; i++) scanf("%d", &stalls[i]);
    
    // Stall positions must be sorted
    qsort(stalls, n, sizeof(int), compare);
    
    int low = 1, high = stalls[n-1] - stalls[0];
    int ans = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1; // Try for a larger distance
        } else {
            high = mid - 1;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}