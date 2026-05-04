#include <stdio.h>

long long mergeAndCount(int arr[], int temp[], int l, int m, int r) {
    int i = l, j = m, k = l;
    long long count = 0;
    while (i <= m - 1 && j <= r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else { temp[k++] = arr[j++]; count += (m - i); }
    }
    while (i <= m - 1) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (i = l; i <= r; i++) arr[i] = temp[i];
    return count;
}

long long solve(int arr[], int temp[], int l, int r) {
    long long count = 0;
    if (l < r) {
        int m = (l + r) / 2;
        count += solve(arr, temp, l, m);
        count += solve(arr, temp, m + 1, r);
        count += mergeAndCount(arr, temp, l, m + 1, r);
    }
    return count;
}

int main() {
    int n; scanf("%d", &n);
    int arr[n], temp[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%lld\n", solve(arr, temp, 0, n - 1));
    return 0;
}