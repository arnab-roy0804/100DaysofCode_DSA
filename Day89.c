#include <stdio.h>

int isPossible(int arr[], int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) return 0; // Single book exceeds limit
        
        if (pageSum + arr[i] > mid) {
            studentCount++;
            pageSum = arr[i];
            if (studentCount > m) return 0;
        } else {
            pageSum += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    int arr[n];
    int sum = 0, max_val = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }
    
    if (m > n) { printf("-1\n"); return 0; }
    
    int low = max_val, high = sum;
    int ans = sum;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1; // Try to minimize the maximum
        } else {
            low = mid + 1;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}