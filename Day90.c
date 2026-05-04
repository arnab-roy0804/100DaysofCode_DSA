#include <stdio.h>

int canPaint(int boards[], int n, int k, int mid) {
    int painters = 1;
    int current_load = 0;
    
    for (int i = 0; i < n; i++) {
        if (boards[i] > mid) return 0;
        
        if (current_load + boards[i] > mid) {
            painters++;
            current_load = boards[i];
            if (painters > k) return 0;
        } else {
            current_load += boards[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    
    int boards[n];
    int sum = 0, max_len = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if (boards[i] > max_len) max_len = boards[i];
    }
    
    int low = max_len, high = sum;
    int ans = sum;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}